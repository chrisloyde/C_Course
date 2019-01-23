#include <stdio.h>
#include <math.h>

/*
Assignment 5
Exercise #6 pg 217, Exercise #7 pg 179;

Exercise #6 pg 217: Asks for x input from user then computes the polynomial
	(3x^5)+(2x^4)-(5x^3)-(x^2)+7x-6
Exercise #7 pg 179: 
*/

int Exercise6();
int Exercise7();

int main() {
	int in = 0;
	do {
		printf("Enter 6 for Exercise #6 on pg. 217\nEnter 7 for Exercise #7 on pg.179\nEnter -1 to quit\n");
		scanf("%d", &in);
		switch (in) {
		case 6: Exercise6(); break;
		case 7: Exercise7(); break;
		}
	} while (in != -1);

	return 0;
}

int Exercise6() {
	double xIn = 0, result = 0;
	printf("Enter value for x: ");
	scanf("%lf", &xIn); // get x input from user.

	// add each element of polynomial to result, adding result to itself if necessarry.
	result = (3 * pow(xIn, 5));
	result = result + (2 * pow(xIn, 4));
	result = result - (5 * pow(xIn, 3));
	result = result - (pow(xIn, 2));
	result = result + (7 * xIn);
	result = result - 6;
	printf("Result = %.4f\n", result);

	return system("pause");
}

int Exercise7() {
	int arr[5][5];
	int rowT = 0, colT = 0;
	// enter rows
	for (int i = 0; i < 5; i++) {
		printf("Enter Row %d: ", i + 1); // add one so row starts at 1 for user
		scanf("%d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4]); // read 5 inputs for each column
	}

	printf("Row totals: ");
	// calculate row totals by using a loop to increment to each row, then manually getting the column number since the size is constant
	for (int r = 0; r < 5; r++) {
		rowT = arr[r][0] + arr[r][1] + arr[r][2] + arr[r][3] + arr[r][4];
		printf("%d ", rowT);
	}
	printf("\nColumn totals: ");
	// calculate column totals by using a loop to increment to each column, then manually getting the row number since the size is constant.
	for (int c = 0; c < 5; c++) {
		colT = arr[0][c] + arr[1][c] + arr[2][c] + arr[3][c] + arr[4][c];
		printf("%d ", colT);
	}
	printf("\n");
	return system("pause");
}