// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__STRUCT_H_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'key'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/OneCIMKeypoints in the package dsrcmsg.
typedef struct dsrcmsg__msg__OneCIMKeypoints
{
  rosidl_runtime_c__String key;
  double x;
  double y;
} dsrcmsg__msg__OneCIMKeypoints;

// Struct for a sequence of dsrcmsg__msg__OneCIMKeypoints.
typedef struct dsrcmsg__msg__OneCIMKeypoints__Sequence
{
  dsrcmsg__msg__OneCIMKeypoints * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dsrcmsg__msg__OneCIMKeypoints__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__STRUCT_H_
