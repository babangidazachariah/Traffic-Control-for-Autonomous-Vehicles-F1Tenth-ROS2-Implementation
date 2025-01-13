// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dsrcmsg/msg/detail/one_cim_keypoints__rosidl_typesupport_introspection_c.h"
#include "dsrcmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dsrcmsg/msg/detail/one_cim_keypoints__functions.h"
#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.h"


// Include directives for member types
// Member `key`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dsrcmsg__msg__OneCIMKeypoints__init(message_memory);
}

void OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_fini_function(void * message_memory)
{
  dsrcmsg__msg__OneCIMKeypoints__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_member_array[3] = {
  {
    "key",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMKeypoints, key),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMKeypoints, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMKeypoints, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_members = {
  "dsrcmsg__msg",  // message namespace
  "OneCIMKeypoints",  // message name
  3,  // number of fields
  sizeof(dsrcmsg__msg__OneCIMKeypoints),
  OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_member_array,  // message members
  OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_init_function,  // function to initialize message memory (memory has to be allocated)
  OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_type_support_handle = {
  0,
  &OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dsrcmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dsrcmsg, msg, OneCIMKeypoints)() {
  if (!OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_type_support_handle.typesupport_identifier) {
    OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &OneCIMKeypoints__rosidl_typesupport_introspection_c__OneCIMKeypoints_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
