/*
 ============================================================================
 Date		 : 10/27/2015
 Assignment	 : Assignment 5 Part 1
 Description : This program outputs an image in the form of HTML.
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* The name of the output file */
#define HTML5_SVG_OUTPUT_FILENAME ("A5P1_2015.html")

/* Size of the HTML5 canvas - Do not change */
#define CANVAS_SIZE_X 800
#define CANVAS_SIZE_Y 800



/* ========================================================================= */
/*                       Library Function Declarations                       */
/*            These functions are defined at the end of the file.            */
/*      (Do not modify these declarations or the corresponding functions)    */
/* ========================================================================= */


/* write_prologue
   This function writes the initial part of the HTML file (which sets up the
   graphics interface). This must be called before any graphical data is written
   to the file.
*/
void write_prologue(FILE *f);

/* write_epilogue
   This function writes the final part of the HTML file. This must be called
   after all data has been written, but before the file is closed.
   (The caller is responsible for closing the file afterwards).
*/
void write_epilogue(FILE *f);

/* write_test_pattern
   Using the circle, ellipse and rectangle functions, this function creates
   a test image to the provided file.
*/
void write_test_pattern(FILE *f);

/* ========================================================================= */
/*                               Main Program                                */
/*        Using the types and functions declared above, as well as the       */
/*              Standard Library, implement the functions below.             */
/*       There are a total of 4 functions to implement (including main).     */
/* ========================================================================= */


/* circle
   Write an svg circle tag with the provided x and y coordinates and the
   provided radius. The colour of the circle will be given by the RGB
   colour values in r, g & b and the opacity will be equal to the float
   value alpha.
*/
void circle(FILE *f, int x, int y, int radius, int r, int g, int b, float alpha){
fprintf(f,"<circle cx=\"%d\" cy=\"%d\" r=\"%d\" style=\"fill:rgb(%d,%d,%d); fill-opacity:%f\"/>",x,y,radius,r,g,b,alpha);

	/* Your code here */
} /* circle */

/* ellipse
   Write an svg ellipse tag with the provided x and y coordinates and the
   provided x & y radii. The colour of the ellipse will be given by the RGB
   colour values in r, g & b and the opacity will be equal to the float
   value alpha.
*/
void ellipse(FILE *f, int x, int y, int radius_x, int radius_y, int r, int g, int b, float alpha){
fprintf(f, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" style=\"fill:rgb(%d,%d,%d); opacity:%f\"/>",x,y,radius_x,radius_y,r,g,b,alpha);
	/* Your code here */
} /* ellipse */

/* rectangle
   Write an svg rect tag with the provided x and y coordinates and the
   provided width and height. The colour of the rectangle will be given by the
   RGB colour values in r, g & b and the opacity will be equal to the float
   value alpha.
*/
void rectangle(FILE *f, int x, int y, int width, int height, int r, int g, int b, float alpha){

fprintf(f,"<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill = rgb(%d,%d,%d) fill-opacity = \"%f\" />", x,y,width,height,r,g,b,alpha);


} /* rectangle */

/* main

   The main program must do the following:

	- Open the output file HTML5_SVG_OUTPUT_FILENAME (also defined at the top of this
	  file), which will contain the output HTML code.

	- Call the write_prologue function to write the HTML prologue to the output file.

	- Call the write_test_pattern function to construct a test image.

	- Call the write_epilogue function to write the HTML epilogue to the output file.

	- Close the output file.
*/
int main(){

	/* Your code here */
	FILE *fp = fopen("A5P1_2015.html", "w");
	write_prologue(fp);

	write_test_pattern(fp);
	write_epilogue(fp);

	fclose(fp);



	return EXIT_SUCCESS;
} /* main */


/* ========================================================================= */
/*                           Library Functions                               */
/*        These are declared above, and will be useful to generate           */
/*            the output file. Do not modify these functions.                */
/* ========================================================================= */


/* write_prologue
   This function writes the initial part of the HTML file (which sets up the
   graphics interface). This must be called before any graphical data is written
   to the file.
*/
void write_prologue(FILE *f){
	if (!f){
		printf("writePrologue error: output file == NULL\n");
		exit(1);
	}
	fputs("<!DOCTYPE html>\n",f);
	fputs("<html>\n",f);
	fputs("<head>\n",f);
	fputs("<title>CSC 111 Fall 2015 -  Assignment 5 Part 1</title>\n",f);
	fputs("</head>\n",f);
	fputs("<body>\n",f);
	fprintf(f,"<svg width=\"%dpx\" height=\"%dpx\">\n",CANVAS_SIZE_X,CANVAS_SIZE_Y);
	fprintf(f,"<g transform=\"translate(0 %d)\">\n",CANVAS_SIZE_Y);
	fputs("<g transform=\"scale(1 -1)\">\n",f);
} /* writePrologue */

/* write_epilogue
   This function writes the final part of the HTML file. This must be called
   after all data has been written, but before the file is closed.
   (The caller is responsible for closing the file afterwards).
*/
void write_epilogue(FILE *f){
	if (!f){
		printf("writeEpilogue error: output file == NULL\n");
		exit(1);
	}
	fputs("</g></g>\n",f);
	fputs("</svg>\n",f);
	fputs("</body>\n",f);
	fputs("</html>\n",f);
} /* writeEpilogue */


/* write_test_pattern
   Using the circle, ellipse and rectangle functions, this function creates
   a test image to the provided file.

   You are not expected to understand or modify this function.
*/
void write_test_pattern(FILE *f){
	int x,y;
	int j,row_number;

	rectangle(f, 0, 0, CANVAS_SIZE_X, CANVAS_SIZE_Y, 192, 192, 255, 1.0);


	y = 0;
	row_number = 0;
	for (j = CANVAS_SIZE_Y/10; (3*j)/4 > 0; j = (3*j)/4){
		for (x = 0; x < CANVAS_SIZE_X; x += 2*CANVAS_SIZE_X/10){
			if (row_number%2 == 0){
				rectangle(f, x, y, CANVAS_SIZE_X/10, j, 0, 0, 0, 1.0);
				rectangle(f, x+CANVAS_SIZE_X/10, y, CANVAS_SIZE_X/10, j, 255, 255, 255, 1.0);
			}else{
				rectangle(f, x, y, CANVAS_SIZE_X/10, j, 255, 255, 255, 1.0);
				rectangle(f, x+CANVAS_SIZE_X/10, y, CANVAS_SIZE_X/10, j, 0, 0, 0, 1.0);
			}
		}
		y += j;
		row_number++;
	}

	x = CANVAS_SIZE_X/2;
	y = CANVAS_SIZE_Y/2;
	ellipse(f, x, y, 4*CANVAS_SIZE_X/9, 2*CANVAS_SIZE_Y/9, 64, 255, 64, 0.75);


	y = 5*CANVAS_SIZE_Y/16;
	for (x = 3*CANVAS_SIZE_X/8 - CANVAS_SIZE_X/30; x < 5*CANVAS_SIZE_X/8; x += CANVAS_SIZE_X/8){
		rectangle(f, x, y, CANVAS_SIZE_X/15, CANVAS_SIZE_Y/5, 0, 0, 255, 1.0);
	}

	y = 9*CANVAS_SIZE_Y/16;
	for (x = 3*CANVAS_SIZE_X/8 - CANVAS_SIZE_X/30; x < 5*CANVAS_SIZE_X/8; x += CANVAS_SIZE_X/8){
		rectangle(f, x, y, CANVAS_SIZE_X/15, CANVAS_SIZE_Y/60, 0, 0, 0, 1.0);
	}

	rectangle(f, 3*CANVAS_SIZE_X/8 - CANVAS_SIZE_X/30, 9*CANVAS_SIZE_Y/16, CANVAS_SIZE_X/60, CANVAS_SIZE_Y/16, 0, 0, 0, 1.0);


	rectangle(f, 4*CANVAS_SIZE_X/8 + CANVAS_SIZE_X/60+1, 9*CANVAS_SIZE_Y/16, CANVAS_SIZE_X/60, CANVAS_SIZE_Y/32, 0, 0, 0, 1.0);
	rectangle(f, 4*CANVAS_SIZE_X/8 - CANVAS_SIZE_X/30, 19*CANVAS_SIZE_Y/32, CANVAS_SIZE_X/15, CANVAS_SIZE_Y/60, 0, 0, 0, 1.0);
	rectangle(f, 4*CANVAS_SIZE_X/8 - CANVAS_SIZE_X/30, 19*CANVAS_SIZE_Y/32, CANVAS_SIZE_X/60, CANVAS_SIZE_Y/32, 0, 0, 0, 1.0);

	rectangle(f, 5*CANVAS_SIZE_X/8 - CANVAS_SIZE_X/30, 9*CANVAS_SIZE_Y/16, CANVAS_SIZE_X/60, CANVAS_SIZE_Y/16, 0, 0, 0, 1.0);

	y = 10*CANVAS_SIZE_Y/16;
	for (x = 3*CANVAS_SIZE_X/8 - CANVAS_SIZE_X/30; x < 5*CANVAS_SIZE_X/8; x += CANVAS_SIZE_X/8){
		rectangle(f, x, y, CANVAS_SIZE_X/15, CANVAS_SIZE_Y/60, 0, 0, 0, 1.0);
	}

	y = CANVAS_SIZE_Y/20;
	for (x = CANVAS_SIZE_X/20; x < CANVAS_SIZE_X; x += CANVAS_SIZE_X/10){
		circle(f, x, y, CANVAS_SIZE_X/10, 255, 128, 128, 1.0);
	}


	y = 19*CANVAS_SIZE_Y/20;
	for (x = CANVAS_SIZE_X/20; x < CANVAS_SIZE_X; x += CANVAS_SIZE_X/10){
		circle(f, x, y, CANVAS_SIZE_X/10, 255, 128, 128, 1.0);
	}
} /* write_test_pattern */
