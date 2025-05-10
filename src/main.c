#include "globals.h"
#include "raylib.h"
#include "title.h"

bool quitGame = false;
int windowWidth = 1200;
int windowHeight = 900;

int
main()
{
        InitWindow(windowWidth, windowHeight, "Cilantro");

        while (!WindowShouldClose() && !quitGame)
        {
                BeginDrawing();
                ClearBackground(BLACK);
                renderTitleScreen();
                DrawFPS(5, 5);
                EndDrawing();
        }

        CloseWindow();

        return 0;
}
