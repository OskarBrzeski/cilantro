#include "title.h"
#include "globals.h"
#include "raylib.h"

int buttonSelected = 0;
int buttonCount = 3;

void
renderTitleScreen()
{
        handleInputTitle();
        renderTitle();
        renderTitleButtons();
}

void
renderTitle()
{
        int fontSize = 130;
        int textWidth = MeasureText("Cilantro", fontSize);
        int textX = (windowWidth - textWidth) / 2;
        int textY = (windowHeight - textWidth) / 2;
        DrawText("Cilantro", textX, textY, fontSize, RAYWHITE);
}

void
renderTitleButtons()
{
        renderTitleButton(buttonCount, 0, "Play");
        renderTitleButton(buttonCount, 1, "Options");
        renderTitleButton(buttonCount, 2, "Quit");
}

void
renderTitleButton(int buttonCount, int buttonPos, const char *text)
{
        int buttonWidth = 200;
        int buttonHeight = 100;
        int buttonY = 650;
        int buttonX = calculateButtonX(buttonWidth, buttonCount, buttonPos);

        Rectangle button = (Rectangle){.x = buttonX,
                                       .y = buttonY,
                                       .width = buttonWidth,
                                       .height = buttonHeight};
        if (buttonSelected == buttonPos)
        {
                DrawRectangleRec(button, GRAY);
        }
        DrawRectangleLinesEx(button, 4.0f, RAYWHITE);

        int fontSize = 30;
        int textWidth = MeasureText(text, fontSize);
        int textY = buttonY + (buttonHeight - fontSize) / 2;
        int textX = buttonX + (buttonWidth - textWidth) / 2;
        DrawText(text, textX, textY, fontSize, RAYWHITE);
}

int
calculateButtonX(int buttonWidth, int buttonCount, int buttonPos)
{
        int buttonGap = 40;
        int leftmostX = (windowWidth - buttonWidth * buttonCount -
                         buttonGap * (buttonCount - 1)) /
                        2;
        return leftmostX + (buttonWidth + buttonGap) * (buttonPos);
}

void
handleInputTitle(void)
{
        int key;
        do
        {
                key = GetKeyPressed();

                if (key == KEY_LEFT && buttonSelected > 0)
                {
                        --buttonSelected;
                }

                if (key == KEY_RIGHT && buttonSelected < (buttonCount - 1))
                {
                        ++buttonSelected;
                }
        } while (key != 0);
}
