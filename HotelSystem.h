#pragma once
#ifndef __HOTEL_SYSTEM__
#define __HOTEL_SYSTEM__

#include "Hotel.h"
#include "User.h"

typedef struct
{
	Hotel*  hotelsArr;
	int		numOfHotels;
	User*   allUsers;
	int		numOfUsers;
}HotelSystem;

void initHotelSystem(HotelSystem* pHs);
User* userInfo(HotelSystem* pHs);
User* getUser(HotelSystem* pHs,char* id);
int isValidID(char* id);
void printAllUsers(HotelSystem* pHs);
int signUp(char* id, HotelSystem* pHs);

#endif