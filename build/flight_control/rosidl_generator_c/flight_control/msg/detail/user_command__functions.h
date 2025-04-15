// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from flight_control:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__FUNCTIONS_H_
#define FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "flight_control/msg/rosidl_generator_c__visibility_control.h"

#include "flight_control/msg/detail/user_command__struct.h"

/// Initialize msg/UserCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * flight_control__msg__UserCommand
 * )) before or use
 * flight_control__msg__UserCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
bool
flight_control__msg__UserCommand__init(flight_control__msg__UserCommand * msg);

/// Finalize msg/UserCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
void
flight_control__msg__UserCommand__fini(flight_control__msg__UserCommand * msg);

/// Create msg/UserCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * flight_control__msg__UserCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
flight_control__msg__UserCommand *
flight_control__msg__UserCommand__create();

/// Destroy msg/UserCommand message.
/**
 * It calls
 * flight_control__msg__UserCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
void
flight_control__msg__UserCommand__destroy(flight_control__msg__UserCommand * msg);

/// Check for msg/UserCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
bool
flight_control__msg__UserCommand__are_equal(const flight_control__msg__UserCommand * lhs, const flight_control__msg__UserCommand * rhs);

/// Copy a msg/UserCommand message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
bool
flight_control__msg__UserCommand__copy(
  const flight_control__msg__UserCommand * input,
  flight_control__msg__UserCommand * output);

/// Initialize array of msg/UserCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * flight_control__msg__UserCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
bool
flight_control__msg__UserCommand__Sequence__init(flight_control__msg__UserCommand__Sequence * array, size_t size);

/// Finalize array of msg/UserCommand messages.
/**
 * It calls
 * flight_control__msg__UserCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
void
flight_control__msg__UserCommand__Sequence__fini(flight_control__msg__UserCommand__Sequence * array);

/// Create array of msg/UserCommand messages.
/**
 * It allocates the memory for the array and calls
 * flight_control__msg__UserCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
flight_control__msg__UserCommand__Sequence *
flight_control__msg__UserCommand__Sequence__create(size_t size);

/// Destroy array of msg/UserCommand messages.
/**
 * It calls
 * flight_control__msg__UserCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
void
flight_control__msg__UserCommand__Sequence__destroy(flight_control__msg__UserCommand__Sequence * array);

/// Check for msg/UserCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
bool
flight_control__msg__UserCommand__Sequence__are_equal(const flight_control__msg__UserCommand__Sequence * lhs, const flight_control__msg__UserCommand__Sequence * rhs);

/// Copy an array of msg/UserCommand messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_flight_control
bool
flight_control__msg__UserCommand__Sequence__copy(
  const flight_control__msg__UserCommand__Sequence * input,
  flight_control__msg__UserCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FLIGHT_CONTROL__MSG__DETAIL__USER_COMMAND__FUNCTIONS_H_
