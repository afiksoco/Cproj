#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Reservation.h"
#include "Date.h"
#include "Guest.h"
#include "General.h"
#include "Room.h"
#include "Date.h"
#include "Hotel.h"


void initReservation(Reservation *pReservation, Reservation **resArr, int resCount, Room *pRoom) {
    initGuest(&pReservation->guestOrdered);
    int ok = 1;
    do {
        ok = 1;
        printf("Check in:\n");
        initDate(&pReservation->checkInDate); // need to check if the room is available in these dates ?
        printf("Check out:\n");
        do {
            initDate(&pReservation->checkOutDate);
            if (compareDates(&pReservation->checkOutDate, &pReservation->checkInDate) <= 0) {
                printf("Check-out date must be later than the check-in date. Please enter again.\n");
            }
        } while (compareDates(&pReservation->checkOutDate, &pReservation->checkInDate) <= 0);
        if (isRoomOccupied(resArr, resCount, pRoom->roomNumber, pReservation->checkInDate,
                           pReservation->checkOutDate)) {
            printf("Your reservation is over lapping other reservation for this room!\n");
            printOccupiedDates(resArr, resCount, pRoom->roomNumber);
            ok = 0;
        }
    } while (!ok);
    ok = 1;
    do {
        getReservationCode(pReservation->reservationCode);

        for (int i = 0; i < resCount; i++) {
            if (!strcmp(pReservation->reservationCode, resArr[i]->reservationCode)) {
                printf("Code already exists");
                ok = 0;
                break;
            }
        }
    } while (!ok);

    pReservation->roomReserved = *pRoom;

}

void getReservationCode(char *code) {
    char temp[MAX_STR_LEN];
    int ok = 1;
    do {
        ok = 1;
        printf("Enter reservation code  - %d upper case letters\t", RES_CODE_LENGTH);
        myGets(temp, MAX_STR_LEN);
        if (strlen(temp) != RES_CODE_LENGTH) {
            printf("code should be %d letters\n", RES_CODE_LENGTH);
            ok = 0;
        } else {
            for (int i = 0; i < RES_CODE_LENGTH; i++) {
                if (isupper(temp[i]) == 0) {
                    printf("Need to be upper case letter\n");
                    ok = 0;
                    break;
                }
            }
        }
    } while (!ok);

    strcpy(code, temp);
}

void printReservation(Reservation *pRes) {
    printf("Reservation #%s:\n", pRes->reservationCode);
    printf("Check in : ");
    printDate(&pRes->checkInDate);
    printf("Check out : ");
    printDate(&pRes->checkOutDate);
    printf("\nRoom type : %s", RoomTypeStr[pRes->roomReserved.type]);
}