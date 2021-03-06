/*
 * upb - a minimalist implementation of protocol buffers.
 *
 * Copyright (c) 2011-2012 Google Inc.  See LICENSE for details.
 * Author: Josh Haberman <jhaberman@gmail.com>
 *
 * TODO(haberman): it's unclear whether a lot of the consistency checks should
 * assert() or return false.
 */

#include "upb/handlers.h"

#include <stdlib.h>
#include <string.h>

#include "upb/sink.h"

// Defined for the sole purpose of having a unique pointer value for
// UPB_NO_CLOSURE.
char _upb_noclosure;

static void freehandlers(upb_refcounted *r) {
  upb_handlers *h = (upb_handlers*)r;

  upb_inttable_iter i;
  upb_inttable_begin(&i, &h->cleanup_);
  for(; !upb_inttable_done(&i); upb_inttable_next(&i)) {
    void *val = (void*)upb_inttable_iter_key(&i);
    upb_value func_val = upb_inttable_iter_value(&i);
    upb_handlerfree *func = upb_value_getfptr(func_val);
    func(val);
  }

  upb_inttable_uninit(&h->cleanup_);
  upb_msgdef_unref(h->msg, h);
  free(h->sub);
  free(h);
}

static void visithandlers(const upb_refcounted *r, upb_refcounted_visit *visit,
                          void *closure) {
  const upb_handlers *h = (const upb_handlers*)r;
  upb_msg_iter i;
  for(upb_msg_begin(&i, h->msg); !upb_msg_done(&i); upb_msg_next(&i)) {
    upb_fielddef *f = upb_msg_iter_field(&i);
    if (!upb_fielddef_issubmsg(f)) continue;
    const upb_handlers *sub = upb_handlers_getsubhandlers(h, f);
    if (sub) visit(r, UPB_UPCAST(sub), closure);
  }
}

static const struct upb_refcounted_vtbl vtbl = {visithandlers, freehandlers};

typedef struct {
  upb_inttable tab;  // maps upb_msgdef* -> upb_handlers*.
  upb_handlers_callback *callback;
  const void *closure;
} dfs_state;

// TODO(haberman): discard upb_handlers* objects that do not actually have any
// handlers set and cannot reach any upb_handlers* object that does.  This is
// slightly tricky to do correctly.
static upb_handlers *newformsg(const upb_msgdef *m, const void *owner,
                               dfs_state *s) {
  upb_handlers *h = upb_handlers_new(m, owner);
  if (!h) return NULL;
  if (!upb_inttable_insertptr(&s->tab, m, upb_value_ptr(h))) goto oom;

  s->callback(s->closure, h);

  // For each submessage field, get or create a handlers object and set it as
  // the subhandlers.
  upb_msg_iter i;
  for(upb_msg_begin(&i, m); !upb_msg_done(&i); upb_msg_next(&i)) {
    upb_fielddef *f = upb_msg_iter_field(&i);
    if (!upb_fielddef_issubmsg(f)) continue;

    const upb_msgdef *subdef = upb_downcast_msgdef(upb_fielddef_subdef(f));
    upb_value subm_ent;
    if (upb_inttable_lookupptr(&s->tab, subdef, &subm_ent)) {
      upb_handlers_setsubhandlers(h, f, upb_value_getptr(subm_ent));
    } else {
      upb_handlers *sub_mh = newformsg(subdef, &sub_mh, s);
      if (!sub_mh) goto oom;
      upb_handlers_setsubhandlers(h, f, sub_mh);
      upb_handlers_unref(sub_mh, &sub_mh);
    }
  }
  return h;

oom:
  upb_handlers_unref(h, owner);
  return NULL;
}

// Given a selector for a STARTSUBMSG handler, resolves to a pointer to the
// subhandlers for this submessage field.
#define SUBH(h, selector) (h->sub[selector])

// The selector for a submessage field is the field index.
#define SUBH_F(h, f) SUBH(h, f->index_)

static int32_t trygetsel(upb_handlers *h, const upb_fielddef *f,
                         upb_handlertype_t type) {
  upb_selector_t sel;
  assert(!upb_handlers_isfrozen(h));
  if (upb_handlers_msgdef(h) != upb_fielddef_containingtype(f)) {
    upb_status_seterrf(
        &h->status_, "type mismatch: field %s does not belong to message %s",
        upb_fielddef_name(f), upb_msgdef_fullname(upb_handlers_msgdef(h)));
    return -1;
  }
  if (!upb_handlers_getselector(f, type, &sel)) {
    upb_status_seterrf(
        &h->status_,
        "type mismatch: cannot register handler type %d for field %s",
        type, upb_fielddef_name(f));
    return -1;
  }
  return sel;
}

static upb_selector_t handlers_getsel(upb_handlers *h, const upb_fielddef *f,
                             upb_handlertype_t type) {
  int32_t sel = trygetsel(h, f, type);
  assert(sel >= 0);
  return sel;
}

static const void **returntype(upb_handlers *h, const upb_fielddef *f,
                               upb_handlertype_t type) {
  return &h->table[handlers_getsel(h, f, type)].attr.return_closure_type_;
}

static bool doset(upb_handlers *h, int32_t sel, const upb_fielddef *f,
                  upb_handlertype_t type, upb_func *func,
                  upb_handlerattr *attr) {
  assert(!upb_handlers_isfrozen(h));

  if (sel < 0) {
    upb_status_seterrmsg(&h->status_,
                         "incorrect handler type for this field.");
    return false;
  }

  if (h->table[sel].func) {
    upb_status_seterrmsg(&h->status_,
                         "cannot change handler once it has been set.");
    return false;
  }

  upb_handlerattr set_attr = UPB_HANDLERATTR_INITIALIZER;
  if (attr) {
    set_attr = *attr;
  }

  // Check that the given closure type matches the closure type that has been
  // established for this context (if any).
  const void *closure_type = upb_handlerattr_closuretype(&set_attr);
  const void **context_closure_type;

  if (type == UPB_HANDLER_STRING) {
    context_closure_type = returntype(h, f, UPB_HANDLER_STARTSTR);
  } else if (f && upb_fielddef_isseq(f) &&
             type != UPB_HANDLER_STARTSEQ &&
             type != UPB_HANDLER_ENDSEQ) {
    context_closure_type = returntype(h, f, UPB_HANDLER_STARTSEQ);
  } else {
    context_closure_type = &h->top_closure_type;
  }

  if (closure_type && *context_closure_type &&
      closure_type != *context_closure_type) {
    // TODO(haberman): better message for debugging.
    upb_status_seterrmsg(&h->status_, "closure type does not match");
    return false;
  }

  if (closure_type)
    *context_closure_type = closure_type;

  // If this is a STARTSEQ or STARTSTR handler, check that the returned pointer
  // matches any pre-existing expectations about what type is expected.
  if (type == UPB_HANDLER_STARTSEQ || type == UPB_HANDLER_STARTSTR) {
    const void *return_type = upb_handlerattr_returnclosuretype(&set_attr);
    const void *table_return_type =
        upb_handlerattr_returnclosuretype(&h->table[sel].attr);
    if (return_type && table_return_type && return_type != table_return_type) {
      upb_status_seterrmsg(&h->status_, "closure return type does not match");
      return false;
    }

    if (table_return_type && !return_type)
      upb_handlerattr_setreturnclosuretype(&set_attr, table_return_type);
  }

  h->table[sel].func = (upb_func*)func;
  h->table[sel].attr = set_attr;
  return true;
}

// Returns the effective closure type for this handler (which will propagate
// from outer frames if this frame has no START* handler).  Not implemented for
// UPB_HANDLER_STRING at the moment since this is not needed.  Returns NULL is
// the effective closure type is unspecified (either no handler was registered
// to specify it or the handler that was registered did not specify the closure
// type).
const void *effective_closure_type(upb_handlers *h, const upb_fielddef *f,
                                   upb_handlertype_t type) {
  assert(type != UPB_HANDLER_STRING);
  const void *ret = h->top_closure_type;
  upb_selector_t sel;
  if (upb_fielddef_isseq(f) &&
      type != UPB_HANDLER_STARTSEQ &&
      type != UPB_HANDLER_ENDSEQ &&
      h->table[sel = handlers_getsel(h, f, UPB_HANDLER_STARTSEQ)].func) {
    ret = upb_handlerattr_returnclosuretype(&h->table[sel].attr);
  }

  if (type == UPB_HANDLER_STRING &&
      h->table[sel = handlers_getsel(h, f, UPB_HANDLER_STARTSTR)].func) {
    ret = upb_handlerattr_returnclosuretype(&h->table[sel].attr);
  }

  // The effective type of the submessage; not used yet.
  // if (type == SUBMESSAGE &&
  //     h->table[sel = handlers_getsel(h, f, UPB_HANDLER_STARTSUBMSG)].func) {
  //   ret = upb_handlerattr_returnclosuretype(&h->table[sel].attr);
  // }

  return ret;
}

// Checks whether the START* handler specified by f & type is missing even
// though it is required to convert the established type of an outer frame
// ("closure_type") into the established type of an inner frame (represented in
// the return closure type of this handler's attr.
bool checkstart(upb_handlers *h, const upb_fielddef *f, upb_handlertype_t type,
                upb_status *status) {
  upb_selector_t sel = handlers_getsel(h, f, type);
  if (h->table[sel].func) return true;
  const void *closure_type = effective_closure_type(h, f, type);
  const upb_handlerattr *attr = &h->table[sel].attr;
  const void *return_closure_type = upb_handlerattr_returnclosuretype(attr);
  if (closure_type && return_closure_type &&
      closure_type != return_closure_type) {
    upb_status_seterrf(status,
                       "expected start handler to return sub type for field %f",
                       upb_fielddef_name(f));
    return false;
  }
  return true;
}

/* Public interface ***********************************************************/

bool upb_handlers_isfrozen(const upb_handlers *h) {
  return upb_refcounted_isfrozen(UPB_UPCAST(h));
}

void upb_handlers_ref(const upb_handlers *h, const void *owner) {
  upb_refcounted_ref(UPB_UPCAST(h), owner);
}

void upb_handlers_unref(const upb_handlers *h, const void *owner) {
  upb_refcounted_unref(UPB_UPCAST(h), owner);
}

void upb_handlers_donateref(
    const upb_handlers *h, const void *from, const void *to) {
  upb_refcounted_donateref(UPB_UPCAST(h), from, to);
}

void upb_handlers_checkref(const upb_handlers *h, const void *owner) {
  upb_refcounted_checkref(UPB_UPCAST(h), owner);
}

upb_handlers *upb_handlers_new(const upb_msgdef *md, const void *owner) {
  assert(upb_msgdef_isfrozen(md));

  int extra = sizeof(upb_handlers_tabent) * (md->selector_count - 1);
  upb_handlers *h = calloc(sizeof(*h) + extra, 1);
  if (!h) return NULL;

  h->msg = md;
  upb_msgdef_ref(h->msg, h);
  upb_status_clear(&h->status_);
  h->sub = calloc(md->submsg_field_count, sizeof(*h->sub));
  if (!h->sub) goto oom;
  if (!upb_refcounted_init(UPB_UPCAST(h), &vtbl, owner)) goto oom;
  if (!upb_inttable_init(&h->cleanup_, UPB_CTYPE_FPTR)) goto oom;

  // calloc() above initialized all handlers to NULL.
  return h;

oom:
  freehandlers(UPB_UPCAST(h));
  return NULL;
}

const upb_handlers *upb_handlers_newfrozen(const upb_msgdef *m,
                                           const void *owner,
                                           upb_handlers_callback *callback,
                                           const void *closure) {
  dfs_state state;
  state.callback = callback;
  state.closure = closure;
  if (!upb_inttable_init(&state.tab, UPB_CTYPE_PTR)) return NULL;

  upb_handlers *ret = newformsg(m, owner, &state);

  upb_inttable_uninit(&state.tab);
  if (!ret) return NULL;

  upb_refcounted *r = UPB_UPCAST(ret);
  bool ok = upb_refcounted_freeze(&r, 1, NULL, UPB_MAX_HANDLER_DEPTH);
  UPB_ASSERT_VAR(ok, ok);

  return ret;
}

const upb_status *upb_handlers_status(upb_handlers *h) {
  assert(!upb_handlers_isfrozen(h));
  return &h->status_;
}

void upb_handlers_clearerr(upb_handlers *h) {
  assert(!upb_handlers_isfrozen(h));
  upb_status_clear(&h->status_);
}

#define SETTER(name, handlerctype, handlertype) \
  bool upb_handlers_set ## name(upb_handlers *h, const upb_fielddef *f, \
                                handlerctype func, upb_handlerattr *attr) { \
    int32_t sel = trygetsel(h, f, handlertype); \
    return doset(h, sel, f, handlertype, (upb_func*)func, attr); \
  }

SETTER(int32,       upb_int32_handlerfunc*,       UPB_HANDLER_INT32);
SETTER(int64,       upb_int64_handlerfunc*,       UPB_HANDLER_INT64);
SETTER(uint32,      upb_uint32_handlerfunc*,      UPB_HANDLER_UINT32);
SETTER(uint64,      upb_uint64_handlerfunc*,      UPB_HANDLER_UINT64);
SETTER(float,       upb_float_handlerfunc*,       UPB_HANDLER_FLOAT);
SETTER(double,      upb_double_handlerfunc*,      UPB_HANDLER_DOUBLE);
SETTER(bool,        upb_bool_handlerfunc*,        UPB_HANDLER_BOOL);
SETTER(startstr,    upb_startstr_handlerfunc*,    UPB_HANDLER_STARTSTR);
SETTER(string,      upb_string_handlerfunc*,      UPB_HANDLER_STRING);
SETTER(endstr,      upb_endfield_handlerfunc*,    UPB_HANDLER_ENDSTR);
SETTER(startseq,    upb_startfield_handlerfunc*,  UPB_HANDLER_STARTSEQ);
SETTER(startsubmsg, upb_startfield_handlerfunc*,  UPB_HANDLER_STARTSUBMSG);
SETTER(endsubmsg,   upb_endfield_handlerfunc*,    UPB_HANDLER_ENDSUBMSG);
SETTER(endseq,      upb_endfield_handlerfunc*,    UPB_HANDLER_ENDSEQ);

#undef SETTER

bool upb_handlers_setstartmsg(upb_handlers *h, upb_startmsg_handlerfunc *func,
                              upb_handlerattr *attr) {
  return doset(h, UPB_STARTMSG_SELECTOR, NULL, UPB_HANDLER_INT32,
               (upb_func *)func, attr);
}

bool upb_handlers_setendmsg(upb_handlers *h, upb_endmsg_handlerfunc *func,
                            upb_handlerattr *attr) {
  assert(!upb_handlers_isfrozen(h));
  return doset(h, UPB_ENDMSG_SELECTOR, NULL, UPB_HANDLER_INT32,
               (upb_func *)func, attr);
}

bool upb_handlers_setsubhandlers(upb_handlers *h, const upb_fielddef *f,
                                 const upb_handlers *sub) {
  assert(sub);
  assert(!upb_handlers_isfrozen(h));
  assert(upb_fielddef_issubmsg(f));
  if (SUBH_F(h, f)) return false;  // Can't reset.
  if (UPB_UPCAST(upb_handlers_msgdef(sub)) != upb_fielddef_subdef(f)) {
    return false;
  }
  SUBH_F(h, f) = sub;
  upb_ref2(sub, h);
  return true;
}

const upb_handlers *upb_handlers_getsubhandlers(const upb_handlers *h,
                                                const upb_fielddef *f) {
  assert(upb_fielddef_issubmsg(f));
  return SUBH_F(h, f);
}

bool upb_handlers_getattr(const upb_handlers *h, upb_selector_t sel,
                          upb_handlerattr *attr) {
  if (!upb_handlers_gethandler(h, sel))
    return false;
  *attr = h->table[sel].attr;
  return true;
}

const upb_handlers *upb_handlers_getsubhandlers_sel(const upb_handlers *h,
                                                    upb_selector_t sel) {
  // STARTSUBMSG selector in sel is the field's selector base.
  return SUBH(h, sel - UPB_STATIC_SELECTOR_COUNT);
}

const upb_msgdef *upb_handlers_msgdef(const upb_handlers *h) { return h->msg; }

bool upb_handlers_addcleanup(upb_handlers *h, void *p, upb_handlerfree *func) {
  if (upb_inttable_lookupptr(&h->cleanup_, p, NULL)) {
    return false;
  }
  bool ok = upb_inttable_insertptr(&h->cleanup_, p, upb_value_fptr(func));
  UPB_ASSERT_VAR(ok, ok);
  return true;
}


/* "Static" methods ***********************************************************/

bool upb_handlers_freeze(upb_handlers *const*handlers, int n, upb_status *s) {
  // TODO: verify we have a transitive closure.
  for (int i = 0; i < n; i++) {
    upb_handlers *h = handlers[i];

    if (!upb_ok(&h->status_)) {
      upb_status_seterrf(s, "handlers for message %s had error status: %s",
                         upb_msgdef_fullname(upb_handlers_msgdef(h)),
                         upb_status_errmsg(&h->status_));
      return false;
    }

    // Check that there are no closure mismatches due to missing Start* handlers
    // or subhandlers with different type-level types.
    upb_msg_iter j;
    for(upb_msg_begin(&j, h->msg); !upb_msg_done(&j); upb_msg_next(&j)) {

      const upb_fielddef *f = upb_msg_iter_field(&j);
      if (upb_fielddef_isseq(f)) {
        if (!checkstart(h, f, UPB_HANDLER_STARTSEQ, s))
          return false;
      }

      if (upb_fielddef_isstring(f)) {
        if (!checkstart(h, f, UPB_HANDLER_STARTSTR, s))
          return false;
      }

      if (upb_fielddef_issubmsg(f)) {
        bool hashandler = false;
        if (upb_handlers_gethandler(
                h, handlers_getsel(h, f, UPB_HANDLER_STARTSUBMSG)) ||
            upb_handlers_gethandler(
                h, handlers_getsel(h, f, UPB_HANDLER_ENDSUBMSG))) {
          hashandler = true;
        }

        if (upb_fielddef_isseq(f) &&
            (upb_handlers_gethandler(
                 h, handlers_getsel(h, f, UPB_HANDLER_STARTSEQ)) ||
             upb_handlers_gethandler(
                 h, handlers_getsel(h, f, UPB_HANDLER_ENDSEQ)))) {
          hashandler = true;
        }

        if (hashandler && !upb_handlers_getsubhandlers(h, f)) {
          // For now we add an empty subhandlers in this case.  It makes the
          // decoder code generator simpler, because it only has to handle two
          // cases (submessage has handlers or not) as opposed to three
          // (submessage has handlers in enclosing message but no subhandlers).
          //
          // This makes parsing less efficient in the case that we want to
          // notice a submessage but skip its contents (like if we're testing
          // for submessage presence or counting the number of repeated
          // submessages).  In this case we will end up parsing the submessage
          // field by field and throwing away the results for each, instead of
          // skipping the whole delimited thing at once.  If this is an issue we
          // can revisit it, but do remember that this only arises when you have
          // handlers (startseq/startsubmsg/endsubmsg/endseq) set for the
          // submessage but no subhandlers.  The uses cases for this are
          // limited.
          upb_handlers *sub = upb_handlers_new(upb_fielddef_msgsubdef(f), &sub);
          upb_handlers_setsubhandlers(h, f, sub);
          upb_handlers_unref(sub, &sub);
        }

        // TODO(haberman): check type of submessage.
        // This is slightly tricky; also consider whether we should check that
        // they match at setsubhandlers time.
      }
    }
  }

  if (!upb_refcounted_freeze((upb_refcounted*const*)handlers, n, s,
                             UPB_MAX_HANDLER_DEPTH)) {
    return false;
  }

  return true;
}

upb_handlertype_t upb_handlers_getprimitivehandlertype(const upb_fielddef *f) {
  switch (upb_fielddef_type(f)) {
    case UPB_TYPE_INT32:
    case UPB_TYPE_ENUM: return UPB_HANDLER_INT32;
    case UPB_TYPE_INT64: return UPB_HANDLER_INT64;
    case UPB_TYPE_UINT32: return UPB_HANDLER_UINT32;
    case UPB_TYPE_UINT64: return UPB_HANDLER_UINT64;
    case UPB_TYPE_FLOAT: return UPB_HANDLER_FLOAT;
    case UPB_TYPE_DOUBLE: return UPB_HANDLER_DOUBLE;
    case UPB_TYPE_BOOL: return UPB_HANDLER_BOOL;
    default: assert(false); return -1;  // Invalid input.
  }
}

bool upb_handlers_getselector(const upb_fielddef *f, upb_handlertype_t type,
                              upb_selector_t *s) {
  switch (type) {
    case UPB_HANDLER_INT32:
    case UPB_HANDLER_INT64:
    case UPB_HANDLER_UINT32:
    case UPB_HANDLER_UINT64:
    case UPB_HANDLER_FLOAT:
    case UPB_HANDLER_DOUBLE:
    case UPB_HANDLER_BOOL:
      if (!upb_fielddef_isprimitive(f) ||
          upb_handlers_getprimitivehandlertype(f) != type)
        return false;
      *s = f->selector_base;
      break;
    case UPB_HANDLER_STRING:
      if (upb_fielddef_isstring(f)) {
        *s = f->selector_base;
      } else if (upb_fielddef_lazy(f)) {
        *s = f->selector_base + 3;
      } else {
        return false;
      }
      break;
    case UPB_HANDLER_STARTSTR:
      if (upb_fielddef_isstring(f) || upb_fielddef_lazy(f)) {
        *s = f->selector_base + 1;
      } else {
        return false;
      }
      break;
    case UPB_HANDLER_ENDSTR:
      if (upb_fielddef_isstring(f) || upb_fielddef_lazy(f)) {
        *s = f->selector_base + 2;
      } else {
        return false;
      }
      break;
    case UPB_HANDLER_STARTSEQ:
      if (!upb_fielddef_isseq(f)) return false;
      *s = f->selector_base - 2;
      break;
    case UPB_HANDLER_ENDSEQ:
      if (!upb_fielddef_isseq(f)) return false;
      *s = f->selector_base - 1;
      break;
    case UPB_HANDLER_STARTSUBMSG:
      if (!upb_fielddef_issubmsg(f)) return false;
      // Selectors for STARTSUBMSG are at the beginning of the table so that the
      // selector can also be used as an index into the "sub" array of
      // subhandlers.  The indexes for the two into these two tables are the
      // same, except that in the handler table the static selectors come first.
      *s = f->index_ + UPB_STATIC_SELECTOR_COUNT;
      break;
    case UPB_HANDLER_ENDSUBMSG:
      if (!upb_fielddef_issubmsg(f)) return false;
      *s = f->selector_base;
      break;
  }
  assert(*s < upb_fielddef_containingtype(f)->selector_count);
  return true;
}

uint32_t upb_handlers_selectorbaseoffset(const upb_fielddef *f) {
  return upb_fielddef_isseq(f) ? 2 : 0;
}

uint32_t upb_handlers_selectorcount(const upb_fielddef *f) {
  uint32_t ret = 1;
  if (upb_fielddef_isseq(f)) ret += 2;    // STARTSEQ/ENDSEQ
  if (upb_fielddef_isstring(f)) ret += 2; // [STRING]/STARTSTR/ENDSTR
  if (upb_fielddef_issubmsg(f)) {
    // ENDSUBMSG (STARTSUBMSG is at table beginning)
    ret += 0;
    if (upb_fielddef_lazy(f)) {
      // STARTSTR/ENDSTR/STRING (for lazy)
      ret += 3;
    }
  }
  return ret;
}


/* upb_handlerattr ************************************************************/

void upb_handlerattr_init(upb_handlerattr *attr) {
  upb_handlerattr from = UPB_HANDLERATTR_INITIALIZER;
  memcpy(attr, &from, sizeof(*attr));
}

void upb_handlerattr_uninit(upb_handlerattr *attr) {
  UPB_UNUSED(attr);
}

bool upb_handlerattr_sethandlerdata(upb_handlerattr *attr, const void *hd) {
  attr->handler_data_ = hd;
  return true;
}

bool upb_handlerattr_setclosuretype(upb_handlerattr *attr, const void *type) {
  attr->closure_type_ = type;
  return true;
}

const void *upb_handlerattr_closuretype(const upb_handlerattr *attr) {
  return attr->closure_type_;
}

bool upb_handlerattr_setreturnclosuretype(upb_handlerattr *attr,
                                          const void *type) {
  attr->return_closure_type_ = type;
  return true;
}

const void *upb_handlerattr_returnclosuretype(const upb_handlerattr *attr) {
  return attr->return_closure_type_;
}

bool upb_handlerattr_setalwaysok(upb_handlerattr *attr, bool alwaysok) {
  attr->alwaysok_ = alwaysok;
  return true;
}

bool upb_handlerattr_alwaysok(const upb_handlerattr *attr) {
  return attr->alwaysok_;
}

/* upb_bufhandle **************************************************************/

size_t upb_bufhandle_objofs(const upb_bufhandle *h) {
  return h->objofs_;
}

/* upb_byteshandler ***********************************************************/

void upb_byteshandler_init(upb_byteshandler* h) {
  memset(h, 0, sizeof(*h));
}

// For when we support handlerfree callbacks.
void upb_byteshandler_uninit(upb_byteshandler* h) {
  UPB_UNUSED(h);
}

bool upb_byteshandler_setstartstr(upb_byteshandler *h,
                                  upb_startstr_handlerfunc *func, void *d) {
  h->table[UPB_STARTSTR_SELECTOR].func = (upb_func*)func;
  h->table[UPB_STARTSTR_SELECTOR].attr.handler_data_ = d;
  return true;
}

bool upb_byteshandler_setstring(upb_byteshandler *h,
                                upb_string_handlerfunc *func, void *d) {
  h->table[UPB_STRING_SELECTOR].func = (upb_func*)func;
  h->table[UPB_STRING_SELECTOR].attr.handler_data_ = d;
  return true;
}

bool upb_byteshandler_setendstr(upb_byteshandler *h,
                                upb_endfield_handlerfunc *func, void *d) {
  h->table[UPB_ENDSTR_SELECTOR].func = (upb_func*)func;
  h->table[UPB_ENDSTR_SELECTOR].attr.handler_data_ = d;
  return true;
}
