#include "title.h"
#include "raylib.h"
#include <stdint.h>

void
renderTitleScreen(int width, int height)
{
        renderTitle(width, height);
        renderTitleButtons(width, height);
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

void
renderTitleButtons(int width, int height)
{
        int buttonCount = 3;

        renderTitleButton(width, height, buttonCount, 0, "Play");
        renderTitleButton(width, height, buttonCount, 1, "Options");
        renderTitleButton(width, height, buttonCount, 2, "Quit");
}

void
renderTitleButton(int width, int height, int buttonCount, int buttonPos,
                  const char *text)
{
        int buttonWidth = 200;
        int buttonHeight = 100;
        int buttonY = 650;
        int buttonX = calculateButtonX(width, height, buttonWidth, buttonCount,
                                       buttonPos);

        Rectangle button = (Rectangle){.x = buttonX,
                                       .y = buttonY,
                                       .width = buttonWidth,
                                       .height = buttonHeight};
        DrawRectangleLinesEx(button, 4.0f, RAYWHITE);

        int fontSize = 30;
        int textWidth = MeasureText(text, fontSize);
        int textY = buttonY + (buttonHeight - fontSize) / 2;
        int textX = buttonX + (buttonWidth - textWidth) / 2;
        DrawText(text, textX, textY, fontSize, RAYWHITE);
}

int
calculateButtonX(int width, int height, int buttonWidth, int buttonCount,
                 int buttonPos)
{
        int buttonGap = 40;
        int leftmostX = (width - buttonWidth * buttonCount -
                         buttonGap * (buttonCount - 1)) /
                        2;
        return leftmostX + (buttonWidth + buttonGap) * (buttonPos);
}
