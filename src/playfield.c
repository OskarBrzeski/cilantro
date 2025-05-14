#include "playfield.h"
#include "globals.h"
#include "raylib.h"
#include "utils.h"
#include <stdint.h>

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
        renderChipsAndMult();
        renderHands();
        renderDiscards();
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
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        const char *goalString = intToString(goal, fontSize);
        int textWidth = MeasureText(goalString, fontSize);
        int textX = centreTextX(&rec, textWidth);
        int textY = centreTextY(&rec, fontSize);
        DrawText(goalString, textX, textY, fontSize, RAYWHITE);
}

void
renderTotalChips(void)
{
        int64_t chips = 64764519060; // temporary

        Rectangle rec = {
            .x = 15,
            .y = 150,
            .width = 270,
            .height = 60,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        int fontSize = 40;
        const char *chipsString = intToString(chips, 16);
        int textWidth = MeasureText(chipsString, fontSize);
        int textX = centreTextX(&rec, textWidth);
        int textY = centreTextY(&rec, fontSize);
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
}

void
renderChipsAndMult(void)
{
        renderChips();
        DrawText("X", 135, 302, 50, WHITE);
        renderMult();
}

void
renderChips(void)
{
        int chips = 620;

        Rectangle rec = {
            .x = 15,
            .y = 300,
            .width = 110,
            .height = 50,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLUE);

        int fontSize = 40;
        const char *chipsString = intToString(chips, 16);
        int textWidth = MeasureText(chipsString, fontSize);
        int textX = rightTextX(&rec, textWidth, 10);
        int textY = centreTextY(&rec, fontSize);
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
}

void
renderMult(void)
{
        int mult = 326;

        Rectangle rec = {
            .x = 300 - 110 - 15,
            .y = 300,
            .width = 110,
            .height = 50,
        };
        DrawRectangleRounded(rec, 0.3f, 0, RED);

        int fontSize = 40;
        const char *chipsString = intToString(mult, 16);
        int textX = leftTextX(&rec, 10);
        int textY = centreTextY(&rec, fontSize);
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
}

void
renderHands(void)
{
        int hands = 4;

        Rectangle rec = {
            .x = 80,
            .y = 500,
            .width = 100,
            .height = 70,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        int labelFontSize = 20;
        const char *handsLabel = "Hands";
        int labelWidth = MeasureText(handsLabel, labelFontSize);
        int labelX = centreTextX(&rec, labelWidth);
        int labelY = upTextY(&rec, 2);
        DrawText(handsLabel, labelX, labelY, labelFontSize, WHITE);

        int handsFontSize = 40;
        const char *handsCount = intToString(hands, 4);
        int handsWidth = MeasureText(handsCount, handsFontSize);
        int handsX = centreTextX(&rec, handsWidth);
        int handsY = downTextY(&rec, handsFontSize, 2);
        DrawText(handsCount, handsX, handsY, handsFontSize, WHITE);
}

void
renderDiscards(void)
{
        int hands = 4;

        Rectangle rec = {
            .x = 190,
            .y = 500,
            .width = 100,
            .height = 70,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        int labelFontSize = 20;
        const char *handsLabel = "Discards";
        int labelWidth = MeasureText(handsLabel, labelFontSize);
        int labelX = centreTextX(&rec, labelWidth);
        int labelY = upTextY(&rec, 2);
        DrawText(handsLabel, labelX, labelY, labelFontSize, WHITE);

        int handsFontSize = 40;
        const char *handsCount = intToString(hands, 4);
        int handsWidth = MeasureText(handsCount, handsFontSize);
        int handsX = centreTextX(&rec, handsWidth);
        int handsY = downTextY(&rec, handsFontSize, 2);
        DrawText(handsCount, handsX, handsY, handsFontSize, WHITE);
}
