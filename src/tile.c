#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "tile.h"
#include "vector.h"

Tile *init_tile(const Model *model, const Vector3 position, f32 scale) {
	if (model == NULL) {
		errno = EINVAL;
		return NULL;
	}

	Tile *t = malloc(sizeof(Tile));
	if (t == NULL) {
		return NULL;
	}

	BoundingBox box = GetMeshBoundingBox(model->meshes[0]);
	Vector3 size = sub_vec3(box.max, box.min);

	t->model = model;
	t->position = position;
	t->size = mult_vec3(size, scale);
	t->scale = scale;
	t->debug_on = false;
	return t;
}

void draw_tile(const Tile *tile) {
	if (tile == NULL) {
		errno = EINVAL;
		return;
	}

	Vector3 position = tile->position;
	DrawModel(*(tile->model), position, tile->scale, WHITE);

	if (tile->debug_on) {
		Vector3 size = tile->size;
		position.y += size.y / 2;
		DrawCubeWires(position, size.x, size.y, size.z, PURPLE);
	}
}
