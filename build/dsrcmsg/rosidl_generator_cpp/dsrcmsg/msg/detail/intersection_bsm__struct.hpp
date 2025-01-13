// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dsrcmsg:msg/IntersectionBSM.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__STRUCT_HPP_
#define DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__dsrcmsg__msg__IntersectionBSM __attribute__((deprecated))
#else
# define DEPRECATED__dsrcmsg__msg__IntersectionBSM __declspec(deprecated)
#endif

namespace dsrcmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IntersectionBSM_
{
  using Type = IntersectionBSM_<ContainerAllocator>;

  explicit IntersectionBSM_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicleid = "";
      this->junctionid = "";
      this->approachleg = "";
      this->departleg = "";
      this->distfromstopline = 0.0;
      this->arrivaltime = 0.0;
      this->vehicletype = 0l;
      this->speed = 0.0;
      this->priority = 0l;
      this->stoppedtime = 0.0;
      this->timestamp = 0.0;
    }
  }

  explicit IntersectionBSM_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vehicleid(_alloc),
    junctionid(_alloc),
    approachleg(_alloc),
    departleg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicleid = "";
      this->junctionid = "";
      this->approachleg = "";
      this->departleg = "";
      this->distfromstopline = 0.0;
      this->arrivaltime = 0.0;
      this->vehicletype = 0l;
      this->speed = 0.0;
      this->priority = 0l;
      this->stoppedtime = 0.0;
      this->timestamp = 0.0;
    }
  }

  // field types and members
  using _vehicleid_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _vehicleid_type vehicleid;
  using _junctionid_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _junctionid_type junctionid;
  using _approachleg_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _approachleg_type approachleg;
  using _departleg_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _departleg_type departleg;
  using _distfromstopline_type =
    double;
  _distfromstopline_type distfromstopline;
  using _point_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _point_type point;
  using _arrivaltime_type =
    double;
  _arrivaltime_type arrivaltime;
  using _vehicletype_type =
    int32_t;
  _vehicletype_type vehicletype;
  using _speed_type =
    double;
  _speed_type speed;
  using _priority_type =
    int32_t;
  _priority_type priority;
  using _stoppedtime_type =
    double;
  _stoppedtime_type stoppedtime;
  using _timestamp_type =
    double;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__vehicleid(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->vehicleid = _arg;
    return *this;
  }
  Type & set__junctionid(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->junctionid = _arg;
    return *this;
  }
  Type & set__approachleg(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->approachleg = _arg;
    return *this;
  }
  Type & set__departleg(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->departleg = _arg;
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
  Type & set__arrivaltime(
    const double & _arg)
  {
    this->arrivaltime = _arg;
    return *this;
  }
  Type & set__vehicletype(
    const int32_t & _arg)
  {
    this->vehicletype = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__priority(
    const int32_t & _arg)
  {
    this->priority = _arg;
    return *this;
  }
  Type & set__stoppedtime(
    const double & _arg)
  {
    this->stoppedtime = _arg;
    return *this;
  }
  Type & set__timestamp(
    const double & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dsrcmsg::msg::IntersectionBSM_<ContainerAllocator> *;
  using ConstRawPtr =
    const dsrcmsg::msg::IntersectionBSM_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::IntersectionBSM_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::IntersectionBSM_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dsrcmsg__msg__IntersectionBSM
    std::shared_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dsrcmsg__msg__IntersectionBSM
    std::shared_ptr<dsrcmsg::msg::IntersectionBSM_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IntersectionBSM_ & other) const
  {
    if (this->vehicleid != other.vehicleid) {
      return false;
    }
    if (this->junctionid != other.junctionid) {
      return false;
    }
    if (this->approachleg != other.approachleg) {
      return false;
    }
    if (this->departleg != other.departleg) {
      return false;
    }
    if (this->distfromstopline != other.distfromstopline) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    if (this->arrivaltime != other.arrivaltime) {
      return false;
    }
    if (this->vehicletype != other.vehicletype) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->priority != other.priority) {
      return false;
    }
    if (this->stoppedtime != other.stoppedtime) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const IntersectionBSM_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IntersectionBSM_

// alias to use template instance with default allocator
using IntersectionBSM =
  dsrcmsg::msg::IntersectionBSM_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__INTERSECTION_BSM__STRUCT_HPP_
