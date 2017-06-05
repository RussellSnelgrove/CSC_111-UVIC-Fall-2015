/*
 ============================================================================
 Date		 : 11/23/2015
 Assignment	 : Assignment 7 Part 3
 Description : This program switchs the contents of words leaving the outer
 	 	 	 	 letters untouched.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define INPUT_FILENAME    ("A7_2015_P3_Sherlock.txt")
#define OUTPUT_FILENAME   ("A7P3_2015_SherlockEncoded.txt")

void processFile(FILE* ifp, FILE* ofp) {
	printf("Begin file processing\n");

	char word[100],temp,c,b;
	int a,x;
	int y=0;
x=0;

	while (!feof(ifp)) {
	fscanf(ifp, "%s", word);

if(strlen(word)>4){
	b = word[0];
	c= word[strlen(word)-1];
	a=strlen(word)-1;
	x=1;
	temp = word[1];
while(x!=(a)){
word[x]=word[x+1];
x++;
}

word[0]=b;
word[strlen(word)-1]=c;
word[strlen(word)-2]=temp;


}else{}




	fprintf(ofp,"%s ",word);
	y++;
	if(y == 11) {
	fprintf(ofp,"\n");
	y = 0;
}
	}

// your code goes here
			printf("End file processing\n");
} /* ProcessFile */

int main(void) {
	printf("Starting text encoding...\n\n");
	unsigned int seed = (unsigned int) time(NULL);
	srand(seed);
	FILE *ifp;
	FILE *ofp;
	ifp = fopen(INPUT_FILENAME, "r");
	if (ifp == NULL) {
		printf("Cannot open input file %s\n", INPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /*if*/
	ofp = fopen(OUTPUT_FILENAME, "w");
	if (ofp == NULL) {
		printf("Cannot create output file %s\n", OUTPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /*if*/
	processFile(ifp, ofp);
	fclose(ofp);
	fclose(ifp);
	printf("\nEncoding finished.\n");
	return EXIT_SUCCESS;
} /*main*/
