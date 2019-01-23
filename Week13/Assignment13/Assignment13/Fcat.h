#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void fcatParse(char *input);						// takes command line input as string (e.g fcat file1.c file2.c) and parses it to give to fcat function.
void fcat(FILE *filePointer, char * directory);		// opens file given and prints the entire contents into stdout