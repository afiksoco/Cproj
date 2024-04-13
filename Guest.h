#ifndef __GUEST__
#define __GUEST__


typedef struct
{
	char*		name;
	char*		lastName;
	char*		phoneNumber;
}Guest;

int initGuest(Guest *pGuest);

void printGuest(Guest *pGuest);

void freeGuest(Guest *pGuest);

#endif