// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dsrcmsg:msg/DSRCMessage.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__TRAITS_HPP_
#define DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__TRAITS_HPP_

#include "dsrcmsg/msg/detail/dsrc_message__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dsrcmsg::msg::DSRCMessage>()
{
  return "dsrcmsg::msg::DSRCMessage";
}

template<>
inline const char * name<dsrcmsg::msg::DSRCMessage>()
{
  return "dsrcmsg/msg/DSRCMessage";
}

template<>
struct has_fixed_size<dsrcmsg::msg::DSRCMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dsrcmsg::msg::DSRCMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dsrcmsg::msg::DSRCMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__TRAITS_HPP_
