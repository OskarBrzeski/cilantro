#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"
#include <stdint.h>

char *
intToString(int64_t number, int strSize);

char *
concatText(const char *first, const char *second);

int
leftTextX(Rectangle *rec, int offset);

int
centreTextX(Rectangle *rec, int textWidth);

int
rightTextX(Rectangle *rec, int textWidth, int offset);

int
upTextY(Rectangle *rec, int offset);

int
centreTextY(Rectangle *rec, int fontSize);

int
downTextY(Rectangle *rec, int fontSize, int offset);

#endif
