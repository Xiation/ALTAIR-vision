// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

#include "ball_detector/msg/detail/ball_distance__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ball_detector
const rosidl_type_hash_t *
ball_detector__msg__BallDistance__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xab, 0x24, 0x2d, 0x70, 0xa3, 0x1d, 0x13, 0xdf,
      0xe1, 0x1b, 0xe1, 0x6a, 0x5c, 0xe3, 0xfa, 0x6f,
      0x4d, 0x65, 0x9b, 0xad, 0x69, 0xb8, 0x06, 0x79,
      0x14, 0xd7, 0xdf, 0x55, 0x36, 0x79, 0xb0, 0x9b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ball_detector__msg__BallDistance__TYPE_NAME[] = "ball_detector/msg/BallDistance";

// Define type names, field names, and default values
static char ball_detector__msg__BallDistance__FIELD_NAME__ball_ada_cok[] = "ball_ada_cok";
static char ball_detector__msg__BallDistance__FIELD_NAME__jaraknya_jing[] = "jaraknya_jing";

static rosidl_runtime_c__type_description__Field ball_detector__msg__BallDistance__FIELDS[] = {
  {
    {ball_detector__msg__BallDistance__FIELD_NAME__ball_ada_cok, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ball_detector__msg__BallDistance__FIELD_NAME__jaraknya_jing, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ball_detector__msg__BallDistance__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ball_detector__msg__BallDistance__TYPE_NAME, 30, 30},
      {ball_detector__msg__BallDistance__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool ball_ada_cok\n"
  "float64 jaraknya_jing";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ball_detector__msg__BallDistance__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ball_detector__msg__BallDistance__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 39, 39},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ball_detector__msg__BallDistance__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ball_detector__msg__BallDistance__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
