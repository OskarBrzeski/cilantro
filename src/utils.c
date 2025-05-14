#include "utils.h"
#include "raylib.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const char *
intToString(int64_t number, int strSize)
{
        char *result = malloc(strSize);
        snprintf(result, strSize, "%li", number);
        return result;
}

int
leftTextX(Rectangle *rec, int offset)
{
        return rec->x + offset;
}

int
centreTextX(Rectangle *rec, int textWidth)
{
        return rec->x + (rec->width - textWidth) / 2;
}

int
rightTextX(Rectangle *rec, int textWidth, int offset)
{
        return rec->x + rec->width - offset - textWidth;
}

int
upTextY(Rectangle *rec, int offset)
{
        return rec->y + offset;
}

int
centreTextY(Rectangle *rec, int fontSize)
{
        return rec->y + (rec->height - fontSize) / 2 + 2;
}

int
downTextY(Rectangle *rec, int fontSize, int offset)
{
        return rec->y + rec->height - offset - fontSize;
}
