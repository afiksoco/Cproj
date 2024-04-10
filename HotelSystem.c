#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "HotelSystem.h"
#include "General.h"


void initHotelSystem(HotelSystem* pHs)
{
	pHs->hotelsArr = NULL;
	pHs->numOfHotels = 0;
	pHs->allUsers = NULL;
	pHs->numOfUsers = 0;

}


User* userInfo(HotelSystem* pHs)
{
	char id[MAX_STR_LEN];
	printf("Welcome to booking. please enter ur id (must be 9 digits)\n");
	int ok = 0;
	do {
		myGets(id, MAX_STR_LEN);
		if(!(ok = isValidID(id)))
			printf("enter valid id please");

	} while (!ok);

	printf("Checking if id exists.......\n");

	User* pUser = getUser(pHs,id);
	if (pUser)
	{
		printf("ID found, logging in......\n");
		return pUser;
	}
	else {
		printf("User not found, signing up\n");
		if (signUp(id, pHs))
		{
			//saveToFile()
			printf("Great! signed up succu....");
			return &pHs->allUsers[pHs->numOfUsers]; // returns the signed up pUser
			
		}
	}
	return NULL;
}

int signUp(char* id, HotelSystem* pHs)
{
	pHs->allUsers = (User*)realloc(pHs->allUsers, (pHs->numOfUsers + 1) * sizeof(User));
	if (!pHs->allUsers)
		return 0;
	initUser(&pHs->allUsers[pHs->numOfUsers], id);
	pHs->numOfUsers++;
	return 1;
}

int isValidID(char* id)
{
	if (strlen(id) != 9)
		return 0;

	for (int i = 0; i < strlen(id); i++) {
		if (!isdigit(id[i])) {
			return 0;
		}
	}
	return 1;
}

User* getUser(HotelSystem* pHs, char* id)
{
	for (int i = 0; i < pHs->numOfUsers; i++)
	{
		if (!strcmp(pHs->allUsers[i].id, id))
			return &pHs->allUsers[i];
	}
	return NULL;
}


void printAllUsers(HotelSystem* pHs)
{
	printf("there are %d user:\n", pHs->numOfUsers);
	for (int i = 0; i < pHs->numOfUsers; i++)
	{
		printUser(&pHs->allUsers[i]);
	}
}