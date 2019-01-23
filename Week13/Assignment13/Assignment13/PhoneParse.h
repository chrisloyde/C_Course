#pragma once
#include <stdio.h>

int getDigitFromChar(char c);				// returns integer represented by character provided, returns -1 if character is not a digit.
void readFileAndDisplay(char *directory);	// Accepts a directory, reads the file, and prints phone numbers in a standardized format.
void initArray(int arr[], int size);		// modifies array parameter, sets all values in array to -1