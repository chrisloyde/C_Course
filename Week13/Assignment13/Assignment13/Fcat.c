// exercise #2 pg 585

#include "Fcat.h"

void fcatParse(char *in) {
	FILE *fp = NULL;
	char *token;
	char *dir = (char*)malloc(sizeof(char *) * (strlen(in) + 8));

	strcpy(dir, "");				// add empty string to directory
	token = strtok(in, " ");		// get token to verify fcat cmd

	// return if fcat cmd is not being run
	if (strcmp(token, "fcat") != 0) {
		printf("Got %s when expected \"fcat\"\n", token);
		return;
	}

	token = strtok(NULL, " ");		// get first file

	while (token != NULL) {
		strcat(dir, token);			// append file into directory
		fcat(fp, dir);				// call fcat function
		token = strtok(NULL, " ");	// get next token
		strcpy(dir, "");			// reset directory string
	}

	free(dir); // free memory
}

void fcat(FILE *fp, char *d) {
	printf("\n\nFILE: %s\n\n", d);		// print filename
	fp = fopen(d, "r");					// open file

	// check if file is opened
	if (fp == NULL) {
		printf("Cannot open %s\n", d);
		return;
	}

	/*
		Loop through entire file, character by character, and print into console
	*/
	char c;
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
	}
	printf("\n");
	fclose(fp);							// close file after print
}