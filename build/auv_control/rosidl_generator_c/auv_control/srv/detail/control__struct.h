// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv_control:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef AUV_CONTROL__SRV__DETAIL__CONTROL__STRUCT_H_
#define AUV_CONTROL__SRV__DETAIL__CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'POSITION'.
enum
{
  auv_control__srv__Control_Request__POSITION = 0
};

/// Constant 'VELOCITY'.
enum
{
  auv_control__srv__Control_Request__VELOCITY = 1
};

/// Constant 'DEPTH'.
enum
{
  auv_control__srv__Control_Request__DEPTH = 2
};

/// Struct defined in srv/Control in the package auv_control.
typedef struct auv_control__srv__Control_Request
{
  uint8_t mode;
} auv_control__srv__Control_Request;

// Struct for a sequence of auv_control__srv__Control_Request.
typedef struct auv_control__srv__Control_Request__Sequence
{
  auv_control__srv__Control_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv_control__srv__Control_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Control in the package auv_control.
typedef struct auv_control__srv__Control_Response
{
  uint8_t structure_needs_at_least_one_member;
} auv_control__srv__Control_Response;

// Struct for a sequence of auv_control__srv__Control_Response.
typedef struct auv_control__srv__Control_Response__Sequence
{
  auv_control__srv__Control_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv_control__srv__Control_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV_CONTROL__SRV__DETAIL__CONTROL__STRUCT_H_
