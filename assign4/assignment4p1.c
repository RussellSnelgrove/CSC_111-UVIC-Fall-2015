/*
 ============================================================================
 Date		 : 10/18/2015
 Assignment	 : Assignment 4 Part 1
 Description : This program outputs onto the console a Roman numerals in the
 	 	 	   console for a number that is inputed.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void) {
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;


	a=1;

	while (a==1){
	printf("Enter a number between 1 and 5000:");
	fflush (stdout);
	scanf ("%d", &b);

	c = b/1000;
	d = (b-(c*1000))/100;
	e = (b-((c*1000)+(d*100)))/10;
	f = (b-((c*1000)+(d*100)+(e*10)))/1;


if (1<=b && b<=5000){
if (c==5){
 printf("MMMMM");
}

if (c==4){
	printf("MMMM");
}

if (c==3){
	printf("MMM");
}

if (c==2){
	printf("MM");
}

if (c==1){
	printf("M");
}

if (d==9){
	printf("CM");
}

if (d==8){
	printf("DCCC");
}

if	(d==7){
	printf("DCC");
}

if (d==6){
	printf("DC");
}

if (d==5){
	printf("D");
}

if (d==4){
	printf("CD");
}

if (d==3) {
	printf("CCC");
}

if (d==2){
	printf("CC");
}

if (d==1){
	printf("C");
}

if (e==9){
	printf("XC");
}

if (e==8){
	printf("LXXX");
}

if (e==7){
	printf("LXX");
}

if (e==6){
	printf("LX");
}

if (e==5){
	printf("L");
}

if (e==4){
	printf("XL");
}

if (e==3){
	printf("XXX");
}

if (e==2){
	printf("XX");
}

if (e==1){
	printf("X");
}

if (f==9){
	printf("IX");
}

if (f==8){
	printf("VIII");
}

if (f==7){
	printf("VII");
}

if (f==6){
	printf("VI");
}

if (f==5){
	printf("V");
}

if (f==4){
	printf("IV");
}

if (f==3){
	printf("III");
}

if (f==2){
	printf("II");
}

if (f==1){
	printf("I");
}

	}
else if (b<1 || b>5000){
	printf("Invalid Number. Exiting the System.");
a++;
}


printf("\n");
	}
	return EXIT_SUCCESS;
}
