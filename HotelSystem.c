#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "HotelSystem.h"
#include "General.h"
#include "Hotel.h"


void initHotelSystem(HotelSystem *pHs) {
    pHs->hotelsArr = NULL;
    pHs->numOfHotels = 0;
    pHs->numOfUsers = 0;
}


int addHotelToSystem(HotelSystem *pHs) {
    pHs->hotelsArr = (Hotel *) realloc(pHs->hotelsArr, (pHs->numOfHotels + 1) * sizeof(Hotel));
    if (!pHs->hotelsArr) {
        return 0;
    }
    if (!initHotel(&pHs->hotelsArr[pHs->numOfHotels])) {
        freeHotel(&pHs->hotelsArr[pHs->numOfHotels]);
        free(&pHs->hotelsArr[pHs->numOfHotels]);
    }
    pHs->numOfHotels++;
    return 1;
}

Hotel *getHotelByName(HotelSystem *pHs, char *hotelName) {
    for (int i = 0; i < pHs->numOfHotels; ++i) {
        if (!strcmp(hotelName, pHs->hotelsArr[i].hotelName)) {
            return &pHs->hotelsArr[i];
        }
    }
    return NULL;
}


Hotel *hotelInfo(HotelSystem *pHs)
{
    Hotel *pHotel;
    printf("Select hotel from the list below by its name.\n");
    printAllHotels(pHs);
    char *hotelName;

    int valid = 0;
    do {
        hotelName = getStrExactName("");
        pHotel = getHotelByName(pHs, hotelName);
        if (pHotel != NULL)
            valid = 1;
        else printf("Hotel doest exists. Try again!\n");
    } while (!valid);
}

void printSystem(HotelSystem *pHs) {
    for (int i = 0; i < pHs->numOfHotels; i++) {
        printf("%-20s %-27s %s\n", "Hotel name", "Address", "Rating");
        Hotel *pHotel = &pHs->hotelsArr[i];
        printHotel(pHotel);
        printAllRooms(pHotel);

        printf("\n");
    }
}


void printAllHotels(HotelSystem *pHs)
{
    printf("%-20s %-27s %s\n", "Hotel name", "Address", "Rating");
    for (int i = 0; i < pHs->numOfHotels; i++) {
        printHotel(&pHs->hotelsArr[i]);
        printf("\n");
    }
}

