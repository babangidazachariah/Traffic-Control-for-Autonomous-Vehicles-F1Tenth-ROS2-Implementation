// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trafficrecord:action/VehWaitTime.idl
// generated code does not contain a copyright notice

#ifndef TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__STRUCT_H_
#define TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'approachleg'
#include "rosidl_runtime_c/string.h"

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_Goal
{
  rosidl_runtime_c__String approachleg;
  float waittime;
} trafficrecord__action__VehWaitTime_Goal;

// Struct for a sequence of trafficrecord__action__VehWaitTime_Goal.
typedef struct trafficrecord__action__VehWaitTime_Goal__Sequence
{
  trafficrecord__action__VehWaitTime_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_Goal__Sequence;


// Constants defined in the message

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_Result
{
  bool recorded;
} trafficrecord__action__VehWaitTime_Result;

// Struct for a sequence of trafficrecord__action__VehWaitTime_Result.
typedef struct trafficrecord__action__VehWaitTime_Result__Sequence
{
  trafficrecord__action__VehWaitTime_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_Result__Sequence;


// Constants defined in the message

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_Feedback
{
  bool partiallyrecorded;
} trafficrecord__action__VehWaitTime_Feedback;

// Struct for a sequence of trafficrecord__action__VehWaitTime_Feedback.
typedef struct trafficrecord__action__VehWaitTime_Feedback__Sequence
{
  trafficrecord__action__VehWaitTime_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "trafficrecord/action/detail/veh_wait_time__struct.h"

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  trafficrecord__action__VehWaitTime_Goal goal;
} trafficrecord__action__VehWaitTime_SendGoal_Request;

// Struct for a sequence of trafficrecord__action__VehWaitTime_SendGoal_Request.
typedef struct trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence
{
  trafficrecord__action__VehWaitTime_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} trafficrecord__action__VehWaitTime_SendGoal_Response;

// Struct for a sequence of trafficrecord__action__VehWaitTime_SendGoal_Response.
typedef struct trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence
{
  trafficrecord__action__VehWaitTime_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} trafficrecord__action__VehWaitTime_GetResult_Request;

// Struct for a sequence of trafficrecord__action__VehWaitTime_GetResult_Request.
typedef struct trafficrecord__action__VehWaitTime_GetResult_Request__Sequence
{
  trafficrecord__action__VehWaitTime_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_GetResult_Response
{
  int8_t status;
  trafficrecord__action__VehWaitTime_Result result;
} trafficrecord__action__VehWaitTime_GetResult_Response;

// Struct for a sequence of trafficrecord__action__VehWaitTime_GetResult_Response.
typedef struct trafficrecord__action__VehWaitTime_GetResult_Response__Sequence
{
  trafficrecord__action__VehWaitTime_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"

// Struct defined in action/VehWaitTime in the package trafficrecord.
typedef struct trafficrecord__action__VehWaitTime_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  trafficrecord__action__VehWaitTime_Feedback feedback;
} trafficrecord__action__VehWaitTime_FeedbackMessage;

// Struct for a sequence of trafficrecord__action__VehWaitTime_FeedbackMessage.
typedef struct trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence
{
  trafficrecord__action__VehWaitTime_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__STRUCT_H_
