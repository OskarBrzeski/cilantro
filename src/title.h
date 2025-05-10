#ifndef TITLE_H
#define TITLE_H

void
renderTitleScreen(void);

void
renderTitle(void);

void
renderTitleButtons(void);

void
renderTitleButton(int buttonCount, int buttonPos, const char *text);

int
calculateButtonX(int buttonWidth, int buttonCount, int buttonPos);

void
handleInputTitle(void);

#endif
