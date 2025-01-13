// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dsrcmsg:msg/IntersectionBSM.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/intersection_bsm__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dsrcmsg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dsrcmsg/msg/detail/intersection_bsm__struct.h"
#include "dsrcmsg/msg/detail/intersection_bsm__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // point
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // point
#include "rosidl_runtime_c/string.h"  // approachleg, departleg, junctionid, vehicleid
#include "rosidl_runtime_c/string_functions.h"  // approachleg, departleg, junctionid, vehicleid

// forward declare type support functions


using _IntersectionBSM__ros_msg_type = dsrcmsg__msg__IntersectionBSM;

static bool _IntersectionBSM__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _IntersectionBSM__ros_msg_type * ros_message = static_cast<const _IntersectionBSM__ros_msg_type *>(untyped_ros_message);
  // Field name: vehicleid
  {
    const rosidl_runtime_c__String * str = &ros_message->vehicleid;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: junctionid
  {
    const rosidl_runtime_c__String * str = &ros_message->junctionid;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: approachleg
  {
    const rosidl_runtime_c__String * str = &ros_message->approachleg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: departleg
  {
    const rosidl_runtime_c__String * str = &ros_message->departleg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: distfromstopline
  {
    cdr << ros_message->distfromstopline;
  }

  // Field name: point
  {
    size_t size = ros_message->point.size;
    auto array_ptr = ros_message->point.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: arrivaltime
  {
    cdr << ros_message->arrivaltime;
  }

  // Field name: vehicletype
  {
    cdr << ros_message->vehicletype;
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: priority
  {
    cdr << ros_message->priority;
  }

  // Field name: stoppedtime
  {
    cdr << ros_message->stoppedtime;
  }

  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  return true;
}

static bool _IntersectionBSM__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _IntersectionBSM__ros_msg_type * ros_message = static_cast<_IntersectionBSM__ros_msg_type *>(untyped_ros_message);
  // Field name: vehicleid
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->vehicleid.data) {
      rosidl_runtime_c__String__init(&ros_message->vehicleid);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->vehicleid,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'vehicleid'\n");
      return false;
    }
  }

  // Field name: junctionid
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->junctionid.data) {
      rosidl_runtime_c__String__init(&ros_message->junctionid);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->junctionid,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'junctionid'\n");
      return false;
    }
  }

  // Field name: approachleg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->approachleg.data) {
      rosidl_runtime_c__String__init(&ros_message->approachleg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->approachleg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'approachleg'\n");
      return false;
    }
  }

  // Field name: departleg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->departleg.data) {
      rosidl_runtime_c__String__init(&ros_message->departleg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->departleg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'departleg'\n");
      return false;
    }
  }

  // Field name: distfromstopline
  {
    cdr >> ros_message->distfromstopline;
  }

  // Field name: point
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->point.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->point);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->point, size)) {
      return "failed to create array for field 'point'";
    }
    auto array_ptr = ros_message->point.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: arrivaltime
  {
    cdr >> ros_message->arrivaltime;
  }

  // Field name: vehicletype
  {
    cdr >> ros_message->vehicletype;
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: priority
  {
    cdr >> ros_message->priority;
  }

  // Field name: stoppedtime
  {
    cdr >> ros_message->stoppedtime;
  }

  // Field name: timestamp
  {
    cdr >> ros_message->timestamp;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dsrcmsg
size_t get_serialized_size_dsrcmsg__msg__IntersectionBSM(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IntersectionBSM__ros_msg_type * ros_message = static_cast<const _IntersectionBSM__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name vehicleid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->vehicleid.size + 1);
  // field.name junctionid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->junctionid.size + 1);
  // field.name approachleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->approachleg.size + 1);
  // field.name departleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->departleg.size + 1);
  // field.name distfromstopline
  {
    size_t item_size = sizeof(ros_message->distfromstopline);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name point
  {
    size_t array_size = ros_message->point.size;
    auto array_ptr = ros_message->point.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arrivaltime
  {
    size_t item_size = sizeof(ros_message->arrivaltime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vehicletype
  {
    size_t item_size = sizeof(ros_message->vehicletype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name priority
  {
    size_t item_size = sizeof(ros_message->priority);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name stoppedtime
  {
    size_t item_size = sizeof(ros_message->stoppedtime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _IntersectionBSM__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dsrcmsg__msg__IntersectionBSM(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dsrcmsg
size_t max_serialized_size_dsrcmsg__msg__IntersectionBSM(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: vehicleid
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: junctionid
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: approachleg
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: departleg
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: distfromstopline
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: point
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arrivaltime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vehicletype
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: priority
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: stoppedtime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: timestamp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _IntersectionBSM__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_dsrcmsg__msg__IntersectionBSM(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_IntersectionBSM = {
  "dsrcmsg::msg",
  "IntersectionBSM",
  _IntersectionBSM__cdr_serialize,
  _IntersectionBSM__cdr_deserialize,
  _IntersectionBSM__get_serialized_size,
  _IntersectionBSM__max_serialized_size
};

static rosidl_message_type_support_t _IntersectionBSM__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_IntersectionBSM,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dsrcmsg, msg, IntersectionBSM)() {
  return &_IntersectionBSM__type_support;
}

#if defined(__cplusplus)
}
#endif
