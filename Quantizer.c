#include <stdlib.h>
#include <stdio.h>
#include "headerResolver.h"

#ifndef Constants
#define MAX_DEPTH 8
#define MAX_PIXELS 17000000
#endif

void init_Quantizer(QUANTIZER *quant, int levels)
{
    (*quant) = malloc(sizeof(Quantizer));
    (*quant)->levels = malloc(sizeof(LEVELSNODE) * MAX_DEPTH);
    for (int i = 0; i < MAX_DEPTH; i++)
    {
        (*quant)->levels[i] = NULL;
    }
    initOctNode(&((*quant)->root), (*quant), 0);
}

void addColortoQuantizer(COLOR c, QUANTIZER quant)
{
    addColor(c, quant->root, 0, quant);
}

void addLevelNode(OCT_NODE OctNode, int level, QUANTIZER Quantizer)
{
    LEVELSNODE LevelsNode = malloc(sizeof(LevelsNode));
    LevelsNode->nodePtr = OctNode;
    LevelsNode->nextPtr = Quantizer->levels[level];
    Quantizer->levels[level] = LevelsNode;
}

void add_RGB_values_to_Quantizer(char *fileName, QUANTIZER Quantizer)
{
    FILE *filePtr = fopen(fileName, "r");
    if (NULL == filePtr)
    {
        printf("file can't be opened \n");
    }
    char ch = '0';
    int n = 0;
    while (ch != EOF)
    {
        int arr[3];
        for (int i = 0; i < 3; i++)
        {
            n = 0;
            while (ch != ' ')
            {
                n = n * 10 + (ch - 48);
                ch = fgetc(filePtr);
            }
            ch = fgetc(filePtr);
            arr[i] = n;
        }
        COLOR c;
        init_color(&c, arr[0], arr[1], arr[2]);
        addColortoQuantizer(c, Quantizer);
    }
}
