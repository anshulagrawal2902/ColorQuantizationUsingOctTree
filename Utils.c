#include "color.h"

int getColorIndex(COLOR color, int level)
{
    int index = 0;
    int mask = 0b10000000 >> level;
    if (color->red & mask)
        index = index | 0b100;
    if (color->green & mask)
        index = index | 0b010;
    if (color->blue & mask)
        index = index | 0b001;

    return index;
}