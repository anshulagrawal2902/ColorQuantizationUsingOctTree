#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerResolver.h"
// #include "readingBitmap.h"
// #include "readbmp.c"


void doMagic(char* imageName, int colorCount){

    QUANTIZER q;
    init_Quantizer(&q);
    add_RGB_values_to_Quantizer(imageName, q);
    COLOR *pallete = makePallete(colorCount, q);

    char fileName[100] ;
    strcpy(fileName, imageName);
    fileName[strlen(fileName) - 3] = 't';
    fileName[strlen(fileName) - 2] = 'x';
    fileName[strlen(fileName) - 1] = 't';
    char qImage[100];
    qImage[0] = 'q';
    strcpy(&qImage[1], fileName);
    writeQuantizedImageToFile(q, qImage, pallete, fileName);
}



int main()
{
    // QUANTIZER q;
    // init_Quantizer(&q);
    // add_RGB_values_to_Quantizer("MARBLES.BMP", q);
    // COLOR *pallete = makePallete(100, q);
    // writeQuantizedImageToFile(q, "qmarbles.txt", pallete, "MARBLES.txt");

    doMagic("MARBLES.BMP", 100);

    // openbmpfile("image1.BMP", "image1.txt");
}

