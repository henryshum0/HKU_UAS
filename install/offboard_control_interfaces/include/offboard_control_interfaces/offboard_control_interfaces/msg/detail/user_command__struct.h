// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from offboard_control_interfaces:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__STRUCT_H_
#define OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TAKEOFF'.
/**
  * missions
 */
enum
{
  offboard_control_interfaces__msg__UserCommand__TAKEOFF = 1
};

/// Constant 'LAND'.
enum
{
  offboard_control_interfaces__msg__UserCommand__LAND = 2
};

/// Constant 'WAYPOINT'.
enum
{
  offboard_control_interfaces__msg__UserCommand__WAYPOINT = 3
};

/// Constant 'AIRDROP'.
enum
{
  offboard_control_interfaces__msg__UserCommand__AIRDROP = 4
};

/// Constant 'MAPPING'.
enum
{
  offboard_control_interfaces__msg__UserCommand__MAPPING = 5
};

/// Constant 'EXECUTE'.
enum
{
  offboard_control_interfaces__msg__UserCommand__EXECUTE = 99
};

/// Constant 'POPLAST'.
enum
{
  offboard_control_interfaces__msg__UserCommand__POPLAST = 100
};

/// Constant 'SUCCESS'.
enum
{
  offboard_control_interfaces__msg__UserCommand__SUCCESS = 200
};

/// Constant 'REJECT'.
enum
{
  offboard_control_interfaces__msg__UserCommand__REJECT = 210
};

/// Constant 'REJECT_SETPOINT_OUTOFREACH'.
enum
{
  offboard_control_interfaces__msg__UserCommand__REJECT_SETPOINT_OUTOFREACH = 211
};

/// Constant 'REJECT_SPEED_INFEASIBLE'.
enum
{
  offboard_control_interfaces__msg__UserCommand__REJECT_SPEED_INFEASIBLE = 212
};

/// Constant 'REJECT_TAKEOFF_HEIGHTINFEASIBLE'.
enum
{
  offboard_control_interfaces__msg__UserCommand__REJECT_TAKEOFF_HEIGHTINFEASIBLE = 213
};

/// Constant 'REJECT_LAND_BEFORE_TAKEOFF'.
enum
{
  offboard_control_interfaces__msg__UserCommand__REJECT_LAND_BEFORE_TAKEOFF = 214
};

/// Constant 'REJECT_TAKEOFF_BEFORE_LAND'.
enum
{
  offboard_control_interfaces__msg__UserCommand__REJECT_TAKEOFF_BEFORE_LAND = 215
};

/// Constant 'REJECT_EMPTY_WAYPOINTS'.
enum
{
  offboard_control_interfaces__msg__UserCommand__REJECT_EMPTY_WAYPOINTS = 216
};

/// Struct defined in msg/UserCommand in the package offboard_control_interfaces.
/**
  * user input
  * for user publishing waypoints/missions to drone
 */
typedef struct offboard_control_interfaces__msg__UserCommand
{
  uint64_t timestamp;
  float lon;
  float lat;
  float x;
  float y;
  float z;
  float speed;
  float yaw;
  uint8_t command;
  bool use_xy;
  uint8_t response;
} offboard_control_interfaces__msg__UserCommand;

// Struct for a sequence of offboard_control_interfaces__msg__UserCommand.
typedef struct offboard_control_interfaces__msg__UserCommand__Sequence
{
  offboard_control_interfaces__msg__UserCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} offboard_control_interfaces__msg__UserCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OFFBOARD_CONTROL_INTERFACES__MSG__DETAIL__USER_COMMAND__STRUCT_H_
