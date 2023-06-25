#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#include "ball.h"
#include "tile.h"

const char *WINDOW_TITLE = "Minigolf";
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

const size_t TILE_COUNT = 64;

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(60);
	DisableCursor();

	Camera cam = {0};
	Camera2D cam2D;
	cam.position = (Vector3){5.0f, 5.0f, 5.0f};
	cam.target = (Vector3){0.0f, 0.0f, 0.0f};
	cam.up = (Vector3){0.0f, 1.0f, 0.0f};
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;

	// Load all desired 3D models once
	Model green_tile_m = LoadModel(ASSETS_PATH "open.glb");
	Model blue_ball_m = LoadModel(ASSETS_PATH "ball_blue.glb");
	Model red_ball_m = LoadModel(ASSETS_PATH "ball_red.glb");

	Ball *ball = init_ball(&blue_ball_m, (Vector3){0, 0.5f, 0}, 1.0f);
	if (errno != 0 && errno != EAGAIN) {
		perror("*** init_ball()");
		fprintf(stderr,
				"*** init_ball(): Ball model is NULL in file %s at line "
				"#%d\n",
				__FILE__, __LINE__);
		return EXIT_FAILURE;
	}
	ball->debug_on = true;

	Tile *tiles[TILE_COUNT];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Vector3 position = (Vector3){i - 3.5f, 0, j - 3.5f};
			tiles[i * 8 + j] = init_tile(&green_tile_m, position, 1.0f);
			if (errno != 0 && errno != EAGAIN) {
				perror("*** init_tile()");
				fprintf(
					stderr,
					"*** init_tile(): Tile model is NULL in file %s at line "
					"#%d\n",
					__FILE__, __LINE__);
				return EXIT_FAILURE;
			}
			tiles[i * 8 + j]->debug_on = true;
		}
	}

	while (!WindowShouldClose()) {
		input_ball(ball);

		UpdateCamera(&cam, CAMERA_THIRD_PERSON);
		bool is_colliding = false;
		for (int i = 0; i < TILE_COUNT; i++) {
			Tile *tile = tiles[i];
			Vector3 tile_position = tile->position;
			Vector3 tile_size = tile->size;

			f64 ground_offset = tile_size.y / 2;

			BoundingBox bb = (BoundingBox){
				.min =
					(Vector3){
						.x = tile_position.x - tile_size.x / 2,
						.y = tile_position.y - tile_size.y / 2 + ground_offset,
						.z = tile_position.z - tile_size.z / 2,
					},
				.max =
					(Vector3){
						.x = tile_position.x + tile_size.x / 2,
						.y = tile_position.y + tile_size.y / 2 + ground_offset,
						.z = tile_position.z + tile_size.z / 2,
					},
			};

			if (CheckCollisionBoxSphere(bb, ball->position, ball->radius)) {
				is_colliding = true;
				break;
			}
		}
		if (is_colliding) {
			ball->model = &red_ball_m;
		} else {
			ball->model = &blue_ball_m;
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(cam);
		{
			draw_ball(ball);
			if (errno != 0 && errno != EAGAIN) {
				perror("*** draw_ball()");
				fprintf(stderr,
						"*** draw_ball(): Ball is NULL in file %s at line "
						"#%d\n",
						__FILE__, __LINE__);
				return EXIT_FAILURE;
			}

			for (size_t i = 0; i < TILE_COUNT; i++) {
				draw_tile(tiles[i]);
				if (errno != 0 && errno != EAGAIN) {
					perror("*** draw_tile()");
					fprintf(stderr,
							"*** draw_tile(): Tile is NULL in file %s at line "
							"#%d\n",
							__FILE__, __LINE__);
					return EXIT_FAILURE;
				}
			}

			DrawGrid(10, 1.0f);
		}
		EndMode3D();
		{
			// 2D GUI
			DrawFPS(10, 10);
		}
		EndDrawing();
	}

	free(ball);
	for (size_t i = 0; i < TILE_COUNT; i++) {
		free(tiles[i]);
	}

	// Unload all desired 3D models once
	UnloadModel(green_tile_m);
	UnloadModel(blue_ball_m);
	UnloadModel(red_ball_m);
	CloseWindow();

	return 0;
}
