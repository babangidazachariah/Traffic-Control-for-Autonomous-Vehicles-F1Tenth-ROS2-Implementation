// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dsrcmsg:msg/OneCIMTlsMsg.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__STRUCT_H_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'junctionid'
// Member 'vehicleid'
// Member 'pathids'
#include "rosidl_runtime_c/string.h"
// Member 'approachpoints'
// Member 'departpoints'
#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.h"

// Struct defined in msg/OneCIMTlsMsg in the package dsrcmsg.
typedef struct dsrcmsg__msg__OneCIMTlsMsg
{
  rosidl_runtime_c__String junctionid;
  rosidl_runtime_c__String vehicleid;
  rosidl_runtime_c__String__Sequence pathids;
  double starttime;
  double duration;
  dsrcmsg__msg__OneCIMKeypoints__Sequence approachpoints;
  dsrcmsg__msg__OneCIMKeypoints__Sequence departpoints;
  double speed;
} dsrcmsg__msg__OneCIMTlsMsg;

// Struct for a sequence of dsrcmsg__msg__OneCIMTlsMsg.
typedef struct dsrcmsg__msg__OneCIMTlsMsg__Sequence
{
  dsrcmsg__msg__OneCIMTlsMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dsrcmsg__msg__OneCIMTlsMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__STRUCT_H_
