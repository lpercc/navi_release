// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from navi_interface:srv/Upload.idl
// generated code does not contain a copyright notice
#include "navi_interface/srv/detail/upload__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"
// Member `instruction`
// Member `task_type`
// Member `target_pose`
// Member `start_pose`
#include "rosidl_runtime_c/string_functions.h"

bool
navi_interface__srv__Upload_Request__init(navi_interface__srv__Upload_Request * msg)
{
  if (!msg) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    navi_interface__srv__Upload_Request__fini(msg);
    return false;
  }
  // instruction
  if (!rosidl_runtime_c__String__init(&msg->instruction)) {
    navi_interface__srv__Upload_Request__fini(msg);
    return false;
  }
  // task_type
  if (!rosidl_runtime_c__String__init(&msg->task_type)) {
    navi_interface__srv__Upload_Request__fini(msg);
    return false;
  }
  // step
  // target_pose
  if (!rosidl_runtime_c__String__init(&msg->target_pose)) {
    navi_interface__srv__Upload_Request__fini(msg);
    return false;
  }
  // start_pose
  if (!rosidl_runtime_c__String__init(&msg->start_pose)) {
    navi_interface__srv__Upload_Request__fini(msg);
    return false;
  }
  return true;
}

void
navi_interface__srv__Upload_Request__fini(navi_interface__srv__Upload_Request * msg)
{
  if (!msg) {
    return;
  }
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
  // instruction
  rosidl_runtime_c__String__fini(&msg->instruction);
  // task_type
  rosidl_runtime_c__String__fini(&msg->task_type);
  // step
  // target_pose
  rosidl_runtime_c__String__fini(&msg->target_pose);
  // start_pose
  rosidl_runtime_c__String__fini(&msg->start_pose);
}

bool
navi_interface__srv__Upload_Request__are_equal(const navi_interface__srv__Upload_Request * lhs, const navi_interface__srv__Upload_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  // instruction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->instruction), &(rhs->instruction)))
  {
    return false;
  }
  // task_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->task_type), &(rhs->task_type)))
  {
    return false;
  }
  // step
  if (lhs->step != rhs->step) {
    return false;
  }
  // target_pose
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_pose), &(rhs->target_pose)))
  {
    return false;
  }
  // start_pose
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->start_pose), &(rhs->start_pose)))
  {
    return false;
  }
  return true;
}

bool
navi_interface__srv__Upload_Request__copy(
  const navi_interface__srv__Upload_Request * input,
  navi_interface__srv__Upload_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  // instruction
  if (!rosidl_runtime_c__String__copy(
      &(input->instruction), &(output->instruction)))
  {
    return false;
  }
  // task_type
  if (!rosidl_runtime_c__String__copy(
      &(input->task_type), &(output->task_type)))
  {
    return false;
  }
  // step
  output->step = input->step;
  // target_pose
  if (!rosidl_runtime_c__String__copy(
      &(input->target_pose), &(output->target_pose)))
  {
    return false;
  }
  // start_pose
  if (!rosidl_runtime_c__String__copy(
      &(input->start_pose), &(output->start_pose)))
  {
    return false;
  }
  return true;
}

navi_interface__srv__Upload_Request *
navi_interface__srv__Upload_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navi_interface__srv__Upload_Request * msg = (navi_interface__srv__Upload_Request *)allocator.allocate(sizeof(navi_interface__srv__Upload_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navi_interface__srv__Upload_Request));
  bool success = navi_interface__srv__Upload_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navi_interface__srv__Upload_Request__destroy(navi_interface__srv__Upload_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navi_interface__srv__Upload_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navi_interface__srv__Upload_Request__Sequence__init(navi_interface__srv__Upload_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navi_interface__srv__Upload_Request * data = NULL;

  if (size) {
    data = (navi_interface__srv__Upload_Request *)allocator.zero_allocate(size, sizeof(navi_interface__srv__Upload_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navi_interface__srv__Upload_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navi_interface__srv__Upload_Request__fini(&data[i - 1]);
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
navi_interface__srv__Upload_Request__Sequence__fini(navi_interface__srv__Upload_Request__Sequence * array)
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
      navi_interface__srv__Upload_Request__fini(&array->data[i]);
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

navi_interface__srv__Upload_Request__Sequence *
navi_interface__srv__Upload_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navi_interface__srv__Upload_Request__Sequence * array = (navi_interface__srv__Upload_Request__Sequence *)allocator.allocate(sizeof(navi_interface__srv__Upload_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navi_interface__srv__Upload_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navi_interface__srv__Upload_Request__Sequence__destroy(navi_interface__srv__Upload_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navi_interface__srv__Upload_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navi_interface__srv__Upload_Request__Sequence__are_equal(const navi_interface__srv__Upload_Request__Sequence * lhs, const navi_interface__srv__Upload_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navi_interface__srv__Upload_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navi_interface__srv__Upload_Request__Sequence__copy(
  const navi_interface__srv__Upload_Request__Sequence * input,
  navi_interface__srv__Upload_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navi_interface__srv__Upload_Request);
    navi_interface__srv__Upload_Request * data =
      (navi_interface__srv__Upload_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navi_interface__srv__Upload_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          navi_interface__srv__Upload_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navi_interface__srv__Upload_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
navi_interface__srv__Upload_Response__init(navi_interface__srv__Upload_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    navi_interface__srv__Upload_Response__fini(msg);
    return false;
  }
  return true;
}

void
navi_interface__srv__Upload_Response__fini(navi_interface__srv__Upload_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
navi_interface__srv__Upload_Response__are_equal(const navi_interface__srv__Upload_Response * lhs, const navi_interface__srv__Upload_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
navi_interface__srv__Upload_Response__copy(
  const navi_interface__srv__Upload_Response * input,
  navi_interface__srv__Upload_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

navi_interface__srv__Upload_Response *
navi_interface__srv__Upload_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navi_interface__srv__Upload_Response * msg = (navi_interface__srv__Upload_Response *)allocator.allocate(sizeof(navi_interface__srv__Upload_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navi_interface__srv__Upload_Response));
  bool success = navi_interface__srv__Upload_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navi_interface__srv__Upload_Response__destroy(navi_interface__srv__Upload_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navi_interface__srv__Upload_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navi_interface__srv__Upload_Response__Sequence__init(navi_interface__srv__Upload_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navi_interface__srv__Upload_Response * data = NULL;

  if (size) {
    data = (navi_interface__srv__Upload_Response *)allocator.zero_allocate(size, sizeof(navi_interface__srv__Upload_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navi_interface__srv__Upload_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navi_interface__srv__Upload_Response__fini(&data[i - 1]);
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
navi_interface__srv__Upload_Response__Sequence__fini(navi_interface__srv__Upload_Response__Sequence * array)
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
      navi_interface__srv__Upload_Response__fini(&array->data[i]);
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

navi_interface__srv__Upload_Response__Sequence *
navi_interface__srv__Upload_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navi_interface__srv__Upload_Response__Sequence * array = (navi_interface__srv__Upload_Response__Sequence *)allocator.allocate(sizeof(navi_interface__srv__Upload_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navi_interface__srv__Upload_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navi_interface__srv__Upload_Response__Sequence__destroy(navi_interface__srv__Upload_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navi_interface__srv__Upload_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navi_interface__srv__Upload_Response__Sequence__are_equal(const navi_interface__srv__Upload_Response__Sequence * lhs, const navi_interface__srv__Upload_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navi_interface__srv__Upload_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navi_interface__srv__Upload_Response__Sequence__copy(
  const navi_interface__srv__Upload_Response__Sequence * input,
  navi_interface__srv__Upload_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navi_interface__srv__Upload_Response);
    navi_interface__srv__Upload_Response * data =
      (navi_interface__srv__Upload_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navi_interface__srv__Upload_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          navi_interface__srv__Upload_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navi_interface__srv__Upload_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
