/*
 ============================================================================
 Date		 : 09/25/2015
 Assignment	 : Assignment 2 Part 1
 Description : This program outputs onto the console an Arithmetic Sequence,
 	 	 	   Harmonic sequence, Fibonacci sequence, and Leonardo sequence.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
	printf("Arithmetic sequence:");
	int k=6;
	while (k<127){
	printf(" %d", k);
	k= k+11;
	}
	printf("\n");


	printf("Harmonic sequence:");
	float j;
	for (j=1; j<12; j++){
	float x;
	x = (1 / j);
	printf(" %.2f", x);
	}
	printf("\n");


	printf("Fibonacci sequence:");
	int a=1;
	int b=1;
	int c;
	c=a+b;
	while(a<700, b<700, c<700){
	printf(" %d %d %d", a, b, c);
	a = c+b;
	b = a+c;
	c = a+b;
}
	printf("\n");

	printf("Leonardo sequence:");
	int d=1;
	int e=1;
	int f;
	f=d+e+1;
	while(d<1500, e<1500, f<1500){
	printf(" %d %d %d", d, e, f);
	d = e+f+1;
	e = d+f+1;
	f = d+e+1;
	}
	return EXIT_SUCCESS;
}
