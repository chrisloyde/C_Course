#include <stdio.h>
/*
Assignment 4
Exercise #1 & Exercise #8

Exercise #1: User enters several numbers one at a time (don't have to be integers).
	When user enters 0 or a negative number display largest non-negative number.
Exercise #8: Prints a 1 month calender based on the number of days in the month and the
	starting day of the week which the month begins.
*/
int exercise1();
int exercise8();

int main() {
	int in = 0;

	// Get the exercise to grade.
	do {
		printf("Enter exercise to run (1=exercise#1, 8=exercise#8, -1=quit) : ");
		scanf("%d", &in);
		if (in == 1) {
			exercise1();
		}
		if (in == 8) {
			exercise8();
		}
		if (in == -1) {
			break;
		}
	} while (in != 1 || in != 8);
	return 0;
}

int exercise1() {
	double largest = 0, in = 1; // assign in to 1 so loop starts, this won't be considered in largest calculation.
	printf("Running Exercise #1\n");
	while (in > 0) {
		printf("Enter a number: ");
		scanf("%lf", &in); // read input from user
		// if in is larger then largest, assign largest to in.
		if (largest < in) {
			largest = in;
		}
	}
	printf("The largest number entered was %lf\n", largest);

	return(system("Pause"));
}

int exercise8() {
	int nDays = 0, nStart = 0;
	printf("Running Exercise #8\n");
	printf("Enter number of days in month: ");
	scanf("%d", &nDays);
	// place nStart in a loop so we can error check and ensure the number is between 1 and 7.
	do {
		printf("Enter starting day of the week. (1=Sun, 7=Sat): ");
		scanf("%d", &nStart);
	} while (nStart < 1 || nStart > 7);

	// print a set number of spaces (left justifed w/ 2 places) before the printing of
	// calendar numbers
	for (int i = 0; i < nStart-1; i++) {
		printf("%2s ","");
	}
	// print from 1 to the total number of days provided by user
	for (int i = 1; i < nDays+1; i++) {
		printf("%2d ", i); // left justifed, 2 number places
		// calculate the end of the week by subtracting 1 from the start provided, adding the
		// increment then doing modulo by 7. 0 means we are at the end of the week.
		if ((i + (nStart - 1)) % 7 == 0) {
			printf("\n"); // print new line
		}
	}
	printf("\n");
	return(system("Pause"));
}