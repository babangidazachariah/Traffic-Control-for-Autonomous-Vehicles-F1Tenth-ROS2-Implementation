// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__STRUCT_HPP_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__dsrcmsg__msg__OneCIMKeypoints __attribute__((deprecated))
#else
# define DEPRECATED__dsrcmsg__msg__OneCIMKeypoints __declspec(deprecated)
#endif

namespace dsrcmsg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OneCIMKeypoints_
{
  using Type = OneCIMKeypoints_<ContainerAllocator>;

  explicit OneCIMKeypoints_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit OneCIMKeypoints_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : key(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->key = "";
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _key_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _key_type key;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__key(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->key = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator> *;
  using ConstRawPtr =
    const dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dsrcmsg__msg__OneCIMKeypoints
    std::shared_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dsrcmsg__msg__OneCIMKeypoints
    std::shared_ptr<dsrcmsg::msg::OneCIMKeypoints_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OneCIMKeypoints_ & other) const
  {
    if (this->key != other.key) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const OneCIMKeypoints_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OneCIMKeypoints_

// alias to use template instance with default allocator
using OneCIMKeypoints =
  dsrcmsg::msg::OneCIMKeypoints_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dsrcmsg

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__STRUCT_HPP_
