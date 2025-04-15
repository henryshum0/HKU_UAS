// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flight_control:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__TRAITS_HPP_
#define FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flight_control/msg/detail/user_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace flight_control
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

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: use_xyz
  {
    out << "use_xyz: ";
    rosidl_generator_traits::value_to_yaml(msg.use_xyz, out);
    out << ", ";
  }

  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
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

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
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

  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: use_xyz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_xyz: ";
    rosidl_generator_traits::value_to_yaml(msg.use_xyz, out);
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

}  // namespace flight_control

namespace rosidl_generator_traits
{

[[deprecated("use flight_control::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flight_control::msg::UserCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  flight_control::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flight_control::msg::to_yaml() instead")]]
inline std::string to_yaml(const flight_control::msg::UserCommand & msg)
{
  return flight_control::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flight_control::msg::UserCommand>()
{
  return "flight_control::msg::UserCommand";
}

template<>
inline const char * name<flight_control::msg::UserCommand>()
{
  return "flight_control/msg/UserCommand";
}

template<>
struct has_fixed_size<flight_control::msg::UserCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<flight_control::msg::UserCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<flight_control::msg::UserCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__TRAITS_HPP_
