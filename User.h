#ifndef __USER__
#define __USER__

#include "Reservation.h"

typedef struct
{

	char* name;
	char* lastName;
	char* phoneNumber;
	char* email;// maybe ? 
	char* id;
	Reservation* myReservations;

}User;

void initUser(User* pUser, char* id);
void printUser(User* pUser);

#endif