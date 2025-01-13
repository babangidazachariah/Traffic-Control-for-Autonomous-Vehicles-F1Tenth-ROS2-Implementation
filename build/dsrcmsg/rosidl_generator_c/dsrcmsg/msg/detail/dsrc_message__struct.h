// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dsrcmsg:msg/DSRCMessage.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__STRUCT_H_
#define DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__STRUCT_H_

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
// Member 'approachleg'
// Member 'departureleg'
#include "rosidl_runtime_c/string.h"
// Member 'point'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/DSRCMessage in the package dsrcmsg.
typedef struct dsrcmsg__msg__DSRCMessage
{
  rosidl_runtime_c__String vehicleid;
  double initialtime;
  double currenttime;
  rosidl_runtime_c__String approachleg;
  rosidl_runtime_c__String departureleg;
  double disttostopline;
  double distfromstopline;
  rosidl_runtime_c__float__Sequence point;
  double speed;
} dsrcmsg__msg__DSRCMessage;

// Struct for a sequence of dsrcmsg__msg__DSRCMessage.
typedef struct dsrcmsg__msg__DSRCMessage__Sequence
{
  dsrcmsg__msg__DSRCMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dsrcmsg__msg__DSRCMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__STRUCT_H_
