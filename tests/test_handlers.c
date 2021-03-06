/*
 * upb - a minimalist implementation of protocol buffers.
 *
 * Copyright (c) 2011 Google Inc.  See LICENSE for details.
 *
 */

#include "upb/handlers.h"
#include "upb/descriptor/descriptor.upb.h"
#include "upb_test.h"
#include <stdlib.h>
#include <string.h>

static bool startmsg(void *c, const void *hd) {
  UPB_UNUSED(c);
  UPB_UNUSED(hd);
  return true;
}

static void test_error() {
  // Test creating handlers of a static msgdef.
  const upb_symtab *s = upbdefs_google_protobuf_descriptor(&s);
  upb_handlers *h =
      upb_handlers_new(upbdefs_google_protobuf_DescriptorProto(s), &h);
  upb_symtab_unref(s, &s);

  // Attempt to set the same handler twice causes error.
  ASSERT(upb_ok(upb_handlers_status(h)));
  upb_handlers_setstartmsg(h, &startmsg, NULL);
  ASSERT(upb_ok(upb_handlers_status(h)));
  upb_handlers_setstartmsg(h, &startmsg, NULL);
  ASSERT(!upb_ok(upb_handlers_status(h)));
  ASSERT(!upb_handlers_freeze(&h, 1, NULL));

  // Clearing the error will let us proceed.
  upb_handlers_clearerr(h);
  ASSERT(upb_handlers_freeze(&h, 1, NULL));
  ASSERT(upb_handlers_isfrozen(h));

  upb_handlers_unref(h, &h);
}

int run_tests(int argc, char *argv[]) {
  UPB_UNUSED(argc);
  UPB_UNUSED(argv);
  test_error();
  return 0;
}
