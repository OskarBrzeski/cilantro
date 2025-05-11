#include "utils.h"
#include <stdio.h>

const char *
intToString(int number, int strSize)
{
        char *result;
        snprintf(result, strSize, "%d", number);
        return result;
}
