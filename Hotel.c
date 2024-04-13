#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hotel.h"
#include "General.h"
#include "Review.h"


void printHotel(Hotel *pHotel) {
    printf("%-21s", pHotel->hotelName);
    printAddress(&pHotel->address);
    if (pHotel->rating == 0) printf("%s", "no rating yet");
    else
        printf("%-10.1f", pHotel->rating);


}

int addRoom(Hotel *pHotel) {
    pHotel->hotelRooms = (Room *) realloc(pHotel->hotelRooms, (pHotel->roomCount + 1) * sizeof(Room));
    if (!pHotel->hotelRooms)
        return 0;
    initRoom(&pHotel->hotelRooms[pHotel->roomCount], pHotel->roomCount);
    pHotel->roomCount++;
    return 1;
}

int initHotel(Hotel *pHotel) {
    pHotel->hotelName = getStrExactName("Enter hotel name\n");
    toTitleCase(pHotel->hotelName);
    initAddress(&pHotel->address);
    pHotel->rating = 0;
    //pHotel->guestCount = 0;
    pHotel->reservationCount = 0;
    pHotel->roomCount = 0;
    pHotel->allReservations = NULL;
    pHotel->facilities = NULL;
    pHotel->hotelRooms = NULL;
  //  pHotel->hotelGuests = NULL;

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

    initReservation(pReservation, pHotel->allReservations, pHotel->reservationCount, pRoom);
    pHotel->allReservations = (Reservation **) realloc(pHotel->allReservations,
                                                       (pHotel->reservationCount + 1) * sizeof(Reservation *));
    if (!pHotel->allReservations) {
        free(pRoom);
        return 0;
    }
    pHotel->allReservations[pHotel->reservationCount] = pReservation;
    pHotel->reservationCount++;

    printReservation(pReservation);
    return 1;
}


int isRoomOccupied(Reservation **reservations, int size, int roomNumber, Date checkin, Date checkout) {
    for (int i = 0; i < size; i++) {
        if (reservations[i]->roomReserved.roomNumber == roomNumber)
            if (compareDates(&reservations[i]->checkInDate, &checkout) < 0 &&
                compareDates(&reservations[i]->checkOutDate, &checkin) > 0) {
                return 1;
            }
    }
    return 0;
}

Room *getRoom(Hotel *pHotel) {
    printf("Choose room from the list below by its room number\n");
    printAllRooms(pHotel);
    int roomNumber;
    scanf("%d", &roomNumber);
    for (int i = 0; i < pHotel->roomCount; ++i) {
        if (roomNumber == pHotel->hotelRooms[i].roomNumber) {
            printf("Chosen room number %d\n", pHotel->hotelRooms[i].roomNumber);
            return &pHotel->hotelRooms[i];
        }
    }
    return NULL;
}

void printAllRooms(Hotel *pHotel) {
    printf("\n%-20s %-25s %s\n", "Room type", "Room number", "Capacity");
    for (int i = 0; i < pHotel->roomCount; i++) {
        printRoom(&pHotel->hotelRooms[i]);
    }
}


void freeHotel(Hotel *pHotel) {
    freeResArray(pHotel->allReservations, pHotel->reservationCount);
    free(pHotel->allReservations);
    ///// need to free a lot more.
}

void printOccupiedDates(Reservation **reservations, int size, int roomNumber) {
    printf("\nOccupied dates : \n");
    for (int i = 0; i < size; i++) {
        if (reservations[i]->roomReserved.roomNumber == roomNumber) {
            printDate(&reservations[i]->checkInDate);
            printf(" ---> ");
            printDate(&reservations[i]->checkOutDate);
            printf("\n");


        }
    }
}

void freeResArray(Reservation **allRes, int size) {
    for (int i = 0; i < size; i++)
        free(allRes[i]);

}

int cancelReservation(Hotel *pHotel) {
    if (pHotel->reservationCount == 0)
        printf("No reservations for this hotel! Exiting...\n");
    showAllReservations(pHotel);
    char *id = getStrExactName("Choose reservation by its ID\n");
    Reservation *res = getReservationByCode(pHotel, id);
    if (!res) {
        printf("No such reservation. Exiting...\n");
        return 0;
    }
    int index = -1;
    for (int i = 0; i < pHotel->reservationCount; i++) {
        if (pHotel->allReservations[i] == res) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Reservation not found in the list.\n");
        return 0;
    }

    freeReservation(pHotel->allReservations[index]);


    for (int i = index; i < pHotel->reservationCount - 1; i++) {
        pHotel->allReservations[i] = pHotel->allReservations[i + 1];
    }

    pHotel->reservationCount--;

    printf("Reservation canceled successfully.\n");
    showAllReservations(pHotel);

    return 1;
}

Reservation *getReservationByCode(Hotel *pHotel, char *id) {
    for (int i = 0; i < pHotel->reservationCount; i++) {
        if (!strcmp(pHotel->allReservations[i]->reservationCode, id))
            return pHotel->allReservations[i];
    }
    return NULL;
}


void showAllReservations(Hotel *pHotel) {
    printf("\n%-15s %-15s %-15s %s\n", "Reservation ID", "Check In", "Check Out", "Room Type");
    for (int i = 0; i < pHotel->reservationCount; ++i) {
        printReservation(pHotel->allReservations[i]);
        printf("\n");
    }

}

int addReview(Hotel *pHotel) {
    Review *pReview = (Review *) calloc(1, sizeof(Review));
    if (!pReview)
        return 0;

    if (!initReview(pReview)) {
        freeReview(pReview);
        free(pReview);
    }

    NODE *pNode = &pHotel->reviewsList.head;
    L_insert(pNode, pReview);
    pHotel->rating = calcRating(&pHotel->reviewsList);

    return 1;
}

void showAllReviews(Hotel *pHotel) {
    L_print(&pHotel->reviewsList, (void (*)(const void *)) printReview);
}

double calcRating(LIST *revList) {

    double sum = 0;
    int count = 0;
    NODE *pNode = &revList->head;
    while (pNode->next != NULL) {
        sum += ((Review *) pNode->next->key)->rating;
        count++;
        pNode = pNode->next;
    }

    return sum / count;
}


int compareByHotelName(const void *v1, const void *v2) {
    const Hotel *h1 = (const Hotel *) v1;
    const Hotel *h2 = (const Hotel *) v2;
    return strcmp(h1->hotelName, h2->hotelName);
}

int compareByRating(const void *v1, const void *v2) {
    const Hotel *h1 = (const Hotel *) v1;
    const Hotel *h2 = (const Hotel *) v2;
    if (h1->rating > h2->rating)return -1;
    if (h1->rating < h2->rating)return 1;
    return 0;
}

int compareByNumberOfRooms(const void *v1, const void *v2) {
    const Hotel *h1 = (const Hotel *) v1;
    const Hotel *h2 = (const Hotel *) v2;
    return h2->roomCount - h1->roomCount;
}

