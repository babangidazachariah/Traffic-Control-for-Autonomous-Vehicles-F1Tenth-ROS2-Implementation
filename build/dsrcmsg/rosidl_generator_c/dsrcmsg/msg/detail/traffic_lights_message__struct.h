// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dsrcmsg:msg/TrafficLightsMessage.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__STRUCT_H_
#define DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pathids'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/TrafficLightsMessage in the package dsrcmsg.
typedef struct dsrcmsg__msg__TrafficLightsMessage
{
  rosidl_runtime_c__String__Sequence pathids;
  double starttime;
  double duration;
  double speed;
} dsrcmsg__msg__TrafficLightsMessage;

// Struct for a sequence of dsrcmsg__msg__TrafficLightsMessage.
typedef struct dsrcmsg__msg__TrafficLightsMessage__Sequence
{
  dsrcmsg__msg__TrafficLightsMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dsrcmsg__msg__TrafficLightsMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__STRUCT_H_
