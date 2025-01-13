// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from trafficrecord:action/HybridCIM.idl
// generated code does not contain a copyright notice
#include "trafficrecord/action/detail/hybrid_cim__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "trafficrecord/action/detail/hybrid_cim__struct.h"
#include "trafficrecord/action/detail/hybrid_cim__functions.h"
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
#include "rosidl_runtime_c/string.h"  // approachleg, departleg, junction, vehicleid
#include "rosidl_runtime_c/string_functions.h"  // approachleg, departleg, junction, vehicleid

// forward declare type support functions


using _HybridCIM_Goal__ros_msg_type = trafficrecord__action__HybridCIM_Goal;

static bool _HybridCIM_Goal__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_Goal__ros_msg_type * ros_message = static_cast<const _HybridCIM_Goal__ros_msg_type *>(untyped_ros_message);
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

  // Field name: junction
  {
    const rosidl_runtime_c__String * str = &ros_message->junction;
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

  // Field name: arrivaltime
  {
    cdr << ros_message->arrivaltime;
  }

  // Field name: point
  {
    size_t size = ros_message->point.size;
    auto array_ptr = ros_message->point.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: vehicletype
  {
    cdr << ros_message->vehicletype;
  }

  // Field name: priority
  {
    cdr << ros_message->priority;
  }

  return true;
}

static bool _HybridCIM_Goal__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_Goal__ros_msg_type * ros_message = static_cast<_HybridCIM_Goal__ros_msg_type *>(untyped_ros_message);
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

  // Field name: junction
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->junction.data) {
      rosidl_runtime_c__String__init(&ros_message->junction);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->junction,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'junction'\n");
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

  // Field name: arrivaltime
  {
    cdr >> ros_message->arrivaltime;
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

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: vehicletype
  {
    cdr >> ros_message->vehicletype;
  }

  // Field name: priority
  {
    cdr >> ros_message->priority;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_Goal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_Goal__ros_msg_type * ros_message = static_cast<const _HybridCIM_Goal__ros_msg_type *>(untyped_ros_message);
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
  // field.name junction
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->junction.size + 1);
  // field.name approachleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->approachleg.size + 1);
  // field.name departleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->departleg.size + 1);
  // field.name arrivaltime
  {
    size_t item_size = sizeof(ros_message->arrivaltime);
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
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vehicletype
  {
    size_t item_size = sizeof(ros_message->vehicletype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name priority
  {
    size_t item_size = sizeof(ros_message->priority);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_Goal__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_Goal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_Goal(
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
  // member: junction
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
  // member: arrivaltime
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
  // member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: vehicletype
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: priority
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_Goal__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_Goal(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_Goal = {
  "trafficrecord::action",
  "HybridCIM_Goal",
  _HybridCIM_Goal__cdr_serialize,
  _HybridCIM_Goal__cdr_deserialize,
  _HybridCIM_Goal__get_serialized_size,
  _HybridCIM_Goal__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_Goal__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_Goal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Goal)() {
  return &_HybridCIM_Goal__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/string.h"  // vehicleids
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // vehicleids

// forward declare type support functions


using _HybridCIM_Result__ros_msg_type = trafficrecord__action__HybridCIM_Result;

static bool _HybridCIM_Result__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_Result__ros_msg_type * ros_message = static_cast<const _HybridCIM_Result__ros_msg_type *>(untyped_ros_message);
  // Field name: vehicleids
  {
    size_t size = ros_message->vehicleids.size;
    auto array_ptr = ros_message->vehicleids.data;
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

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: recorded
  {
    cdr << (ros_message->recorded ? true : false);
  }

  return true;
}

static bool _HybridCIM_Result__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_Result__ros_msg_type * ros_message = static_cast<_HybridCIM_Result__ros_msg_type *>(untyped_ros_message);
  // Field name: vehicleids
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->vehicleids.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->vehicleids);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->vehicleids, size)) {
      return "failed to create array for field 'vehicleids'";
    }
    auto array_ptr = ros_message->vehicleids.data;
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
        fprintf(stderr, "failed to assign string into field 'vehicleids'\n");
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

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: recorded
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->recorded = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_Result(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_Result__ros_msg_type * ros_message = static_cast<const _HybridCIM_Result__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name vehicleids
  {
    size_t array_size = ros_message->vehicleids.size;
    auto array_ptr = ros_message->vehicleids.data;
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
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name recorded
  {
    size_t item_size = sizeof(ros_message->recorded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_Result__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_Result(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_Result(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: vehicleids
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

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: recorded
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_Result__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_Result(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_Result = {
  "trafficrecord::action",
  "HybridCIM_Result",
  _HybridCIM_Result__cdr_serialize,
  _HybridCIM_Result__cdr_deserialize,
  _HybridCIM_Result__get_serialized_size,
  _HybridCIM_Result__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_Result__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_Result,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Result)() {
  return &_HybridCIM_Result__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/string.h"  // nextapproachleg
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // nextapproachleg

// forward declare type support functions


using _HybridCIM_Feedback__ros_msg_type = trafficrecord__action__HybridCIM_Feedback;

static bool _HybridCIM_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_Feedback__ros_msg_type * ros_message = static_cast<const _HybridCIM_Feedback__ros_msg_type *>(untyped_ros_message);
  // Field name: schedulein
  {
    cdr << ros_message->schedulein;
  }

  // Field name: nextapproachleg
  {
    const rosidl_runtime_c__String * str = &ros_message->nextapproachleg;
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

  return true;
}

static bool _HybridCIM_Feedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_Feedback__ros_msg_type * ros_message = static_cast<_HybridCIM_Feedback__ros_msg_type *>(untyped_ros_message);
  // Field name: schedulein
  {
    cdr >> ros_message->schedulein;
  }

  // Field name: nextapproachleg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->nextapproachleg.data) {
      rosidl_runtime_c__String__init(&ros_message->nextapproachleg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->nextapproachleg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'nextapproachleg'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_Feedback__ros_msg_type * ros_message = static_cast<const _HybridCIM_Feedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name schedulein
  {
    size_t item_size = sizeof(ros_message->schedulein);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nextapproachleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->nextapproachleg.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_Feedback__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_Feedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_Feedback(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: schedulein
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nextapproachleg
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_Feedback__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_Feedback(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_Feedback = {
  "trafficrecord::action",
  "HybridCIM_Feedback",
  _HybridCIM_Feedback__cdr_serialize,
  _HybridCIM_Feedback__cdr_deserialize,
  _HybridCIM_Feedback__get_serialized_size,
  _HybridCIM_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_Feedback__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_Feedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Feedback)() {
  return &_HybridCIM_Feedback__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"  // goal
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_trafficrecord__action__HybridCIM_Goal(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_trafficrecord__action__HybridCIM_Goal(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Goal)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID)();


using _HybridCIM_SendGoal_Request__ros_msg_type = trafficrecord__action__HybridCIM_SendGoal_Request;

static bool _HybridCIM_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_SendGoal_Request__ros_msg_type * ros_message = static_cast<const _HybridCIM_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal_id, cdr))
    {
      return false;
    }
  }

  // Field name: goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Goal
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _HybridCIM_SendGoal_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_SendGoal_Request__ros_msg_type * ros_message = static_cast<_HybridCIM_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal_id))
    {
      return false;
    }
  }

  // Field name: goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Goal
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_SendGoal_Request__ros_msg_type * ros_message = static_cast<const _HybridCIM_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name goal_id

  current_alignment += get_serialized_size_unique_identifier_msgs__msg__UUID(
    &(ros_message->goal_id), current_alignment);
  // field.name goal

  current_alignment += get_serialized_size_trafficrecord__action__HybridCIM_Goal(
    &(ros_message->goal), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_SendGoal_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: goal_id
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_unique_identifier_msgs__msg__UUID(
        full_bounded, current_alignment);
    }
  }
  // member: goal
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_trafficrecord__action__HybridCIM_Goal(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_SendGoal_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_SendGoal_Request = {
  "trafficrecord::action",
  "HybridCIM_SendGoal_Request",
  _HybridCIM_SendGoal_Request__cdr_serialize,
  _HybridCIM_SendGoal_Request__cdr_deserialize,
  _HybridCIM_SendGoal_Request__get_serialized_size,
  _HybridCIM_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_SendGoal_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_SendGoal_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_SendGoal_Request)() {
  return &_HybridCIM_SendGoal_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();


using _HybridCIM_SendGoal_Response__ros_msg_type = trafficrecord__action__HybridCIM_SendGoal_Response;

static bool _HybridCIM_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_SendGoal_Response__ros_msg_type * ros_message = static_cast<const _HybridCIM_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: accepted
  {
    cdr << (ros_message->accepted ? true : false);
  }

  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->stamp, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _HybridCIM_SendGoal_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_SendGoal_Response__ros_msg_type * ros_message = static_cast<_HybridCIM_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: accepted
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->accepted = tmp ? true : false;
  }

  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->stamp))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_SendGoal_Response__ros_msg_type * ros_message = static_cast<const _HybridCIM_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name accepted
  {
    size_t item_size = sizeof(ros_message->accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name stamp

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_SendGoal_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: accepted
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: stamp
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_builtin_interfaces__msg__Time(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_SendGoal_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_SendGoal_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_SendGoal_Response = {
  "trafficrecord::action",
  "HybridCIM_SendGoal_Response",
  _HybridCIM_SendGoal_Response__cdr_serialize,
  _HybridCIM_SendGoal_Response__cdr_deserialize,
  _HybridCIM_SendGoal_Response__get_serialized_size,
  _HybridCIM_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_SendGoal_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_SendGoal_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_SendGoal_Response)() {
  return &_HybridCIM_SendGoal_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "trafficrecord/action/hybrid_cim.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t HybridCIM_SendGoal__callbacks = {
  "trafficrecord::action",
  "HybridCIM_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_SendGoal_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_SendGoal_Response)(),
};

static rosidl_service_type_support_t HybridCIM_SendGoal__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &HybridCIM_SendGoal__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_SendGoal)() {
  return &HybridCIM_SendGoal__handle;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID)();


using _HybridCIM_GetResult_Request__ros_msg_type = trafficrecord__action__HybridCIM_GetResult_Request;

static bool _HybridCIM_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_GetResult_Request__ros_msg_type * ros_message = static_cast<const _HybridCIM_GetResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal_id, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _HybridCIM_GetResult_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_GetResult_Request__ros_msg_type * ros_message = static_cast<_HybridCIM_GetResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal_id))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_GetResult_Request__ros_msg_type * ros_message = static_cast<const _HybridCIM_GetResult_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name goal_id

  current_alignment += get_serialized_size_unique_identifier_msgs__msg__UUID(
    &(ros_message->goal_id), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_GetResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_GetResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_GetResult_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: goal_id
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_unique_identifier_msgs__msg__UUID(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_GetResult_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_GetResult_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_GetResult_Request = {
  "trafficrecord::action",
  "HybridCIM_GetResult_Request",
  _HybridCIM_GetResult_Request__cdr_serialize,
  _HybridCIM_GetResult_Request__cdr_deserialize,
  _HybridCIM_GetResult_Request__get_serialized_size,
  _HybridCIM_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_GetResult_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_GetResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_GetResult_Request)() {
  return &_HybridCIM_GetResult_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"  // result

// forward declare type support functions
size_t get_serialized_size_trafficrecord__action__HybridCIM_Result(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_trafficrecord__action__HybridCIM_Result(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Result)();


using _HybridCIM_GetResult_Response__ros_msg_type = trafficrecord__action__HybridCIM_GetResult_Response;

static bool _HybridCIM_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_GetResult_Response__ros_msg_type * ros_message = static_cast<const _HybridCIM_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: result
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Result
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->result, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _HybridCIM_GetResult_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_GetResult_Response__ros_msg_type * ros_message = static_cast<_HybridCIM_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: result
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Result
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->result))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_GetResult_Response__ros_msg_type * ros_message = static_cast<const _HybridCIM_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name result

  current_alignment += get_serialized_size_trafficrecord__action__HybridCIM_Result(
    &(ros_message->result), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_GetResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_GetResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_GetResult_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: result
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_trafficrecord__action__HybridCIM_Result(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_GetResult_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_GetResult_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_GetResult_Response = {
  "trafficrecord::action",
  "HybridCIM_GetResult_Response",
  _HybridCIM_GetResult_Response__cdr_serialize,
  _HybridCIM_GetResult_Response__cdr_deserialize,
  _HybridCIM_GetResult_Response__get_serialized_size,
  _HybridCIM_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_GetResult_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_GetResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_GetResult_Response)() {
  return &_HybridCIM_GetResult_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/hybrid_cim.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t HybridCIM_GetResult__callbacks = {
  "trafficrecord::action",
  "HybridCIM_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_GetResult_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_GetResult_Response)(),
};

static rosidl_service_type_support_t HybridCIM_GetResult__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &HybridCIM_GetResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_GetResult)() {
  return &HybridCIM_GetResult__handle;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__struct.h"
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "trafficrecord/action/detail/hybrid_cim__functions.h"  // feedback
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_trafficrecord__action__HybridCIM_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_trafficrecord__action__HybridCIM_Feedback(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Feedback)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_trafficrecord
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID)();


using _HybridCIM_FeedbackMessage__ros_msg_type = trafficrecord__action__HybridCIM_FeedbackMessage;

static bool _HybridCIM_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _HybridCIM_FeedbackMessage__ros_msg_type * ros_message = static_cast<const _HybridCIM_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal_id, cdr))
    {
      return false;
    }
  }

  // Field name: feedback
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Feedback
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->feedback, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _HybridCIM_FeedbackMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _HybridCIM_FeedbackMessage__ros_msg_type * ros_message = static_cast<_HybridCIM_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal_id))
    {
      return false;
    }
  }

  // Field name: feedback
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_Feedback
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->feedback))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__HybridCIM_FeedbackMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HybridCIM_FeedbackMessage__ros_msg_type * ros_message = static_cast<const _HybridCIM_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name goal_id

  current_alignment += get_serialized_size_unique_identifier_msgs__msg__UUID(
    &(ros_message->goal_id), current_alignment);
  // field.name feedback

  current_alignment += get_serialized_size_trafficrecord__action__HybridCIM_Feedback(
    &(ros_message->feedback), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _HybridCIM_FeedbackMessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__HybridCIM_FeedbackMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__HybridCIM_FeedbackMessage(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: goal_id
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_unique_identifier_msgs__msg__UUID(
        full_bounded, current_alignment);
    }
  }
  // member: feedback
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_trafficrecord__action__HybridCIM_Feedback(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _HybridCIM_FeedbackMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__HybridCIM_FeedbackMessage(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_HybridCIM_FeedbackMessage = {
  "trafficrecord::action",
  "HybridCIM_FeedbackMessage",
  _HybridCIM_FeedbackMessage__cdr_serialize,
  _HybridCIM_FeedbackMessage__cdr_deserialize,
  _HybridCIM_FeedbackMessage__get_serialized_size,
  _HybridCIM_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _HybridCIM_FeedbackMessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HybridCIM_FeedbackMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, HybridCIM_FeedbackMessage)() {
  return &_HybridCIM_FeedbackMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
