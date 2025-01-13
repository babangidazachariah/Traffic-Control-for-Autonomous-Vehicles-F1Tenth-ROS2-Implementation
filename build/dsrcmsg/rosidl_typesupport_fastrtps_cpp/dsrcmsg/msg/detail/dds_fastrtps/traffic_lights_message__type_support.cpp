// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dsrcmsg:msg/TrafficLightsMessage.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/traffic_lights_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dsrcmsg/msg/detail/traffic_lights_message__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace dsrcmsg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
cdr_serialize(
  const dsrcmsg::msg::TrafficLightsMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pathids
  {
    cdr << ros_message.pathids;
  }
  // Member: starttime
  cdr << ros_message.starttime;
  // Member: duration
  cdr << ros_message.duration;
  // Member: speed
  cdr << ros_message.speed;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dsrcmsg::msg::TrafficLightsMessage & ros_message)
{
  // Member: pathids
  {
    cdr >> ros_message.pathids;
  }

  // Member: starttime
  cdr >> ros_message.starttime;

  // Member: duration
  cdr >> ros_message.duration;

  // Member: speed
  cdr >> ros_message.speed;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
get_serialized_size(
  const dsrcmsg::msg::TrafficLightsMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pathids
  {
    size_t array_size = ros_message.pathids.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.pathids[index].size() + 1);
    }
  }
  // Member: starttime
  {
    size_t item_size = sizeof(ros_message.starttime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: duration
  {
    size_t item_size = sizeof(ros_message.duration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed
  {
    size_t item_size = sizeof(ros_message.speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
max_serialized_size_TrafficLightsMessage(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: pathids
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

  // Member: starttime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: duration
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TrafficLightsMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dsrcmsg::msg::TrafficLightsMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TrafficLightsMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dsrcmsg::msg::TrafficLightsMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TrafficLightsMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dsrcmsg::msg::TrafficLightsMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TrafficLightsMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_TrafficLightsMessage(full_bounded, 0);
}

static message_type_support_callbacks_t _TrafficLightsMessage__callbacks = {
  "dsrcmsg::msg",
  "TrafficLightsMessage",
  _TrafficLightsMessage__cdr_serialize,
  _TrafficLightsMessage__cdr_deserialize,
  _TrafficLightsMessage__get_serialized_size,
  _TrafficLightsMessage__max_serialized_size
};

static rosidl_message_type_support_t _TrafficLightsMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TrafficLightsMessage__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dsrcmsg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dsrcmsg
const rosidl_message_type_support_t *
get_message_type_support_handle<dsrcmsg::msg::TrafficLightsMessage>()
{
  return &dsrcmsg::msg::typesupport_fastrtps_cpp::_TrafficLightsMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dsrcmsg, msg, TrafficLightsMessage)() {
  return &dsrcmsg::msg::typesupport_fastrtps_cpp::_TrafficLightsMessage__handle;
}

#ifdef __cplusplus
}
#endif
