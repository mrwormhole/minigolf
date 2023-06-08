#ifndef TILE_H
#define TILE_H

#include "raylib.h"

#include "number.h"

typedef struct Tile {
	const Model *model;
	Vector3 position;
	Vector3 size;
	float scale;
	bool debug_on;
} Tile;

Tile *init_tile(const Model *model, const Vector3 position, f32 scale);
void draw_tile(const Tile *tile);

#endif
