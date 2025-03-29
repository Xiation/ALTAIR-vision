// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

#include "temp_ball_detector/msg/detail/ball_distance__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
const rosidl_type_hash_t *
temp_ball_detector__msg__BallDistance__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1c, 0xc2, 0x4b, 0x7d, 0x11, 0x33, 0xdd, 0x09,
      0x6d, 0x41, 0x03, 0x2b, 0x64, 0xcf, 0x1d, 0x47,
      0x22, 0x0b, 0xa1, 0xfa, 0xdb, 0x6b, 0xb3, 0xc6,
      0x0e, 0xdb, 0xfb, 0x02, 0x67, 0x8d, 0x22, 0xf9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char temp_ball_detector__msg__BallDistance__TYPE_NAME[] = "temp_ball_detector/msg/BallDistance";

// Define type names, field names, and default values
static char temp_ball_detector__msg__BallDistance__FIELD_NAME__ball_ada_cok[] = "ball_ada_cok";
static char temp_ball_detector__msg__BallDistance__FIELD_NAME__jaraknya_jing[] = "jaraknya_jing";

static rosidl_runtime_c__type_description__Field temp_ball_detector__msg__BallDistance__FIELDS[] = {
  {
    {temp_ball_detector__msg__BallDistance__FIELD_NAME__ball_ada_cok, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {temp_ball_detector__msg__BallDistance__FIELD_NAME__jaraknya_jing, 13, 13},
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
temp_ball_detector__msg__BallDistance__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {temp_ball_detector__msg__BallDistance__TYPE_NAME, 35, 35},
      {temp_ball_detector__msg__BallDistance__FIELDS, 2, 2},
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
temp_ball_detector__msg__BallDistance__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {temp_ball_detector__msg__BallDistance__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 39, 39},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
temp_ball_detector__msg__BallDistance__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *temp_ball_detector__msg__BallDistance__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
