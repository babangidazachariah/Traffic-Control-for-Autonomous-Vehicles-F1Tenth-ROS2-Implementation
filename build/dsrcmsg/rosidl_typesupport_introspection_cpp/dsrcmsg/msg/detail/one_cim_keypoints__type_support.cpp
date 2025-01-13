// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dsrcmsg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void OneCIMKeypoints_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dsrcmsg::msg::OneCIMKeypoints(_init);
}

void OneCIMKeypoints_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dsrcmsg::msg::OneCIMKeypoints *>(message_memory);
  typed_message->~OneCIMKeypoints();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OneCIMKeypoints_message_member_array[3] = {
  {
    "key",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg::msg::OneCIMKeypoints, key),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg::msg::OneCIMKeypoints, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg::msg::OneCIMKeypoints, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OneCIMKeypoints_message_members = {
  "dsrcmsg::msg",  // message namespace
  "OneCIMKeypoints",  // message name
  3,  // number of fields
  sizeof(dsrcmsg::msg::OneCIMKeypoints),
  OneCIMKeypoints_message_member_array,  // message members
  OneCIMKeypoints_init_function,  // function to initialize message memory (memory has to be allocated)
  OneCIMKeypoints_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OneCIMKeypoints_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OneCIMKeypoints_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dsrcmsg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dsrcmsg::msg::OneCIMKeypoints>()
{
  return &::dsrcmsg::msg::rosidl_typesupport_introspection_cpp::OneCIMKeypoints_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dsrcmsg, msg, OneCIMKeypoints)() {
  return &::dsrcmsg::msg::rosidl_typesupport_introspection_cpp::OneCIMKeypoints_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
