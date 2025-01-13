// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dsrcmsg:msg/OneCIMTlsMsg.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__STRUCT_HPP_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'approachpoints'
// Member 'departpoints'
#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dsrcmsg__msg__OneCIMTlsMsg __attribute__((deprecated))
#else
# define DEPRECATED__dsrcmsg__msg__OneCIMTlsMsg __declspec(deprecated)
#endif

namespace dsrcmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OneCIMTlsMsg_
{
  using Type = OneCIMTlsMsg_<ContainerAllocator>;

  explicit OneCIMTlsMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->junctionid = "";
      this->vehicleid = "";
      this->starttime = 0.0;
      this->duration = 0.0;
      this->speed = 0.0;
    }
  }

  explicit OneCIMTlsMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : junctionid(_alloc),
    vehicleid(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->junctionid = "";
      this->vehicleid = "";
      this->starttime = 0.0;
      this->duration = 0.0;
      this->speed = 0.0;
    }
  }

  // field types and members
  using _junctionid_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _junctionid_type junctionid;
  using _vehicleid_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _vehicleid_type vehicleid;
  using _pathids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _pathids_type pathids;
  using _starttime_type =
    double;
  _starttime_type starttime;
  using _duration_type =
    double;
  _duration_type duration;
  using _approachpoints_type =
    std::vector<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>, typename ContainerAllocator::template rebind<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>::other>;
  _approachpoints_type approachpoints;
  using _departpoints_type =
    std::vector<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>, typename ContainerAllocator::template rebind<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>::other>;
  _departpoints_type departpoints;
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__junctionid(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->junctionid = _arg;
    return *this;
  }
  Type & set__vehicleid(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->vehicleid = _arg;
    return *this;
  }
  Type & set__pathids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->pathids = _arg;
    return *this;
  }
  Type & set__starttime(
    const double & _arg)
  {
    this->starttime = _arg;
    return *this;
  }
  Type & set__duration(
    const double & _arg)
  {
    this->duration = _arg;
    return *this;
  }
  Type & set__approachpoints(
    const std::vector<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>, typename ContainerAllocator::template rebind<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>::other> & _arg)
  {
    this->approachpoints = _arg;
    return *this;
  }
  Type & set__departpoints(
    const std::vector<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>, typename ContainerAllocator::template rebind<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>::other> & _arg)
  {
    this->departpoints = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dsrcmsg__msg__OneCIMTlsMsg
    std::shared_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dsrcmsg__msg__OneCIMTlsMsg
    std::shared_ptr<dsrcmsg::msg::OneCIMTlsMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OneCIMTlsMsg_ & other) const
  {
    if (this->junctionid != other.junctionid) {
      return false;
    }
    if (this->vehicleid != other.vehicleid) {
      return false;
    }
    if (this->pathids != other.pathids) {
      return false;
    }
    if (this->starttime != other.starttime) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    if (this->approachpoints != other.approachpoints) {
      return false;
    }
    if (this->departpoints != other.departpoints) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const OneCIMTlsMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OneCIMTlsMsg_

// alias to use template instance with default allocator
using OneCIMTlsMsg =
  dsrcmsg::msg::OneCIMTlsMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_TLS_MSG__STRUCT_HPP_
