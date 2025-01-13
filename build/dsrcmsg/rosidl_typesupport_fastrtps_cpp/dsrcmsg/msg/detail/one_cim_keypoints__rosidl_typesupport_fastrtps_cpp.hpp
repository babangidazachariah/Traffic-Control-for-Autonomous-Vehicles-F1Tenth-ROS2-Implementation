// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "dsrcmsg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace dsrcmsg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
cdr_serialize(
  const dsrcmsg::msg::OneCIMKeypoints & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dsrcmsg::msg::OneCIMKeypoints & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
get_serialized_size(
  const dsrcmsg::msg::OneCIMKeypoints & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
max_serialized_size_OneCIMKeypoints(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dsrcmsg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dsrcmsg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dsrcmsg, msg, OneCIMKeypoints)();

#ifdef __cplusplus
}
#endif

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
