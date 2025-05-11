#include "globals.h"
#include "playfield.h"
#include "raylib.h"

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
                renderPlayField();
                DrawFPS(5, 5);
                EndDrawing();
        }

        CloseWindow();

        return 0;
}
