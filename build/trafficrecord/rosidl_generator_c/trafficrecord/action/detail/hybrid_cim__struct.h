// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trafficrecord:action/HybridCIM.idl
// generated code does not contain a copyright notice

#ifndef TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__STRUCT_H_
#define TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'vehicleid'
// Member 'junction'
// Member 'approachleg'
// Member 'departleg'
#include "rosidl_runtime_c/string.h"
// Member 'point'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_Goal
{
  rosidl_runtime_c__String vehicleid;
  rosidl_runtime_c__String junction;
  rosidl_runtime_c__String approachleg;
  rosidl_runtime_c__String departleg;
  double arrivaltime;
  rosidl_runtime_c__float__Sequence point;
  float speed;
  int32_t vehicletype;
  int32_t priority;
} trafficrecord__action__HybridCIM_Goal;

// Struct for a sequence of trafficrecord__action__HybridCIM_Goal.
typedef struct trafficrecord__action__HybridCIM_Goal__Sequence
{
  trafficrecord__action__HybridCIM_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'vehicleids'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_Result
{
  rosidl_runtime_c__String__Sequence vehicleids;
  double starttime;
  int32_t duration;
  int32_t speed;
  bool recorded;
} trafficrecord__action__HybridCIM_Result;

// Struct for a sequence of trafficrecord__action__HybridCIM_Result.
typedef struct trafficrecord__action__HybridCIM_Result__Sequence
{
  trafficrecord__action__HybridCIM_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'nextapproachleg'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_Feedback
{
  int32_t schedulein;
  rosidl_runtime_c__String nextapproachleg;
} trafficrecord__action__HybridCIM_Feedback;

// Struct for a sequence of trafficrecord__action__HybridCIM_Feedback.
typedef struct trafficrecord__action__HybridCIM_Feedback__Sequence
{
  trafficrecord__action__HybridCIM_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "trafficrecord/action/detail/hybrid_cim__struct.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  trafficrecord__action__HybridCIM_Goal goal;
} trafficrecord__action__HybridCIM_SendGoal_Request;

// Struct for a sequence of trafficrecord__action__HybridCIM_SendGoal_Request.
typedef struct trafficrecord__action__HybridCIM_SendGoal_Request__Sequence
{
  trafficrecord__action__HybridCIM_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} trafficrecord__action__HybridCIM_SendGoal_Response;

// Struct for a sequence of trafficrecord__action__HybridCIM_SendGoal_Response.
typedef struct trafficrecord__action__HybridCIM_SendGoal_Response__Sequence
{
  trafficrecord__action__HybridCIM_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} trafficrecord__action__HybridCIM_GetResult_Request;

// Struct for a sequence of trafficrecord__action__HybridCIM_GetResult_Request.
typedef struct trafficrecord__action__HybridCIM_GetResult_Request__Sequence
{
  trafficrecord__action__HybridCIM_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_GetResult_Response
{
  int8_t status;
  trafficrecord__action__HybridCIM_Result result;
} trafficrecord__action__HybridCIM_GetResult_Response;

// Struct for a sequence of trafficrecord__action__HybridCIM_GetResult_Response.
typedef struct trafficrecord__action__HybridCIM_GetResult_Response__Sequence
{
  trafficrecord__action__HybridCIM_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"

// Struct defined in action/HybridCIM in the package trafficrecord.
typedef struct trafficrecord__action__HybridCIM_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  trafficrecord__action__HybridCIM_Feedback feedback;
} trafficrecord__action__HybridCIM_FeedbackMessage;

// Struct for a sequence of trafficrecord__action__HybridCIM_FeedbackMessage.
typedef struct trafficrecord__action__HybridCIM_FeedbackMessage__Sequence
{
  trafficrecord__action__HybridCIM_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__HybridCIM_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__STRUCT_H_
