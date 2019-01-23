#include "PhoneParse.h"

int getDigitFromChar(char c) {
	int digit = (int)c;						// pass c into digit as an integer.
	if ((digit >= 48) && (digit <= 57)) {	// determine if character is a number
		return (digit - 48);				// return the character representation as a number and subtract 48 to get the integer.
	}

	return -1;								// return -1 since character is not an integer.
}

void readFileAndDisplay(char *d) {
	int phoneNum[10];
	int num = -1;
	int index = 0;
	char c;

	FILE *fp = fopen(d, "r");			// open file

	// check if file was opened properly
	if (fp == NULL) {
		printf("Cannot open %s", d);
		return;
	}

	initArray(phoneNum, 10);			// initialize array

	// evaluate each character in file
	while ((c = fgetc(fp)) != EOF) {
		// if c is a new line, then we can assume we've reached the end of a phone number and print what is stored in phone number array
		if (c == '\n') {
			// ensure that phone number has actually been read in, and isn't default (prevents against random new lines in the file).
			if (phoneNum[0] != -1) {
				// print the contents of the array formatted
				printf("(%d%d%d) %d%d%d-%d%d%d%d\n", phoneNum[0], phoneNum[1], phoneNum[2], phoneNum[3],
					phoneNum[4], phoneNum[5], phoneNum[6], phoneNum[7], phoneNum[8], phoneNum[9]);
				// reset index and initialize array (set all values to -1)
				index = 0;
				initArray(phoneNum, 10);
				continue;				// get next character
			}
		}
		else {
			// if character is a digit
			if ((num = getDigitFromChar(c)) != -1) {
				phoneNum[index] = num;	// assign number to corresponding index
				++index;				// increment index
			}
		}
	}

	// if we've reached end of file, but the phone number hasn't been printed out and reset, then we need to print that number.
	if (phoneNum[0] != -1) {
		printf("(%d%d%d) %d%d%d-%d%d%d%d\n", phoneNum[0], phoneNum[1], phoneNum[2], phoneNum[3],
			phoneNum[4], phoneNum[5], phoneNum[6], phoneNum[7], phoneNum[8], phoneNum[9]);
		initArray(phoneNum, 10);
	}
	
	fclose(fp); // close file
	return;
}

void initArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = -1;
	}
}