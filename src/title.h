#ifndef TITLE_H
#define TITLE_H

typedef enum
{
        TITLE_PLAY = 0,
        TITLE_OPTIONS,
        TITLE_QUIT,
        TITLE_BUTTON_COUNT,
} TitleButtonEnum;

void
renderTitleScreen(void);

void
renderTitle(void);

void
renderTitleButtons(void);

void
renderTitleButton(int buttonCount, int buttonPos);

int
calculateButtonX(int buttonWidth, int buttonCount, int buttonPos);

const char *
titleButtonText(int buttonPos);

void
handleInputTitle(void);

void
titleButtonPressed(void);

#endif
