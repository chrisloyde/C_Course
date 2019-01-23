#include <stdio.h>
#include <ctype.h>


int exercise3();
int exercise4();

int main() {
	int input;
	printf("Enter exercise number to run: ");
	scanf("%d", &input);

	// check which exercise to run then run the corresponding function
	if (input == 3) {
		exercise3();

	}
	else if (input == 4) {
		exercise4();
	}
	// if input is invalid then we can print a simple error message and call main
	// again so user can retry.
	else {
		printf("Invalid exercise number: %d\n", input);
		main();
	}

	return 0;
}

// function which represents the solution to exercise 3 on page 50.
int exercise3() {
	int prefix, identifier, publisher, item, checkDigit;
	printf("Enter ISBN: ");
	// take user inphut which should be seperated into 5 integers seperated by '-'
	scanf("%d-%d-%d-%d-%d", &prefix, &identifier, &publisher, &item, &checkDigit);
	printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher Code: %d\nItem number: %d\nCheck digit: %d\n",
		prefix, identifier, publisher, item, checkDigit);
	return system("pause");
}

// function which represents the solution to exercise 4 on page 157.
int exercise4() {
	char input[32], processedInput[32];
	printf("Enter a phone number: ");
	scanf("%s", &input); // read a string from user representing phone number

	char a, b; // declare some new variables for loop
	
	// parse the user inputted string to translate any alphabetic phone numbers to
	// numeric form.
	for (int i = 0; i < 32; i++) {
		a = (char)toupper(input[i]);
		
		// assign b to the ASCII value 2-9
		if (a == 'A' || a == 'B' || a == 'C') {
			b = (char)50; 
		} 
		else if (a == 'D' || a == 'E' || a == 'F') {
			b = (char)51;
		} 
		else if (a == 'G' || a == 'H' || a == 'I') {
			b = (char)52;
		}
		else if (a == 'J' || a == 'K' || a == 'L') {
			b = (char)53;
		} 
		else if (a == 'M' || a == 'N' || a == 'O') {
			b = (char)54;
		}
		else if (a == 'P' || a == 'R' || a == 'S') {
			b = (char)55;
		}
		else if (a == 'T' || a == 'U' || a == 'V') {
			b = (char)56;
		}
		else if (a == 'W' || a == 'X' || a == 'Y' || a == 'Z') {
			b = (char)57;
		}
		else {
			// if the input is not a letter, do not change and just assign b to equal a
			b = a;
		}

		// add b to processedInput character array.
		processedInput[i] = b;
	}

	// print the processed input
	printf("%s\n", processedInput);

	return system("pause");
}