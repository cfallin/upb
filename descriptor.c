#include "descriptor.h"

static struct upb_string google_protobuf_filedescriptor_name = {
  .byte_len=32, .data=(uint8_t*)"google/protobuf/descriptor.proto"
};

static struct upb_string google_protobuf_filedescriptor_package = {
  .byte_len=15, .data=(uint8_t*)"google.protobuf"
};

struct google_protobuf_DescriptorProto google_protobuf_FileDescriptorSet_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_FileDescriptorProto_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_DescriptorProto_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_FieldDescriptorProto_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_EnumDescriptorProto_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_EnumValueDescriptorProto_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_ServiceDescriptorProto_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_MethodDescriptorProto_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_FileOptions_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_MessageOptions_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_FieldOptions_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_EnumOptions_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_EnumValueOptions_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_ServiceOptions_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_MethodOptions_descriptor;
struct google_protobuf_DescriptorProto google_protobuf_UninterpretedOption_descriptor;

static google_protobuf_DescriptorProto *google_protobuf_filedescriptor_message_type_array[] = {
  &google_protobuf_FileDescriptorSet_descriptor,
  &google_protobuf_FileDescriptorProto_descriptor,
  &google_protobuf_DescriptorProto_descriptor,
  &google_protobuf_FieldDescriptorProto_descriptor,
  &google_protobuf_EnumDescriptorProto_descriptor,
  &google_protobuf_EnumValueDescriptorProto_descriptor,
  &google_protobuf_ServiceDescriptorProto_descriptor,
  &google_protobuf_MethodDescriptorProto_descriptor,
  &google_protobuf_FileOptions_descriptor,
  &google_protobuf_MessageOptions_descriptor,
  &google_protobuf_FieldOptions_descriptor,
  &google_protobuf_EnumOptions_descriptor,
  &google_protobuf_EnumValueOptions_descriptor,
  &google_protobuf_ServiceOptions_descriptor,
  &google_protobuf_MethodOptions_descriptor,
  &google_protobuf_UninterpretedOption_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto) google_protobuf_filedescriptor_message_type = {
  .len=16, .elements=google_protobuf_filedescriptor_message_type_array
};

google_protobuf_FileDescriptorProto google_protobuf_filedescriptor = {
  .set_flags = { .has = {
    .name = 1,
    .package = 1,
    .dependency = 0,
    .message_type = 1,
    .enum_type = 0,
    .service = 0,
    .extension = 0,
    .options = 1,
  } },
  .name = &google_protobuf_filedescriptor_name,
  .package = &google_protobuf_filedescriptor_package,
  .dependency = NULL,
  .message_type = &google_protobuf_filedescriptor_message_type,
};

/* google_protobuf_FileDescriptorSet_descriptor */
static struct upb_string google_protobuf_FileDescriptorSet_descriptor_name = {
  .byte_len=17, .data=(uint8_t*)"FileDescriptorSet"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorSet_file_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_FileDescriptorSet_descriptor_field_array[] = {
  &google_protobuf_FileDescriptorSet_file_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_FileDescriptorSet_descriptor_field = {
  .len=1, .elements=google_protobuf_FileDescriptorSet_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_FileDescriptorSet_descriptor = {
  .name = &google_protobuf_FileDescriptorSet_descriptor_name,
  .field = &google_protobuf_FileDescriptorSet_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_FileDescriptorSet_file_fieldname = {
  .byte_len=4, .data=(uint8_t*)"file"
};

static struct upb_string google_protobuf_FileDescriptorSet_file_field_typename = {
  .byte_len=19, .data=(uint8_t*)"FileDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorSet_file = {
  .name = &google_protobuf_FileDescriptorSet_file_fieldname,
  .number = (uint32_t)1,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_FileDescriptorSet_file_field_typename,
};
/* google_protobuf_FileDescriptorProto_descriptor */
static struct upb_string google_protobuf_FileDescriptorProto_descriptor_name = {
  .byte_len=19, .data=(uint8_t*)"FileDescriptorProto"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_package_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_dependency_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_message_type_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_enum_type_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_service_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_extension_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_options_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_FileDescriptorProto_descriptor_field_array[] = {
  &google_protobuf_FileDescriptorProto_name_descriptor,
  &google_protobuf_FileDescriptorProto_package_descriptor,
  &google_protobuf_FileDescriptorProto_dependency_descriptor,
  &google_protobuf_FileDescriptorProto_message_type_descriptor,
  &google_protobuf_FileDescriptorProto_enum_type_descriptor,
  &google_protobuf_FileDescriptorProto_service_descriptor,
  &google_protobuf_FileDescriptorProto_extension_descriptor,
  &google_protobuf_FileDescriptorProto_options_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_FileDescriptorProto_descriptor_field = {
  .len=8, .elements=google_protobuf_FileDescriptorProto_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_FileDescriptorProto_descriptor = {
  .name = &google_protobuf_FileDescriptorProto_descriptor_name,
  .field = &google_protobuf_FileDescriptorProto_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_FileDescriptorProto_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_name = {
  .name = &google_protobuf_FileDescriptorProto_name_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FileDescriptorProto_package_fieldname = {
  .byte_len=7, .data=(uint8_t*)"package"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_package = {
  .name = &google_protobuf_FileDescriptorProto_package_fieldname,
  .number = (uint32_t)2,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FileDescriptorProto_dependency_fieldname = {
  .byte_len=10, .data=(uint8_t*)"dependency"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_dependency = {
  .name = &google_protobuf_FileDescriptorProto_dependency_fieldname,
  .number = (uint32_t)3,
  .label = 3,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FileDescriptorProto_message_type_fieldname = {
  .byte_len=12, .data=(uint8_t*)"message_type"
};

static struct upb_string google_protobuf_FileDescriptorProto_message_type_field_typename = {
  .byte_len=15, .data=(uint8_t*)"DescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_message_type = {
  .name = &google_protobuf_FileDescriptorProto_message_type_fieldname,
  .number = (uint32_t)4,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_FileDescriptorProto_message_type_field_typename,
};
static struct upb_string google_protobuf_FileDescriptorProto_enum_type_fieldname = {
  .byte_len=9, .data=(uint8_t*)"enum_type"
};

static struct upb_string google_protobuf_FileDescriptorProto_enum_type_field_typename = {
  .byte_len=19, .data=(uint8_t*)"EnumDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_enum_type = {
  .name = &google_protobuf_FileDescriptorProto_enum_type_fieldname,
  .number = (uint32_t)5,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_FileDescriptorProto_enum_type_field_typename,
};
static struct upb_string google_protobuf_FileDescriptorProto_service_fieldname = {
  .byte_len=7, .data=(uint8_t*)"service"
};

static struct upb_string google_protobuf_FileDescriptorProto_service_field_typename = {
  .byte_len=22, .data=(uint8_t*)"ServiceDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_service = {
  .name = &google_protobuf_FileDescriptorProto_service_fieldname,
  .number = (uint32_t)6,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_FileDescriptorProto_service_field_typename,
};
static struct upb_string google_protobuf_FileDescriptorProto_extension_fieldname = {
  .byte_len=9, .data=(uint8_t*)"extension"
};

static struct upb_string google_protobuf_FileDescriptorProto_extension_field_typename = {
  .byte_len=20, .data=(uint8_t*)"FieldDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_extension = {
  .name = &google_protobuf_FileDescriptorProto_extension_fieldname,
  .number = (uint32_t)7,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_FileDescriptorProto_extension_field_typename,
};
static struct upb_string google_protobuf_FileDescriptorProto_options_fieldname = {
  .byte_len=7, .data=(uint8_t*)"options"
};

static struct upb_string google_protobuf_FileDescriptorProto_options_field_typename = {
  .byte_len=11, .data=(uint8_t*)"FileOptions"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileDescriptorProto_options = {
  .name = &google_protobuf_FileDescriptorProto_options_fieldname,
  .number = (uint32_t)8,
  .label = 1,
  .type = 11,
  .type_name = &google_protobuf_FileDescriptorProto_options_field_typename,
};
/* google_protobuf_DescriptorProto_descriptor */
static struct upb_string google_protobuf_DescriptorProto_descriptor_name = {
  .byte_len=15, .data=(uint8_t*)"DescriptorProto"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_field_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_extension_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_nested_type_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_enum_type_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_extension_range_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_options_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_DescriptorProto_descriptor_field_array[] = {
  &google_protobuf_DescriptorProto_name_descriptor,
  &google_protobuf_DescriptorProto_field_descriptor,
  &google_protobuf_DescriptorProto_extension_descriptor,
  &google_protobuf_DescriptorProto_nested_type_descriptor,
  &google_protobuf_DescriptorProto_enum_type_descriptor,
  &google_protobuf_DescriptorProto_extension_range_descriptor,
  &google_protobuf_DescriptorProto_options_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_DescriptorProto_descriptor_field = {
  .len=7, .elements=google_protobuf_DescriptorProto_descriptor_field_array
};

struct google_protobuf_DescriptorProto google_protobuf_DescriptorProto_ExtensionRange_descriptor;

static google_protobuf_DescriptorProto *google_protobuf_DescriptorProto_descriptor_nested_type_array[] = {
  &google_protobuf_DescriptorProto_ExtensionRange_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto) google_protobuf_DescriptorProto_descriptor_nested_type = {
  .len=1, .elements=google_protobuf_DescriptorProto_descriptor_nested_type_array
};

google_protobuf_DescriptorProto google_protobuf_DescriptorProto_descriptor = {
  .name = &google_protobuf_DescriptorProto_descriptor_name,
  .field = &google_protobuf_DescriptorProto_descriptor_field,
  .nested_type = &google_protobuf_DescriptorProto_descriptor_nested_type,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_DescriptorProto_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_name = {
  .name = &google_protobuf_DescriptorProto_name_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_DescriptorProto_field_fieldname = {
  .byte_len=5, .data=(uint8_t*)"field"
};

static struct upb_string google_protobuf_DescriptorProto_field_field_typename = {
  .byte_len=20, .data=(uint8_t*)"FieldDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_field = {
  .name = &google_protobuf_DescriptorProto_field_fieldname,
  .number = (uint32_t)2,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_DescriptorProto_field_field_typename,
};
static struct upb_string google_protobuf_DescriptorProto_extension_fieldname = {
  .byte_len=9, .data=(uint8_t*)"extension"
};

static struct upb_string google_protobuf_DescriptorProto_extension_field_typename = {
  .byte_len=20, .data=(uint8_t*)"FieldDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_extension = {
  .name = &google_protobuf_DescriptorProto_extension_fieldname,
  .number = (uint32_t)6,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_DescriptorProto_extension_field_typename,
};
static struct upb_string google_protobuf_DescriptorProto_nested_type_fieldname = {
  .byte_len=11, .data=(uint8_t*)"nested_type"
};

static struct upb_string google_protobuf_DescriptorProto_nested_type_field_typename = {
  .byte_len=15, .data=(uint8_t*)"DescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_nested_type = {
  .name = &google_protobuf_DescriptorProto_nested_type_fieldname,
  .number = (uint32_t)3,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_DescriptorProto_nested_type_field_typename,
};
static struct upb_string google_protobuf_DescriptorProto_enum_type_fieldname = {
  .byte_len=9, .data=(uint8_t*)"enum_type"
};

static struct upb_string google_protobuf_DescriptorProto_enum_type_field_typename = {
  .byte_len=19, .data=(uint8_t*)"EnumDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_enum_type = {
  .name = &google_protobuf_DescriptorProto_enum_type_fieldname,
  .number = (uint32_t)4,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_DescriptorProto_enum_type_field_typename,
};
static struct upb_string google_protobuf_DescriptorProto_extension_range_fieldname = {
  .byte_len=15, .data=(uint8_t*)"extension_range"
};

static struct upb_string google_protobuf_DescriptorProto_extension_range_field_typename = {
  .byte_len=14, .data=(uint8_t*)"ExtensionRange"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_extension_range = {
  .name = &google_protobuf_DescriptorProto_extension_range_fieldname,
  .number = (uint32_t)5,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_DescriptorProto_extension_range_field_typename,
};
static struct upb_string google_protobuf_DescriptorProto_options_fieldname = {
  .byte_len=7, .data=(uint8_t*)"options"
};

static struct upb_string google_protobuf_DescriptorProto_options_field_typename = {
  .byte_len=14, .data=(uint8_t*)"MessageOptions"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_options = {
  .name = &google_protobuf_DescriptorProto_options_fieldname,
  .number = (uint32_t)7,
  .label = 1,
  .type = 11,
  .type_name = &google_protobuf_DescriptorProto_options_field_typename,
};
/* google_protobuf_DescriptorProto_ExtensionRange_descriptor */
static struct upb_string google_protobuf_DescriptorProto_ExtensionRange_descriptor_name = {
  .byte_len=14, .data=(uint8_t*)"ExtensionRange"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_ExtensionRange_start_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_ExtensionRange_end_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_DescriptorProto_ExtensionRange_descriptor_field_array[] = {
  &google_protobuf_DescriptorProto_ExtensionRange_start_descriptor,
  &google_protobuf_DescriptorProto_ExtensionRange_end_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_DescriptorProto_ExtensionRange_descriptor_field = {
  .len=2, .elements=google_protobuf_DescriptorProto_ExtensionRange_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_DescriptorProto_ExtensionRange_descriptor = {
  .name = &google_protobuf_DescriptorProto_ExtensionRange_descriptor_name,
  .field = &google_protobuf_DescriptorProto_ExtensionRange_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_DescriptorProto_ExtensionRange_start_fieldname = {
  .byte_len=5, .data=(uint8_t*)"start"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_ExtensionRange_start = {
  .name = &google_protobuf_DescriptorProto_ExtensionRange_start_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 5,
  .type_name = NULL,
};
static struct upb_string google_protobuf_DescriptorProto_ExtensionRange_end_fieldname = {
  .byte_len=3, .data=(uint8_t*)"end"
};

google_protobuf_FieldDescriptorProto google_protobuf_DescriptorProto_ExtensionRange_end = {
  .name = &google_protobuf_DescriptorProto_ExtensionRange_end_fieldname,
  .number = (uint32_t)2,
  .label = 1,
  .type = 5,
  .type_name = NULL,
};
/* google_protobuf_FieldDescriptorProto_descriptor */
static struct upb_string google_protobuf_FieldDescriptorProto_descriptor_name = {
  .byte_len=20, .data=(uint8_t*)"FieldDescriptorProto"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_number_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_label_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_type_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_type_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_extendee_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_default_value_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_options_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_FieldDescriptorProto_descriptor_field_array[] = {
  &google_protobuf_FieldDescriptorProto_name_descriptor,
  &google_protobuf_FieldDescriptorProto_number_descriptor,
  &google_protobuf_FieldDescriptorProto_label_descriptor,
  &google_protobuf_FieldDescriptorProto_type_descriptor,
  &google_protobuf_FieldDescriptorProto_type_name_descriptor,
  &google_protobuf_FieldDescriptorProto_extendee_descriptor,
  &google_protobuf_FieldDescriptorProto_default_value_descriptor,
  &google_protobuf_FieldDescriptorProto_options_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_FieldDescriptorProto_descriptor_field = {
  .len=8, .elements=google_protobuf_FieldDescriptorProto_descriptor_field_array
};

struct google_protobuf_EnumDescriptorProto google_protobuf_FieldDescriptorProto_Type_descriptor;
struct google_protobuf_EnumDescriptorProto google_protobuf_FieldDescriptorProto_Label_descriptor;

static google_protobuf_EnumDescriptorProto *google_protobuf_FieldDescriptorProto_descriptor_enum_type_array[] = {
  &google_protobuf_FieldDescriptorProto_Type_descriptor,
  &google_protobuf_FieldDescriptorProto_Label_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_EnumDescriptorProto) google_protobuf_FieldDescriptorProto_descriptor_enum_type = {
  .len=2, .elements=google_protobuf_FieldDescriptorProto_descriptor_enum_type_array
};

google_protobuf_DescriptorProto google_protobuf_FieldDescriptorProto_descriptor = {
  .name = &google_protobuf_FieldDescriptorProto_descriptor_name,
  .field = &google_protobuf_FieldDescriptorProto_descriptor_field,
  .nested_type = NULL,
  .enum_type = &google_protobuf_FieldDescriptorProto_descriptor_enum_type,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_FieldDescriptorProto_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_name = {
  .name = &google_protobuf_FieldDescriptorProto_name_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FieldDescriptorProto_number_fieldname = {
  .byte_len=6, .data=(uint8_t*)"number"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_number = {
  .name = &google_protobuf_FieldDescriptorProto_number_fieldname,
  .number = (uint32_t)3,
  .label = 1,
  .type = 5,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FieldDescriptorProto_label_fieldname = {
  .byte_len=5, .data=(uint8_t*)"label"
};

static struct upb_string google_protobuf_FieldDescriptorProto_label_field_typename = {
  .byte_len=5, .data=(uint8_t*)"Label"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_label = {
  .name = &google_protobuf_FieldDescriptorProto_label_fieldname,
  .number = (uint32_t)4,
  .label = 1,
  .type = 14,
  .type_name = &google_protobuf_FieldDescriptorProto_label_field_typename,
};
static struct upb_string google_protobuf_FieldDescriptorProto_type_fieldname = {
  .byte_len=4, .data=(uint8_t*)"type"
};

static struct upb_string google_protobuf_FieldDescriptorProto_type_field_typename = {
  .byte_len=4, .data=(uint8_t*)"Type"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_type = {
  .name = &google_protobuf_FieldDescriptorProto_type_fieldname,
  .number = (uint32_t)5,
  .label = 1,
  .type = 14,
  .type_name = &google_protobuf_FieldDescriptorProto_type_field_typename,
};
static struct upb_string google_protobuf_FieldDescriptorProto_type_name_fieldname = {
  .byte_len=9, .data=(uint8_t*)"type_name"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_type_name = {
  .name = &google_protobuf_FieldDescriptorProto_type_name_fieldname,
  .number = (uint32_t)6,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FieldDescriptorProto_extendee_fieldname = {
  .byte_len=8, .data=(uint8_t*)"extendee"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_extendee = {
  .name = &google_protobuf_FieldDescriptorProto_extendee_fieldname,
  .number = (uint32_t)2,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FieldDescriptorProto_default_value_fieldname = {
  .byte_len=13, .data=(uint8_t*)"default_value"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_default_value = {
  .name = &google_protobuf_FieldDescriptorProto_default_value_fieldname,
  .number = (uint32_t)7,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FieldDescriptorProto_options_fieldname = {
  .byte_len=7, .data=(uint8_t*)"options"
};

static struct upb_string google_protobuf_FieldDescriptorProto_options_field_typename = {
  .byte_len=12, .data=(uint8_t*)"FieldOptions"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldDescriptorProto_options = {
  .name = &google_protobuf_FieldDescriptorProto_options_fieldname,
  .number = (uint32_t)8,
  .label = 1,
  .type = 11,
  .type_name = &google_protobuf_FieldDescriptorProto_options_field_typename,
};
static struct upb_string google_protobuf_FieldDescriptorProto_Type_name = {
  .byte_len=4, .data=(uint8_t*)"Type"
};

google_protobuf_EnumDescriptorProto google_protobuf_FieldDescriptorProto_Type_descriptor = {
  .name = &google_protobuf_FieldDescriptorProto_Type_name,
};
static struct upb_string google_protobuf_FieldDescriptorProto_Label_name = {
  .byte_len=5, .data=(uint8_t*)"Label"
};

google_protobuf_EnumDescriptorProto google_protobuf_FieldDescriptorProto_Label_descriptor = {
  .name = &google_protobuf_FieldDescriptorProto_Label_name,
};
/* google_protobuf_EnumDescriptorProto_descriptor */
static struct upb_string google_protobuf_EnumDescriptorProto_descriptor_name = {
  .byte_len=19, .data=(uint8_t*)"EnumDescriptorProto"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_EnumDescriptorProto_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_EnumDescriptorProto_value_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_EnumDescriptorProto_options_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_EnumDescriptorProto_descriptor_field_array[] = {
  &google_protobuf_EnumDescriptorProto_name_descriptor,
  &google_protobuf_EnumDescriptorProto_value_descriptor,
  &google_protobuf_EnumDescriptorProto_options_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_EnumDescriptorProto_descriptor_field = {
  .len=3, .elements=google_protobuf_EnumDescriptorProto_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_EnumDescriptorProto_descriptor = {
  .name = &google_protobuf_EnumDescriptorProto_descriptor_name,
  .field = &google_protobuf_EnumDescriptorProto_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_EnumDescriptorProto_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumDescriptorProto_name = {
  .name = &google_protobuf_EnumDescriptorProto_name_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_EnumDescriptorProto_value_fieldname = {
  .byte_len=5, .data=(uint8_t*)"value"
};

static struct upb_string google_protobuf_EnumDescriptorProto_value_field_typename = {
  .byte_len=24, .data=(uint8_t*)"EnumValueDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumDescriptorProto_value = {
  .name = &google_protobuf_EnumDescriptorProto_value_fieldname,
  .number = (uint32_t)2,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_EnumDescriptorProto_value_field_typename,
};
static struct upb_string google_protobuf_EnumDescriptorProto_options_fieldname = {
  .byte_len=7, .data=(uint8_t*)"options"
};

static struct upb_string google_protobuf_EnumDescriptorProto_options_field_typename = {
  .byte_len=11, .data=(uint8_t*)"EnumOptions"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumDescriptorProto_options = {
  .name = &google_protobuf_EnumDescriptorProto_options_fieldname,
  .number = (uint32_t)3,
  .label = 1,
  .type = 11,
  .type_name = &google_protobuf_EnumDescriptorProto_options_field_typename,
};
/* google_protobuf_EnumValueDescriptorProto_descriptor */
static struct upb_string google_protobuf_EnumValueDescriptorProto_descriptor_name = {
  .byte_len=24, .data=(uint8_t*)"EnumValueDescriptorProto"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_EnumValueDescriptorProto_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_EnumValueDescriptorProto_number_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_EnumValueDescriptorProto_options_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_EnumValueDescriptorProto_descriptor_field_array[] = {
  &google_protobuf_EnumValueDescriptorProto_name_descriptor,
  &google_protobuf_EnumValueDescriptorProto_number_descriptor,
  &google_protobuf_EnumValueDescriptorProto_options_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_EnumValueDescriptorProto_descriptor_field = {
  .len=3, .elements=google_protobuf_EnumValueDescriptorProto_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_EnumValueDescriptorProto_descriptor = {
  .name = &google_protobuf_EnumValueDescriptorProto_descriptor_name,
  .field = &google_protobuf_EnumValueDescriptorProto_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_EnumValueDescriptorProto_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumValueDescriptorProto_name = {
  .name = &google_protobuf_EnumValueDescriptorProto_name_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_EnumValueDescriptorProto_number_fieldname = {
  .byte_len=6, .data=(uint8_t*)"number"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumValueDescriptorProto_number = {
  .name = &google_protobuf_EnumValueDescriptorProto_number_fieldname,
  .number = (uint32_t)2,
  .label = 1,
  .type = 5,
  .type_name = NULL,
};
static struct upb_string google_protobuf_EnumValueDescriptorProto_options_fieldname = {
  .byte_len=7, .data=(uint8_t*)"options"
};

static struct upb_string google_protobuf_EnumValueDescriptorProto_options_field_typename = {
  .byte_len=16, .data=(uint8_t*)"EnumValueOptions"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumValueDescriptorProto_options = {
  .name = &google_protobuf_EnumValueDescriptorProto_options_fieldname,
  .number = (uint32_t)3,
  .label = 1,
  .type = 11,
  .type_name = &google_protobuf_EnumValueDescriptorProto_options_field_typename,
};
/* google_protobuf_ServiceDescriptorProto_descriptor */
static struct upb_string google_protobuf_ServiceDescriptorProto_descriptor_name = {
  .byte_len=22, .data=(uint8_t*)"ServiceDescriptorProto"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_ServiceDescriptorProto_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_ServiceDescriptorProto_method_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_ServiceDescriptorProto_options_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_ServiceDescriptorProto_descriptor_field_array[] = {
  &google_protobuf_ServiceDescriptorProto_name_descriptor,
  &google_protobuf_ServiceDescriptorProto_method_descriptor,
  &google_protobuf_ServiceDescriptorProto_options_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_ServiceDescriptorProto_descriptor_field = {
  .len=3, .elements=google_protobuf_ServiceDescriptorProto_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_ServiceDescriptorProto_descriptor = {
  .name = &google_protobuf_ServiceDescriptorProto_descriptor_name,
  .field = &google_protobuf_ServiceDescriptorProto_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_ServiceDescriptorProto_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

google_protobuf_FieldDescriptorProto google_protobuf_ServiceDescriptorProto_name = {
  .name = &google_protobuf_ServiceDescriptorProto_name_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_ServiceDescriptorProto_method_fieldname = {
  .byte_len=6, .data=(uint8_t*)"method"
};

static struct upb_string google_protobuf_ServiceDescriptorProto_method_field_typename = {
  .byte_len=21, .data=(uint8_t*)"MethodDescriptorProto"
};

google_protobuf_FieldDescriptorProto google_protobuf_ServiceDescriptorProto_method = {
  .name = &google_protobuf_ServiceDescriptorProto_method_fieldname,
  .number = (uint32_t)2,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_ServiceDescriptorProto_method_field_typename,
};
static struct upb_string google_protobuf_ServiceDescriptorProto_options_fieldname = {
  .byte_len=7, .data=(uint8_t*)"options"
};

static struct upb_string google_protobuf_ServiceDescriptorProto_options_field_typename = {
  .byte_len=14, .data=(uint8_t*)"ServiceOptions"
};

google_protobuf_FieldDescriptorProto google_protobuf_ServiceDescriptorProto_options = {
  .name = &google_protobuf_ServiceDescriptorProto_options_fieldname,
  .number = (uint32_t)3,
  .label = 1,
  .type = 11,
  .type_name = &google_protobuf_ServiceDescriptorProto_options_field_typename,
};
/* google_protobuf_MethodDescriptorProto_descriptor */
static struct upb_string google_protobuf_MethodDescriptorProto_descriptor_name = {
  .byte_len=21, .data=(uint8_t*)"MethodDescriptorProto"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_input_type_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_output_type_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_options_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_MethodDescriptorProto_descriptor_field_array[] = {
  &google_protobuf_MethodDescriptorProto_name_descriptor,
  &google_protobuf_MethodDescriptorProto_input_type_descriptor,
  &google_protobuf_MethodDescriptorProto_output_type_descriptor,
  &google_protobuf_MethodDescriptorProto_options_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_MethodDescriptorProto_descriptor_field = {
  .len=4, .elements=google_protobuf_MethodDescriptorProto_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_MethodDescriptorProto_descriptor = {
  .name = &google_protobuf_MethodDescriptorProto_descriptor_name,
  .field = &google_protobuf_MethodDescriptorProto_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_MethodDescriptorProto_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_name = {
  .name = &google_protobuf_MethodDescriptorProto_name_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_MethodDescriptorProto_input_type_fieldname = {
  .byte_len=10, .data=(uint8_t*)"input_type"
};

google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_input_type = {
  .name = &google_protobuf_MethodDescriptorProto_input_type_fieldname,
  .number = (uint32_t)2,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_MethodDescriptorProto_output_type_fieldname = {
  .byte_len=11, .data=(uint8_t*)"output_type"
};

google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_output_type = {
  .name = &google_protobuf_MethodDescriptorProto_output_type_fieldname,
  .number = (uint32_t)3,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_MethodDescriptorProto_options_fieldname = {
  .byte_len=7, .data=(uint8_t*)"options"
};

static struct upb_string google_protobuf_MethodDescriptorProto_options_field_typename = {
  .byte_len=13, .data=(uint8_t*)"MethodOptions"
};

google_protobuf_FieldDescriptorProto google_protobuf_MethodDescriptorProto_options = {
  .name = &google_protobuf_MethodDescriptorProto_options_fieldname,
  .number = (uint32_t)4,
  .label = 1,
  .type = 11,
  .type_name = &google_protobuf_MethodDescriptorProto_options_field_typename,
};
/* google_protobuf_FileOptions_descriptor */
static struct upb_string google_protobuf_FileOptions_descriptor_name = {
  .byte_len=11, .data=(uint8_t*)"FileOptions"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_java_package_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_java_outer_classname_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_java_multiple_files_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_optimize_for_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_uninterpreted_option_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_FileOptions_descriptor_field_array[] = {
  &google_protobuf_FileOptions_java_package_descriptor,
  &google_protobuf_FileOptions_java_outer_classname_descriptor,
  &google_protobuf_FileOptions_java_multiple_files_descriptor,
  &google_protobuf_FileOptions_optimize_for_descriptor,
  &google_protobuf_FileOptions_uninterpreted_option_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_FileOptions_descriptor_field = {
  .len=5, .elements=google_protobuf_FileOptions_descriptor_field_array
};

struct google_protobuf_EnumDescriptorProto google_protobuf_FileOptions_OptimizeMode_descriptor;

static google_protobuf_EnumDescriptorProto *google_protobuf_FileOptions_descriptor_enum_type_array[] = {
  &google_protobuf_FileOptions_OptimizeMode_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_EnumDescriptorProto) google_protobuf_FileOptions_descriptor_enum_type = {
  .len=1, .elements=google_protobuf_FileOptions_descriptor_enum_type_array
};

struct google_protobuf_DescriptorProto_ExtensionRange google_protobuf_FileOptions_descriptor_extension_range0_descriptor;

static google_protobuf_DescriptorProto_ExtensionRange *google_protobuf_FileOptions_descriptor_extension_range_array[] = {
  &google_protobuf_FileOptions_descriptor_extension_range0_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto_ExtensionRange) google_protobuf_FileOptions_descriptor_extension_range = {
  .len=1, .elements=google_protobuf_FileOptions_descriptor_extension_range_array
};

google_protobuf_DescriptorProto google_protobuf_FileOptions_descriptor = {
  .name = &google_protobuf_FileOptions_descriptor_name,
  .field = &google_protobuf_FileOptions_descriptor_field,
  .nested_type = NULL,
  .enum_type = &google_protobuf_FileOptions_descriptor_enum_type,
  .extension_range = &google_protobuf_FileOptions_descriptor_extension_range,
};
static struct upb_string google_protobuf_FileOptions_java_package_fieldname = {
  .byte_len=12, .data=(uint8_t*)"java_package"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_java_package = {
  .name = &google_protobuf_FileOptions_java_package_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FileOptions_java_outer_classname_fieldname = {
  .byte_len=20, .data=(uint8_t*)"java_outer_classname"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_java_outer_classname = {
  .name = &google_protobuf_FileOptions_java_outer_classname_fieldname,
  .number = (uint32_t)8,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FileOptions_java_multiple_files_fieldname = {
  .byte_len=19, .data=(uint8_t*)"java_multiple_files"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_java_multiple_files = {
  .name = &google_protobuf_FileOptions_java_multiple_files_fieldname,
  .number = (uint32_t)10,
  .label = 1,
  .type = 8,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FileOptions_optimize_for_fieldname = {
  .byte_len=12, .data=(uint8_t*)"optimize_for"
};

static struct upb_string google_protobuf_FileOptions_optimize_for_field_typename = {
  .byte_len=12, .data=(uint8_t*)"OptimizeMode"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_optimize_for = {
  .name = &google_protobuf_FileOptions_optimize_for_fieldname,
  .number = (uint32_t)9,
  .label = 1,
  .type = 14,
  .type_name = &google_protobuf_FileOptions_optimize_for_field_typename,
};
static struct upb_string google_protobuf_FileOptions_uninterpreted_option_fieldname = {
  .byte_len=20, .data=(uint8_t*)"uninterpreted_option"
};

static struct upb_string google_protobuf_FileOptions_uninterpreted_option_field_typename = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

google_protobuf_FieldDescriptorProto google_protobuf_FileOptions_uninterpreted_option = {
  .name = &google_protobuf_FileOptions_uninterpreted_option_fieldname,
  .number = (uint32_t)999,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_FileOptions_uninterpreted_option_field_typename,
};
static struct upb_string google_protobuf_FileOptions_OptimizeMode_name = {
  .byte_len=12, .data=(uint8_t*)"OptimizeMode"
};

google_protobuf_EnumDescriptorProto google_protobuf_FileOptions_OptimizeMode_descriptor = {
  .name = &google_protobuf_FileOptions_OptimizeMode_name,
};
/* google_protobuf_MessageOptions_descriptor */
static struct upb_string google_protobuf_MessageOptions_descriptor_name = {
  .byte_len=14, .data=(uint8_t*)"MessageOptions"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_MessageOptions_message_set_wire_format_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_MessageOptions_uninterpreted_option_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_MessageOptions_descriptor_field_array[] = {
  &google_protobuf_MessageOptions_message_set_wire_format_descriptor,
  &google_protobuf_MessageOptions_uninterpreted_option_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_MessageOptions_descriptor_field = {
  .len=2, .elements=google_protobuf_MessageOptions_descriptor_field_array
};

struct google_protobuf_DescriptorProto_ExtensionRange google_protobuf_MessageOptions_descriptor_extension_range0_descriptor;

static google_protobuf_DescriptorProto_ExtensionRange *google_protobuf_MessageOptions_descriptor_extension_range_array[] = {
  &google_protobuf_MessageOptions_descriptor_extension_range0_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto_ExtensionRange) google_protobuf_MessageOptions_descriptor_extension_range = {
  .len=1, .elements=google_protobuf_MessageOptions_descriptor_extension_range_array
};

google_protobuf_DescriptorProto google_protobuf_MessageOptions_descriptor = {
  .name = &google_protobuf_MessageOptions_descriptor_name,
  .field = &google_protobuf_MessageOptions_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = &google_protobuf_MessageOptions_descriptor_extension_range,
};
static struct upb_string google_protobuf_MessageOptions_message_set_wire_format_fieldname = {
  .byte_len=23, .data=(uint8_t*)"message_set_wire_format"
};

google_protobuf_FieldDescriptorProto google_protobuf_MessageOptions_message_set_wire_format = {
  .name = &google_protobuf_MessageOptions_message_set_wire_format_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 8,
  .type_name = NULL,
};
static struct upb_string google_protobuf_MessageOptions_uninterpreted_option_fieldname = {
  .byte_len=20, .data=(uint8_t*)"uninterpreted_option"
};

static struct upb_string google_protobuf_MessageOptions_uninterpreted_option_field_typename = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

google_protobuf_FieldDescriptorProto google_protobuf_MessageOptions_uninterpreted_option = {
  .name = &google_protobuf_MessageOptions_uninterpreted_option_fieldname,
  .number = (uint32_t)999,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_MessageOptions_uninterpreted_option_field_typename,
};
/* google_protobuf_FieldOptions_descriptor */
static struct upb_string google_protobuf_FieldOptions_descriptor_name = {
  .byte_len=12, .data=(uint8_t*)"FieldOptions"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_FieldOptions_ctype_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldOptions_experimental_map_key_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_FieldOptions_uninterpreted_option_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_FieldOptions_descriptor_field_array[] = {
  &google_protobuf_FieldOptions_ctype_descriptor,
  &google_protobuf_FieldOptions_experimental_map_key_descriptor,
  &google_protobuf_FieldOptions_uninterpreted_option_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_FieldOptions_descriptor_field = {
  .len=3, .elements=google_protobuf_FieldOptions_descriptor_field_array
};

struct google_protobuf_EnumDescriptorProto google_protobuf_FieldOptions_CType_descriptor;

static google_protobuf_EnumDescriptorProto *google_protobuf_FieldOptions_descriptor_enum_type_array[] = {
  &google_protobuf_FieldOptions_CType_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_EnumDescriptorProto) google_protobuf_FieldOptions_descriptor_enum_type = {
  .len=1, .elements=google_protobuf_FieldOptions_descriptor_enum_type_array
};

struct google_protobuf_DescriptorProto_ExtensionRange google_protobuf_FieldOptions_descriptor_extension_range0_descriptor;

static google_protobuf_DescriptorProto_ExtensionRange *google_protobuf_FieldOptions_descriptor_extension_range_array[] = {
  &google_protobuf_FieldOptions_descriptor_extension_range0_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto_ExtensionRange) google_protobuf_FieldOptions_descriptor_extension_range = {
  .len=1, .elements=google_protobuf_FieldOptions_descriptor_extension_range_array
};

google_protobuf_DescriptorProto google_protobuf_FieldOptions_descriptor = {
  .name = &google_protobuf_FieldOptions_descriptor_name,
  .field = &google_protobuf_FieldOptions_descriptor_field,
  .nested_type = NULL,
  .enum_type = &google_protobuf_FieldOptions_descriptor_enum_type,
  .extension_range = &google_protobuf_FieldOptions_descriptor_extension_range,
};
static struct upb_string google_protobuf_FieldOptions_ctype_fieldname = {
  .byte_len=5, .data=(uint8_t*)"ctype"
};

static struct upb_string google_protobuf_FieldOptions_ctype_field_typename = {
  .byte_len=5, .data=(uint8_t*)"CType"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldOptions_ctype = {
  .name = &google_protobuf_FieldOptions_ctype_fieldname,
  .number = (uint32_t)1,
  .label = 1,
  .type = 14,
  .type_name = &google_protobuf_FieldOptions_ctype_field_typename,
};
static struct upb_string google_protobuf_FieldOptions_experimental_map_key_fieldname = {
  .byte_len=20, .data=(uint8_t*)"experimental_map_key"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldOptions_experimental_map_key = {
  .name = &google_protobuf_FieldOptions_experimental_map_key_fieldname,
  .number = (uint32_t)9,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_FieldOptions_uninterpreted_option_fieldname = {
  .byte_len=20, .data=(uint8_t*)"uninterpreted_option"
};

static struct upb_string google_protobuf_FieldOptions_uninterpreted_option_field_typename = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

google_protobuf_FieldDescriptorProto google_protobuf_FieldOptions_uninterpreted_option = {
  .name = &google_protobuf_FieldOptions_uninterpreted_option_fieldname,
  .number = (uint32_t)999,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_FieldOptions_uninterpreted_option_field_typename,
};
static struct upb_string google_protobuf_FieldOptions_CType_name = {
  .byte_len=5, .data=(uint8_t*)"CType"
};

google_protobuf_EnumDescriptorProto google_protobuf_FieldOptions_CType_descriptor = {
  .name = &google_protobuf_FieldOptions_CType_name,
};
/* google_protobuf_EnumOptions_descriptor */
static struct upb_string google_protobuf_EnumOptions_descriptor_name = {
  .byte_len=11, .data=(uint8_t*)"EnumOptions"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_EnumOptions_uninterpreted_option_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_EnumOptions_descriptor_field_array[] = {
  &google_protobuf_EnumOptions_uninterpreted_option_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_EnumOptions_descriptor_field = {
  .len=1, .elements=google_protobuf_EnumOptions_descriptor_field_array
};

struct google_protobuf_DescriptorProto_ExtensionRange google_protobuf_EnumOptions_descriptor_extension_range0_descriptor;

static google_protobuf_DescriptorProto_ExtensionRange *google_protobuf_EnumOptions_descriptor_extension_range_array[] = {
  &google_protobuf_EnumOptions_descriptor_extension_range0_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto_ExtensionRange) google_protobuf_EnumOptions_descriptor_extension_range = {
  .len=1, .elements=google_protobuf_EnumOptions_descriptor_extension_range_array
};

google_protobuf_DescriptorProto google_protobuf_EnumOptions_descriptor = {
  .name = &google_protobuf_EnumOptions_descriptor_name,
  .field = &google_protobuf_EnumOptions_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = &google_protobuf_EnumOptions_descriptor_extension_range,
};
static struct upb_string google_protobuf_EnumOptions_uninterpreted_option_fieldname = {
  .byte_len=20, .data=(uint8_t*)"uninterpreted_option"
};

static struct upb_string google_protobuf_EnumOptions_uninterpreted_option_field_typename = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumOptions_uninterpreted_option = {
  .name = &google_protobuf_EnumOptions_uninterpreted_option_fieldname,
  .number = (uint32_t)999,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_EnumOptions_uninterpreted_option_field_typename,
};
/* google_protobuf_EnumValueOptions_descriptor */
static struct upb_string google_protobuf_EnumValueOptions_descriptor_name = {
  .byte_len=16, .data=(uint8_t*)"EnumValueOptions"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_EnumValueOptions_uninterpreted_option_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_EnumValueOptions_descriptor_field_array[] = {
  &google_protobuf_EnumValueOptions_uninterpreted_option_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_EnumValueOptions_descriptor_field = {
  .len=1, .elements=google_protobuf_EnumValueOptions_descriptor_field_array
};

struct google_protobuf_DescriptorProto_ExtensionRange google_protobuf_EnumValueOptions_descriptor_extension_range0_descriptor;

static google_protobuf_DescriptorProto_ExtensionRange *google_protobuf_EnumValueOptions_descriptor_extension_range_array[] = {
  &google_protobuf_EnumValueOptions_descriptor_extension_range0_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto_ExtensionRange) google_protobuf_EnumValueOptions_descriptor_extension_range = {
  .len=1, .elements=google_protobuf_EnumValueOptions_descriptor_extension_range_array
};

google_protobuf_DescriptorProto google_protobuf_EnumValueOptions_descriptor = {
  .name = &google_protobuf_EnumValueOptions_descriptor_name,
  .field = &google_protobuf_EnumValueOptions_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = &google_protobuf_EnumValueOptions_descriptor_extension_range,
};
static struct upb_string google_protobuf_EnumValueOptions_uninterpreted_option_fieldname = {
  .byte_len=20, .data=(uint8_t*)"uninterpreted_option"
};

static struct upb_string google_protobuf_EnumValueOptions_uninterpreted_option_field_typename = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

google_protobuf_FieldDescriptorProto google_protobuf_EnumValueOptions_uninterpreted_option = {
  .name = &google_protobuf_EnumValueOptions_uninterpreted_option_fieldname,
  .number = (uint32_t)999,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_EnumValueOptions_uninterpreted_option_field_typename,
};
/* google_protobuf_ServiceOptions_descriptor */
static struct upb_string google_protobuf_ServiceOptions_descriptor_name = {
  .byte_len=14, .data=(uint8_t*)"ServiceOptions"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_ServiceOptions_uninterpreted_option_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_ServiceOptions_descriptor_field_array[] = {
  &google_protobuf_ServiceOptions_uninterpreted_option_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_ServiceOptions_descriptor_field = {
  .len=1, .elements=google_protobuf_ServiceOptions_descriptor_field_array
};

struct google_protobuf_DescriptorProto_ExtensionRange google_protobuf_ServiceOptions_descriptor_extension_range0_descriptor;

static google_protobuf_DescriptorProto_ExtensionRange *google_protobuf_ServiceOptions_descriptor_extension_range_array[] = {
  &google_protobuf_ServiceOptions_descriptor_extension_range0_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto_ExtensionRange) google_protobuf_ServiceOptions_descriptor_extension_range = {
  .len=1, .elements=google_protobuf_ServiceOptions_descriptor_extension_range_array
};

google_protobuf_DescriptorProto google_protobuf_ServiceOptions_descriptor = {
  .name = &google_protobuf_ServiceOptions_descriptor_name,
  .field = &google_protobuf_ServiceOptions_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = &google_protobuf_ServiceOptions_descriptor_extension_range,
};
static struct upb_string google_protobuf_ServiceOptions_uninterpreted_option_fieldname = {
  .byte_len=20, .data=(uint8_t*)"uninterpreted_option"
};

static struct upb_string google_protobuf_ServiceOptions_uninterpreted_option_field_typename = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

google_protobuf_FieldDescriptorProto google_protobuf_ServiceOptions_uninterpreted_option = {
  .name = &google_protobuf_ServiceOptions_uninterpreted_option_fieldname,
  .number = (uint32_t)999,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_ServiceOptions_uninterpreted_option_field_typename,
};
/* google_protobuf_MethodOptions_descriptor */
static struct upb_string google_protobuf_MethodOptions_descriptor_name = {
  .byte_len=13, .data=(uint8_t*)"MethodOptions"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_MethodOptions_uninterpreted_option_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_MethodOptions_descriptor_field_array[] = {
  &google_protobuf_MethodOptions_uninterpreted_option_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_MethodOptions_descriptor_field = {
  .len=1, .elements=google_protobuf_MethodOptions_descriptor_field_array
};

struct google_protobuf_DescriptorProto_ExtensionRange google_protobuf_MethodOptions_descriptor_extension_range0_descriptor;

static google_protobuf_DescriptorProto_ExtensionRange *google_protobuf_MethodOptions_descriptor_extension_range_array[] = {
  &google_protobuf_MethodOptions_descriptor_extension_range0_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto_ExtensionRange) google_protobuf_MethodOptions_descriptor_extension_range = {
  .len=1, .elements=google_protobuf_MethodOptions_descriptor_extension_range_array
};

google_protobuf_DescriptorProto google_protobuf_MethodOptions_descriptor = {
  .name = &google_protobuf_MethodOptions_descriptor_name,
  .field = &google_protobuf_MethodOptions_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = &google_protobuf_MethodOptions_descriptor_extension_range,
};
static struct upb_string google_protobuf_MethodOptions_uninterpreted_option_fieldname = {
  .byte_len=20, .data=(uint8_t*)"uninterpreted_option"
};

static struct upb_string google_protobuf_MethodOptions_uninterpreted_option_field_typename = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

google_protobuf_FieldDescriptorProto google_protobuf_MethodOptions_uninterpreted_option = {
  .name = &google_protobuf_MethodOptions_uninterpreted_option_fieldname,
  .number = (uint32_t)999,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_MethodOptions_uninterpreted_option_field_typename,
};
/* google_protobuf_UninterpretedOption_descriptor */
static struct upb_string google_protobuf_UninterpretedOption_descriptor_name = {
  .byte_len=19, .data=(uint8_t*)"UninterpretedOption"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_name_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_identifier_value_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_positive_int_value_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_negative_int_value_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_double_value_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_string_value_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_UninterpretedOption_descriptor_field_array[] = {
  &google_protobuf_UninterpretedOption_name_descriptor,
  &google_protobuf_UninterpretedOption_identifier_value_descriptor,
  &google_protobuf_UninterpretedOption_positive_int_value_descriptor,
  &google_protobuf_UninterpretedOption_negative_int_value_descriptor,
  &google_protobuf_UninterpretedOption_double_value_descriptor,
  &google_protobuf_UninterpretedOption_string_value_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_UninterpretedOption_descriptor_field = {
  .len=6, .elements=google_protobuf_UninterpretedOption_descriptor_field_array
};

struct google_protobuf_DescriptorProto google_protobuf_UninterpretedOption_NamePart_descriptor;

static google_protobuf_DescriptorProto *google_protobuf_UninterpretedOption_descriptor_nested_type_array[] = {
  &google_protobuf_UninterpretedOption_NamePart_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_DescriptorProto) google_protobuf_UninterpretedOption_descriptor_nested_type = {
  .len=1, .elements=google_protobuf_UninterpretedOption_descriptor_nested_type_array
};

google_protobuf_DescriptorProto google_protobuf_UninterpretedOption_descriptor = {
  .name = &google_protobuf_UninterpretedOption_descriptor_name,
  .field = &google_protobuf_UninterpretedOption_descriptor_field,
  .nested_type = &google_protobuf_UninterpretedOption_descriptor_nested_type,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_UninterpretedOption_name_fieldname = {
  .byte_len=4, .data=(uint8_t*)"name"
};

static struct upb_string google_protobuf_UninterpretedOption_name_field_typename = {
  .byte_len=8, .data=(uint8_t*)"NamePart"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_name = {
  .name = &google_protobuf_UninterpretedOption_name_fieldname,
  .number = (uint32_t)2,
  .label = 3,
  .type = 11,
  .type_name = &google_protobuf_UninterpretedOption_name_field_typename,
};
static struct upb_string google_protobuf_UninterpretedOption_identifier_value_fieldname = {
  .byte_len=16, .data=(uint8_t*)"identifier_value"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_identifier_value = {
  .name = &google_protobuf_UninterpretedOption_identifier_value_fieldname,
  .number = (uint32_t)3,
  .label = 1,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_UninterpretedOption_positive_int_value_fieldname = {
  .byte_len=18, .data=(uint8_t*)"positive_int_value"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_positive_int_value = {
  .name = &google_protobuf_UninterpretedOption_positive_int_value_fieldname,
  .number = (uint32_t)4,
  .label = 1,
  .type = 4,
  .type_name = NULL,
};
static struct upb_string google_protobuf_UninterpretedOption_negative_int_value_fieldname = {
  .byte_len=18, .data=(uint8_t*)"negative_int_value"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_negative_int_value = {
  .name = &google_protobuf_UninterpretedOption_negative_int_value_fieldname,
  .number = (uint32_t)5,
  .label = 1,
  .type = 3,
  .type_name = NULL,
};
static struct upb_string google_protobuf_UninterpretedOption_double_value_fieldname = {
  .byte_len=12, .data=(uint8_t*)"double_value"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_double_value = {
  .name = &google_protobuf_UninterpretedOption_double_value_fieldname,
  .number = (uint32_t)6,
  .label = 1,
  .type = 1,
  .type_name = NULL,
};
static struct upb_string google_protobuf_UninterpretedOption_string_value_fieldname = {
  .byte_len=12, .data=(uint8_t*)"string_value"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_string_value = {
  .name = &google_protobuf_UninterpretedOption_string_value_fieldname,
  .number = (uint32_t)7,
  .label = 1,
  .type = 12,
  .type_name = NULL,
};
/* google_protobuf_UninterpretedOption_NamePart_descriptor */
static struct upb_string google_protobuf_UninterpretedOption_NamePart_descriptor_name = {
  .byte_len=8, .data=(uint8_t*)"NamePart"
};

struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_NamePart_name_part_descriptor;
struct google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_NamePart_is_extension_descriptor;

static google_protobuf_FieldDescriptorProto *google_protobuf_UninterpretedOption_NamePart_descriptor_field_array[] = {
  &google_protobuf_UninterpretedOption_NamePart_name_part_descriptor,
  &google_protobuf_UninterpretedOption_NamePart_is_extension_descriptor,
};

static UPB_STRUCT_ARRAY(google_protobuf_FieldDescriptorProto) google_protobuf_UninterpretedOption_NamePart_descriptor_field = {
  .len=2, .elements=google_protobuf_UninterpretedOption_NamePart_descriptor_field_array
};

google_protobuf_DescriptorProto google_protobuf_UninterpretedOption_NamePart_descriptor = {
  .name = &google_protobuf_UninterpretedOption_NamePart_descriptor_name,
  .field = &google_protobuf_UninterpretedOption_NamePart_descriptor_field,
  .nested_type = NULL,
  .enum_type = NULL,
  .extension_range = NULL,
};
static struct upb_string google_protobuf_UninterpretedOption_NamePart_name_part_fieldname = {
  .byte_len=9, .data=(uint8_t*)"name_part"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_NamePart_name_part = {
  .name = &google_protobuf_UninterpretedOption_NamePart_name_part_fieldname,
  .number = (uint32_t)1,
  .label = 2,
  .type = 9,
  .type_name = NULL,
};
static struct upb_string google_protobuf_UninterpretedOption_NamePart_is_extension_fieldname = {
  .byte_len=12, .data=(uint8_t*)"is_extension"
};

google_protobuf_FieldDescriptorProto google_protobuf_UninterpretedOption_NamePart_is_extension = {
  .name = &google_protobuf_UninterpretedOption_NamePart_is_extension_fieldname,
  .number = (uint32_t)2,
  .label = 2,
  .type = 8,
  .type_name = NULL,
};