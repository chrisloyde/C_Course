/*
Assignment 16
Exercise#5 pg. 704 ; Exercise#2 pg. 734

Exercise #5 pg 704 (DayDiff):
	Program that prompts the user to enter two dates, then prints the difference between them measured in days.
	Hint: mkdtime and difftime functions

Exercise #2 pg. 734:
	(c99) Program converts a complex number in Cartesian coordinates to polar form.
	User ents a and b (the real and imaginary parts of the number); the program will display the values r(radius) and (theta)
*/

#include "DayDiff.h"
#include <math.h>

void exercise2();

int main() {
	int in = -1;

	while (in != 0) {
		printf("1- Exercise #5\n2- Exercise #2\n3- Quit\n");
		scanf("%d", &in);
		getchar();			// clear enter input
		switch (in) {
		case 1:
			printf("The difference in days is: %d\n", findDiffInDays());
			break;
		case 2:
			exercise2();
			break;
		case 3:
			in = 0;
			break;
		}
	}


	return 0;
}

void exercise2() {
	double real, img, rad, theta;

	printf("Enter real value and imaginary value of complex number (seperated by space):");
	scanf("%lf %lf", &real, &img);
	getchar();						// clear enter input
	
	rad = sqrt((real * real) + (img * img));
	theta = atan(real / img);

	printf("real value: %g\nimaginary value: %g\nradius value: %g\ntheta radians: %g\n", real, img, rad, theta);
}