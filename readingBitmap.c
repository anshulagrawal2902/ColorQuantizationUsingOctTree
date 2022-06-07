#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "readingBitmap.h"

unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader, char *textFileName)
{
    FILE *filePtr;
    BITMAPFILEHEADER bitmapFileHeader;
    unsigned char *bitmapImage;
    int imageIdx = 0;
    unsigned char tempRGB;

    //open file in read binary mode
    filePtr = fopen(filename, "rb");
    if (filePtr == NULL)
        return NULL;

    //read the bitmap file header
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

    //verify that this is a .BMP file by checking bitmap id
    if (bitmapFileHeader.bfType != 0x4D42)
    {
        fclose(filePtr);
        return NULL;
    }

    //read the bitmap info header
    fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

    //move file pointer to the beginning of bitmap data
    fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

    //allocate enough memory for the bitmap image data
    bitmapImage = (unsigned char *)malloc(sizeof(unsigned char) * bitmapInfoHeader->biSizeImage);

    //verify memory allocation
    if (!bitmapImage)
    {
        free(bitmapImage);
        fclose(filePtr);
        return NULL;
    }

    //read in the bitmap image data
    fread(bitmapImage, bitmapInfoHeader->biSizeImage, 1, filePtr);

    //make sure bitmap image data was read
    if (bitmapImage == NULL)
    {
        fclose(filePtr);
        return NULL;
    }

    //swap the R and B values to get RGB (bitmap is BGR)
    // for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3)
    // {
    //     tempRGB = bitmapImage[imageIdx];
    //     bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
    //     bitmapImage[imageIdx + 2] = tempRGB;
    // }

    //close file and return bitmap image data
    fclose(filePtr);

    // writing bmp image to text file
    FILE *filePtr1 = fopen(textFileName, "w");

    for (int i = 0; i < bitmapInfoHeader->biSizeImage; i++)
    {
        fprintf(filePtr1, "%d ", bitmapImage[i]);   
    }

    fclose(filePtr1);
    return bitmapImage;
}
