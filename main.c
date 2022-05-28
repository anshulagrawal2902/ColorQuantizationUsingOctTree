#include <stdio.h>
#include <stdlib.h>
#include "OctNode.h"
int main()
{
    OCT_NODE OctNode;
    initOctNode(&OctNode);
    initOctNode(&(OctNode->children[3]));
    OctNode->children[3]->pixelCount = 2;
    OCT_NODE *arr;
    getLeafNodes(OctNode, &arr, 0);
    for (int i = 0; i < 4; i++)
    {
        printf("%d", arr[0]->pixelCount);
    }
    printf("%d", OctNode->c->blue);
    printf("%d", OctNode->children[3]->c->blue);
}