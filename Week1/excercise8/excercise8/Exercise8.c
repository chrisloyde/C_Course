#include <stdio.h>
/*
* Assignment #1 Exercise #8
*
* Calculates the remaining balance on a loan after the first, second, and third monthly payments.
*
* Input: loan amount, interest rate, monthly payment
* Output: 3 outputs for first payment, second payment, and third payment.
*/

int main() {
	// declare variables
	float loan, interest, payment, monthlyInterestRate, balance;

	// scan input from user for amount of loan, interest rate, and monthly payment.
	printf("Enter amount of loan:");
	scanf("%f", &loan);
	printf("Enter interest rate:");
	scanf("%f", &interest);
	printf("Enter monthly payment:");
	scanf("%f", &payment);

	monthlyInterestRate = (interest / 100) / 12; // calculate monthly interest rate.
	balance = loan; // assign balance equal to loan

					// change balance for each monthly payment then print results.
	balance = balance - payment + (balance*monthlyInterestRate); // applying equation to calculate new balance.
	printf("Balance remaining after first payment: $%.2f\n", balance);
	balance = balance - payment + (balance*monthlyInterestRate);
	printf("Balance remaining after second payment: $%.2f\n", balance);
	balance = balance - payment + (balance*monthlyInterestRate);
	printf("Balance remaining after third payment: $%.2f\n", balance);

	return system("pause");
}