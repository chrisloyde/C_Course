/*
Assignment 6
Exercise #1(b) & #9

Exercise #9 pg.274:
double innter_product(const double *a, const double *b, int n)
loops through each array and multiplies values using pointer arithmetic, returns the result.
a[0]*b[0] + ... + a[n-1]*b[n-1].
Prompts user for both double list which will have equal size

Exercise #1(b):
Program which reads a message, then prints the reversal using pointer arithmetic to keep track of position in array.
*/
#include <stdio.h>
#include <stdlib.h>
double inner_product(const double *a, const double *b, int n);
void exercise1();
void exercise9();
void printDoubleArray(const double *, int);
void clearBuffer();

int main() {
	int in = 0;
	// loop to run programs
	do {
		printf("Enter Exercise to run:\n'1' for Exercise #1 on pg.275\n'9' for Exercise #9 on pg.274\n'-1' to exit\n");
		scanf("%d", &in);
		// switch statement to check inputs
		switch (in) {
		case 1: exercise1();  break;
		case 9: exercise9(); break;
		case -1: break;
		}
	} while (in != -1);
	return 0;
}

void exercise9() {
	int size;
	double *a, *b;
	printf("Enter size of arrays: ");
	scanf("%d", &size); // get size from user
						// use malloc to reserve size of each array according to size
	a = (double *)malloc(size * sizeof(*a));
	b = (double *)malloc(size * sizeof(*b));

	// 2 loops to get input from user for each element in array
	for (int i = 0; i < size; i++) {
		printf("Enter double value for a[%d]: ", i);
		scanf("%lf", &a[i]);
	}
	for (int i = 0; i < size; i++) {
		printf("Enter double value for b[%d]: ", i);
		scanf("%lf", &b[i]);
	}
	// print arrays
	printf("Array A: "); printDoubleArray(a, size);
	printf("Array B: "); printDoubleArray(b, size);

	printf("\nProduct is: %lf\n", inner_product(a, b, size));

	// free arrays
	free(a);
	free(b);
}

// performs a mathematical property on 2 double arrays and returns the result
// a[0]*b[0] + ... + a[n-1]*b[n-1].
double inner_product(const double *a, const double *b, int n) {
	double prod = 0;
	// loops and performs pointer arithmetic to multiply and add the arrays.
	for (int i = 0; i < n; i++) {
		prod = prod + (*a)*(*b);
		a++; b++; // incrment array pointers
	}
	return prod;
}

void exercise1() {
	const int SIZE = 1024; // const standard input buffer
	int exSize = 0; // excact size which will be important for reversal.
	char *inStr, *revStr;
	char *inPtr, *revPtr; // pointer to a positon in inStr
	char c = '\0';

	// allocate size for inStr and revStr
	inStr = (char *)malloc(SIZE*sizeof(*inStr));
	inPtr = inStr;

	clearBuffer(); // clear input buffer to make sure there are no new lines
	printf("Enter a message: ");

	// read message from user
	for (int i = 0; i < SIZE; i++) {
		c = getchar(); // get character from input
		// if c is new line or we are at the end of the array
		if (c == '\n' || i == SIZE - 1) {
			*inPtr = '\0'; // add null terminating character to signify end of string
			break;
		}

		else {
			*inPtr = c; // add character to array
		}
		inPtr++;
		exSize++;
	}
	// do reversal
	revStr = (char *)malloc((exSize+1) * sizeof(*revStr)); // allocate revStr to the exact size + 1 (+1 to account for null terminator)
	revPtr = revStr;  // assign reverse pointer to reverse String.
	--inPtr; // decrement the inPtr since its on the null terminator
	for (int i = 0; i < exSize; i++) {
		*revPtr = *inPtr; // assign whats at input string pointer to whats at reverse string pointer
		// increment pointers, adding reverse string pointer and subtracting input string pointer
		revPtr++;
		inPtr--;
	}
	*revPtr = '\0'; // add null terminating character at the end of reverse string.

	printf("Reversal is: %s\n", revStr); // print reverse string

	// free allocated memory
	free(inStr);
	free(revStr);
}

// clear input buffer
void clearBuffer() {
	char c = getchar();
	while (c != '\n' && c != EOF) {
		c = getchar();
	}
}

// prints doublearray to console
void printDoubleArray(const double *arr, int size) {
	// loop through array and use pointer arithmetic to print each value.
	for (int i = 0; i < size; i++) {
		printf("%lf ", *arr);
		arr++;
	}
	printf("\n");
}