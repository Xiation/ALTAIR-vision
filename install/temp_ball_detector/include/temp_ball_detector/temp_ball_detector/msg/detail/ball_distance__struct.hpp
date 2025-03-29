// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "temp_ball_detector/msg/ball_distance.hpp"


#ifndef TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__STRUCT_HPP_
#define TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__temp_ball_detector__msg__BallDistance __attribute__((deprecated))
#else
# define DEPRECATED__temp_ball_detector__msg__BallDistance __declspec(deprecated)
#endif

namespace temp_ball_detector
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BallDistance_
{
  using Type = BallDistance_<ContainerAllocator>;

  explicit BallDistance_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ball_ada_cok = false;
      this->jaraknya_jing = 0.0;
    }
  }

  explicit BallDistance_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ball_ada_cok = false;
      this->jaraknya_jing = 0.0;
    }
  }

  // field types and members
  using _ball_ada_cok_type =
    bool;
  _ball_ada_cok_type ball_ada_cok;
  using _jaraknya_jing_type =
    double;
  _jaraknya_jing_type jaraknya_jing;

  // setters for named parameter idiom
  Type & set__ball_ada_cok(
    const bool & _arg)
  {
    this->ball_ada_cok = _arg;
    return *this;
  }
  Type & set__jaraknya_jing(
    const double & _arg)
  {
    this->jaraknya_jing = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    temp_ball_detector::msg::BallDistance_<ContainerAllocator> *;
  using ConstRawPtr =
    const temp_ball_detector::msg::BallDistance_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      temp_ball_detector::msg::BallDistance_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      temp_ball_detector::msg::BallDistance_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__temp_ball_detector__msg__BallDistance
    std::shared_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__temp_ball_detector__msg__BallDistance
    std::shared_ptr<temp_ball_detector::msg::BallDistance_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BallDistance_ & other) const
  {
    if (this->ball_ada_cok != other.ball_ada_cok) {
      return false;
    }
    if (this->jaraknya_jing != other.jaraknya_jing) {
      return false;
    }
    return true;
  }
  bool operator!=(const BallDistance_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BallDistance_

// alias to use template instance with default allocator
using BallDistance =
  temp_ball_detector::msg::BallDistance_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace temp_ball_detector

#endif  // TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__STRUCT_HPP_
