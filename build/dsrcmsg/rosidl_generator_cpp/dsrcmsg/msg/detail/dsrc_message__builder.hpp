// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dsrcmsg:msg/DSRCMessage.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__BUILDER_HPP_
#define DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__BUILDER_HPP_

#include "dsrcmsg/msg/detail/dsrc_message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dsrcmsg
{

namespace msg
{

namespace builder
{

class Init_DSRCMessage_speed
{
public:
  explicit Init_DSRCMessage_speed(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  ::dsrcmsg::msg::DSRCMessage speed(::dsrcmsg::msg::DSRCMessage::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_point
{
public:
  explicit Init_DSRCMessage_point(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  Init_DSRCMessage_speed point(::dsrcmsg::msg::DSRCMessage::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_DSRCMessage_speed(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_distfromstopline
{
public:
  explicit Init_DSRCMessage_distfromstopline(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  Init_DSRCMessage_point distfromstopline(::dsrcmsg::msg::DSRCMessage::_distfromstopline_type arg)
  {
    msg_.distfromstopline = std::move(arg);
    return Init_DSRCMessage_point(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_disttostopline
{
public:
  explicit Init_DSRCMessage_disttostopline(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  Init_DSRCMessage_distfromstopline disttostopline(::dsrcmsg::msg::DSRCMessage::_disttostopline_type arg)
  {
    msg_.disttostopline = std::move(arg);
    return Init_DSRCMessage_distfromstopline(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_departureleg
{
public:
  explicit Init_DSRCMessage_departureleg(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  Init_DSRCMessage_disttostopline departureleg(::dsrcmsg::msg::DSRCMessage::_departureleg_type arg)
  {
    msg_.departureleg = std::move(arg);
    return Init_DSRCMessage_disttostopline(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_approachleg
{
public:
  explicit Init_DSRCMessage_approachleg(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  Init_DSRCMessage_departureleg approachleg(::dsrcmsg::msg::DSRCMessage::_approachleg_type arg)
  {
    msg_.approachleg = std::move(arg);
    return Init_DSRCMessage_departureleg(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_currenttime
{
public:
  explicit Init_DSRCMessage_currenttime(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  Init_DSRCMessage_approachleg currenttime(::dsrcmsg::msg::DSRCMessage::_currenttime_type arg)
  {
    msg_.currenttime = std::move(arg);
    return Init_DSRCMessage_approachleg(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_initialtime
{
public:
  explicit Init_DSRCMessage_initialtime(::dsrcmsg::msg::DSRCMessage & msg)
  : msg_(msg)
  {}
  Init_DSRCMessage_currenttime initialtime(::dsrcmsg::msg::DSRCMessage::_initialtime_type arg)
  {
    msg_.initialtime = std::move(arg);
    return Init_DSRCMessage_currenttime(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

class Init_DSRCMessage_vehicleid
{
public:
  Init_DSRCMessage_vehicleid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DSRCMessage_initialtime vehicleid(::dsrcmsg::msg::DSRCMessage::_vehicleid_type arg)
  {
    msg_.vehicleid = std::move(arg);
    return Init_DSRCMessage_initialtime(msg_);
  }

private:
  ::dsrcmsg::msg::DSRCMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dsrcmsg::msg::DSRCMessage>()
{
  return dsrcmsg::msg::builder::Init_DSRCMessage_vehicleid();
}

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__BUILDER_HPP_
