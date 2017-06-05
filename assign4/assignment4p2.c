/*
 ============================================================================
 Date		 : 10/18/2015
 Assignment	 : Assignment 4 Part 2
 Description : This program capitalizes the first letter of every word in an
 	 	 	   inputed sentence.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void read_and_capitalize(){
	char c;
	c = getchar();
	int a = 1;


	while(c != '\n'){
		if (a==1){
			printf("%c", toupper(c));
			a=0;
		}
		else if ( isspace(c) ){
			printf(" ");
			a=1;
		}else{
			printf("%c",(c));
		}

		c = getchar();
	}
	printf("\n");
}

int main(void){

	printf("Enter a line of text: ");
	fflush(stdout);
	read_and_capitalize();
	return EXIT_SUCCESS;
}
