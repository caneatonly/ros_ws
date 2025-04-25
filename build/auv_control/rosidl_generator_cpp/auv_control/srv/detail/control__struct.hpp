// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv_control:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef AUV_CONTROL__SRV__DETAIL__CONTROL__STRUCT_HPP_
#define AUV_CONTROL__SRV__DETAIL__CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__auv_control__srv__Control_Request __attribute__((deprecated))
#else
# define DEPRECATED__auv_control__srv__Control_Request __declspec(deprecated)
#endif

namespace auv_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Control_Request_
{
  using Type = Control_Request_<ContainerAllocator>;

  explicit Control_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit Control_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t POSITION =
    0u;
  static constexpr uint8_t VELOCITY =
    1u;
  static constexpr uint8_t DEPTH =
    2u;

  // pointer types
  using RawPtr =
    auv_control::srv::Control_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv_control::srv::Control_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv_control::srv::Control_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv_control::srv::Control_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv_control::srv::Control_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv_control::srv::Control_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv_control::srv::Control_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv_control::srv::Control_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv_control::srv::Control_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv_control::srv::Control_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv_control__srv__Control_Request
    std::shared_ptr<auv_control::srv::Control_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv_control__srv__Control_Request
    std::shared_ptr<auv_control::srv::Control_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Control_Request_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const Control_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Control_Request_

// alias to use template instance with default allocator
using Control_Request =
  auv_control::srv::Control_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Control_Request_<ContainerAllocator>::POSITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Control_Request_<ContainerAllocator>::VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Control_Request_<ContainerAllocator>::DEPTH;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace auv_control


#ifndef _WIN32
# define DEPRECATED__auv_control__srv__Control_Response __attribute__((deprecated))
#else
# define DEPRECATED__auv_control__srv__Control_Response __declspec(deprecated)
#endif

namespace auv_control
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Control_Response_
{
  using Type = Control_Response_<ContainerAllocator>;

  explicit Control_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Control_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    auv_control::srv::Control_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv_control::srv::Control_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv_control::srv::Control_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv_control::srv::Control_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv_control::srv::Control_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv_control::srv::Control_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv_control::srv::Control_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv_control::srv::Control_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv_control::srv::Control_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv_control::srv::Control_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv_control__srv__Control_Response
    std::shared_ptr<auv_control::srv::Control_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv_control__srv__Control_Response
    std::shared_ptr<auv_control::srv::Control_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Control_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Control_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Control_Response_

// alias to use template instance with default allocator
using Control_Response =
  auv_control::srv::Control_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace auv_control

namespace auv_control
{

namespace srv
{

struct Control
{
  using Request = auv_control::srv::Control_Request;
  using Response = auv_control::srv::Control_Response;
};

}  // namespace srv

}  // namespace auv_control

#endif  // AUV_CONTROL__SRV__DETAIL__CONTROL__STRUCT_HPP_
