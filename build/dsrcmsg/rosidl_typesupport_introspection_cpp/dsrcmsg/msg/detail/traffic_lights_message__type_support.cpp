// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dsrcmsg:msg/TrafficLightsMessage.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dsrcmsg/msg/detail/traffic_lights_message__struct.hpp"
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

void TrafficLightsMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dsrcmsg::msg::TrafficLightsMessage(_init);
}

void TrafficLightsMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dsrcmsg::msg::TrafficLightsMessage *>(message_memory);
  typed_message->~TrafficLightsMessage();
}

size_t size_function__TrafficLightsMessage__pathids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TrafficLightsMessage__pathids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__TrafficLightsMessage__pathids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__TrafficLightsMessage__pathids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TrafficLightsMessage_message_member_array[4] = {
  {
    "pathids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg::msg::TrafficLightsMessage, pathids),  // bytes offset in struct
    nullptr,  // default value
    size_function__TrafficLightsMessage__pathids,  // size() function pointer
    get_const_function__TrafficLightsMessage__pathids,  // get_const(index) function pointer
    get_function__TrafficLightsMessage__pathids,  // get(index) function pointer
    resize_function__TrafficLightsMessage__pathids  // resize(index) function pointer
  },
  {
    "starttime",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg::msg::TrafficLightsMessage, starttime),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "duration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg::msg::TrafficLightsMessage, duration),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dsrcmsg::msg::TrafficLightsMessage, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TrafficLightsMessage_message_members = {
  "dsrcmsg::msg",  // message namespace
  "TrafficLightsMessage",  // message name
  4,  // number of fields
  sizeof(dsrcmsg::msg::TrafficLightsMessage),
  TrafficLightsMessage_message_member_array,  // message members
  TrafficLightsMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  TrafficLightsMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TrafficLightsMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TrafficLightsMessage_message_members,
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
get_message_type_support_handle<dsrcmsg::msg::TrafficLightsMessage>()
{
  return &::dsrcmsg::msg::rosidl_typesupport_introspection_cpp::TrafficLightsMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dsrcmsg, msg, TrafficLightsMessage)() {
  return &::dsrcmsg::msg::rosidl_typesupport_introspection_cpp::TrafficLightsMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
