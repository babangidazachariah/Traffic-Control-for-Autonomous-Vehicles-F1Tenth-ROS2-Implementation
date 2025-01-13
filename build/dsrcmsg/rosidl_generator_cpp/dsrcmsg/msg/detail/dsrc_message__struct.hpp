// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dsrcmsg:msg/DSRCMessage.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__STRUCT_HPP_
#define DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__dsrcmsg__msg__DSRCMessage __attribute__((deprecated))
#else
# define DEPRECATED__dsrcmsg__msg__DSRCMessage __declspec(deprecated)
#endif

namespace dsrcmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DSRCMessage_
{
  using Type = DSRCMessage_<ContainerAllocator>;

  explicit DSRCMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicleid = "";
      this->initialtime = 0.0;
      this->currenttime = 0.0;
      this->approachleg = "";
      this->departureleg = "";
      this->disttostopline = 0.0;
      this->distfromstopline = 0.0;
      this->speed = 0.0;
    }
  }

  explicit DSRCMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vehicleid(_alloc),
    approachleg(_alloc),
    departureleg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicleid = "";
      this->initialtime = 0.0;
      this->currenttime = 0.0;
      this->approachleg = "";
      this->departureleg = "";
      this->disttostopline = 0.0;
      this->distfromstopline = 0.0;
      this->speed = 0.0;
    }
  }

  // field types and members
  using _vehicleid_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _vehicleid_type vehicleid;
  using _initialtime_type =
    double;
  _initialtime_type initialtime;
  using _currenttime_type =
    double;
  _currenttime_type currenttime;
  using _approachleg_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _approachleg_type approachleg;
  using _departureleg_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _departureleg_type departureleg;
  using _disttostopline_type =
    double;
  _disttostopline_type disttostopline;
  using _distfromstopline_type =
    double;
  _distfromstopline_type distfromstopline;
  using _point_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _point_type point;
  using _speed_type =
    double;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__vehicleid(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->vehicleid = _arg;
    return *this;
  }
  Type & set__initialtime(
    const double & _arg)
  {
    this->initialtime = _arg;
    return *this;
  }
  Type & set__currenttime(
    const double & _arg)
  {
    this->currenttime = _arg;
    return *this;
  }
  Type & set__approachleg(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->approachleg = _arg;
    return *this;
  }
  Type & set__departureleg(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->departureleg = _arg;
    return *this;
  }
  Type & set__disttostopline(
    const double & _arg)
  {
    this->disttostopline = _arg;
    return *this;
  }
  Type & set__distfromstopline(
    const double & _arg)
  {
    this->distfromstopline = _arg;
    return *this;
  }
  Type & set__point(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->point = _arg;
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
    dsrcmsg::msg::DSRCMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const dsrcmsg::msg::DSRCMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::DSRCMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::DSRCMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dsrcmsg__msg__DSRCMessage
    std::shared_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dsrcmsg__msg__DSRCMessage
    std::shared_ptr<dsrcmsg::msg::DSRCMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DSRCMessage_ & other) const
  {
    if (this->vehicleid != other.vehicleid) {
      return false;
    }
    if (this->initialtime != other.initialtime) {
      return false;
    }
    if (this->currenttime != other.currenttime) {
      return false;
    }
    if (this->approachleg != other.approachleg) {
      return false;
    }
    if (this->departureleg != other.departureleg) {
      return false;
    }
    if (this->disttostopline != other.disttostopline) {
      return false;
    }
    if (this->distfromstopline != other.distfromstopline) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const DSRCMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DSRCMessage_

// alias to use template instance with default allocator
using DSRCMessage =
  dsrcmsg::msg::DSRCMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__DSRC_MESSAGE__STRUCT_HPP_
