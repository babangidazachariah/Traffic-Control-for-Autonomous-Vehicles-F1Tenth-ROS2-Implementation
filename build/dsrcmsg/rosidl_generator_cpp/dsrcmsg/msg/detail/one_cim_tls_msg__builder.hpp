// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dsrcmsg:msg/OneCIMTlsMsg.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__BUILDER_HPP_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__BUILDER_HPP_

#include "dsrcmsg/msg/detail/one_cim_tls_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dsrcmsg
{

namespace msg
{

namespace builder
{

class Init_OneCIMTlsMsg_speed
{
public:
  explicit Init_OneCIMTlsMsg_speed(::dsrcmsg::msg::OneCIMTlsMsg & msg)
  : msg_(msg)
  {}
  ::dsrcmsg::msg::OneCIMTlsMsg speed(::dsrcmsg::msg::OneCIMTlsMsg::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

class Init_OneCIMTlsMsg_departpoints
{
public:
  explicit Init_OneCIMTlsMsg_departpoints(::dsrcmsg::msg::OneCIMTlsMsg & msg)
  : msg_(msg)
  {}
  Init_OneCIMTlsMsg_speed departpoints(::dsrcmsg::msg::OneCIMTlsMsg::_departpoints_type arg)
  {
    msg_.departpoints = std::move(arg);
    return Init_OneCIMTlsMsg_speed(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

class Init_OneCIMTlsMsg_approachpoints
{
public:
  explicit Init_OneCIMTlsMsg_approachpoints(::dsrcmsg::msg::OneCIMTlsMsg & msg)
  : msg_(msg)
  {}
  Init_OneCIMTlsMsg_departpoints approachpoints(::dsrcmsg::msg::OneCIMTlsMsg::_approachpoints_type arg)
  {
    msg_.approachpoints = std::move(arg);
    return Init_OneCIMTlsMsg_departpoints(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

class Init_OneCIMTlsMsg_duration
{
public:
  explicit Init_OneCIMTlsMsg_duration(::dsrcmsg::msg::OneCIMTlsMsg & msg)
  : msg_(msg)
  {}
  Init_OneCIMTlsMsg_approachpoints duration(::dsrcmsg::msg::OneCIMTlsMsg::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_OneCIMTlsMsg_approachpoints(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

class Init_OneCIMTlsMsg_starttime
{
public:
  explicit Init_OneCIMTlsMsg_starttime(::dsrcmsg::msg::OneCIMTlsMsg & msg)
  : msg_(msg)
  {}
  Init_OneCIMTlsMsg_duration starttime(::dsrcmsg::msg::OneCIMTlsMsg::_starttime_type arg)
  {
    msg_.starttime = std::move(arg);
    return Init_OneCIMTlsMsg_duration(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

class Init_OneCIMTlsMsg_pathids
{
public:
  explicit Init_OneCIMTlsMsg_pathids(::dsrcmsg::msg::OneCIMTlsMsg & msg)
  : msg_(msg)
  {}
  Init_OneCIMTlsMsg_starttime pathids(::dsrcmsg::msg::OneCIMTlsMsg::_pathids_type arg)
  {
    msg_.pathids = std::move(arg);
    return Init_OneCIMTlsMsg_starttime(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

class Init_OneCIMTlsMsg_vehicleid
{
public:
  explicit Init_OneCIMTlsMsg_vehicleid(::dsrcmsg::msg::OneCIMTlsMsg & msg)
  : msg_(msg)
  {}
  Init_OneCIMTlsMsg_pathids vehicleid(::dsrcmsg::msg::OneCIMTlsMsg::_vehicleid_type arg)
  {
    msg_.vehicleid = std::move(arg);
    return Init_OneCIMTlsMsg_pathids(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

class Init_OneCIMTlsMsg_junctionid
{
public:
  Init_OneCIMTlsMsg_junctionid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OneCIMTlsMsg_vehicleid junctionid(::dsrcmsg::msg::OneCIMTlsMsg::_junctionid_type arg)
  {
    msg_.junctionid = std::move(arg);
    return Init_OneCIMTlsMsg_vehicleid(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMTlsMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dsrcmsg::msg::OneCIMTlsMsg>()
{
  return dsrcmsg::msg::builder::Init_OneCIMTlsMsg_junctionid();
}

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__BUILDER_HPP_
