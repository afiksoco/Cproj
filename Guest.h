#ifndef __GUEST__
#define __GUEST__


typedef struct
{

	char*		name;
	char*		lastName;
	char*		phoneNumber;
	char*		email;
	char*		id;

}Guest;

int initGuest(char* id);

#endif