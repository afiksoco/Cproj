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
    double rating;
    Facility *facilities;
    LIST reviewsList;
    Room *hotelRooms;
   // Guest **hotelGuests;
    int roomCount;
  //  int guestCount;
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

int isRoomOccupied(Reservation **reservations, int size, int roomNumber, Date checkin, Date checkout);

void printOccupiedDates(Reservation **reservations, int size, int roomNumber);

void showAllReservations(Hotel *pHotel);

int cancelReservation(Hotel *pHotel);

Reservation *getReservationByCode(Hotel *pHotel, char *id);

int addReview(Hotel *pHotel);

double calcRating(LIST *revList);

void showAllReviews(Hotel *pHotel);

int	compareByHotelName(const void* v1, const void* v2);

int	compareByRating(const void* v1, const void* v2);

int	compareByNumberOfRooms(const void* v1, const void* v2);


#endif