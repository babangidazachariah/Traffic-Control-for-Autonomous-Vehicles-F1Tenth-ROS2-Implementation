// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dsrcmsg:msg/TrafficLightsMessage.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__BUILDER_HPP_
#define DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__BUILDER_HPP_

#include "dsrcmsg/msg/detail/traffic_lights_message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dsrcmsg
{

namespace msg
{

namespace builder
{

class Init_TrafficLightsMessage_speed
{
public:
  explicit Init_TrafficLightsMessage_speed(::dsrcmsg::msg::TrafficLightsMessage & msg)
  : msg_(msg)
  {}
  ::dsrcmsg::msg::TrafficLightsMessage speed(::dsrcmsg::msg::TrafficLightsMessage::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dsrcmsg::msg::TrafficLightsMessage msg_;
};

class Init_TrafficLightsMessage_duration
{
public:
  explicit Init_TrafficLightsMessage_duration(::dsrcmsg::msg::TrafficLightsMessage & msg)
  : msg_(msg)
  {}
  Init_TrafficLightsMessage_speed duration(::dsrcmsg::msg::TrafficLightsMessage::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_TrafficLightsMessage_speed(msg_);
  }

private:
  ::dsrcmsg::msg::TrafficLightsMessage msg_;
};

class Init_TrafficLightsMessage_starttime
{
public:
  explicit Init_TrafficLightsMessage_starttime(::dsrcmsg::msg::TrafficLightsMessage & msg)
  : msg_(msg)
  {}
  Init_TrafficLightsMessage_duration starttime(::dsrcmsg::msg::TrafficLightsMessage::_starttime_type arg)
  {
    msg_.starttime = std::move(arg);
    return Init_TrafficLightsMessage_duration(msg_);
  }

private:
  ::dsrcmsg::msg::TrafficLightsMessage msg_;
};

class Init_TrafficLightsMessage_pathids
{
public:
  Init_TrafficLightsMessage_pathids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrafficLightsMessage_starttime pathids(::dsrcmsg::msg::TrafficLightsMessage::_pathids_type arg)
  {
    msg_.pathids = std::move(arg);
    return Init_TrafficLightsMessage_starttime(msg_);
  }

private:
  ::dsrcmsg::msg::TrafficLightsMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dsrcmsg::msg::TrafficLightsMessage>()
{
  return dsrcmsg::msg::builder::Init_TrafficLightsMessage_pathids();
}

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__TRAFFIC_LIGHTS_MESSAGE__BUILDER_HPP_
