/*
 ============================================================================
 Date		 : 10/26/2015
 Assignment	 : Assignment 5 Part 1
 Description : This program outputs a random image of shapes.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

/* The name of the output file */
#define HTML5_SVG_OUTPUT_FILENAME ("A5P2_2015.html")

/* Size of the HTML5 canvas - Do not change */
#define CANVAS_SIZE 800
#define CANVAS_SIZE_X CANVAS_SIZE
#define CANVAS_SIZE_Y CANVAS_SIZE



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

/* ========================================================================= */
/*                               Main Program                                */
/*        Using the types and functions declared above, as well as the       */
/*              Standard Library, implement the functions below.             */
/*       There are a total of 5 functions to implement (including main).     */
/* ========================================================================= */


/* circle
   Write an svg circle tag with the provided x and y coordinates and the
   provided radius. The colour of the circle will be given by the RGB
   colour values in r, g & b and the opacity will be equal to the float
   value alpha.

   *** COPY YOUR CIRCLE FUNCTION FROM PART 1 ***
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

   *** COPY YOUR ELLIPSE FUNCTION FROM PART 1 ***
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

   *** COPY YOUR RECTANGLE FUNCTION FROM PART 1 ***
*/
void rectangle(FILE *f, int x, int y, int width, int height, int r, int g, int b, float alpha){
	fprintf(f,"<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill = rgb(%d,%d,%d) fill-opacity = \"%f\" />", x,y,width,height,r,g,b,alpha);

	/* Your code here */
} /* rectangle */

/* generate_random_art
   Produce randomly generated CSC 111 art with the following algorithm.
   Repeat the following procedure 1000 times:
      - Generate a random number Z between 0 and 2 (inclusive)
	  - If Z is 0, call the rectangle function with random parameters where
	       - The x and y coordinates are between 0 and CANVAS_SIZE/2 (inclusive)
		   - The width and height are between 1 and CANVAS_SIZE/2 (inclusive)
		   - The colour values r, g and b are between 0 and 255 (inclusive)
		   - The alpha value is between 0.0 and 0.5.
	  - If Z is 1, call the circle function with random parameters where
	       - The x and y coordinates are between 0 and CANVAS_SIZE-1 (inclusive)
		   - The radius is between 1 and CANVAS_SIZE/8 (inclusive)
		   - The colour values r, g and b are between 0 and 255 (inclusive)
		   - The alpha value is between 0.0 and 1.0 (fractional values such as 0.5 must be possible)
	  - If Z is 2, call the ellipse function with random parameters where
	       - The x and y coordinates are between 0 and CANVAS_SIZE (inclusive)
		   - The radius_x and radius_y parameters are between 1 and CANVAS_SIZE/16 (inclusive)
		   - The colour values r, g and b are between 0 and 255 (inclusive)
		   - The alpha value is between 0.0 and 1.0 (fractional values such as 0.5 must be possible)
*/
void generate_random_art(FILE *f){
	/* Your code here */

	int z;
	int a=1;
	int x;
	int y;
	int width;
	int height;
	int r;
	int g;
	int b;
	float alpha;
	float c;
	int radius;
	int radius_x;
	int radius_y;


while (a<1001){

z=rand()%3;

if (z==0){
x=rand()%(1+CANVAS_SIZE/2);
y=rand()%(1+CANVAS_SIZE/2);
width=1+rand()%(1+CANVAS_SIZE/2);
height=1+rand()%(1+CANVAS_SIZE/2);
r=rand()%256;
g=rand()%256;
b=rand()%256;
c=rand()%6;
alpha=c/10;

rectangle(f,x,y,width,height,r,g,b,alpha);
}

if (z==1){
	x=rand()%(CANVAS_SIZE);
	y=rand()%(CANVAS_SIZE);
	radius=1+rand()%(1+CANVAS_SIZE/8);
	r=rand()%256;
	g=rand()%256;
	b=rand()%256;
	c=rand()%11;
	alpha=c/10;
	circle(f,x,y,radius,r,g,b,alpha);

if (z==2){
	x=rand()%(1+CANVAS_SIZE);
	y=rand()%(1+CANVAS_SIZE);
	radius_x=1+rand()%(1+CANVAS_SIZE/16);
	radius_y=1+rand()%(1+CANVAS_SIZE/16);
	r=rand()%256;
	g=rand()%256;
	b=rand()%256;
	c=rand()%11;
	alpha=c/10;
	ellipse(f,x,y,radius_x,radius_y,r,g,b,alpha);

}

}
a++;
}
} /* generate_random_art */


/* main

   The main program must do the following:

    - Set the seed of the random number generator to the current time.

	- Open the output file HTML5_SVG_OUTPUT_FILENAME (also defined at the top of this
	  file), which will contain the output HTML code.

	- Call the write_prologue function to write the HTML prologue to the output file.

	- Call the generate_random_art function to generate random art.

	- Call the write_epilogue function to write the HTML epilogue to the output file.

	- Close the output file.
*/
int main(){
	unsigned int seed=(unsigned int)time (NULL);
	srand(seed);
	FILE *fp = fopen("A5P2_2015.html", "w");


	write_prologue(fp);
	generate_random_art(fp);
	write_epilogue(fp);

	fclose(fp);	return EXIT_SUCCESS;
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
	fputs("<title>CSC 111 Fall 2015 -  Assignment 5 Part 2</title>\n",f);
	fputs("</head>\n",f);
	fputs("<body>\n",f);
	fputs("CSC 111 Art: <br />",f);
	fprintf(f,"<svg width=\"%dpx\" height=\"%dpx\">\n",CANVAS_SIZE_X,CANVAS_SIZE_Y);
	fprintf(f,"<g transform=\"translate(0 %d)\">\n",CANVAS_SIZE_Y);
	fputs("<g transform=\"scale(1 -1)\">\n",f);
	fprintf(f,"<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" style=\"fill: none; stroke-width: 5; stroke:rgb(255,255,255); stroke-opacity:1.0;\" />",CANVAS_SIZE_X,CANVAS_SIZE_Y);
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
