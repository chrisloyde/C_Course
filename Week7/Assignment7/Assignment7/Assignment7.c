/*
Assignment 7
Exercise #1 and Exercise #18

Exercise #1: 
	Program accepts several words from user input and determines the smallest and largest words according to the dictionary.
Exercise #18: 
	Program accepts a data from the user in the from mm/dd/yyyy and then displays it in the form month dd, yyyy.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void exercise_1();
void exercise_18();
void clearBuffer();

int main() {
	int in = 0;
	
	while (in != -1) {
		printf("Enter 1 for Exercise #1\nEnter 2 for Exercise #18\nEnter -1 to quit ");
		scanf("%d", &in); 
		clearBuffer(); // clear input buffer after getting input to remove trailing \n
		switch (in) {
		case 1: exercise_1(); break;
		case 2: exercise_18(); break;
		case 18: exercise_18(); break;
		case -1: in = -1; break;
		default: printf("Incorrect exercise number\n");
		}
	}
	return 0;
}

void exercise_1() {
	char *inputStr, *largestStr, *smallestStr; // initialize an character array with 20 spaces
	// allocate memory for each character pointer
	inputStr    = (char *)malloc(20*sizeof(inputStr));
	largestStr  = (char *)malloc(20*sizeof(largestStr)); 
	smallestStr = (char *)malloc(20*sizeof(smallestStr));

	int quit = 0; // declare variable for our quit check on input loop
	
	// create dummy strings
	strcpy(largestStr, "");
	strcpy(smallestStr, "");

	do {
		printf("Enter a word: ");
		fgets(inputStr, 20, stdin);  // get input from user
		inputStr = strtok(inputStr, "\n"); // remove new line character

		// if the length of our largest or smallest string is 0 (indicated this is the first run of this loop)
		// then assign their values to first input.
		if (strlen(largestStr) == 0) {
			strcpy(largestStr, inputStr);
		}
		if (strlen(smallestStr) == 0) {
			strcpy(smallestStr, inputStr);
		}

		// quit condition ( 4 character word )
		if ((strlen(inputStr)) == 4) {
			quit = 1;
		}

		// compare strings to see if it's a new largest or smallest word
		if (strcmp(inputStr, smallestStr) < 0) {
			strcpy(smallestStr, inputStr);
		}
		if (strcmp(inputStr, largestStr) > 0) {
			strcpy(largestStr, inputStr);
		}


	} while (quit != 1); // run loop while quit does not equal 1 or true
	printf("Smallest Word: %s\nLargest Word: %s\n", smallestStr, largestStr);
}

void exercise_18() {
	char **months; // declare a 2D array of character pointers
	int month, day, year;
	months = malloc(12 * sizeof(months)); // allocate size for 12 strings (12 months)
	*months = malloc(32 * sizeof(*months)); // allocate size for a string small enough to store each month
	// add month names to array.
	months[0] = "January";	months[6] = "July";
	months[1] = "February";	months[7] = "August";
	months[2] = "March";	months[8] = "Septemeber";
	months[3] = "April";	months[9] = "October";
	months[4] = "May";		months[10] = "November";
	months[5] = "June";		months[11] = "December";

	printf("Enter a Date (mm/dd/yyy) : ");
	scanf("%d/%d/%d", &month, &day, &year);
	// print formatted string base on inputs
	// subtract one from inputted month since arrays start at 0
	printf("%s %d, %d\n", months[month - 1], day, year);

}

void clearBuffer() {
	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');
}