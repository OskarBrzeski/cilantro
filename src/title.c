#include "title.h"
#include "globals.h"
#include "raylib.h"

int buttonSelected = 0;

void
renderTitleScreen(void)
{
        handleInputTitle();
        renderTitle();
        renderTitleButtons();
}

void
renderTitle(void)
{
        int fontSize = 130;
        int textWidth = MeasureText("Cilantro", fontSize);
        int textX = (windowWidth - textWidth) / 2;
        int textY = (windowHeight - textWidth) / 2;
        DrawText("Cilantro", textX, textY, fontSize, RAYWHITE);
}

void
renderTitleButtons(void)
{
        renderTitleButton(TITLE_BUTTON_COUNT, 0);
        renderTitleButton(TITLE_BUTTON_COUNT, 1);
        renderTitleButton(TITLE_BUTTON_COUNT, 2);
}

void
renderTitleButton(int TITLE_BUTTON_COUNT, int buttonPos)
{
        int buttonWidth = 200;
        int buttonHeight = 100;
        int buttonY = 650;
        int buttonX =
            calculateButtonX(buttonWidth, TITLE_BUTTON_COUNT, buttonPos);

        Rectangle button = (Rectangle){.x = buttonX,
                                       .y = buttonY,
                                       .width = buttonWidth,
                                       .height = buttonHeight};
        if (buttonSelected == buttonPos)
        {
                DrawRectangleRec(button, GRAY);
        }
        DrawRectangleLinesEx(button, 4.0f, RAYWHITE);

        const char *text = titleButtonText(buttonPos);
        int fontSize = 30;
        int textWidth = MeasureText(text, fontSize);
        int textY = buttonY + (buttonHeight - fontSize) / 2;
        int textX = buttonX + (buttonWidth - textWidth) / 2;
        DrawText(text, textX, textY, fontSize, RAYWHITE);
}

int
calculateButtonX(int buttonWidth, int TITLE_BUTTON_COUNT, int buttonPos)
{
        int buttonGap = 40;
        int leftmostX = (windowWidth - buttonWidth * TITLE_BUTTON_COUNT -
                         buttonGap * (TITLE_BUTTON_COUNT - 1)) /
                        2;
        return leftmostX + (buttonWidth + buttonGap) * (buttonPos);
}

const char *
titleButtonText(int buttonPos)
{
        switch (buttonPos)
        {
        case TITLE_PLAY:
                return "Play";
        case TITLE_OPTIONS:
                return "Options";
        case TITLE_QUIT:
                return "Quit";
        }
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

                if (key == KEY_RIGHT &&
                    buttonSelected < (TITLE_BUTTON_COUNT - 1))
                {
                        ++buttonSelected;
                }

                if (key == KEY_ENTER)
                {
                        titleButtonPressed();
                }
        } while (key != 0);
}

void
titleButtonPressed(void)
{
        switch (buttonSelected)
        {
        case TITLE_PLAY:
                break;
        case TITLE_OPTIONS:
                break;
        case TITLE_QUIT:
                quitGame = true;
        }
}
