#include <stdio.h>

#include "raylib.h"

const char *WINDOW_TITLE = "Minigolf";
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const float MOUSE_WHEEL_SENSITIVITY = 0.125f;

const int TILE_COUNT = 81;

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

	Model greenTile = LoadModel(ASSETS_PATH "open.glb");
	Model blueBall = LoadModel(ASSETS_PATH "ball_blue.glb");

	Vector3 positions[TILE_COUNT] = {0};

	int tileIndex = 0;
	for (int i = -4; i < 5; i++) {
		for (int j = -4; j < 5; j++) {
			positions[tileIndex] = (Vector3){i, 0, j};
			tileIndex++;
		}
	}

	while (!WindowShouldClose()) {
		UpdateCamera(&cam, CAMERA_THIRD_PERSON);

		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(cam);
		{
			DrawModel(blueBall, (Vector3){0, 0.5f, 0}, 1.0f, WHITE);
			for (size_t i = 0; i < TILE_COUNT; i++) {
				DrawModel(greenTile, positions[i], 1.0f, WHITE);
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

	UnloadModel(greenTile);
	UnloadModel(blueBall);
	CloseWindow();

	return 0;
}
