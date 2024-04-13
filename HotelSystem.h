#pragma once
#ifndef __HOTEL_SYSTEM__
#define __HOTEL_SYSTEM__

#include "Hotel.h"

typedef enum {
    eName, eRating, eRooms, eNotSorted, eNofSortType
} eSortType;


static const char* SortTypeStr[eNofSortType]
        = { "Hotel name", "Rating", "Number of rooms", "Not sorted"};


typedef struct {

    Hotel *hotelsArr;
    int numOfHotels;
    eSortType	sortType;

} HotelSystem;

void initHotelSystem(HotelSystem *pHs);


void printAllHotels(HotelSystem *pHs);

int addHotelToSystem(HotelSystem *pHs);

Hotel *getHotelByName(HotelSystem *pHs, char *hotelName);

void printSystem(HotelSystem *pHs);

Hotel *hotelInfo(HotelSystem *pHs);

void freeSystem(HotelSystem *pHs);

void sortHotel(HotelSystem *pHs);

void searchHotel(const HotelSystem *pHs);


#endif