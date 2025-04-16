// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from offboard_control_interfaces:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__TRAITS_HPP_
#define OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "offboard_control_interfaces/msg/detail/user_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace offboard_control_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const UserCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << ", ";
  }

  // member: use_xy
  {
    out << "use_xy: ";
    rosidl_generator_traits::value_to_yaml(msg.use_xy, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: lon
  {
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << ", ";
  }

  // member: lat
  {
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UserCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }

  // member: use_xy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_xy: ";
    rosidl_generator_traits::value_to_yaml(msg.use_xy, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << "\n";
  }

  // member: lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UserCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace offboard_control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use offboard_control_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const offboard_control_interfaces::msg::UserCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  offboard_control_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use offboard_control_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const offboard_control_interfaces::msg::UserCommand & msg)
{
  return offboard_control_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<offboard_control_interfaces::msg::UserCommand>()
{
  return "offboard_control_interfaces::msg::UserCommand";
}

template<>
inline const char * name<offboard_control_interfaces::msg::UserCommand>()
{
  return "offboard_control_interfaces/msg/UserCommand";
}

template<>
struct has_fixed_size<offboard_control_interfaces::msg::UserCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<offboard_control_interfaces::msg::UserCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<offboard_control_interfaces::msg::UserCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__TRAITS_HPP_
