#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "General.h"
#include "Date.h"

const int DAY_MONTHS[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
#define SEPERATOR '/'

void initDate(Date* pDate)
{
	char date[MAX_STR_LEN];
	int ok = 0;
	printf("Enter Date in this format : dd%cmm%cyyyy\n", SEPERATOR, SEPERATOR);

	do
	{
	myGets(date, MAX_STR_LEN);
	
	
	if (!(ok = checkDate(date, pDate)))
		printf("Wrong input, enter new date in this format :  dd%cmm%cyyyy\n", SEPERATOR, SEPERATOR);
	
		
	} while (!ok);

}

int	 checkDate(char* date, Date* pDate)
{
	int day, month, year;
	if (strlen(date) != 10)
		return 0;
	if ((date[2] != SEPERATOR) || (date[5] != SEPERATOR))
		return 0;
	int x = sscanf(date, "%d/%d/%d", &day, &month, &year);
	if (day < 1 || month < 1 || month > 12)
		return 0;

	if (day > DAY_MONTHS[month - 1])
		return 0;

	pDate->day = day;
	pDate->month = month;
	pDate->year = year;

	return 1;
}

void printDate(const Date* pDate) 
{
	printf("date: %02d/%02d/%d", pDate->day, pDate->month, pDate->year);
}