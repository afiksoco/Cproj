#ifndef __HOTEL__
#define __HOTEL__

#include "Address.h"
#include "Facility.h"
#include "List.h"
#include "Room.h"
#include "Guest.h"
#include "Reservation.h"

typedef struct
{
	char*		hotelName;
	Address		address;
	int			rating;
	Facility*	facilities;
	LIST		reviewsList;
	Room*		hotelRooms;
	Guest**		hotelGuests;
	int			roomCount;
	int			guestCount;
	//Reservation* allReservations;

}Hotel;



#endif