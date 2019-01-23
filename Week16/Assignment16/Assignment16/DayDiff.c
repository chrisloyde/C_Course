#include "DayDiff.h"

int findDiffInDays() {
	int day, month, year;
	double secondsDiff = 0.0;
	struct tm date1;
	struct tm date2;
	time_t t1, t2;

	printf("Enter first date in format mm-dd-yyyy:\n");
	scanf("%d-%d-%d", &month, &day, &year);
	getchar();											// clear input stream

	t1 = setDate(&date1, month, day, year);				// set date and return seconds since epoch

	printf("Enter second date in format mm-dd-yyyy:\n");
	scanf("%d-%d-%d", &month, &day, &year);
	getchar();											// clear input stream

	t2 = setDate(&date2, month, day, year);				// set date and return seconds since epoch
	/*
		Determine which is the earlier time to find the difference appropriately
	*/
	if (t1 < t2) {
		secondsDiff = difftime(t2, t1);
	}
	else {
		secondsDiff = difftime(t1, t2);
	}
	day = (((secondsDiff / 60) / 60) / 24);				// convert to days

	return day;
}

time_t setDate(struct tm *date, int month, int day, int year) {
	date->tm_mday = day;
	date->tm_mon = month;
	date->tm_year = (year-1900);		// subtract 1900 to get the correct year
	date->tm_sec = 0;
	date->tm_min = 0;
	date->tm_hour = 0;
	date->tm_isdst = -1;

	return mktime(date);				// normalize date values and return seconds since epoch
}