#include <stdio.h>
#include <stdlib.h>
#include "color.h"

int main()
{
    COLOR c;
    init_color(&c, 12, 13, 14);
    // printf("jello");
    int *arr = getArray(c);
    for (int i = 0; i < 3; i++)
    {
        printf("%d", i);
    }
    // printf("%s", toString(c));
}