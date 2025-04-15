// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from offboard_control_interfaces:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__BUILDER_HPP_
#define OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "offboard_control_interfaces/msg/detail/user_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace offboard_control_interfaces
{

namespace msg
{

namespace builder
{

class Init_UserCommand_response
{
public:
  explicit Init_UserCommand_response(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  ::offboard_control_interfaces::msg::UserCommand response(::offboard_control_interfaces::msg::UserCommand::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_use_xy
{
public:
  explicit Init_UserCommand_use_xy(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_response use_xy(::offboard_control_interfaces::msg::UserCommand::_use_xy_type arg)
  {
    msg_.use_xy = std::move(arg);
    return Init_UserCommand_response(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_command
{
public:
  explicit Init_UserCommand_command(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_use_xy command(::offboard_control_interfaces::msg::UserCommand::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_UserCommand_use_xy(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_yaw
{
public:
  explicit Init_UserCommand_yaw(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_command yaw(::offboard_control_interfaces::msg::UserCommand::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_UserCommand_command(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_speed
{
public:
  explicit Init_UserCommand_speed(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_yaw speed(::offboard_control_interfaces::msg::UserCommand::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_UserCommand_yaw(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_z
{
public:
  explicit Init_UserCommand_z(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_speed z(::offboard_control_interfaces::msg::UserCommand::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_UserCommand_speed(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_y
{
public:
  explicit Init_UserCommand_y(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_z y(::offboard_control_interfaces::msg::UserCommand::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_UserCommand_z(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_x
{
public:
  explicit Init_UserCommand_x(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_y x(::offboard_control_interfaces::msg::UserCommand::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_UserCommand_y(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_lat
{
public:
  explicit Init_UserCommand_lat(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_x lat(::offboard_control_interfaces::msg::UserCommand::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_UserCommand_x(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_lon
{
public:
  explicit Init_UserCommand_lon(::offboard_control_interfaces::msg::UserCommand & msg)
  : msg_(msg)
  {}
  Init_UserCommand_lat lon(::offboard_control_interfaces::msg::UserCommand::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_UserCommand_lat(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

class Init_UserCommand_timestamp
{
public:
  Init_UserCommand_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UserCommand_lon timestamp(::offboard_control_interfaces::msg::UserCommand::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_UserCommand_lon(msg_);
  }

private:
  ::offboard_control_interfaces::msg::UserCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::offboard_control_interfaces::msg::UserCommand>()
{
  return offboard_control_interfaces::msg::builder::Init_UserCommand_timestamp();
}

}  // namespace offboard_control_interfaces

#endif  // OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__BUILDER_HPP_
