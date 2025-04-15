// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from flight_control:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "flight_control/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "flight_control/msg/detail/user_command__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace flight_control
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flight_control
cdr_serialize(
  const flight_control::msg::UserCommand & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flight_control
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  flight_control::msg::UserCommand & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flight_control
get_serialized_size(
  const flight_control::msg::UserCommand & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flight_control
max_serialized_size_UserCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace flight_control

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flight_control
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, flight_control, msg, UserCommand)();

#ifdef __cplusplus
}
#endif

#endif  // FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
