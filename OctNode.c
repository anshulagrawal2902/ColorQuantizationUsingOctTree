#include "OctNode.h"
#include <stdlib.h>
#include <stdio.h>

void initOctNode(OCT_NODE *OctNode)
{
    *OctNode = (OCT_NODE)malloc(sizeof(OctNode));
    init_color(&((*OctNode)->c), 0, 0, 0);
    (*OctNode)->children = (OCT_NODE *)malloc(sizeof(OCT_NODE) * 8);
    for (int i = 0; i < 8; i++)
    {
        (*OctNode)->children[i] = NULL;
    }
}

int isLeaf(OCT_NODE OctNode)
{
    if (OctNode->pixelCount > 0)
        return 1;
    else
        return 0;
}

void getLeafNodes(OCT_NODE OctNode, OCT_NODE **arr, int rear)
{
    if (OctNode->pixelCount > 0)
    {
        (*arr)[rear++] = OctNode;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (OctNode->children[i] == NULL)
            continue;
        getLeafNodes(OctNode->children[i], arr, rear);
    }
}
