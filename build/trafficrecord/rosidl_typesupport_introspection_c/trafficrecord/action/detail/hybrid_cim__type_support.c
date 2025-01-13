// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trafficrecord:action/HybridCIM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
#include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trafficrecord/action/detail/hybrid_cim__functions.h"
#include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `vehicleid`
// Member `junction`
// Member `approachleg`
// Member `departleg`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_Goal__init(message_memory);
}

void HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_member_array[9] = {
  {
    "vehicleid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Goal, vehicleid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "junction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Goal, junction),  // bytes offset in struct
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
    offsetof(trafficrecord__action__HybridCIM_Goal, approachleg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "departleg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Goal, departleg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arrivaltime",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Goal, arrivaltime),  // bytes offset in struct
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
    offsetof(trafficrecord__action__HybridCIM_Goal, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Goal, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vehicletype",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Goal, vehicletype),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "priority",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Goal, priority),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_Goal",  // message name
  9,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_Goal),
  HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_member_array,  // message members
  HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_type_support_handle = {
  0,
  &HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_Goal)() {
  if (!HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_type_support_handle.typesupport_identifier) {
    HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_Goal__rosidl_typesupport_introspection_c__HybridCIM_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `vehicleids`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_Result__init(message_memory);
}

void HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_member_array[5] = {
  {
    "vehicleids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Result, vehicleids),  // bytes offset in struct
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
    offsetof(trafficrecord__action__HybridCIM_Result, starttime),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Result, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Result, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "recorded",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Result, recorded),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_Result",  // message name
  5,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_Result),
  HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_member_array,  // message members
  HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_type_support_handle = {
  0,
  &HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_Result)() {
  if (!HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_type_support_handle.typesupport_identifier) {
    HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_Result__rosidl_typesupport_introspection_c__HybridCIM_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `nextapproachleg`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_Feedback__init(message_memory);
}

void HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_member_array[2] = {
  {
    "schedulein",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Feedback, schedulein),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "nextapproachleg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_Feedback, nextapproachleg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_Feedback",  // message name
  2,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_Feedback),
  HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_member_array,  // message members
  HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_type_support_handle = {
  0,
  &HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_Feedback)() {
  if (!HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_type_support_handle.typesupport_identifier) {
    HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_Feedback__rosidl_typesupport_introspection_c__HybridCIM_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "trafficrecord/action/hybrid_cim.h"
// Member `goal`
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_SendGoal_Request__init(message_memory);
}

void HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_SendGoal_Request),
  HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_member_array,  // message members
  HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_type_support_handle = {
  0,
  &HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_SendGoal_Request)() {
  HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_Goal)();
  if (!HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_SendGoal_Request__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_SendGoal_Response__init(message_memory);
}

void HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_SendGoal_Response),
  HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_member_array,  // message members
  HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_type_support_handle = {
  0,
  &HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_SendGoal_Response)() {
  HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_SendGoal_Response__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_service_members = {
  "trafficrecord__action",  // service namespace
  "HybridCIM_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_service_type_support_handle = {
  0,
  &trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_SendGoal)() {
  if (!trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_service_type_support_handle.typesupport_identifier) {
    trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_SendGoal_Response)()->data;
  }

  return &trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_GetResult_Request__init(message_memory);
}

void HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_GetResult_Request),
  HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_member_array,  // message members
  HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_type_support_handle = {
  0,
  &HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_GetResult_Request)() {
  HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_GetResult_Request__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "trafficrecord/action/hybrid_cim.h"
// Member `result`
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_GetResult_Response__init(message_memory);
}

void HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_GetResult_Response),
  HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_member_array,  // message members
  HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_type_support_handle = {
  0,
  &HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_GetResult_Response)() {
  HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_Result)();
  if (!HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_GetResult_Response__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_service_members = {
  "trafficrecord__action",  // service namespace
  "HybridCIM_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_service_type_support_handle = {
  0,
  &trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_GetResult)() {
  if (!trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_service_type_support_handle.typesupport_identifier) {
    trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_GetResult_Response)()->data;
  }

  return &trafficrecord__action__detail__hybrid_cim__rosidl_typesupport_introspection_c__HybridCIM_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "trafficrecord/action/hybrid_cim.h"
// Member `feedback`
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trafficrecord__action__HybridCIM_FeedbackMessage__init(message_memory);
}

void HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_fini_function(void * message_memory)
{
  trafficrecord__action__HybridCIM_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trafficrecord__action__HybridCIM_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_members = {
  "trafficrecord__action",  // message namespace
  "HybridCIM_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(trafficrecord__action__HybridCIM_FeedbackMessage),
  HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_member_array,  // message members
  HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_type_support_handle = {
  0,
  &HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trafficrecord
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_FeedbackMessage)() {
  HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trafficrecord, action, HybridCIM_Feedback)();
  if (!HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HybridCIM_FeedbackMessage__rosidl_typesupport_introspection_c__HybridCIM_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
