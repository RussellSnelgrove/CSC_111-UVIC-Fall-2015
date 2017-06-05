/*
 ============================================================================
 Date		 : 09/25/2015
 Assignment	 : Assignment 3 Part 1
 Description : This program outputs onto the console the volume of a cone with
 	 	 	   a variety of heights and radii.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float circleArea (float r){
	return M_PI*r*r;
}


float coneVolume (float r, float h){
	float baseArea = circleArea(r);
	float volume = (h/3)*baseArea;
	return volume;
}

int main(void) {
	int a = 1;
	printf("h");
	while(a<10){
		printf("\tr = %d",a);
		a=a+1;
	}

	printf("\n");


	float h;
	float r=1;
	for(h=1;h<11;h++){
		printf("%1.0f",h);
		while(r<10){
			float volume;
			volume = coneVolume(r,h);
			printf("\t%3.2f",volume);
		r++;
	}

		if (r==10){
			r=r-9;
		}
	printf("\n");
}


	return EXIT_SUCCESS;
}
