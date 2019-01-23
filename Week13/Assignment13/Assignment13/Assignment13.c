/*
Assignment 13
Exercise #3 & #17 pg. 585, 588

Exercise #3:
	Program concatenates any number of files by writing them to standard ouput.

Exercise #17:
	Read phone number from file (seperated by new line) and display them in a standardized format (xxx) xxx-xxxx
	Reading phone numbers from the file should ignore any characters that are not digits.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Fcat.h"
#include "PhoneParse.h"

// macros which give default file paths
#define PHONE "./phone_numbers.txt"
#define FCAT "fcat f1.c invlaidFile.txt f2.c f3.c f4.c"

int main() {

	char * strInput = (char *)malloc(512 * sizeof(char *));
	int in = -1;

	while (in != 0) {

		printf("1- Exercise #3\n2- Exercise #17\n3- Run exercises with presets\n4- Quit\n");
		scanf("%d", &in);
		getchar(); // clear enter input

		switch (in) {
		case 1:
			// run exercsie 3
			printf("Enter fcat command. Format: fcat filename1.file filename2.file filename3.file ...\n");
			fgets(strInput, 500, stdin);			// get input from user
			strInput = strtok(strInput, "\n");		// remove trailing new line if there is one.
			fcatParse(strInput);					// send command to fcat parser
			break;
		case 2:
			// run exercise 17
			printf("Enter directory/filename for phone numbers file.\n");
			fgets(strInput, 500, stdin);
			strInput = strtok(strInput, "\n");
			readFileAndDisplay(strInput);
			break;
		case 3:
			// run presets
			strcpy(strInput, FCAT);
			fcatParse(strInput);
			printf("\n\n");
			readFileAndDisplay(PHONE);
			printf("\n\n");
			break;
		case 4:
			in = 0;
			break;
		}
	}

	return 0;
}

