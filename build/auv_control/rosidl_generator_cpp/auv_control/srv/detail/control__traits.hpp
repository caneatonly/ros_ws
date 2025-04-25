// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auv_control:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef AUV_CONTROL__SRV__DETAIL__CONTROL__TRAITS_HPP_
#define AUV_CONTROL__SRV__DETAIL__CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "auv_control/srv/detail/control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace auv_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const Control_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Control_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Control_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace auv_control

namespace rosidl_generator_traits
{

[[deprecated("use auv_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const auv_control::srv::Control_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  auv_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auv_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const auv_control::srv::Control_Request & msg)
{
  return auv_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<auv_control::srv::Control_Request>()
{
  return "auv_control::srv::Control_Request";
}

template<>
inline const char * name<auv_control::srv::Control_Request>()
{
  return "auv_control/srv/Control_Request";
}

template<>
struct has_fixed_size<auv_control::srv::Control_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<auv_control::srv::Control_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<auv_control::srv::Control_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace auv_control
{

namespace srv
{

inline void to_flow_style_yaml(
  const Control_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Control_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Control_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace auv_control

namespace rosidl_generator_traits
{

[[deprecated("use auv_control::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const auv_control::srv::Control_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  auv_control::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use auv_control::srv::to_yaml() instead")]]
inline std::string to_yaml(const auv_control::srv::Control_Response & msg)
{
  return auv_control::srv::to_yaml(msg);
}

template<>
inline const char * data_type<auv_control::srv::Control_Response>()
{
  return "auv_control::srv::Control_Response";
}

template<>
inline const char * name<auv_control::srv::Control_Response>()
{
  return "auv_control/srv/Control_Response";
}

template<>
struct has_fixed_size<auv_control::srv::Control_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<auv_control::srv::Control_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<auv_control::srv::Control_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auv_control::srv::Control>()
{
  return "auv_control::srv::Control";
}

template<>
inline const char * name<auv_control::srv::Control>()
{
  return "auv_control/srv/Control";
}

template<>
struct has_fixed_size<auv_control::srv::Control>
  : std::integral_constant<
    bool,
    has_fixed_size<auv_control::srv::Control_Request>::value &&
    has_fixed_size<auv_control::srv::Control_Response>::value
  >
{
};

template<>
struct has_bounded_size<auv_control::srv::Control>
  : std::integral_constant<
    bool,
    has_bounded_size<auv_control::srv::Control_Request>::value &&
    has_bounded_size<auv_control::srv::Control_Response>::value
  >
{
};

template<>
struct is_service<auv_control::srv::Control>
  : std::true_type
{
};

template<>
struct is_service_request<auv_control::srv::Control_Request>
  : std::true_type
{
};

template<>
struct is_service_response<auv_control::srv::Control_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUV_CONTROL__SRV__DETAIL__CONTROL__TRAITS_HPP_
