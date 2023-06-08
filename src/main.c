#include <stdio.h>

#include "main.h"

const char *WINDOW_TITLE = "Minigolf";
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const float MOUSE_WHEEL_SENSITIVITY = 0.125f;

const int TILE_COUNT = 64;

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
	Model redBall = LoadModel(ASSETS_PATH "ball_red.glb");
	
	BoundingBox tileBB = GetMeshBoundingBox(greenTile.meshes[0]);
	BoundingBox ballBB = GetMeshBoundingBox(blueBall.meshes[0]);

	Vector3 ballPosition = (Vector3){0, 0.5f, 0};
	Vector3 positions[TILE_COUNT] = {0};

	int tileIndex = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			positions[tileIndex] = (Vector3){i - 3.5f, 0, j - 3.5f};
			tileIndex++;
		}
	}

	Vector3 origin = {0, 0, 0};

	while (!WindowShouldClose()) {
		if (IsKeyDown(KEY_I)) {
            ballPosition.y += 0.005f;
        }
		if (IsKeyDown(KEY_J)) {
			ballPosition.y -= 0.005f;
		}
		if (IsKeyDown(KEY_K)) {
			ballPosition.x -= 0.005f;
		}
		if (IsKeyDown(KEY_L)) {
			ballPosition.x += 0.005f;
		}


		UpdateCamera(&cam, CAMERA_THIRD_PERSON);
		bool isColliding = false;

		//CheckCollisionBoxSphere()


		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(cam);
		{
			DrawModel(blueBall, ballPosition, 1.0f, WHITE);
			Vector3 ballSize = SubstractVec3(ballBB.max, ballBB.min);
			DrawSphereWires(ballPosition, ballSize.x / 2, 20, 20, PURPLE);
			if (!isColliding) {
				DrawModel(blueBall, ballPosition, 1.0f, WHITE);
			} else {
				DrawModel(redBall, ballPosition, 1.0f, WHITE);
			}

			for (size_t i = 0; i < TILE_COUNT; i++) {
				DrawModel(greenTile, positions[i], 1.0f, WHITE);	
			}
			Vector3 greenTileSize = SubstractVec3(tileBB.max, tileBB.min);
			DrawCubeWires(origin, greenTileSize.x * 8, greenTileSize.y * 2, greenTileSize.z * 8, PURPLE);
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

Vector3 SubstractVec3(Vector3 a, Vector3 b) {
	return (Vector3){.x = a.x - b.x, .y = a.y - b.y, .z = a.z - b.z};
}