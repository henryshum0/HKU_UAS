// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from flight_control:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__STRUCT_HPP_
#define FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__flight_control__msg__UserCommand __attribute__((deprecated))
#else
# define DEPRECATED__flight_control__msg__UserCommand __declspec(deprecated)
#endif

namespace flight_control
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UserCommand_
{
  using Type = UserCommand_<ContainerAllocator>;

  explicit UserCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->lon = 0.0f;
      this->lat = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->yaw = 0.0f;
      this->command = 0;
      this->use_xyz = false;
      this->response = 0;
    }
  }

  explicit UserCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->lon = 0.0f;
      this->lat = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->yaw = 0.0f;
      this->command = 0;
      this->use_xyz = false;
      this->response = 0;
    }
  }

  // field types and members
  using _timestamp_type =
    uint64_t;
  _timestamp_type timestamp;
  using _lon_type =
    float;
  _lon_type lon;
  using _lat_type =
    float;
  _lat_type lat;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _command_type =
    uint8_t;
  _command_type command;
  using _use_xyz_type =
    bool;
  _use_xyz_type use_xyz;
  using _response_type =
    uint8_t;
  _response_type response;

  // setters for named parameter idiom
  Type & set__timestamp(
    const uint64_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__lon(
    const float & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__lat(
    const float & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__command(
    const uint8_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__use_xyz(
    const bool & _arg)
  {
    this->use_xyz = _arg;
    return *this;
  }
  Type & set__response(
    const uint8_t & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TAKEOFF =
    1u;
  static constexpr uint8_t LAND =
    2u;
  static constexpr uint8_t WAYPOINT =
    3u;
  static constexpr uint8_t AIRDROP =
    4u;
  static constexpr uint8_t MAPPING =
    5u;
  static constexpr uint8_t EXECUTE =
    99u;
  static constexpr uint8_t POPLAST =
    100u;
  static constexpr uint8_t SUCCESS =
    200u;
  static constexpr uint8_t REJECT =
    210u;
  static constexpr uint8_t REJECT_SETPOINT_OUTOFREACH =
    211u;
  static constexpr uint8_t REJECT_SPPED_INFEASIBLE =
    212u;
  static constexpr uint8_t REJECT_TAKEOFF_HEIGHTINFEASIBLE =
    213u;
  static constexpr uint8_t REJECT_MISSING_TAKEOFF =
    214u;
  static constexpr uint8_t REJECT_MISSING_LAND =
    215u;

  // pointer types
  using RawPtr =
    flight_control::msg::UserCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const flight_control::msg::UserCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<flight_control::msg::UserCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<flight_control::msg::UserCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      flight_control::msg::UserCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<flight_control::msg::UserCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      flight_control::msg::UserCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<flight_control::msg::UserCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<flight_control::msg::UserCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<flight_control::msg::UserCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__flight_control__msg__UserCommand
    std::shared_ptr<flight_control::msg::UserCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__flight_control__msg__UserCommand
    std::shared_ptr<flight_control::msg::UserCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserCommand_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->lat != other.lat) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->command != other.command) {
      return false;
    }
    if (this->use_xyz != other.use_xyz) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserCommand_

// alias to use template instance with default allocator
using UserCommand =
  flight_control::msg::UserCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::TAKEOFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::LAND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::WAYPOINT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::AIRDROP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::MAPPING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::EXECUTE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::POPLAST;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::SUCCESS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::REJECT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::REJECT_SETPOINT_OUTOFREACH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::REJECT_SPPED_INFEASIBLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::REJECT_TAKEOFF_HEIGHTINFEASIBLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::REJECT_MISSING_TAKEOFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t UserCommand_<ContainerAllocator>::REJECT_MISSING_LAND;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace flight_control

#endif  // FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__STRUCT_HPP_
