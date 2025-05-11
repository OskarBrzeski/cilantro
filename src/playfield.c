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
        renderChipsGoal();
        renderTotalChips();
}

void
renderChipsGoal(void)
{
        int goal = 500000; // temporary
        int fontSize = 30;

        const char *goalLabel = "Goal:";
        DrawText(goalLabel, 15, 90, fontSize, RAYWHITE);

        int goalTextLength = MeasureText(goalLabel, fontSize);

        Rectangle rec = {
            .x = 25 + goalTextLength,
            .y = 80,
            .width = 260 - goalTextLength,
            .height = 50,
        };
        DrawRectangleRounded(rec, 0.25f, 0, BLACK);

        const char *goalString = intToString(goal, fontSize);
        int textWidth = MeasureText(goalString, fontSize);
        int textX = rec.x + (rec.width - textWidth) / 2;
        int textY = rec.y + (rec.height - fontSize) / 2;
        DrawText(goalString, textX, textY, fontSize, RAYWHITE);
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

        int fontSize = 40;
        const char *chipsString = intToString(chips, 16);
        int textWidth = MeasureText(chipsString, fontSize);
        int textX = rec.x + (rec.width - textWidth) / 2;
        int textY = rec.y + (rec.height - fontSize) / 2;
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
}
