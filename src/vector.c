#include "vector.h"

inline Vector3 add_vec3(Vector3 a, Vector3 b) {
	return (Vector3){.x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z};
}

inline Vector3 sub_vec3(Vector3 a, Vector3 b) {
	return (Vector3){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z};
}

inline Vector3 mult_vec3(Vector3 a, f32 k) {
	return (Vector3){.x = a.x * k, .y = a.y * k, .z = a.z * k};
}

inline Vector3 div_vec3(Vector3 a, f32 k) {
	return (Vector3){.x = a.x / k, .y = a.y / k, .z = a.z / k};
}
