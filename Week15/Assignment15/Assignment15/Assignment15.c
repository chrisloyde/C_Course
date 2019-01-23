/*
Assignment 15
Exercise 6(a) pg525:
	Uses bitwise operators to write the functin:
		unsigned short swapBytes(unsigned short i);

		function:
			return the number that results from swapping the two bytes in i.
			(Short integers occupy two bytes).
			Example: if i has the value 0x1234 (00010010 00110100 in binary)
				swapBytes returns 0x3412 (00110100 00010010 in binary).
			Program is tested by writing a program that reads a hexadecimal number, then writes the number with bytes swapped.
Programming Project 2
	Obtain locale from user input and display values stored in lconv structure.
		grouping and mon_grouping should be displayed as decimal numbers.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void exercise6();
void project2();
unsigned short swapBytes(unsigned short i);


int main() {
	char buf[24];
	int in = -1;

	while (in != 0) {
		printf("1- Exercise #6\n2- Programming Project #2\n 3- Quit\n");
		scanf_s("%d", &in);
		getchar(); // clear enter
		
		switch (in) {
		case 1:
			exercise6();
			break;
		case 2:
			printf("Enter locale:\n");
			fgets(buf, 24, stdin);
			project2(buf);
			break;
		case 3:
			in = 0;
			break;
		}
	}

	return 0;
}

void exercise6() {
	unsigned short i;
	printf("Enter a hexadecimal number (up to four digits): ");
	scanf_s("%hx", &i);											// read in as hexadecimal
	getchar();													// clear input stream.
	printf("Number with bytes swapped %hx\n", swapBytes(i));	// print as hexadecimal
}

void project2(char * l) {
	struct lconv *locale;

	setlocale(LC_ALL, l);

	// after locale is set, assign data to local struct
	locale = localeconv();

	// Print info from locale
	printf("decimal_point = \"%s\"\n",		locale->decimal_point);
	printf("thousands_sep = \"%s\"\n",		locale->thousands_sep);
	printf("grouping = %d\n",				(int)locale->grouping[0]);		// display as decimal number
	printf("mon_decimal_point = \"%s\"\n",	locale->mon_decimal_point);

	printf("mon_thousands_sep = \"%s\"\n",	locale->mon_thousands_sep);
	printf("mon_grouping = %d\n",			(int)locale->mon_grouping[0]);	// display as decimal number
	printf("positive_sign = \"%s\"\n",		locale->positive_sign);
	printf("negative_sign = \"%s\"\n",		locale->negative_sign);

	printf("currency_symbol = \"%s\"\n",	locale->currency_symbol);
	printf("frac_digits = %d\n",			locale->frac_digits);
	printf("p_cs_precedes = %d\n",			locale->p_cs_precedes);
	printf("n_cs_precedes = %d\n",			locale->n_cs_precedes);

	printf("p_sep_by_space = %d\n",			locale->p_sep_by_space);
	printf("n_sep_by_space = %d\n",			locale->n_sep_by_space);
	printf("p_sign_posn = %d\n",			locale->p_sign_posn);
	printf("n_sign_posn = %d\n",			locale->n_sign_posn);

	printf("int_curr_symbol = \"%s\"\n",	locale->int_curr_symbol);
	printf("int_frac_digits = %d\n",		locale->int_frac_digits);
	printf("int_p_cs_precedes = %d\n",		locale->p_cs_precedes);
	printf("int_n_cs_precedes = %d\n",		locale->n_cs_precedes);

	printf("int_p_sep_by_space = %d\n",		locale->p_sep_by_space);
	printf("int_n_sep_by_space = %d\n",		locale->n_sep_by_space);
	printf("int_p_sign_posn = %d\n",		locale->p_sign_posn);
	printf("int_n_sign_posn = %d\n",		locale->n_sign_posn);

}

unsigned short swapBytes(unsigned short i) {
	/* return inclusive OR of i with bytes shift left by 8 places and i shifted right by 8 places.
		using example in header commenting:
			original: 00010010 00110100
			(i << 8) 00110100 00000000
			(i >> 8) 00000000 00010010
			(result) 00110100 00010010
	*/
	return (i << 8) | (i >> 8);
}