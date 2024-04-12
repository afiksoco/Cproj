#pragma once
#ifndef __ROOM__
#define __ROOM__


#include "Guest.h"

typedef enum {
    eSingle, eDouble, eSuite, eNofRoomTypes
} eRoomType;

static const char *RoomTypeStr[eNofRoomTypes]
        = {"Single", "Double", "Suite"};


typedef struct {

    int capacity;
    eRoomType type;
    int roomNumber;
    Guest *guests;

} Room;


void initRoom(Room *pRoom, int roomCount);

int validRoomNumber(Room *roomArr, int roomCount);

int isRoomNumberExists(Room *roomArr, int roomCount, int roomNumber);

void freeRoom(Room *pRoom);

void printRoom(Room *pRoom);


#endif