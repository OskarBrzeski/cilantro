#include <stdint.h>

void
renderTitleScreen(int width, int height);

void
renderTitle(int width, int height);

void
renderTitleButtons(int width, int height);

void
renderTitleButton(int width, int height, int buttonCount, int buttonPos,
                  const char *text);

int
calculateButtonX(int width, int height, int buttonWidth, int buttonCount,
                 int buttonPos);
