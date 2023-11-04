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

int final_val;

// Function for representing colors in 4 regions 
int factor4(int val)
{
	if(val >=0 && val<=63)
	{
		final_val=32;
	}
	else if(val >=64 && val <=127)
	{
		final_val=96;
	}
	else if(val >=128 && val <=191)
	{
		final_val=160;
	}
	else if(val >= 192 && val <=255)
	{
		final_val=224;
	}
	return final_val;
} 

// Function for representing colors in 8 regions
int factor8(int val)
{
	if(val >=0 && val<=31)
	{
		final_val=16;
	}
	else if(val >=32 && val <=63)
	{
		final_val=48;
	}
	else if(val >=64 && val <=95)
	{
		final_val=80;
	}	
	else if(val >=96 && val <=127)
	{
		final_val=112;
	}
	else if(val >=128 && val <=159)
	{
		final_val=144;
	}
	else if(val >=160 && val <=191)
	{
		final_val=176;
	}
	else if(val >=192 && val <=223)
	{
		final_val=208;
	}
	else if(val >=224 && val <=255)
	{
		final_val=240;
	}
	return final_val;
}

// Function for representing colors in 16 regions
int factor16(int val)
{
	if(val >=0 && val <=15)
	{
		final_val=8;
	}
	else if(val >=16 && val <=31)
	{
		final_val=24;
	}
	else if(val >=32 && val <=47)
	{
		final_val=40;
	}
	else if(val >=48 && val <=63)
	{
		final_val=56;
	}
	else if(val >=64 && val <=79)
	{
		final_val=72;
	}
	else if(val >=80 && val <=95)
	{
		final_val=88;
	}
	else if(val >=96 && val <=111)
	{
		final_val=104;
	}
	else if(val >=112 && val <=127)
	{
		final_val=120;
	}
	else if(val >=128 && val <=143)
	{
		final_val=136;
	}
	else if(val >=144 && val <=159)
	{
		final_val=152;
	}
	else if(val >=160 && val <=175)
	{
		final_val=168;
	}
	else if(val >=176 && val <=191)
	{
		final_val=184;
	}
	else if(val >=192 && val <=207)
	{
		final_val=200;
	}
	else if(val >=208 && val <=223)
	{
		final_val=216;
	}
	else if(val >=224 && val <=239)
	{
		final_val=232;
	}
	else if(val >=240 && val <=255)
	{
		final_val=248;
	}
	return final_val;
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

            // Quantization logic for factor 2 (8 colors)
            if (Factor_value == 2) 
            {
               colorquantized_red =  ( red <= 127 ) ? 64 : 192 ;
	       colorquantized_green =  ( green <= 127 ) ? 64 : 192 ;
               colorquantized_blue =  ( blue <= 127 ) ? 64 : 192 ;
		
	    }
	    // Quantization logic for factor 4 (64 colors)
            if (Factor_value == 4) 
            {
               colorquantized_red =  factor4(red);
	       colorquantized_green =  factor4(green);
               colorquantized_blue =  factor4(blue);
		
	    }
	    // Quantization logic for factor 8 (512 colors)
            if (Factor_value == 8) 
            {
               colorquantized_red =  factor8(red);
	       colorquantized_green =  factor8(green);
               colorquantized_blue =  factor8(blue);
		
	    }
	   // Quantization logic for factor 16 (4096 colors)
            if (Factor_value == 16) 
            {
               colorquantized_red =  factor16(red);
	       colorquantized_green =  factor16(green);
               colorquantized_blue =  factor16(blue);
		
	    }

            // Assigning the quantized values to the pixels in the new image
            PutRPixel(image_quantized_2, cols, j, i, colorquantized_red);
            PutGPixel(image_quantized_2, cols, j, i, colorquantized_green);
            PutBPixel(image_quantized_2, cols, j, i, colorquantized_blue);
		  
		   
	
      }
  }
  
  // WritePPM("out.ppm", image, rows, cols);

     WritePPM("quantized.ppm", image_quantized_2 , rows, cols);
}
