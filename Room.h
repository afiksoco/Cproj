#pragma once
#ifndef __ROOM__
#define __ROOM__


#include "Guest.h"

typedef enum {
	eSingle, eDouble, eSuite, eNofRoomTypes
} eRoomType;

static const char* RoomTypeStr[eNofRoomTypes]
		= { "Single", "Double", "Suite" };


typedef struct
{	
	int			capacity;
	eRoomType	type;
	int			roomNumber;
	Guest		guest;

}Room;



#endif