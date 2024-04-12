#ifndef __HOTEL__
#define __HOTEL__

#include "Address.h"
#include "Facility.h"
#include "List.h"
#include "Room.h"
#include "Guest.h"
#include "Reservation.h"

typedef struct {
    char *hotelName;
    Address address;
    int rating;
    Facility *facilities;
    LIST reviewsList;
    Room *hotelRooms;
    Guest **hotelGuests;
    int roomCount;
    int guestCount;
    int reservationCount;
    Reservation **allReservations;


} Hotel;

void printHotel(Hotel *pHotel);

int initHotel(Hotel *pHotel);

void freeHotel(Hotel *pHotel);

int addRoom(Hotel *pHotel);

void printAllRooms(Hotel *pHotel);

Room *getRoom(Hotel *pHotel);

int createReservation(Hotel *pHotel);

void freeResArray(Reservation **allRes, int size);

#endif