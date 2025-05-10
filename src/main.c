#include "raylib.h"
#include "title.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900

int
main()
{
        InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Cilantro");

        while (!WindowShouldClose())
        {
                BeginDrawing();
                ClearBackground(BLACK);
                renderTitleScreen(WINDOW_WIDTH, WINDOW_HEIGHT);
                DrawFPS(5, 5);
                EndDrawing();
        }

        CloseWindow();

        return 0;
}
