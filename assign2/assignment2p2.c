/*
 ============================================================================
 Date		 : 09/25/2015
 Assignment	 : Assignment 2 Part 2
 Description : This program outputs onto the console a column of powers of three,
 	 	 	   column of what power of three it is, and a column of 1/the power of three.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
float a=1;
float b=0;
float c=1.0;
while(a<2000,b<10,c>0.000050801){
	printf("%1.0f %1.0f %1.10f\n", a,b,c);
	a=a*3;
	b=b+1;
	c=1/a;
}
	return EXIT_SUCCESS;
}
