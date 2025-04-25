// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv_control:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef AUV_CONTROL__SRV__DETAIL__CONTROL__BUILDER_HPP_
#define AUV_CONTROL__SRV__DETAIL__CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "auv_control/srv/detail/control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace auv_control
{

namespace srv
{

namespace builder
{

class Init_Control_Request_mode
{
public:
  Init_Control_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::auv_control::srv::Control_Request mode(::auv_control::srv::Control_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv_control::srv::Control_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv_control::srv::Control_Request>()
{
  return auv_control::srv::builder::Init_Control_Request_mode();
}

}  // namespace auv_control


namespace auv_control
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv_control::srv::Control_Response>()
{
  return ::auv_control::srv::Control_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace auv_control

#endif  // AUV_CONTROL__SRV__DETAIL__CONTROL__BUILDER_HPP_
