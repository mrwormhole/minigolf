#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "ball.h"
#include "vector.h"

Ball *init_ball(const Model *model, const Vector3 position, f32 scale) {
	if (model == NULL) {
		errno = EINVAL;
		return NULL;
	}

	Ball *b = malloc(sizeof(Ball));
	if (b == NULL) {
		return NULL;
	}

	BoundingBox box = GetMeshBoundingBox(model->meshes[0]);
	Vector3 size = sub_vec3(box.max, box.min);

	b->model = model;
	b->position = position;
	b->radius = size.x / 2 * scale;
	b->scale = scale;
	b->debug_on = false;
	return b;
}

void draw_ball(const Ball *ball) {
	DrawModel(*(ball->model), ball->position, ball->scale, WHITE);

	if (ball->debug_on) {
		DrawSphereWires(ball->position, ball->radius, 20, 20, PURPLE);
	}
}

void input_ball(Ball *ball) {
	if (IsKeyDown(KEY_I)) {
		ball->position.y += 0.005f;
	}
	if (IsKeyDown(KEY_J)) {
		ball->position.y -= 0.005f;
	}
	if (IsKeyDown(KEY_K)) {
		ball->position.x -= 0.005f;
	}
	if (IsKeyDown(KEY_L)) {
		ball->position.x += 0.005f;
	}
}
