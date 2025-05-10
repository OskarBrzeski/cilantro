#include "title.h"
#include "raylib.h"
#include <stdint.h>

void
renderTitleScreen(int width, int height)
{
        renderTitle(width, height);
}

void
renderTitle(int width, int height)
{

        int fontSize = 130;
        int textWidth = MeasureText("Cilantro", fontSize);
        int textX = (width - textWidth) / 2;
        int textY = (height - textWidth) / 2;
        DrawText("Cilantro", textX, textY, fontSize, RAYWHITE);
}
