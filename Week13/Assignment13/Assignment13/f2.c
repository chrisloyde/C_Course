

#include <stdio.h>
#include <math.h>

#define DISP(f,x) printf(#f "(%g) = %g\n", x, f(x)) // display a function call when called with argument x
#define DISP2(f,x,y) printf(#f "(%g, %g) = %g\n", x, y, f(x,y)) // displays a function call when called with arguments x and y

// has value of 1 if x and y both fall between 0 and n-1 inclusive. Has 0 if otherwise.
#define CHECK(x,y,n) (((x >= 0) && (x < n) && (y >= 0) && (y < n))? 1 : 0)

// determines the median of 3 values
#define MEDIAN(x,y,z) ((x > y) ? (y > z) ? y : (x > z) ? z : x : (y > z) ? (x > z) ? x: z: y)

//Computes the polynomial(3x ^ 5) + (2x ^ 4) - (5x ^ 3) - (x ^ 2) + (7x) + (6)
#define POLYNOMIAL(x) (3*(pow(x,5))) + (2*(pow(x,4))) - (5*(pow(x,3))) - (pow(x,2)) + (7*x) + 6

void check();
void median();
void polynomial();

int main() {
	// call macros for exercise 6
	DISP(sqrt, 64.0);
	DISP2(pow, 2.0, 4.0);

	// call macros for exercise 9
	int in = 0;
	do {
		printf("'1' - CHECK\n'2' - MEDIAN\n'3' - POLYNOMIAL\n'-1' to Quit\n");
		scanf("%d", &in);
		switch (in) {
		case 1: 
			check();
			break;
		case 2:
			median();
			break;
		case 3:
			polynomial();
			break;
		case -1:
			in = -1;
			break;
		}
	} while (in != -1);
	
	printf("Press Enter to Quit\n"); getchar();
	return 0;
}

void check() {
	int x, y, n;
	printf("CHECK has value of 1 if x and y are between 0 and n-1 (inclusive)\n");
	printf("Enter values for x, y, n\n");
	scanf("%d %d %d", &x, &y, &n);
	printf("CHECK has value %d\n", CHECK(x,y,n));
}

void median() {
	int x, y, z;
	printf("MEDIAN determines and contains the median of 3 provided numbers\n");
	printf("Enter 3 values for x, y, and n\n");
	scanf("%d %d %d", &x, &y, &z);
	printf("MEDIAN of %d %d %d is : %d\n", x, y, z, MEDIAN(x, y, z));
}

void polynomial() {
	int x;
	printf("POLYNOMIAL calculates (3x ^ 5) + (2x ^ 4) - (5x ^ 3) - (x ^ 2) + (7x) + (6)\n");
	printf("Enter number for x\n");
	scanf("%d", &x);
	printf("(3*%d ^ 5) + (2*%d ^ 4) - (5*%d ^ 3) - (%d ^ 2) + (7*%d) + (6)\n = %g\n", x, x, x, x, x, POLYNOMIAL(x));
}