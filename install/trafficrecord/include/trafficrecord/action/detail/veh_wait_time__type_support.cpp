// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from trafficrecord:action/VehWaitTime.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_Goal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_Goal(_init);
}

void VehWaitTime_Goal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_Goal *>(message_memory);
  typed_message->~VehWaitTime_Goal();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_Goal_message_member_array[2] = {
  {
    "approachleg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_Goal, approachleg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "waittime",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_Goal, waittime),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_Goal_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_Goal",  // message name
  2,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_Goal),
  VehWaitTime_Goal_message_member_array,  // message members
  VehWaitTime_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_Goal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_Goal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_Goal_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_Goal>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_Goal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_Goal)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_Result_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_Result(_init);
}

void VehWaitTime_Result_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_Result *>(message_memory);
  typed_message->~VehWaitTime_Result();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_Result_message_member_array[1] = {
  {
    "recorded",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_Result, recorded),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_Result_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_Result",  // message name
  1,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_Result),
  VehWaitTime_Result_message_member_array,  // message members
  VehWaitTime_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_Result_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_Result_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_Result_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_Result>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_Result_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_Result)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_Feedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_Feedback(_init);
}

void VehWaitTime_Feedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_Feedback *>(message_memory);
  typed_message->~VehWaitTime_Feedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_Feedback_message_member_array[1] = {
  {
    "partiallyrecorded",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_Feedback, partiallyrecorded),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_Feedback_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_Feedback",  // message name
  1,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_Feedback),
  VehWaitTime_Feedback_message_member_array,  // message members
  VehWaitTime_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_Feedback_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_Feedback>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_Feedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_Feedback)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_SendGoal_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_SendGoal_Request(_init);
}

void VehWaitTime_SendGoal_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_SendGoal_Request *>(message_memory);
  typed_message->~VehWaitTime_SendGoal_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_SendGoal_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "goal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<trafficrecord::action::VehWaitTime_Goal>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_SendGoal_Request, goal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_SendGoal_Request_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_SendGoal_Request),
  VehWaitTime_SendGoal_Request_message_member_array,  // message members
  VehWaitTime_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_SendGoal_Request>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_SendGoal_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_SendGoal_Request)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_SendGoal_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_SendGoal_Response(_init);
}

void VehWaitTime_SendGoal_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_SendGoal_Response *>(message_memory);
  typed_message->~VehWaitTime_SendGoal_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_SendGoal_Response, accepted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_SendGoal_Response, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_SendGoal_Response_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_SendGoal_Response),
  VehWaitTime_SendGoal_Response_message_member_array,  // message members
  VehWaitTime_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_SendGoal_Response>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_SendGoal_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_SendGoal_Response)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers VehWaitTime_SendGoal_service_members = {
  "trafficrecord::action",  // service namespace
  "VehWaitTime_SendGoal",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<trafficrecord::action::VehWaitTime_SendGoal>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t VehWaitTime_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<trafficrecord::action::VehWaitTime_SendGoal>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_SendGoal_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::trafficrecord::action::VehWaitTime_SendGoal_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::trafficrecord::action::VehWaitTime_SendGoal_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_SendGoal)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<trafficrecord::action::VehWaitTime_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_GetResult_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_GetResult_Request(_init);
}

void VehWaitTime_GetResult_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_GetResult_Request *>(message_memory);
  typed_message->~VehWaitTime_GetResult_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_GetResult_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_GetResult_Request_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_GetResult_Request),
  VehWaitTime_GetResult_Request_message_member_array,  // message members
  VehWaitTime_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_GetResult_Request>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_GetResult_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_GetResult_Request)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_GetResult_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_GetResult_Response(_init);
}

void VehWaitTime_GetResult_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_GetResult_Response *>(message_memory);
  typed_message->~VehWaitTime_GetResult_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_GetResult_Response, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "result",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<trafficrecord::action::VehWaitTime_Result>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_GetResult_Response, result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_GetResult_Response_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_GetResult_Response),
  VehWaitTime_GetResult_Response_message_member_array,  // message members
  VehWaitTime_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_GetResult_Response>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_GetResult_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_GetResult_Response)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers VehWaitTime_GetResult_service_members = {
  "trafficrecord::action",  // service namespace
  "VehWaitTime_GetResult",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<trafficrecord::action::VehWaitTime_GetResult>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t VehWaitTime_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_GetResult_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<trafficrecord::action::VehWaitTime_GetResult>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_GetResult_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::trafficrecord::action::VehWaitTime_GetResult_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::trafficrecord::action::VehWaitTime_GetResult_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_GetResult)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<trafficrecord::action::VehWaitTime_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trafficrecord
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void VehWaitTime_FeedbackMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trafficrecord::action::VehWaitTime_FeedbackMessage(_init);
}

void VehWaitTime_FeedbackMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trafficrecord::action::VehWaitTime_FeedbackMessage *>(message_memory);
  typed_message->~VehWaitTime_FeedbackMessage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehWaitTime_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_FeedbackMessage, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "feedback",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<trafficrecord::action::VehWaitTime_Feedback>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord::action::VehWaitTime_FeedbackMessage, feedback),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehWaitTime_FeedbackMessage_message_members = {
  "trafficrecord::action",  // message namespace
  "VehWaitTime_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(trafficrecord::action::VehWaitTime_FeedbackMessage),
  VehWaitTime_FeedbackMessage_message_member_array,  // message members
  VehWaitTime_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  VehWaitTime_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehWaitTime_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehWaitTime_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace trafficrecord


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trafficrecord::action::VehWaitTime_FeedbackMessage>()
{
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_FeedbackMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trafficrecord, action, VehWaitTime_FeedbackMessage)() {
  return &::trafficrecord::action::rosidl_typesupport_introspection_cpp::VehWaitTime_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
