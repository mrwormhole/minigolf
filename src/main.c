#include <stdio.h>

#include "raylib.h"


const char *WINDOW_TITLE = "Minigolf";
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const float MOUSE_WHEEL_SENSITIVITY = 0.125f;

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

	Model m = LoadModel(ASSETS_PATH "ramp.glb");
	Vector3 pos = {0.0f, 0.0f, 0.0f};

	while (!WindowShouldClose()) {

        float wheel = GetMouseWheelMove();
		if (wheel > 0) {
            cam.position.x += (cam.target.x - cam.position.x) * MOUSE_WHEEL_SENSITIVITY;
            cam.position.y += (cam.target.y -cam.position.y) * MOUSE_WHEEL_SENSITIVITY;
            cam.position.z += (cam.target.z - cam.position.z) * MOUSE_WHEEL_SENSITIVITY;
		}
        if (wheel < 0) {
            cam.position.x -= (cam.target.x - cam.position.x) * MOUSE_WHEEL_SENSITIVITY;
            cam.position.y -= (cam.target.y -cam.position.y) * MOUSE_WHEEL_SENSITIVITY;
            cam.position.z -= (cam.target.z - cam.position.z) *MOUSE_WHEEL_SENSITIVITY;
		}

		UpdateCamera(&cam, CAMERA_FIRST_PERSON);

		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(cam);
		{
			DrawModel(m, pos, 1.0f, WHITE);
			DrawGrid(10, 1.0f);
		}
		EndMode3D();
        {
            DrawFPS(10, 10);
        }
		EndDrawing();
	}

	UnloadModel(m);
	CloseWindow();

	return 0;
}
