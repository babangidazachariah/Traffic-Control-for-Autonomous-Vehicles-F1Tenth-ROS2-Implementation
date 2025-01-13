// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dsrcmsg:msg/TrafficLightsMessage.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__TRAITS_HPP_
#define DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__TRAITS_HPP_

#include "dsrcmsg/msg/detail/traffic_lights_message__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dsrcmsg::msg::TrafficLightsMessage>()
{
  return "dsrcmsg::msg::TrafficLightsMessage";
}

template<>
inline const char * name<dsrcmsg::msg::TrafficLightsMessage>()
{
  return "dsrcmsg/msg/TrafficLightsMessage";
}

template<>
struct has_fixed_size<dsrcmsg::msg::TrafficLightsMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dsrcmsg::msg::TrafficLightsMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dsrcmsg::msg::TrafficLightsMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__TRAITS_HPP_
