// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dsrcmsg:msg/OneCIMTlsMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dsrcmsg/msg/detail/one_cim_tls_msg__rosidl_typesupport_introspection_c.h"
#include "dsrcmsg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dsrcmsg/msg/detail/one_cim_tls_msg__functions.h"
#include "dsrcmsg/msg/detail/one_cim_tls_msg__struct.h"


// Include directives for member types
// Member `junctionid`
// Member `vehicleid`
// Member `pathids`
#include "rosidl_runtime_c/string_functions.h"
// Member `approachpoints`
// Member `departpoints`
#include "dsrcmsg/msg/one_cim_keypoints.h"
// Member `approachpoints`
// Member `departpoints`
#include "dsrcmsg/msg/detail/one_cim_keypoints__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dsrcmsg__msg__OneCIMTlsMsg__init(message_memory);
}

void OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_fini_function(void * message_memory)
{
  dsrcmsg__msg__OneCIMTlsMsg__fini(message_memory);
}

size_t OneCIMTlsMsg__rosidl_typesupport_introspection_c__size_function__OneCIMKeypoints__approachpoints(
  const void * untyped_member)
{
  const dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (const dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  return member->size;
}

const void * OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_const_function__OneCIMKeypoints__approachpoints(
  const void * untyped_member, size_t index)
{
  const dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (const dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  return &member->data[index];
}

void * OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_function__OneCIMKeypoints__approachpoints(
  void * untyped_member, size_t index)
{
  dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  return &member->data[index];
}

bool OneCIMTlsMsg__rosidl_typesupport_introspection_c__resize_function__OneCIMKeypoints__approachpoints(
  void * untyped_member, size_t size)
{
  dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(member);
  return dsrcmsg__msg__OneCIMKeypoints__Sequence__init(member, size);
}

size_t OneCIMTlsMsg__rosidl_typesupport_introspection_c__size_function__OneCIMKeypoints__departpoints(
  const void * untyped_member)
{
  const dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (const dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  return member->size;
}

const void * OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_const_function__OneCIMKeypoints__departpoints(
  const void * untyped_member, size_t index)
{
  const dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (const dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  return &member->data[index];
}

void * OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_function__OneCIMKeypoints__departpoints(
  void * untyped_member, size_t index)
{
  dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  return &member->data[index];
}

bool OneCIMTlsMsg__rosidl_typesupport_introspection_c__resize_function__OneCIMKeypoints__departpoints(
  void * untyped_member, size_t size)
{
  dsrcmsg__msg__OneCIMKeypoints__Sequence * member =
    (dsrcmsg__msg__OneCIMKeypoints__Sequence *)(untyped_member);
  dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(member);
  return dsrcmsg__msg__OneCIMKeypoints__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_member_array[8] = {
  {
    "junctionid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, junctionid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vehicleid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, vehicleid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pathids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, pathids),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "starttime",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, starttime),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "approachpoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, approachpoints),  // bytes offset in struct
    NULL,  // default value
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__size_function__OneCIMKeypoints__approachpoints,  // size() function pointer
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_const_function__OneCIMKeypoints__approachpoints,  // get_const(index) function pointer
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_function__OneCIMKeypoints__approachpoints,  // get(index) function pointer
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__resize_function__OneCIMKeypoints__approachpoints  // resize(index) function pointer
  },
  {
    "departpoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, departpoints),  // bytes offset in struct
    NULL,  // default value
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__size_function__OneCIMKeypoints__departpoints,  // size() function pointer
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_const_function__OneCIMKeypoints__departpoints,  // get_const(index) function pointer
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__get_function__OneCIMKeypoints__departpoints,  // get(index) function pointer
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__resize_function__OneCIMKeypoints__departpoints  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg__msg__OneCIMTlsMsg, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_members = {
  "dsrcmsg__msg",  // message namespace
  "OneCIMTlsMsg",  // message name
  8,  // number of fields
  sizeof(dsrcmsg__msg__OneCIMTlsMsg),
  OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_member_array,  // message members
  OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_type_support_handle = {
  0,
  &OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dsrcmsg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dsrcmsg, msg, OneCIMTlsMsg)() {
  OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dsrcmsg, msg, OneCIMKeypoints)();
  OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dsrcmsg, msg, OneCIMKeypoints)();
  if (!OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_type_support_handle.typesupport_identifier) {
    OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &OneCIMTlsMsg__rosidl_typesupport_introspection_c__OneCIMTlsMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
