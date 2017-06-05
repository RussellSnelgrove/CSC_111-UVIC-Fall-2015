/*
 ============================================================================
 Date		 : 09/25/2015
 Assignment	 : Assignment 2 Part 2
 Description : This program outputs onto the console a column of Liters per 100Km and
 	 	 	   another column of Miles per gallon.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("Liters	Miles\n");
	printf("per	per\n");
	printf("100 KM	gallon\n");
float a=4.0;
float b=100*0.621371/0.219969*(1/a);
while (a<8.0,b>35.2){
	printf("%1.1f %1.1f\n",a,b);
	a=a+0.1;
	b=100*0.621371/0.219969*(1/a);
}



	return EXIT_SUCCESS;
}
