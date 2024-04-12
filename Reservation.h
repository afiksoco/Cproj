#ifndef __RESERVATION__
#define __RESERVATION__


#define RES_CODE_LENGTH 3

/*
#include "Hotel.h"
*/
#include "Date.h"
#include "Guest.h"
#include "Room.h"


typedef struct {


    Guest guestOrdered;
    Date checkInDate;
    Date checkOutDate;
    Room roomReserved;
    char reservationCode[RES_CODE_LENGTH + 1];

} Reservation;


void initReservation(Reservation *pReservation, Reservation **resArr, int resCount, Room *pRoom);

void getReservationCode(char *code);

void printReservation(Reservation *pRes);

#endif
