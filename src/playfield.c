#include "playfield.h"
#include "globals.h"
#include "raylib.h"
#include "utils.h"
#include <stdint.h>
#include <stdlib.h>

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
        renderCash();
        renderAnte();
        renderRound();
}

void
renderChipsGoal(void)
{
        int goal = 500000; // temporary
        int fontSize = 30;

        char *goalLabel = "Goal:";
        DrawText(goalLabel, 15, 90, fontSize, RAYWHITE);

        int goalTextLength = MeasureText(goalLabel, fontSize);

        Rectangle rec = {
            .x = 25 + goalTextLength,
            .y = 80,
            .width = 260 - goalTextLength,
            .height = 50,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        char *goalString = intToString(goal, fontSize);
        int textWidth = MeasureText(goalString, fontSize);
        int textX = centreTextX(&rec, textWidth);
        int textY = centreTextY(&rec, fontSize);
        DrawText(goalString, textX, textY, fontSize, RAYWHITE);
        free(goalString);
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
        char *chipsString = intToString(chips, 16);
        int textWidth = MeasureText(chipsString, fontSize);
        int textX = centreTextX(&rec, textWidth);
        int textY = centreTextY(&rec, fontSize);
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
        free(chipsString);
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
        char *chipsString = intToString(chips, 16);
        int textWidth = MeasureText(chipsString, fontSize);
        int textX = rightTextX(&rec, textWidth, 10);
        int textY = centreTextY(&rec, fontSize);
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
        free(chipsString);
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
        char *chipsString = intToString(mult, 16);
        int textX = leftTextX(&rec, 10);
        int textY = centreTextY(&rec, fontSize);
        DrawText(chipsString, textX, textY, fontSize, RAYWHITE);
        free(chipsString);
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
        char *handsLabel = "Hands";
        int labelWidth = MeasureText(handsLabel, labelFontSize);
        int labelX = centreTextX(&rec, labelWidth);
        int labelY = upTextY(&rec, 2);
        DrawText(handsLabel, labelX, labelY, labelFontSize, WHITE);

        int handsFontSize = 40;
        char *handsCount = intToString(hands, 4);
        int handsWidth = MeasureText(handsCount, handsFontSize);
        int handsX = centreTextX(&rec, handsWidth);
        int handsY = downTextY(&rec, handsFontSize, 2);
        DrawText(handsCount, handsX, handsY, handsFontSize, WHITE);
        free(handsCount);
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
        char *discardsLabel = "Discards";
        int labelWidth = MeasureText(discardsLabel, labelFontSize);
        int labelX = centreTextX(&rec, labelWidth);
        int labelY = upTextY(&rec, 2);
        DrawText(discardsLabel, labelX, labelY, labelFontSize, WHITE);

        int discardsFontSize = 40;
        char *discardsCount = intToString(hands, 4);
        int handsWidth = MeasureText(discardsCount, discardsFontSize);
        int handsX = centreTextX(&rec, handsWidth);
        int handsY = downTextY(&rec, discardsFontSize, 2);
        DrawText(discardsCount, handsX, handsY, discardsFontSize, WHITE);
        free(discardsCount);
}

void
renderCash(void)
{
        int cash = 594;

        Rectangle rec = {
            .x = 80,
            .y = 600,
            .width = 210,
            .height = 70,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        int labelFontSize = 20;
        char *cashLabel = "Cash";
        int labelWidth = MeasureText(cashLabel, labelFontSize);
        int labelX = centreTextX(&rec, labelWidth);
        int labelY = upTextY(&rec, 2);
        DrawText(cashLabel, labelX, labelY, labelFontSize, WHITE);

        int cashFontSize = 40;
        char *cashCount = intToString(cash, 6);
        char *cashText = concatText("$", cashCount);
        int cashWidth = MeasureText(cashText, cashFontSize);
        int cashX = centreTextX(&rec, cashWidth);
        int cashY = downTextY(&rec, cashFontSize, 2);
        DrawText(cashText, cashX, cashY, cashFontSize, WHITE);
}

void
renderAnte(void)
{
        int ante = 13;

        Rectangle rec = {
            .x = 80,
            .y = 700,
            .width = 100,
            .height = 70,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        int labelFontSize = 20;
        char *anteLabel = "Ante";
        int labelWidth = MeasureText(anteLabel, labelFontSize);
        int labelX = centreTextX(&rec, labelWidth);
        int labelY = upTextY(&rec, 2);
        DrawText(anteLabel, labelX, labelY, labelFontSize, WHITE);

        int anteFontSize = 40;
        char *anteCount = intToString(ante, 4);
        char *anteText = concatText(anteCount, "/8");
        int anteWidth = MeasureText(anteText, anteFontSize);
        int anteX = centreTextX(&rec, anteWidth);
        int anteY = downTextY(&rec, anteFontSize, 2);
        DrawText(anteText, anteX, anteY, anteFontSize, WHITE);
        free(anteCount);
}

void
renderRound(void)
{
        int round = 55;

        Rectangle rec = {
            .x = 190,
            .y = 700,
            .width = 100,
            .height = 70,
        };
        DrawRectangleRounded(rec, 0.3f, 0, BLACK);

        int labelFontSize = 20;
        char *roundLabel = "Round";
        int labelWidth = MeasureText(roundLabel, labelFontSize);
        int labelX = centreTextX(&rec, labelWidth);
        int labelY = upTextY(&rec, 2);
        DrawText(roundLabel, labelX, labelY, labelFontSize, WHITE);

        int roundsFontSize = 40;
        char *roundCount = intToString(round, 4);
        int roundWidth = MeasureText(roundCount, roundsFontSize);
        int roundX = centreTextX(&rec, roundWidth);
        int roundY = downTextY(&rec, roundsFontSize, 2);
        DrawText(roundCount, roundX, roundY, roundsFontSize, WHITE);
        free(roundCount);
}
