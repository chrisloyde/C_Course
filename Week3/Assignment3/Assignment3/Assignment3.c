#include <stdio.h>
/*
CIS265 Assignment 3 : Exercise#4 & Exercise#5

Exercise#4: Reads an integer entered by the user and displays it in octal.
Output is always displayed as 5 digits.

Exercise#5: Converts a UPC check digit using the 11 digit identification.
*/
int exercise4();
int exercise5();
int charToInt(char c);

int main() {
	int in;
	printf("Enter number of exercise (4 for Exercise#4, 5 for Exercise#5):");
	scanf("%d", &in);
	if (in == 4) {
		exercise4();
	}
	
	if (in == 5) {
		exercise5();
	}

	return 0;
}

// function to perform exercise 4
int exercise4() {
	int input, math;
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &input);
	printf("In octal, your number is: "); // this output will be appended to.
	// Octal requires 5 digits to loop from 0-4
	for (int i = 0; i < 5; i++) {
		math = input; // every new iteration assign math to input
		// loop downwards from 3(next to last digit)-i, to 0.
		// subtract i to control how many divisions we want to perform.
		for (int j = (3 - i); j >= 0; j--) {
			math = math / 8;  // divide math by 8 and assign to math.
		}
		printf("%d", math%8); // print the remainder of the final result of math.
	}
	printf("\n");
	return system("pause");
}

// function to perform exercise 5.
int exercise5() {
	char in[1024];
	int sum1, sum2, chkDigit;
	printf("Enter 11 digit UPC: ");
	scanf("%s", &in); //read upc as string

	// add first, third, fifth, seventh, ninth, and eleventh digits.
	sum1 = charToInt(in[0]) + charToInt(in[2]) + charToInt(in[4])
		+ charToInt(in[6]) + charToInt(in[8]) + charToInt(in[10]);
	// add second, fourth, sixth, eighth, and tenth digits.
	sum2 = charToInt(in[1]) + charToInt(in[3]) + charToInt(in[5])
		+ charToInt(in[7]) + charToInt(in[9]);
	// do remainding math to calculate check digit.
	chkDigit = (sum1 * 3) + sum2;
	chkDigit = chkDigit - 1;
	chkDigit = chkDigit % 10;
	chkDigit = 9 - chkDigit;

	printf("Check Digit is: %d\n", chkDigit);

	return system("pause");
}

// helper method for exercise5 which converts a charcter to its numerical representation
// e.g char '9' has the numerical representation 9 but the DEC representation 57.
// achieved by subtracting 48 from the DEC representation.
int charToInt(char c) {
	return ((int)c)-48;
}