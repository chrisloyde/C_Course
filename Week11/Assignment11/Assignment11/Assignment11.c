/*
Assignment 11
Exercise 7 pg. 239-240
	Takes an input from the user then displays the number, using
	characters to simulate the effect of a seven-segment display.
*/
#include <stdio.h>

#define MAX_DIGITS 10

void clearDigitsArray();
void processDigit(int digit, int position);
void printDigitsArray();

char digits[4][MAX_DIGITS*4];

int main() {
	int in[MAX_DIGITS];
	char c;
	int limit = 0;
	while (limit < MAX_DIGITS) {
		c = fgetc(stdin); // get character from user
		// check if character is a number
		if ((int)c >= 48 && (int)c <= 57) {
			in[limit] = (int)c-48; // subtract 48 to get the proper int from char
			++limit; // increment limit if a number was found
		}
		// if enter is pushed end input
		if (c == '\n') {
			break;
		}
	}

	// if there were too many numbers inputted the input needs to be cleared
	if (limit == MAX_DIGITS) {
		// get character until new line is reached 
		while (getchar() != '\n') {

		}
		
	}
	// clearing the digits array also fills it with new line characters/
	clearDigitsArray();

	// process all digits
	for (int i = 0; i < MAX_DIGITS; i++) {
		processDigit(in[i], i);
	}

	// print digits
	printDigitsArray();
	getchar();
	return 0;
}

void clearDigitsArray() {
	// set the digits array values to blank characters
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < (MAX_DIGITS * 4); j++) {
			digits[i][j] = ' ';
		}
	}
}

void processDigit(int d, int p) {
	// create a small 2d array to store individual numbers
	char rep[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			rep[i][j] = ' ';
		}
	}

	// for each number there are specific places characters could go.
	switch (d) {
	case 0:
		rep[0][1] = '_';
		rep[1][0] = '|'; rep[1][2] = '|';
		rep[2][0] = '|'; rep[2][2] = '|';
		rep[2][1] = '_';
		break;
	case 1:
		rep[1][2] = '|';
		rep[2][2] = '|';
		break;
	case 2:
		rep[0][1] = '_';
		rep[1][2] = '|';
		rep[1][1] = '_';
		rep[2][0] = '|';
		rep[2][1] = '_';
		break;
	case 3:
		rep[0][1] = '_';
		rep[1][2] = '|';
		rep[1][1] = '_';
		rep[2][2] = '|';
		rep[2][1] = '_';
		break;
	case 4:
		rep[1][0] = '|'; rep[1][2] = '|';
		rep[1][1] = '_';
		rep[2][2] = '|';
		break;
	case 5:
		rep[0][1] = '_';
		rep[1][0] = '|';
		rep[1][1] = '_';
		rep[2][2] = '|';
		rep[2][1] = '_';
		break;
	case 6:
		rep[0][1] = '_';
		rep[1][0] = '|';
		rep[1][1] = '_';
		rep[2][0] = '|'; rep[2][2] = '|';
		rep[2][1] = '_';
		break;
	case 7: 
		rep[0][1] = '_';
		rep[1][2] = '|';
		rep[2][2] = '|';
		break;
	case 8:
		rep[0][1] = '_';
		rep[1][0] = '|'; rep[1][2] = '|';
		rep[1][1] = '_';
		rep[2][0] = '|'; rep[2][2] = '|';
		rep[2][1] = '_';
		break;
	case 9:
		rep[0][1] = '_';
		rep[1][0] = '|'; rep[1][2] = '|';
		rep[1][1] = '_';
		rep[2][2] = '|';
		break;
	}

	// add the array generated in this function to the digits array
	// the position is multiplied by 4 to store the 3 width number and a space.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			digits[i][j+(p*4)] = rep[i][j];
		}
	}
}

void printDigitsArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < (MAX_DIGITS * 4); j++) {
			printf("%c",digits[i][j]);
		}
		printf("\n");
	}
}