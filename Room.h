#pragma once
#ifndef __ROOM__
#define __ROOM__

typedef enum {
    eSingle, eDouble, eSuite, eNofRoomTypes
} eRoomType;

static const char *RoomTypeStr[eNofRoomTypes]
        = {"Single", "Double", "Suite"};


typedef struct {

    int capacity;
    eRoomType type;
    int roomNumber;
} Room;


void initRoom(Room *pRoom, int roomCount);

void freeRoom(Room *pRoom);

void printRoom(Room *pRoom);

//int addReservation(Room* pRoom, Reservation *pRes);

//int isRoomOccupied(Reservation *pRes,Room* pRoom);



#endif