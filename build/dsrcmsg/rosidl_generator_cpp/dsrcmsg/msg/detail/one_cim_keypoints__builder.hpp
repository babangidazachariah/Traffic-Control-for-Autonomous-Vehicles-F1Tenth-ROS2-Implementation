// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__BUILDER_HPP_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__BUILDER_HPP_

#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dsrcmsg
{

namespace msg
{

namespace builder
{

class Init_OneCIMKeypoints_y
{
public:
  explicit Init_OneCIMKeypoints_y(::dsrcmsg::msg::OneCIMKeypoints & msg)
  : msg_(msg)
  {}
  ::dsrcmsg::msg::OneCIMKeypoints y(::dsrcmsg::msg::OneCIMKeypoints::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMKeypoints msg_;
};

class Init_OneCIMKeypoints_x
{
public:
  explicit Init_OneCIMKeypoints_x(::dsrcmsg::msg::OneCIMKeypoints & msg)
  : msg_(msg)
  {}
  Init_OneCIMKeypoints_y x(::dsrcmsg::msg::OneCIMKeypoints::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_OneCIMKeypoints_y(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMKeypoints msg_;
};

class Init_OneCIMKeypoints_key
{
public:
  Init_OneCIMKeypoints_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OneCIMKeypoints_x key(::dsrcmsg::msg::OneCIMKeypoints::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_OneCIMKeypoints_x(msg_);
  }

private:
  ::dsrcmsg::msg::OneCIMKeypoints msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dsrcmsg::msg::OneCIMKeypoints>()
{
  return dsrcmsg::msg::builder::Init_OneCIMKeypoints_key();
}

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__BUILDER_HPP_
