#include "raylib.h"

const char *WINDOW_TITLE = "Minigolf";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(60);

	Texture2D texture = LoadTexture(ASSETS_PATH "penguin.png");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);

		const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
		const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
		DrawTexture(texture, texture_x, texture_y, WHITE);

		const char *text = "OMG! IT WORKS!";
		const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
		DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2,
				 texture_y + texture.height + text_size.y + 10, 20, BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
