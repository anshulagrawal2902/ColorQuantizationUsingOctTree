#include <stdio.h>
#include <stdlib.h>
#include "headerResolver.h"
#include"readingBitmap.h"

int main()
{
    QUANTIZER q;
    init_Quantizer(&q);
    add_RGB_values_to_Quantizer("image1.txt", q);
    COLOR *pallete = makePallete(256, q);
    writeQuantizedImageToFile(q, "qimage1.txt", pallete, "image1.txt");
}
