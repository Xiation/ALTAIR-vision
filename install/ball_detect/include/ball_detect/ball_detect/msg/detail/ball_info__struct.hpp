// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ball_detect/msg/ball_info.hpp"


#ifndef BALL_DETECT__MSG__DETAIL__BALL_INFO__STRUCT_HPP_
#define BALL_DETECT__MSG__DETAIL__BALL_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ball_detect__msg__BallInfo __attribute__((deprecated))
#else
# define DEPRECATED__ball_detect__msg__BallInfo __declspec(deprecated)
#endif

namespace ball_detect
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BallInfo_
{
  using Type = BallInfo_<ContainerAllocator>;

  explicit BallInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
      this->x_pixel = 0l;
      this->y_pixel = 0l;
      this->radius_pixel = 0.0;
      this->confidence = 0.0;
    }
  }

  explicit BallInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
      this->x_pixel = 0l;
      this->y_pixel = 0l;
      this->radius_pixel = 0.0;
      this->confidence = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _distance_type =
    double;
  _distance_type distance;
  using _x_pixel_type =
    int32_t;
  _x_pixel_type x_pixel;
  using _y_pixel_type =
    int32_t;
  _y_pixel_type y_pixel;
  using _radius_pixel_type =
    double;
  _radius_pixel_type radius_pixel;
  using _confidence_type =
    double;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__x_pixel(
    const int32_t & _arg)
  {
    this->x_pixel = _arg;
    return *this;
  }
  Type & set__y_pixel(
    const int32_t & _arg)
  {
    this->y_pixel = _arg;
    return *this;
  }
  Type & set__radius_pixel(
    const double & _arg)
  {
    this->radius_pixel = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ball_detect::msg::BallInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const ball_detect::msg::BallInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ball_detect::msg::BallInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ball_detect::msg::BallInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ball_detect::msg::BallInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ball_detect::msg::BallInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ball_detect::msg::BallInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ball_detect::msg::BallInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ball_detect::msg::BallInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ball_detect::msg::BallInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ball_detect__msg__BallInfo
    std::shared_ptr<ball_detect::msg::BallInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ball_detect__msg__BallInfo
    std::shared_ptr<ball_detect::msg::BallInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BallInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->x_pixel != other.x_pixel) {
      return false;
    }
    if (this->y_pixel != other.y_pixel) {
      return false;
    }
    if (this->radius_pixel != other.radius_pixel) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const BallInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BallInfo_

// alias to use template instance with default allocator
using BallInfo =
  ball_detect::msg::BallInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ball_detect

#endif  // BALL_DETECT__MSG__DETAIL__BALL_INFO__STRUCT_HPP_
