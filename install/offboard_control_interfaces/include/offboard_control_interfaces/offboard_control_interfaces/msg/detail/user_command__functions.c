// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from offboard_control_interfaces:msg/UserCommand.idl
// generated code does not contain a copyright notice
#include "offboard_control_interfaces/msg/detail/user_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
offboard_control_interfaces__msg__UserCommand__init(offboard_control_interfaces__msg__UserCommand * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // lon
  // lat
  // x
  // y
  // z
  // speed
  // yaw
  // command
  // use_xy
  // response
  return true;
}

void
offboard_control_interfaces__msg__UserCommand__fini(offboard_control_interfaces__msg__UserCommand * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // lon
  // lat
  // x
  // y
  // z
  // speed
  // yaw
  // command
  // use_xy
  // response
}

bool
offboard_control_interfaces__msg__UserCommand__are_equal(const offboard_control_interfaces__msg__UserCommand * lhs, const offboard_control_interfaces__msg__UserCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // lon
  if (lhs->lon != rhs->lon) {
    return false;
  }
  // lat
  if (lhs->lat != rhs->lat) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // command
  if (lhs->command != rhs->command) {
    return false;
  }
  // use_xy
  if (lhs->use_xy != rhs->use_xy) {
    return false;
  }
  // response
  if (lhs->response != rhs->response) {
    return false;
  }
  return true;
}

bool
offboard_control_interfaces__msg__UserCommand__copy(
  const offboard_control_interfaces__msg__UserCommand * input,
  offboard_control_interfaces__msg__UserCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // lon
  output->lon = input->lon;
  // lat
  output->lat = input->lat;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // speed
  output->speed = input->speed;
  // yaw
  output->yaw = input->yaw;
  // command
  output->command = input->command;
  // use_xy
  output->use_xy = input->use_xy;
  // response
  output->response = input->response;
  return true;
}

offboard_control_interfaces__msg__UserCommand *
offboard_control_interfaces__msg__UserCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  offboard_control_interfaces__msg__UserCommand * msg = (offboard_control_interfaces__msg__UserCommand *)allocator.allocate(sizeof(offboard_control_interfaces__msg__UserCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(offboard_control_interfaces__msg__UserCommand));
  bool success = offboard_control_interfaces__msg__UserCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
offboard_control_interfaces__msg__UserCommand__destroy(offboard_control_interfaces__msg__UserCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    offboard_control_interfaces__msg__UserCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
offboard_control_interfaces__msg__UserCommand__Sequence__init(offboard_control_interfaces__msg__UserCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  offboard_control_interfaces__msg__UserCommand * data = NULL;

  if (size) {
    data = (offboard_control_interfaces__msg__UserCommand *)allocator.zero_allocate(size, sizeof(offboard_control_interfaces__msg__UserCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = offboard_control_interfaces__msg__UserCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        offboard_control_interfaces__msg__UserCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
offboard_control_interfaces__msg__UserCommand__Sequence__fini(offboard_control_interfaces__msg__UserCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      offboard_control_interfaces__msg__UserCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

offboard_control_interfaces__msg__UserCommand__Sequence *
offboard_control_interfaces__msg__UserCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  offboard_control_interfaces__msg__UserCommand__Sequence * array = (offboard_control_interfaces__msg__UserCommand__Sequence *)allocator.allocate(sizeof(offboard_control_interfaces__msg__UserCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = offboard_control_interfaces__msg__UserCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
offboard_control_interfaces__msg__UserCommand__Sequence__destroy(offboard_control_interfaces__msg__UserCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    offboard_control_interfaces__msg__UserCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
offboard_control_interfaces__msg__UserCommand__Sequence__are_equal(const offboard_control_interfaces__msg__UserCommand__Sequence * lhs, const offboard_control_interfaces__msg__UserCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!offboard_control_interfaces__msg__UserCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
offboard_control_interfaces__msg__UserCommand__Sequence__copy(
  const offboard_control_interfaces__msg__UserCommand__Sequence * input,
  offboard_control_interfaces__msg__UserCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(offboard_control_interfaces__msg__UserCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    offboard_control_interfaces__msg__UserCommand * data =
      (offboard_control_interfaces__msg__UserCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!offboard_control_interfaces__msg__UserCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          offboard_control_interfaces__msg__UserCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!offboard_control_interfaces__msg__UserCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
