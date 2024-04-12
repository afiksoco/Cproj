#pragma once
#ifndef __HOTEL_SYSTEM__
#define __HOTEL_SYSTEM__

#include "Hotel.h"
#include "User.h"

typedef struct {
    Hotel *hotelsArr;
    int numOfHotels;
    int numOfUsers;
} HotelSystem;

void initHotelSystem(HotelSystem *pHs);

int isValidID(char *id);

void printAllUsers(HotelSystem *pHs);

void printAllHotels(HotelSystem *pHs);

int addHotelToSystem(HotelSystem *pHs);

Hotel *getHotelByName(HotelSystem *pHs, char *hotelName);

void printSystem(HotelSystem *pHs);

Hotel *hotelInfo(HotelSystem *pHs);


int signUp(char *id, HotelSystem *pHs);

#endif