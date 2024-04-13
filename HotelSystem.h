#pragma once
#ifndef __HOTEL_SYSTEM__
#define __HOTEL_SYSTEM__

#include "Hotel.h"

typedef struct {
    Hotel *hotelsArr;
    int numOfHotels;
} HotelSystem;

void initHotelSystem(HotelSystem *pHs);


void printAllHotels(HotelSystem *pHs);

int addHotelToSystem(HotelSystem *pHs);

Hotel *getHotelByName(HotelSystem *pHs, char *hotelName);

void printSystem(HotelSystem *pHs);

Hotel *hotelInfo(HotelSystem *pHs);

void freeSystem(HotelSystem *pHs);

#endif