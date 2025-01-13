// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dsrcmsg:msg/IntersectionBSM.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__BUILDER_HPP_
#define DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__BUILDER_HPP_

#include "dsrcmsg/msg/detail/intersection_bsm__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dsrcmsg
{

namespace msg
{

namespace builder
{

class Init_IntersectionBSM_timestamp
{
public:
  explicit Init_IntersectionBSM_timestamp(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  ::dsrcmsg::msg::IntersectionBSM timestamp(::dsrcmsg::msg::IntersectionBSM::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_stoppedtime
{
public:
  explicit Init_IntersectionBSM_stoppedtime(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_timestamp stoppedtime(::dsrcmsg::msg::IntersectionBSM::_stoppedtime_type arg)
  {
    msg_.stoppedtime = std::move(arg);
    return Init_IntersectionBSM_timestamp(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_priority
{
public:
  explicit Init_IntersectionBSM_priority(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_stoppedtime priority(::dsrcmsg::msg::IntersectionBSM::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_IntersectionBSM_stoppedtime(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_speed
{
public:
  explicit Init_IntersectionBSM_speed(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_priority speed(::dsrcmsg::msg::IntersectionBSM::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_IntersectionBSM_priority(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_vehicletype
{
public:
  explicit Init_IntersectionBSM_vehicletype(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_speed vehicletype(::dsrcmsg::msg::IntersectionBSM::_vehicletype_type arg)
  {
    msg_.vehicletype = std::move(arg);
    return Init_IntersectionBSM_speed(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_arrivaltime
{
public:
  explicit Init_IntersectionBSM_arrivaltime(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_vehicletype arrivaltime(::dsrcmsg::msg::IntersectionBSM::_arrivaltime_type arg)
  {
    msg_.arrivaltime = std::move(arg);
    return Init_IntersectionBSM_vehicletype(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_point
{
public:
  explicit Init_IntersectionBSM_point(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_arrivaltime point(::dsrcmsg::msg::IntersectionBSM::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_IntersectionBSM_arrivaltime(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_distfromstopline
{
public:
  explicit Init_IntersectionBSM_distfromstopline(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_point distfromstopline(::dsrcmsg::msg::IntersectionBSM::_distfromstopline_type arg)
  {
    msg_.distfromstopline = std::move(arg);
    return Init_IntersectionBSM_point(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_departleg
{
public:
  explicit Init_IntersectionBSM_departleg(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_distfromstopline departleg(::dsrcmsg::msg::IntersectionBSM::_departleg_type arg)
  {
    msg_.departleg = std::move(arg);
    return Init_IntersectionBSM_distfromstopline(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_approachleg
{
public:
  explicit Init_IntersectionBSM_approachleg(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_departleg approachleg(::dsrcmsg::msg::IntersectionBSM::_approachleg_type arg)
  {
    msg_.approachleg = std::move(arg);
    return Init_IntersectionBSM_departleg(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_junctionid
{
public:
  explicit Init_IntersectionBSM_junctionid(::dsrcmsg::msg::IntersectionBSM & msg)
  : msg_(msg)
  {}
  Init_IntersectionBSM_approachleg junctionid(::dsrcmsg::msg::IntersectionBSM::_junctionid_type arg)
  {
    msg_.junctionid = std::move(arg);
    return Init_IntersectionBSM_approachleg(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

class Init_IntersectionBSM_vehicleid
{
public:
  Init_IntersectionBSM_vehicleid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IntersectionBSM_junctionid vehicleid(::dsrcmsg::msg::IntersectionBSM::_vehicleid_type arg)
  {
    msg_.vehicleid = std::move(arg);
    return Init_IntersectionBSM_junctionid(msg_);
  }

private:
  ::dsrcmsg::msg::IntersectionBSM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dsrcmsg::msg::IntersectionBSM>()
{
  return dsrcmsg::msg::builder::Init_IntersectionBSM_vehicleid();
}

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__BUILDER_HPP_
