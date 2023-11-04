/* Programming Assignment - 2
Assignemnt Name : Uniform Quantization
Name : Sahithi Priya Bhavanam
euid : sb1923 
compiler used : Tiny C*/

#define FILENAME_LEN 20
//#define G_MASK_SIZE 100
#define IMAGE_SIZE 400
#define mask_size 1

#include "PPMTools.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Pixel_quantization(int Factor_value, int pixel) 
{
	int arr[256]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
	int size = sizeof(arr) / sizeof(arr[0]);
    	int pixelsPerPart = size / Factor_value;
    	for (int i = 0; i < size; i++) 
		{
        	if (i % pixelsPerPart == 0) 
			{

        	}
    	}
       for (int i = 0; i < size; i += pixelsPerPart) 
       {
       		for (int j = i; j < i + pixelsPerPart; j++) 
			{
            		if (arr[j] == pixel) 
					{
                		double sum = 0;
                		for (int k = i; k < i + pixelsPerPart; k++) 
						{
                    		sum += arr[k];
                		}
					int quantized_value = (int)ceil((double)sum / pixelsPerPart);
					return quantized_value;
					}
			}
    	}
}

void main()
{
  unsigned char *image,*image_quantized_2;
  int cols, rows, i, j;
  int red,blue,green,Factor_value;
  char filename[FILENAME_LEN];
  
  printf("Enter image file name:");
  scanf("%s", filename);

  printf("Enter the Factor value (2(8-colors), 4(64-colors), 8(512-colors), or 16(4096-colors)) : ");
  scanf("%d", &Factor_value);

  image = ReadPPM(filename,&cols, &rows);
  image_quantized_2 = CreatePPM(cols, rows);

  for (i = 0; i < rows; i++) 
  {
      for (j = 0; j < cols; j++) 
      {
          PutRPixel(image_quantized_2, cols, j, i, 255);
          PutGPixel(image_quantized_2, cols, j, i, 255);
          PutBPixel(image_quantized_2, cols, j, i, 255);
       }
  }
  for (i=0;i<rows;i++) {
      for(j=0;j<cols;j++) {
          red=(int)GetRPixel(image,cols,j,i);
          green=(int)GetGPixel(image, cols,j,i);
	  blue=(int)GetBPixel(image, cols,j,i);
		
	  float colorquantized_red, colorquantized_green, colorquantized_blue;

          colorquantized_red =  Pixel_quantization(Factor_value,red) ;
		  colorquantized_green =  Pixel_quantization(Factor_value,green) ;
          colorquantized_blue =  Pixel_quantization(Factor_value,blue) ;

          // Assigning the quantized values to the pixels in the new image
          PutRPixel(image_quantized_2, cols, j, i, colorquantized_red);
          PutGPixel(image_quantized_2, cols, j, i, colorquantized_green);
          PutBPixel(image_quantized_2, cols, j, i, colorquantized_blue);	   
	
      }
  }
  
  // WritePPM("out.ppm", image, rows, cols);

     WritePPM("quantized.ppm", image_quantized_2 , rows, cols);
}
