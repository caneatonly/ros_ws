// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auv_control:srv/Control.idl
// generated code does not contain a copyright notice
#include "auv_control/srv/detail/control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
auv_control__srv__Control_Request__init(auv_control__srv__Control_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  return true;
}

void
auv_control__srv__Control_Request__fini(auv_control__srv__Control_Request * msg)
{
  if (!msg) {
    return;
  }
  // mode
}

bool
auv_control__srv__Control_Request__are_equal(const auv_control__srv__Control_Request * lhs, const auv_control__srv__Control_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  return true;
}

bool
auv_control__srv__Control_Request__copy(
  const auv_control__srv__Control_Request * input,
  auv_control__srv__Control_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  return true;
}

auv_control__srv__Control_Request *
auv_control__srv__Control_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_control__srv__Control_Request * msg = (auv_control__srv__Control_Request *)allocator.allocate(sizeof(auv_control__srv__Control_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auv_control__srv__Control_Request));
  bool success = auv_control__srv__Control_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auv_control__srv__Control_Request__destroy(auv_control__srv__Control_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auv_control__srv__Control_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auv_control__srv__Control_Request__Sequence__init(auv_control__srv__Control_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_control__srv__Control_Request * data = NULL;

  if (size) {
    data = (auv_control__srv__Control_Request *)allocator.zero_allocate(size, sizeof(auv_control__srv__Control_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auv_control__srv__Control_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auv_control__srv__Control_Request__fini(&data[i - 1]);
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
auv_control__srv__Control_Request__Sequence__fini(auv_control__srv__Control_Request__Sequence * array)
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
      auv_control__srv__Control_Request__fini(&array->data[i]);
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

auv_control__srv__Control_Request__Sequence *
auv_control__srv__Control_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_control__srv__Control_Request__Sequence * array = (auv_control__srv__Control_Request__Sequence *)allocator.allocate(sizeof(auv_control__srv__Control_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auv_control__srv__Control_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auv_control__srv__Control_Request__Sequence__destroy(auv_control__srv__Control_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auv_control__srv__Control_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auv_control__srv__Control_Request__Sequence__are_equal(const auv_control__srv__Control_Request__Sequence * lhs, const auv_control__srv__Control_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auv_control__srv__Control_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auv_control__srv__Control_Request__Sequence__copy(
  const auv_control__srv__Control_Request__Sequence * input,
  auv_control__srv__Control_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auv_control__srv__Control_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auv_control__srv__Control_Request * data =
      (auv_control__srv__Control_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auv_control__srv__Control_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auv_control__srv__Control_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auv_control__srv__Control_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
auv_control__srv__Control_Response__init(auv_control__srv__Control_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
auv_control__srv__Control_Response__fini(auv_control__srv__Control_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
auv_control__srv__Control_Response__are_equal(const auv_control__srv__Control_Response * lhs, const auv_control__srv__Control_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
auv_control__srv__Control_Response__copy(
  const auv_control__srv__Control_Response * input,
  auv_control__srv__Control_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

auv_control__srv__Control_Response *
auv_control__srv__Control_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_control__srv__Control_Response * msg = (auv_control__srv__Control_Response *)allocator.allocate(sizeof(auv_control__srv__Control_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auv_control__srv__Control_Response));
  bool success = auv_control__srv__Control_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auv_control__srv__Control_Response__destroy(auv_control__srv__Control_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auv_control__srv__Control_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auv_control__srv__Control_Response__Sequence__init(auv_control__srv__Control_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_control__srv__Control_Response * data = NULL;

  if (size) {
    data = (auv_control__srv__Control_Response *)allocator.zero_allocate(size, sizeof(auv_control__srv__Control_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auv_control__srv__Control_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auv_control__srv__Control_Response__fini(&data[i - 1]);
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
auv_control__srv__Control_Response__Sequence__fini(auv_control__srv__Control_Response__Sequence * array)
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
      auv_control__srv__Control_Response__fini(&array->data[i]);
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

auv_control__srv__Control_Response__Sequence *
auv_control__srv__Control_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_control__srv__Control_Response__Sequence * array = (auv_control__srv__Control_Response__Sequence *)allocator.allocate(sizeof(auv_control__srv__Control_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auv_control__srv__Control_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auv_control__srv__Control_Response__Sequence__destroy(auv_control__srv__Control_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auv_control__srv__Control_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auv_control__srv__Control_Response__Sequence__are_equal(const auv_control__srv__Control_Response__Sequence * lhs, const auv_control__srv__Control_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auv_control__srv__Control_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auv_control__srv__Control_Response__Sequence__copy(
  const auv_control__srv__Control_Response__Sequence * input,
  auv_control__srv__Control_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auv_control__srv__Control_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auv_control__srv__Control_Response * data =
      (auv_control__srv__Control_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auv_control__srv__Control_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auv_control__srv__Control_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auv_control__srv__Control_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
