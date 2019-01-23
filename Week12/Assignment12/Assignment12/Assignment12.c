/*
Assignment 12
C Structs & Enumerations Project
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ID_SIZE 7			// Max length of ID (6 character id + 1 for nullterminating character)
#define INFO_SIZE 32		// Max length for a information attribute (name, major, or campus)
#define RECORD_LENGTH 104	// Max length of record (3x32 size records + 8 size ID)
#define DB_SIZE 100			// Max number of records allowed in Database

// struct to hold each attribute per record in a database
struct Record {
	char id[ID_SIZE];
	char name[INFO_SIZE];
	char major[INFO_SIZE];
	char campus[INFO_SIZE];
};

struct Record records[DB_SIZE];		// Array of record structs to hold database
int recordLength = 0;

void loadDatabase(char *filename);	// intialize and loads a database
int searchDatabaseByID(char *id);	// search the loaded database for matching ID
void campusCount();					// count students per campus in loaded database 
void displayDatabase();				// display all contents of loaded database


int main() {
	int quit = 0;
	char in;
	char id[ID_SIZE];

	loadDatabase("student database.txt"); // load in database

	while (quit == 0) {
		printf("\n1- Press (D) to display all students records information\n");
		printf("2- Press (S) to search and display a student information by student ID\n");
		printf("3- Press (C) to provide a count of students per campus\n");
		printf("4 -Press (Q) to quit\n");

		in = fgetc(stdin);

		switch (in) {
		// display student records
		case 'D': case 'd':
			displayDatabase();
			getchar();						// clear input buffer
			break;
		// search and display a student information by student ID
		case 'S': case 's':
			printf("Enter Student ID to Search: ");
			getchar();						// clear input buffer
			fgets(id, ID_SIZE, stdin);		// get user id from user
			searchDatabaseByID(id);			// search database using id from user.
			getchar();						// clear input buffer
			break;
		// provide a count of students per campus
		case 'C': case 'c':
			campusCount();
			getchar();						// clear input buffer
			break;
		// quit cmd
		case 'Q': case 'q':
			quit = 1;
			break;
		}
	}
	return 0;
}

// Takes string as filename parameter, loads file, then constructs record structs for each record in database.
// records are stored in global records array.
void loadDatabase(char *filename) {
	FILE *db;
	char s[RECORD_LENGTH]; // assumed record length
	char *token;

	// open file for read only
	fopen_s(&db, filename, "r");
	if (db == NULL) {
		printf("Database failed to open.\n");
		exit(EXIT_FAILURE);
	}

	while ((fgets(s,RECORD_LENGTH,db)) != NULL) {
		// since records are expected to be in the same order processing is easy.
		// token is the string from either the start of the file or the end of the prevous token until a comma.
		// The only exception is for campus, where the record doesn't end with a comma but a \n
		// first item is id
		token = strtok(s, ",");
		strcpy(records[recordLength].id, token);

		// second item is name
		token = strtok(NULL, ",");
		strcpy(records[recordLength].name, token);
		
		// third item is major
		token = strtok(NULL, ",");
		strcpy(records[recordLength].major, token);
		
		// fourth item is campus
		token = strtok(NULL, "\n");
		strcpy(records[recordLength].campus, token);

		// increment recordLength to complete each record.
		++recordLength;
	}

	fclose(db); // close file
}

// Searches a database for corresponding IDs provided by string parameter.
// returns number of entries found.
int searchDatabaseByID(char *id) {
	int count = 0;

	for (int i = 0; i < recordLength; i++) {
		// compare search ID with all record Ids
		if (strcmp(id, records[i].id) == 0) {
			++count; // increment number of records found
			// print statement to print entire record.
			printf("%-8s %-32s %-32s %-32s\n", records[i].id, records[i].name, records[i].major, records[i].campus);
		}
	}

	if (count == 0) {
		printf("No records found matching ID %s", id);
	}

	return count;
}

void campusCount() {
	enum campuses {Downtown, East, West, n} recCamp; // enum initialization
	int eastN = 0, downN = 0, westN = 0, nN = 0;	 // counts for each type nN will store records that aren't accounted for.

	for (int i = 0; i < recordLength; i++) {
		// Determine what the record contains and apply the correct enum.
		if (strcmp(records[i].campus, "Downtown Campus") == 0) {
			recCamp = Downtown;
		}
		else if (strcmp(records[i].campus, "East Campus") == 0) {
			recCamp = East;
		}
		else if (strcmp(records[i].campus, "West Campus") == 0) {
			recCamp = West;
		}
		else {
			// error case enum.
			recCamp = n;
		}

		// depending on the case increment count appropriately.
		switch (recCamp) {
		case Downtown:
			++downN;
			break;
		case East:
			++eastN;
			break;
		case West:
			++westN;
			break;
		default:
			++nN;
			break;
		}
	}
	printf("East Campus %d Students\n", eastN);
	printf("West Campus %d Students\n", westN);
	printf("Downtown Campus %d Students\n", downN);
	//printf("Unknown Campus %d Students\n", nN);
}

void displayDatabase() {
	for (int i = 0; i < recordLength; i++) {
		printf("%-8s %-32s %-32s %-32s\n", records[i].id, records[i].name, records[i].major, records[i].campus);
	}
}