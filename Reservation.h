#ifndef __RESERVATION__
#define __RESERVATION__


#define RES_CODE_LENGTH 3

#include "Hotel.h"
#include "Date.h"
#include "Guest.h"

typedef struct
{

	/*Hotel		hotelReserved;
	Guest		guestOrdered;
	Room		roomReserved;
	Date		checkInDate;
	Date		checkOutDate;*/
	char		reservationCode[RES_CODE_LENGTH + 1];

}Reservation;


#endif
