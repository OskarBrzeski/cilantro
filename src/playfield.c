#include "playfield.h"
#include "globals.h"
#include "raylib.h"
#include "utils.h"

void
renderPlayField(void)
{
        renderFieldLayout();
}

void
renderFieldLayout(void)
{
        DrawRectangle(0, 0, 300, windowHeight, GRAY);
        renderTotalChips();
}

void
renderTotalChips(void)
{
        int chips = 347645; // temporary

        Rectangle rec = {
            .x = 15,
            .y = 150,
            .width = 270,
            .height = 60,
        };
        DrawRectangleRounded(rec, 0.25f, 0, BLACK);

        int fontSize = 30;
        const char *chipsString = intToString(chips, 16);
        int textWidth = MeasureText(chipsString, fontSize);
        int textX = rec.x + (rec.width - textWidth) / 2;
        int textY = rec.y + (rec.height - fontSize) / 2;
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
}
