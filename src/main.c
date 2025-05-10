#include "raylib.h"

#define WINDOWWIDTH 1200
#define WINDOWHEIGHT 900
#define SQUAREWIDTH 250

int
main()
{
        InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Cilantro");

        while (!WindowShouldClose())
        {
                BeginDrawing();
                ClearBackground(BLACK);
                DrawRectangle((WINDOWWIDTH - SQUAREWIDTH) / 2,
                              (WINDOWHEIGHT - SQUAREWIDTH) / 2, SQUAREWIDTH,
                              SQUAREWIDTH, RAYWHITE);
                DrawFPS(5, 5);
                EndDrawing();
        }

        CloseWindow();

        return 0;
}
