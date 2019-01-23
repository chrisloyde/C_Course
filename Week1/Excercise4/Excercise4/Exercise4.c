#include <stdio.h>
/*
* Assignment #1 Exercise #4
*
* Program which takes a dollar-and-cents input and displays the
* amount with 5% tax added.
*
* Input: dollar-and-cents amount
* Output: Input multiplied and added to 5% tax.
*/

int main() {
	float input, output; // declare some needed variables

	printf("Enter an amount: ");
	scanf("%f", &input); // scan for user dollar-and-cents input and store in input
	output = (input*1.05f); // multiply the input by 1.05 (.05 for 5% tax, 1 to include input) and store result in output
	printf("With tax added: $%.2f\n", output); // print output

	/* instead of returning 0, return a pause system call so output can be seen. */
	return system("pause"); 
}