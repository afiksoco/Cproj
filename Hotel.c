#include <stdio.h>
#include <stdlib.h>
#include "Hotel.h"
#include "General.h"

void printHotel(Hotel *pHotel) {
    printf("%-21s", pHotel->hotelName);
    printAddress(&pHotel->address);
    if (pHotel->rating == 0) printf("%-10s", "no rating yet");
    else
        printf("%-10d", pHotel->rating);


}

int addRoom(Hotel *pHotel) {
    pHotel->hotelRooms = (Room *) realloc(pHotel->hotelRooms, (pHotel->roomCount + 1) * sizeof(Room));
    if (!pHotel->hotelRooms)
        return 0;
    initRoom(&pHotel->hotelRooms[pHotel->roomCount], pHotel->roomCount);
    pHotel->roomCount++;
    return 1;
}


/*int addReservation(Hotel *pHotel) {
    pHotel->allReservations = (Reservation *) realloc(pHotel->allReservations,
                                                      (pHotel->reservationCount + 1) * sizeof(Reservation));
    if (!pHotel->allReservations)
        return 0;
    initReservation(&pHotel->allReservations[pHotel->reservationCount], pHotel->allReservations,
                    pHotel->reservationCount);
    pHotel->reservationCount++;
    return 1;
}*/

int initHotel(Hotel *pHotel) {
    pHotel->hotelName = getStrExactName("Enter hotel name\n");
    toTitleCase(pHotel->hotelName);
    initAddress(&pHotel->address);
    pHotel->rating = 0;
    pHotel->guestCount = 0;
    pHotel->reservationCount = 0;
    pHotel->roomCount = 0;
    pHotel->allReservations = NULL;
    pHotel->facilities = NULL;
    pHotel->hotelRooms = NULL;
    pHotel->hotelGuests = NULL;

    BOOL val = L_init(&pHotel->reviewsList);
    if (val == 0)
        return 0;
/*    if (!readManagerFromTextFile(fileName, pManager))
        return 2;*/
    else
        return 1;

}

int createReservation(Hotel *pHotel) {
    if (pHotel->roomCount == 0) {
        printf("There are no rooms to create reservation.\n");
        return 0;
    }
    Reservation *pReservation = (Reservation *) calloc(1, sizeof(Reservation));
    if (!pReservation) return 0;

    Room *pRoom = getRoom(pHotel);
    printf("There are no rooms to csscscsccsction.\n");

    initReservation(pReservation, pHotel->allReservations, pHotel->reservationCount, pRoom);
    printf("aadasd");
    pHotel->allReservations = (Reservation **) realloc(pHotel->allReservations,
                                                       (pHotel->reservationCount + 1) * sizeof(Reservation *));
    if (!pHotel->allReservations)
    {
        free(pRoom);
        return 0;
    }
    pHotel->allReservations[pHotel->reservationCount] = pReservation;
    pHotel->reservationCount++;
    return 1;

}

Room *getRoom(Hotel *pHotel) {
    printf("Choose room from the list below by its room number\n");
    printAllRooms(pHotel);
    int roomNumber;
    scanf("%d", &roomNumber);
    for (int i = 0; i < pHotel->roomCount; ++i) {
        if (roomNumber == pHotel->hotelRooms[i].roomNumber) {
            printf("Chosen room number %d", pHotel->hotelRooms[i].roomNumber);
            return &pHotel->hotelRooms[i];
        }
    }
    return NULL;
}

void printAllRooms(Hotel *pHotel) {
    printf("\n%-15s %-15s %-15s\n", "Room type", "Room number", "Capacity");
    for (int i = 0; i < pHotel->roomCount; i++) {
        printRoom(&pHotel->hotelRooms[i]);
    }
}


void freeHotel(Hotel *pHotel) {
    freeResArray(pHotel->allReservations, pHotel->reservationCount);
    free(pHotel->allReservations);
    ///// need to free a lot more.
}


void freeResArray(Reservation **allRes, int size)
{
    for (int i = 0; i < size; i++)
        free(allRes[i]);

}