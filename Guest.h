#ifndef __GUEST__
#define __GUEST__


typedef struct
{

	char*		name;
	char*		lastName;
	char*		phoneNumber;
	char*		id;

}Guest;

int initGuest(Guest *pGuest);

#endif