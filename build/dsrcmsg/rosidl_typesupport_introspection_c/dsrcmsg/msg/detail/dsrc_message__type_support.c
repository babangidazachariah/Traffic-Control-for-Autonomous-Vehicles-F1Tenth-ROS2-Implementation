// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dsrcmsg:msg/DSRCMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dsrcmsg/msg/detail/dsrc_message__rosidl_typesupport_introspection_c.h"
#include "dsrcmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dsrcmsg/msg/detail/dsrc_message__functions.h"
#include "dsrcmsg/msg/detail/dsrc_message__struct.h"


// Include directives for member types
// Member `vehicleid`
// Member `approachleg`
// Member `departureleg`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dsrcmsg__msg__DSRCMessage__init(message_memory);
}

void DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_fini_function(void * message_memory)
{
  dsrcmsg__msg__DSRCMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_member_array[9] = {
  {
    "vehicleid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, vehicleid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "initialtime",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, initialtime),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "currenttime",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, currenttime),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "approachleg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, approachleg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "departureleg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, departureleg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "disttostopline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, disttostopline),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distfromstopline",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, distfromstopline),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__DSRCMessage, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_members = {
  "dsrcmsg__msg",  // message namespace
  "DSRCMessage",  // message name
  9,  // number of fields
  sizeof(dsrcmsg__msg__DSRCMessage),
  DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_member_array,  // message members
  DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_type_support_handle = {
  0,
  &DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dsrcmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dsrcmsg, msg, DSRCMessage)() {
  if (!DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_type_support_handle.typesupport_identifier) {
    DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &DSRCMessage__rosidl_typesupport_introspection_c__DSRCMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
