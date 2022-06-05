#include <stdio.h>
#include <stdlib.h>
#include "headerResolver.h"
#include"readingBitmap.h"

int main()
{

    BITMAPINFOHEADER bitmapInfoHeader;
    unsigned char *bitmapData;
    bitmapData = LoadBitmapFile("image3.bmp", &bitmapInfoHeader, "image3.txt");

    QUANTIZER q;
    init_Quantizer(&q);
    add_RGB_values_to_Quantizer("image3.txt", q);
    COLOR *pallete = makePallete(100, q);
    writeQuantizedImageToFile(q, "qimage3.txt", pallete, "image3.txt");
}
