// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dsrcmsg:msg/OneCIMTlsMsg.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/one_cim_tls_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dsrcmsg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dsrcmsg/msg/detail/one_cim_tls_msg__struct.h"
#include "dsrcmsg/msg/detail/one_cim_tls_msg__functions.h"
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

#include "dsrcmsg/msg/detail/one_cim_keypoints__functions.h"  // approachpoints, departpoints
#include "rosidl_runtime_c/string.h"  // junctionid, pathids, vehicleid
#include "rosidl_runtime_c/string_functions.h"  // junctionid, pathids, vehicleid

// forward declare type support functions
size_t get_serialized_size_dsrcmsg__msg__OneCIMKeypoints(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_dsrcmsg__msg__OneCIMKeypoints(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dsrcmsg, msg, OneCIMKeypoints)();


using _OneCIMTlsMsg__ros_msg_type = dsrcmsg__msg__OneCIMTlsMsg;

static bool _OneCIMTlsMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OneCIMTlsMsg__ros_msg_type * ros_message = static_cast<const _OneCIMTlsMsg__ros_msg_type *>(untyped_ros_message);
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

  // Field name: pathids
  {
    size_t size = ros_message->pathids.size;
    auto array_ptr = ros_message->pathids.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  // Field name: starttime
  {
    cdr << ros_message->starttime;
  }

  // Field name: duration
  {
    cdr << ros_message->duration;
  }

  // Field name: approachpoints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dsrcmsg, msg, OneCIMKeypoints
      )()->data);
    size_t size = ros_message->approachpoints.size;
    auto array_ptr = ros_message->approachpoints.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: departpoints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dsrcmsg, msg, OneCIMKeypoints
      )()->data);
    size_t size = ros_message->departpoints.size;
    auto array_ptr = ros_message->departpoints.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  return true;
}

static bool _OneCIMTlsMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OneCIMTlsMsg__ros_msg_type * ros_message = static_cast<_OneCIMTlsMsg__ros_msg_type *>(untyped_ros_message);
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

  // Field name: pathids
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->pathids.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->pathids);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->pathids, size)) {
      return "failed to create array for field 'pathids'";
    }
    auto array_ptr = ros_message->pathids.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'pathids'\n");
        return false;
      }
    }
  }

  // Field name: starttime
  {
    cdr >> ros_message->starttime;
  }

  // Field name: duration
  {
    cdr >> ros_message->duration;
  }

  // Field name: approachpoints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dsrcmsg, msg, OneCIMKeypoints
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->approachpoints.data) {
      dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(&ros_message->approachpoints);
    }
    if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__init(&ros_message->approachpoints, size)) {
      return "failed to create array for field 'approachpoints'";
    }
    auto array_ptr = ros_message->approachpoints.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: departpoints
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, dsrcmsg, msg, OneCIMKeypoints
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->departpoints.data) {
      dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(&ros_message->departpoints);
    }
    if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__init(&ros_message->departpoints, size)) {
      return "failed to create array for field 'departpoints'";
    }
    auto array_ptr = ros_message->departpoints.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dsrcmsg
size_t get_serialized_size_dsrcmsg__msg__OneCIMTlsMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OneCIMTlsMsg__ros_msg_type * ros_message = static_cast<const _OneCIMTlsMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name junctionid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->junctionid.size + 1);
  // field.name vehicleid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->vehicleid.size + 1);
  // field.name pathids
  {
    size_t array_size = ros_message->pathids.size;
    auto array_ptr = ros_message->pathids.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name starttime
  {
    size_t item_size = sizeof(ros_message->starttime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name duration
  {
    size_t item_size = sizeof(ros_message->duration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name approachpoints
  {
    size_t array_size = ros_message->approachpoints.size;
    auto array_ptr = ros_message->approachpoints.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_dsrcmsg__msg__OneCIMKeypoints(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name departpoints
  {
    size_t array_size = ros_message->departpoints.size;
    auto array_ptr = ros_message->departpoints.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_dsrcmsg__msg__OneCIMKeypoints(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _OneCIMTlsMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dsrcmsg__msg__OneCIMTlsMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dsrcmsg
size_t max_serialized_size_dsrcmsg__msg__OneCIMTlsMsg(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

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
  // member: pathids
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: starttime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: duration
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: approachpoints
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_dsrcmsg__msg__OneCIMKeypoints(
        full_bounded, current_alignment);
    }
  }
  // member: departpoints
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_dsrcmsg__msg__OneCIMKeypoints(
        full_bounded, current_alignment);
    }
  }
  // member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _OneCIMTlsMsg__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_dsrcmsg__msg__OneCIMTlsMsg(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_OneCIMTlsMsg = {
  "dsrcmsg::msg",
  "OneCIMTlsMsg",
  _OneCIMTlsMsg__cdr_serialize,
  _OneCIMTlsMsg__cdr_deserialize,
  _OneCIMTlsMsg__get_serialized_size,
  _OneCIMTlsMsg__max_serialized_size
};

static rosidl_message_type_support_t _OneCIMTlsMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OneCIMTlsMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dsrcmsg, msg, OneCIMTlsMsg)() {
  return &_OneCIMTlsMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
