// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from trafficrecord:action/VehWaitTime.idl
// generated code does not contain a copyright notice
#include "trafficrecord/action/detail/veh_wait_time__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "trafficrecord/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "trafficrecord/action/detail/veh_wait_time__struct.h"
#include "trafficrecord/action/detail/veh_wait_time__functions.h"
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

#include "rosidl_runtime_c/string.h"  // approachleg
#include "rosidl_runtime_c/string_functions.h"  // approachleg

// forward declare type support functions


using _VehWaitTime_Goal__ros_msg_type = trafficrecord__action__VehWaitTime_Goal;

static bool _VehWaitTime_Goal__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_Goal__ros_msg_type * ros_message = static_cast<const _VehWaitTime_Goal__ros_msg_type *>(untyped_ros_message);
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

  // Field name: waittime
  {
    cdr << ros_message->waittime;
  }

  return true;
}

static bool _VehWaitTime_Goal__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_Goal__ros_msg_type * ros_message = static_cast<_VehWaitTime_Goal__ros_msg_type *>(untyped_ros_message);
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

  // Field name: waittime
  {
    cdr >> ros_message->waittime;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__VehWaitTime_Goal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_Goal__ros_msg_type * ros_message = static_cast<const _VehWaitTime_Goal__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name approachleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->approachleg.size + 1);
  // field.name waittime
  {
    size_t item_size = sizeof(ros_message->waittime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VehWaitTime_Goal__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_Goal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_Goal(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

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
  // member: waittime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _VehWaitTime_Goal__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_Goal(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_Goal = {
  "trafficrecord::action",
  "VehWaitTime_Goal",
  _VehWaitTime_Goal__cdr_serialize,
  _VehWaitTime_Goal__cdr_deserialize,
  _VehWaitTime_Goal__get_serialized_size,
  _VehWaitTime_Goal__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_Goal__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_Goal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Goal)() {
  return &_VehWaitTime_Goal__type_support;
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
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"
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


// forward declare type support functions


using _VehWaitTime_Result__ros_msg_type = trafficrecord__action__VehWaitTime_Result;

static bool _VehWaitTime_Result__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_Result__ros_msg_type * ros_message = static_cast<const _VehWaitTime_Result__ros_msg_type *>(untyped_ros_message);
  // Field name: recorded
  {
    cdr << (ros_message->recorded ? true : false);
  }

  return true;
}

static bool _VehWaitTime_Result__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_Result__ros_msg_type * ros_message = static_cast<_VehWaitTime_Result__ros_msg_type *>(untyped_ros_message);
  // Field name: recorded
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->recorded = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__VehWaitTime_Result(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_Result__ros_msg_type * ros_message = static_cast<const _VehWaitTime_Result__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name recorded
  {
    size_t item_size = sizeof(ros_message->recorded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VehWaitTime_Result__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_Result(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_Result(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: recorded
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _VehWaitTime_Result__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_Result(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_Result = {
  "trafficrecord::action",
  "VehWaitTime_Result",
  _VehWaitTime_Result__cdr_serialize,
  _VehWaitTime_Result__cdr_deserialize,
  _VehWaitTime_Result__get_serialized_size,
  _VehWaitTime_Result__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_Result__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_Result,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Result)() {
  return &_VehWaitTime_Result__type_support;
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
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"
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


// forward declare type support functions


using _VehWaitTime_Feedback__ros_msg_type = trafficrecord__action__VehWaitTime_Feedback;

static bool _VehWaitTime_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_Feedback__ros_msg_type * ros_message = static_cast<const _VehWaitTime_Feedback__ros_msg_type *>(untyped_ros_message);
  // Field name: partiallyrecorded
  {
    cdr << (ros_message->partiallyrecorded ? true : false);
  }

  return true;
}

static bool _VehWaitTime_Feedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_Feedback__ros_msg_type * ros_message = static_cast<_VehWaitTime_Feedback__ros_msg_type *>(untyped_ros_message);
  // Field name: partiallyrecorded
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->partiallyrecorded = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t get_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_Feedback__ros_msg_type * ros_message = static_cast<const _VehWaitTime_Feedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name partiallyrecorded
  {
    size_t item_size = sizeof(ros_message->partiallyrecorded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VehWaitTime_Feedback__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: partiallyrecorded
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _VehWaitTime_Feedback__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_Feedback = {
  "trafficrecord::action",
  "VehWaitTime_Feedback",
  _VehWaitTime_Feedback__cdr_serialize,
  _VehWaitTime_Feedback__cdr_deserialize,
  _VehWaitTime_Feedback__get_serialized_size,
  _VehWaitTime_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_Feedback__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_Feedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Feedback)() {
  return &_VehWaitTime_Feedback__type_support;
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
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"
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
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"  // goal
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_trafficrecord__action__VehWaitTime_Goal(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_trafficrecord__action__VehWaitTime_Goal(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Goal)();
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


using _VehWaitTime_SendGoal_Request__ros_msg_type = trafficrecord__action__VehWaitTime_SendGoal_Request;

static bool _VehWaitTime_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_SendGoal_Request__ros_msg_type * ros_message = static_cast<const _VehWaitTime_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
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
        rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Goal
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _VehWaitTime_SendGoal_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_SendGoal_Request__ros_msg_type * ros_message = static_cast<_VehWaitTime_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
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
        rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Goal
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
size_t get_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_SendGoal_Request__ros_msg_type * ros_message = static_cast<const _VehWaitTime_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
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

  current_alignment += get_serialized_size_trafficrecord__action__VehWaitTime_Goal(
    &(ros_message->goal), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _VehWaitTime_SendGoal_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Request(
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
        max_serialized_size_trafficrecord__action__VehWaitTime_Goal(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _VehWaitTime_SendGoal_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_SendGoal_Request = {
  "trafficrecord::action",
  "VehWaitTime_SendGoal_Request",
  _VehWaitTime_SendGoal_Request__cdr_serialize,
  _VehWaitTime_SendGoal_Request__cdr_deserialize,
  _VehWaitTime_SendGoal_Request__get_serialized_size,
  _VehWaitTime_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_SendGoal_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_SendGoal_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_SendGoal_Request)() {
  return &_VehWaitTime_SendGoal_Request__type_support;
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
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"
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


using _VehWaitTime_SendGoal_Response__ros_msg_type = trafficrecord__action__VehWaitTime_SendGoal_Response;

static bool _VehWaitTime_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_SendGoal_Response__ros_msg_type * ros_message = static_cast<const _VehWaitTime_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
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

static bool _VehWaitTime_SendGoal_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_SendGoal_Response__ros_msg_type * ros_message = static_cast<_VehWaitTime_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
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
size_t get_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_SendGoal_Response__ros_msg_type * ros_message = static_cast<const _VehWaitTime_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _VehWaitTime_SendGoal_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Response(
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

static size_t _VehWaitTime_SendGoal_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_SendGoal_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_SendGoal_Response = {
  "trafficrecord::action",
  "VehWaitTime_SendGoal_Response",
  _VehWaitTime_SendGoal_Response__cdr_serialize,
  _VehWaitTime_SendGoal_Response__cdr_deserialize,
  _VehWaitTime_SendGoal_Response__get_serialized_size,
  _VehWaitTime_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_SendGoal_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_SendGoal_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_SendGoal_Response)() {
  return &_VehWaitTime_SendGoal_Response__type_support;
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
#include "trafficrecord/action/veh_wait_time.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t VehWaitTime_SendGoal__callbacks = {
  "trafficrecord::action",
  "VehWaitTime_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_SendGoal_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_SendGoal_Response)(),
};

static rosidl_service_type_support_t VehWaitTime_SendGoal__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &VehWaitTime_SendGoal__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_SendGoal)() {
  return &VehWaitTime_SendGoal__handle;
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
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"
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


using _VehWaitTime_GetResult_Request__ros_msg_type = trafficrecord__action__VehWaitTime_GetResult_Request;

static bool _VehWaitTime_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_GetResult_Request__ros_msg_type * ros_message = static_cast<const _VehWaitTime_GetResult_Request__ros_msg_type *>(untyped_ros_message);
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

static bool _VehWaitTime_GetResult_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_GetResult_Request__ros_msg_type * ros_message = static_cast<_VehWaitTime_GetResult_Request__ros_msg_type *>(untyped_ros_message);
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
size_t get_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_GetResult_Request__ros_msg_type * ros_message = static_cast<const _VehWaitTime_GetResult_Request__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _VehWaitTime_GetResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Request(
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

static size_t _VehWaitTime_GetResult_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_GetResult_Request = {
  "trafficrecord::action",
  "VehWaitTime_GetResult_Request",
  _VehWaitTime_GetResult_Request__cdr_serialize,
  _VehWaitTime_GetResult_Request__cdr_deserialize,
  _VehWaitTime_GetResult_Request__get_serialized_size,
  _VehWaitTime_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_GetResult_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_GetResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_GetResult_Request)() {
  return &_VehWaitTime_GetResult_Request__type_support;
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
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"
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
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"  // result

// forward declare type support functions
size_t get_serialized_size_trafficrecord__action__VehWaitTime_Result(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_trafficrecord__action__VehWaitTime_Result(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Result)();


using _VehWaitTime_GetResult_Response__ros_msg_type = trafficrecord__action__VehWaitTime_GetResult_Response;

static bool _VehWaitTime_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_GetResult_Response__ros_msg_type * ros_message = static_cast<const _VehWaitTime_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: result
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Result
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->result, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _VehWaitTime_GetResult_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_GetResult_Response__ros_msg_type * ros_message = static_cast<_VehWaitTime_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: result
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Result
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
size_t get_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_GetResult_Response__ros_msg_type * ros_message = static_cast<const _VehWaitTime_GetResult_Response__ros_msg_type *>(untyped_ros_message);
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

  current_alignment += get_serialized_size_trafficrecord__action__VehWaitTime_Result(
    &(ros_message->result), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _VehWaitTime_GetResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Response(
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
        max_serialized_size_trafficrecord__action__VehWaitTime_Result(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _VehWaitTime_GetResult_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_GetResult_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_GetResult_Response = {
  "trafficrecord::action",
  "VehWaitTime_GetResult_Response",
  _VehWaitTime_GetResult_Response__cdr_serialize,
  _VehWaitTime_GetResult_Response__cdr_deserialize,
  _VehWaitTime_GetResult_Response__get_serialized_size,
  _VehWaitTime_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_GetResult_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_GetResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_GetResult_Response)() {
  return &_VehWaitTime_GetResult_Response__type_support;
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
// #include "trafficrecord/action/veh_wait_time.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t VehWaitTime_GetResult__callbacks = {
  "trafficrecord::action",
  "VehWaitTime_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_GetResult_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_GetResult_Response)(),
};

static rosidl_service_type_support_t VehWaitTime_GetResult__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &VehWaitTime_GetResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_GetResult)() {
  return &VehWaitTime_GetResult__handle;
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
// #include "trafficrecord/action/detail/veh_wait_time__struct.h"
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"
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
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"  // feedback
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Feedback)();
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


using _VehWaitTime_FeedbackMessage__ros_msg_type = trafficrecord__action__VehWaitTime_FeedbackMessage;

static bool _VehWaitTime_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehWaitTime_FeedbackMessage__ros_msg_type * ros_message = static_cast<const _VehWaitTime_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
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
        rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Feedback
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->feedback, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _VehWaitTime_FeedbackMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehWaitTime_FeedbackMessage__ros_msg_type * ros_message = static_cast<_VehWaitTime_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
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
        rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_Feedback
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
size_t get_serialized_size_trafficrecord__action__VehWaitTime_FeedbackMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehWaitTime_FeedbackMessage__ros_msg_type * ros_message = static_cast<const _VehWaitTime_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
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

  current_alignment += get_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
    &(ros_message->feedback), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _VehWaitTime_FeedbackMessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trafficrecord__action__VehWaitTime_FeedbackMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trafficrecord
size_t max_serialized_size_trafficrecord__action__VehWaitTime_FeedbackMessage(
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
        max_serialized_size_trafficrecord__action__VehWaitTime_Feedback(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _VehWaitTime_FeedbackMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trafficrecord__action__VehWaitTime_FeedbackMessage(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehWaitTime_FeedbackMessage = {
  "trafficrecord::action",
  "VehWaitTime_FeedbackMessage",
  _VehWaitTime_FeedbackMessage__cdr_serialize,
  _VehWaitTime_FeedbackMessage__cdr_deserialize,
  _VehWaitTime_FeedbackMessage__get_serialized_size,
  _VehWaitTime_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _VehWaitTime_FeedbackMessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehWaitTime_FeedbackMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trafficrecord, action, VehWaitTime_FeedbackMessage)() {
  return &_VehWaitTime_FeedbackMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
