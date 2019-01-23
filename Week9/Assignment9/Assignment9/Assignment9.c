/*
Assignment 9
Exercise 5

Exercise 5 pg 456:
	Sorts a series of words entered by user into alphabetical order.
	Assumes each word is no more then 20 characters long.
	Stops reading when user enters an empty word.

	Words are stored in a dynamically allocated string stored in an array of string pointers.
*/


#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define MAX_WORDS 100 // Max number of words that can be inputted
#define MAX_WORD_LENGTH 20 // Max length of words.

char * getWordFromIn();
void sortArray(char **unsortedArray, int size);
int readLine(char str[], int n);
void printHeader();


int main() {
	printHeader();

	char ** arr[MAX_WORDS];
	char * word;
	int i = 0;

	//word = getWordFromIn();
	while (strlen(word = getWordFromIn())!= 0) {
		// if increment is equal to or greater then the max number of words allowed,
		// break loop.
		if (i >= MAX_WORDS) {
			printf("No Space Left\n");
			break;
		}

		arr[i] = word; // add string to array

		++i;
	}

	sortArray(arr, i);

	printf("Sorted Array is: ");
	for (int j = 0; j < i; j++) {
		printf("%s ", arr[j]);
	}

	printf("\n\nPress Enter to Exit\n");
	getchar();
	
	// free memory
	// Go through array of strings and free each string pointer created with malloc.
	for (int k = 0; k < i; k++) {
		free(arr[k]);
	}

	return 0;
}

void sortArray(char **uA, int s) {

	char buf[MAX_WORD_LENGTH + 1]; // create a buffer to temporarily store a string while sorting

	// loop through the entire string multiple times to compare each element with every other element
	for (int i = 0; i < s - 1; i++) {
		for (int j = i; j < s; j++) {
			// swap positions of strings if one should come before the other.
			if (strcmp(uA[i], uA[j]) > 0) {
				strcpy(buf, uA[i]); // copy first into buffer
				strcpy(uA[i], uA[j]); // copy second to first position
				strcpy(uA[j], buf); // copy buffer to second positon
				}
			}
		}
}

char * getWordFromIn() {
	char *inBuff[MAX_WORD_LENGTH+1]; // size for 20 characters + \0 character 
	char *ret;

	printf("Enter a Word: ");
	readLine(inBuff, MAX_WORD_LENGTH);
	if (strlen(inBuff) > 0) {
		ret = (char *)malloc((strlen(inBuff)) * sizeof(char*)); //dynamically create a string
		strcpy(ret, inBuff); // copy from buffer to dymanimcally allocated string
		return ret; // return dynamically allocated string
	}
	else {
		return "";
	}

}

// readLine function provided by book
int readLine(char str[], int n) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}

void printHeader() {
	printf("Chris Peterson\nCIS265\nAssignment #9\nExercise 5\n\n");
}