// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flight_control:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__STRUCT_H_
#define FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__STRUCT_H_

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
  flight_control__msg__UserCommand__TAKEOFF = 1
};

/// Constant 'LAND'.
enum
{
  flight_control__msg__UserCommand__LAND = 2
};

/// Constant 'WAYPOINT'.
enum
{
  flight_control__msg__UserCommand__WAYPOINT = 3
};

/// Constant 'AIRDROP'.
enum
{
  flight_control__msg__UserCommand__AIRDROP = 4
};

/// Constant 'MAPPING'.
enum
{
  flight_control__msg__UserCommand__MAPPING = 5
};

/// Constant 'EXECUTE'.
enum
{
  flight_control__msg__UserCommand__EXECUTE = 99
};

/// Constant 'POPLAST'.
enum
{
  flight_control__msg__UserCommand__POPLAST = 100
};

/// Constant 'SUCCESS'.
enum
{
  flight_control__msg__UserCommand__SUCCESS = 200
};

/// Constant 'REJECT'.
enum
{
  flight_control__msg__UserCommand__REJECT = 210
};

/// Constant 'REJECT_SETPOINT_OUTOFREACH'.
enum
{
  flight_control__msg__UserCommand__REJECT_SETPOINT_OUTOFREACH = 211
};

/// Constant 'REJECT_SPPED_INFEASIBLE'.
enum
{
  flight_control__msg__UserCommand__REJECT_SPPED_INFEASIBLE = 212
};

/// Constant 'REJECT_TAKEOFF_HEIGHTINFEASIBLE'.
enum
{
  flight_control__msg__UserCommand__REJECT_TAKEOFF_HEIGHTINFEASIBLE = 213
};

/// Constant 'REJECT_MISSING_TAKEOFF'.
enum
{
  flight_control__msg__UserCommand__REJECT_MISSING_TAKEOFF = 214
};

/// Constant 'REJECT_MISSING_LAND'.
enum
{
  flight_control__msg__UserCommand__REJECT_MISSING_LAND = 215
};

/// Struct defined in msg/UserCommand in the package flight_control.
/**
  * user input
  * for user publishing waypoints/missions to drone
 */
typedef struct flight_control__msg__UserCommand
{
  uint64_t timestamp;
  float lon;
  float lat;
  float x;
  float y;
  float z;
  float yaw;
  uint8_t command;
  bool use_xyz;
  uint8_t response;
} flight_control__msg__UserCommand;

// Struct for a sequence of flight_control__msg__UserCommand.
typedef struct flight_control__msg__UserCommand__Sequence
{
  flight_control__msg__UserCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flight_control__msg__UserCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__STRUCT_H_
