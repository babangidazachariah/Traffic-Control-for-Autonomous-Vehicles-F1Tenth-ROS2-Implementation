// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dsrcmsg:msg/IntersectionBSM.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__STRUCT_H_
#define DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__STRUCT_H_

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
// Member 'junctionid'
// Member 'approachleg'
// Member 'departleg'
#include "rosidl_runtime_c/string.h"
// Member 'point'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/IntersectionBSM in the package dsrcmsg.
typedef struct dsrcmsg__msg__IntersectionBSM
{
  rosidl_runtime_c__String vehicleid;
  rosidl_runtime_c__String junctionid;
  rosidl_runtime_c__String approachleg;
  rosidl_runtime_c__String departleg;
  double distfromstopline;
  rosidl_runtime_c__float__Sequence point;
  double arrivaltime;
  int32_t vehicletype;
  double speed;
  int32_t priority;
  double stoppedtime;
  double timestamp;
} dsrcmsg__msg__IntersectionBSM;

// Struct for a sequence of dsrcmsg__msg__IntersectionBSM.
typedef struct dsrcmsg__msg__IntersectionBSM__Sequence
{
  dsrcmsg__msg__IntersectionBSM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dsrcmsg__msg__IntersectionBSM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__STRUCT_H_
