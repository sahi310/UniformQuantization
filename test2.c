/* Programming Assignment - 2
compiler used : Tiny C*/

#define FILENAME_LEN 20
//#define G_MASK_SIZE 100
#define IMAGE_SIZE 400
#define mask_size 1

#include "PPMTools.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int uniform(int value,int fv)
{
 int qValue = 0;

    if (fv == 2) 
	{
        qValue = (value < 128) ? 64 : 192;
    } 
	else if (fv == 4) 
	{
        if (value < 64) 
		{
            qValue = 32;
        } 
		else if (value < 128) 
		{
            qValue = 96;
        } 
		else if (value < 192) {
            qValue = 160;
        } 
		else
		{
            qValue = 224;
        }
    } 
	else if (fv == 8) 
	{
        qValue = (value / 32) * 32 + 16;
    } 
	else if (fv == 16) 
	{
        qValue = (value / 16) * 16 + 8;
    } 

    return qValue;
	
} 

void main()
{
  unsigned char *image,*q_image;
  int cols, rows, i, j,fv;
  int red,blue,green;
  char filename[FILENAME_LEN];
  
  printf("Enter image file name:");
  scanf("%s", filename);

  printf("Enter the Factor value: ");
  scanf("%d", &fv);

  image = ReadPPM(filename,&cols, &rows);
  q_image = CreatePPM(cols, rows);

  for (i = 0; i < rows; i++) 
  {
      for (j = 0; j < cols; j++) 
      {
          PutRPixel(q_image, cols, j, i, 255);
          PutGPixel(q_image, cols, j, i, 255);
          PutBPixel(q_image, cols, j, i, 255);
       }
  }
  for (i=0;i<rows;i++) 
  {
      for(j=0;j<cols;j++) 
	  {
          red=(int)GetRPixel(image,cols,j,i);
          green=(int)GetGPixel(image, cols,j,i);
		  blue=(int)GetBPixel(image, cols,j,i);
		  
		  int redvalue,greenvalue,bluevalue;
		  
		  redvalue = uniform(red,fv);
		  greenvalue= uniform(green,fv);
		  bluevalue = uniform(blue,fv);
		
          // Assigning the quantized values to the pixels in the new image
          PutRPixel(q_image, cols, j, i, redvalue);
          PutGPixel(q_image, cols, j, i, greenvalue);
          PutBPixel(q_image, cols, j, i, bluevalue);
      }
  }
  
   WritePPM("out1.ppm", q_image, rows, cols);

}
