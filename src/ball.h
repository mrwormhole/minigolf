#ifndef BALL_H
#define BALL_H

#include "raylib.h"

#include "number.h"

typedef struct Ball {
	const Model *model;
	Vector3 position;
	float radius;
	float scale;
	bool debug_on;
} Ball;

Ball *init_ball(const Model *model, const Vector3 position, f32 scale);
void draw_ball(const Ball *ball);
void input_ball(Ball *ball);

#endif
