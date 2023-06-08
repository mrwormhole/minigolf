#ifndef VECTOR_H
#define VECTOR_H

#include "raylib.h"

#include "number.h"

Vector3 add_vec3(Vector3 a, Vector3 b);
Vector3 sub_vec3(Vector3 a, Vector3 b);
Vector3 mult_vec3(Vector3 a, f32 k);
Vector3 div_vec3(Vector3 a, f32 k);

#endif
