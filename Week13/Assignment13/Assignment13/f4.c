

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int getUserInput();
// returns number of instances in the word, prints entire contents of file with brackets around specified word.
int searchFileForWord(char *path, char *word);
// displays only the number of lines specifeid
void displayLines(char *path, int lines);
// append to file
void appendToFile(char *path, char *append);

int main() {
	int in, quit = 0, lineCount;
	char inStr[64];
	char appendStr[1024];

	
	while (quit != 1) {
		in = getUserInput();

		switch (in) {
		case 1:
			printf("Enter word to search for: ");
			scanf("%s", inStr);
			printf("\n\nNumber of occurences of the word \"%s\" is %d\n", inStr, searchFileForWord("CIS265.txt", inStr));
			break;
		case 2:
			printf("Enter number of lines to display: ");
			scanf("%d", &lineCount);
			displayLines("CIS265.txt", lineCount);
			printf("\n");
			break;
		case 3:
			printf("Type anything to append to the file: ");
			fgets(appendStr, 1024, stdin); // get user input for appending to file
			appendToFile("CIS265.txt", appendStr);
			break;
		case 4:
			printf("Quitting...\n");
			quit = 1;
			break;
		}
	}
	return 0;
}

int getUserInput() {
	char in;
	printf("1- Press (S) to search for a word\n");
	printf("2- Press (L) to display specified number of text lines to the screen\n");
	printf("3- Press (A) to append new content to the file\n");
	printf("4- Press (Q) to quit\n");

	scanf(" %c", &in);
	getchar();
	switch (in) {
	case 'S': case 's':
		return 1;
		break;
	case 'L': case 'l':
		return 2;
		break;
	case 'A': case 'a':
		return 3;
		break;
	case 'Q': case 'q':
		return 4;
		break;
	default:
		return 0;
		break;
	}
}

int searchFileForWord(char *path, char *word) {
	FILE *fp = fopen(path, "r"); // open file for reading
	int count = 0, wordLength = strlen(word), matching = 0;
	fpos_t filePos;
	char c, ch;
	// check if file was opened succesfully
	if (fp == NULL) {
		printf("Can't open %s\n", path);
		exit(EXIT_FAILURE);
	}

	while ((c = fgetc(fp)) != EOF) {
		// if character is at the start of a new word
		if (c == ' ' || c == '.' || c == '\n' || c == ',') {
			matching = 0;
			fgetpos(fp, &filePos); // save position at start of word
			for (int i = 0; i < wordLength; i++) {
				ch = fgetc(fp);
				// if the characters match in both the file and the provided word at specified positions
				// OR if the uppercase character from the file matches the provided word at a specified postion
				// increment matching. If they don't set matching to 0 and break.
				if (ch == word[i] || ((char)ch+32) == word[i] || ((char)ch-32) == word[i]) {
					++matching;
				}
				else {
					matching = 0;
					break;
				}
			}
			// before we reset position we need to ensure that the word matches totally.
			// This prevents the program from matching the word system to systems (or any word like that)
			// by checking for new word indicators.
			if (matching == wordLength) {
				ch = fgetc(fp);
				// check if the next character marks the end of a word
				if (ch != ' ' && ch != '.' && ch != '\n' && ch != ',') {
					// if the next character does not match the end of the word set matching to 0.
					matching = 0;
				}
			}
			fsetpos(fp, &filePos); // reset file stream to previous position before analyzing word

			if (matching == wordLength) {
				printf(" ["); // print bracket with leading whitespace.
				// decrement matching to determine where to place the end bracket.
				while (matching > 0) {
					c = fgetc(fp); // get character
					printf("%c", c); // print character
					matching--; // decrement matching
				}
				printf("]"); // print bracket since we should be at the end of the word
				c = fgetc(fp); // get the next character.
				count++; // increment count since a matching word was found.
			}
		}
		printf("%c", c);
	}
	fclose(fp); // close file stream
	return count; // return number of occurances.
}

void displayLines(char *path, int lines) {
	FILE *fp = fopen(path, "r");
	char c;
	int counter = 0;
	if (fp == NULL) {
		printf("Can't open %s\n", path);
		exit(EXIT_FAILURE);
	}
	// read through file till end of file marker
	while ((c = fgetc(fp)) != EOF) {
		// if counter increments to line stop looping
		if (counter == lines) {
			break;
		}
		else {
			// if the current character equals a new line character then increment counter.
			if (c == '\n') {
				++counter;
			}
		}
		// as long as we haven't achieved the number of new lines then print characters
		printf("%c", c);
	}
	fclose(fp); // close file stream.
}

void appendToFile(char *path, char *append) {
	FILE *fp = fopen(path, "a"); // create file stream for appending
	if (fp == NULL) {
		printf("Can't open %s\n", path);
		exit(EXIT_FAILURE);
	}
	// print string to append to the file to file at the end.
	fprintf(fp,"%s",append);

	fclose(fp);
}