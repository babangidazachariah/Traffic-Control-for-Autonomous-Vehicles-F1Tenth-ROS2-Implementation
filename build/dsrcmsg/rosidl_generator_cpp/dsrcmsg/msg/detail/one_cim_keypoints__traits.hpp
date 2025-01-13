// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__TRAITS_HPP_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__TRAITS_HPP_

#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dsrcmsg::msg::OneCIMKeypoints>()
{
  return "dsrcmsg::msg::OneCIMKeypoints";
}

template<>
inline const char * name<dsrcmsg::msg::OneCIMKeypoints>()
{
  return "dsrcmsg/msg/OneCIMKeypoints";
}

template<>
struct has_fixed_size<dsrcmsg::msg::OneCIMKeypoints>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dsrcmsg::msg::OneCIMKeypoints>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dsrcmsg::msg::OneCIMKeypoints>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__TRAITS_HPP_
