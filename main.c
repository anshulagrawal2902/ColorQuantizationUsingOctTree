#include <stdio.h>
#include <stdlib.h>
#include "headerResolver.h"

int main()
{
    QUANTIZER q;
    init_Quantizer(&q, 8);
    add_RGB_values_to_Quantizer("RGB_vals (5).txt", q);
    OCT_NODE *arr;
    arr = getLeafNodes(q->root);
    int i = 0;
    while (arr[i] != NULL)
    {
        }
}