// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dsrcmsg:msg/IntersectionBSM.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/intersection_bsm__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dsrcmsg/msg/detail/intersection_bsm__struct.hpp"

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
  const dsrcmsg::msg::IntersectionBSM & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: vehicleid
  cdr << ros_message.vehicleid;
  // Member: junctionid
  cdr << ros_message.junctionid;
  // Member: approachleg
  cdr << ros_message.approachleg;
  // Member: departleg
  cdr << ros_message.departleg;
  // Member: distfromstopline
  cdr << ros_message.distfromstopline;
  // Member: point
  {
    cdr << ros_message.point;
  }
  // Member: arrivaltime
  cdr << ros_message.arrivaltime;
  // Member: vehicletype
  cdr << ros_message.vehicletype;
  // Member: speed
  cdr << ros_message.speed;
  // Member: priority
  cdr << ros_message.priority;
  // Member: stoppedtime
  cdr << ros_message.stoppedtime;
  // Member: timestamp
  cdr << ros_message.timestamp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dsrcmsg::msg::IntersectionBSM & ros_message)
{
  // Member: vehicleid
  cdr >> ros_message.vehicleid;

  // Member: junctionid
  cdr >> ros_message.junctionid;

  // Member: approachleg
  cdr >> ros_message.approachleg;

  // Member: departleg
  cdr >> ros_message.departleg;

  // Member: distfromstopline
  cdr >> ros_message.distfromstopline;

  // Member: point
  {
    cdr >> ros_message.point;
  }

  // Member: arrivaltime
  cdr >> ros_message.arrivaltime;

  // Member: vehicletype
  cdr >> ros_message.vehicletype;

  // Member: speed
  cdr >> ros_message.speed;

  // Member: priority
  cdr >> ros_message.priority;

  // Member: stoppedtime
  cdr >> ros_message.stoppedtime;

  // Member: timestamp
  cdr >> ros_message.timestamp;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
get_serialized_size(
  const dsrcmsg::msg::IntersectionBSM & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: vehicleid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.vehicleid.size() + 1);
  // Member: junctionid
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.junctionid.size() + 1);
  // Member: approachleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.approachleg.size() + 1);
  // Member: departleg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.departleg.size() + 1);
  // Member: distfromstopline
  {
    size_t item_size = sizeof(ros_message.distfromstopline);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: point
  {
    size_t array_size = ros_message.point.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.point[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: arrivaltime
  {
    size_t item_size = sizeof(ros_message.arrivaltime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vehicletype
  {
    size_t item_size = sizeof(ros_message.vehicletype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed
  {
    size_t item_size = sizeof(ros_message.speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: priority
  {
    size_t item_size = sizeof(ros_message.priority);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stoppedtime
  {
    size_t item_size = sizeof(ros_message.stoppedtime);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: timestamp
  {
    size_t item_size = sizeof(ros_message.timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
max_serialized_size_IntersectionBSM(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: vehicleid
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: junctionid
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: approachleg
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: departleg
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: distfromstopline
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: point
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: arrivaltime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: vehicletype
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: priority
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: stoppedtime
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: timestamp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _IntersectionBSM__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dsrcmsg::msg::IntersectionBSM *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _IntersectionBSM__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dsrcmsg::msg::IntersectionBSM *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _IntersectionBSM__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dsrcmsg::msg::IntersectionBSM *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _IntersectionBSM__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_IntersectionBSM(full_bounded, 0);
}

static message_type_support_callbacks_t _IntersectionBSM__callbacks = {
  "dsrcmsg::msg",
  "IntersectionBSM",
  _IntersectionBSM__cdr_serialize,
  _IntersectionBSM__cdr_deserialize,
  _IntersectionBSM__get_serialized_size,
  _IntersectionBSM__max_serialized_size
};

static rosidl_message_type_support_t _IntersectionBSM__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_IntersectionBSM__callbacks,
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
get_message_type_support_handle<dsrcmsg::msg::IntersectionBSM>()
{
  return &dsrcmsg::msg::typesupport_fastrtps_cpp::_IntersectionBSM__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dsrcmsg, msg, IntersectionBSM)() {
  return &dsrcmsg::msg::typesupport_fastrtps_cpp::_IntersectionBSM__handle;
}

#ifdef __cplusplus
}
#endif
