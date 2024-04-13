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


Hotel *hotelInfo(HotelSystem *pHs) {
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

void sortHotel(HotelSystem *pHs) {
    int opt;
    printf("Base on what field do you want to sort?\n");
    do {
        printf("Enter 1 for hotel name\n");
        printf("Enter 2 for hotel rating\n");
        printf("Enter 3 for number of rooms\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                qsort(pHs->hotelsArr, pHs->numOfHotels, sizeof(Hotel), compareByHotelName);
                pHs->sortType = eName;
                break;
            case 2:
                qsort(pHs->hotelsArr, pHs->numOfHotels, sizeof(Hotel), compareByRating);
                pHs->sortType = eRating;
                break;
            case 3:
                qsort(pHs->hotelsArr, pHs->numOfHotels, sizeof(Hotel), compareByNumberOfRooms);
                pHs->sortType = eRooms;
                break;
        }
    } while (opt < 1 || opt > 3);
}


void printAllHotels(HotelSystem *pHs) {
    printf("%-20s %-27s %s\n", "Hotel name", "Address", "Rating");
    for (int i = 0; i < pHs->numOfHotels; i++) {
        printHotel(&pHs->hotelsArr[i]);
        printf("\n");
    }
}

void freeSystem(HotelSystem *pHs) {
    for (int i = 0; i < pHs->numOfHotels; ++i) {
        freeHotel(&pHs->hotelsArr[i]);
        free(pHs->hotelsArr);
    }
}

void searchHotel(const HotelSystem *pHs) {
    if (pHs->sortType == eNotSorted) {
        printf("Cant search! array must be sorted!\n");
        return;
    }
    Hotel *pHotel;
    Hotel h = {0};
    Hotel *pTemp = &h;
    if (pHs->sortType == eName) {
        h.hotelName = getStrExactName("Enter hotel name to search\n");
        pHotel = bsearch(pTemp, pHs->hotelsArr, pHs->numOfHotels, sizeof(Hotel), compareByHotelName);

    }
    if (pHs->sortType == eRating) {
        printf("Enter rating to search by\n");
        scanf("%lf", &h.rating);
        pHotel = bsearch(pTemp, pHs->hotelsArr, pHs->numOfHotels, sizeof(Hotel), compareByRating);

    }
    if (pHs->sortType == eRooms) {
        printf("Enter number of rooms\n");
        scanf("%d", &h.roomCount);
        pHotel = bsearch(pTemp, pHs->hotelsArr, pHs->numOfHotels, sizeof(Hotel), compareByNumberOfRooms);

    }
    if (!pHotel) {
        printf("Hotel was not found\n");
        return;
    }
    printf("Hotel found:  ");
    printHotel(pHotel);
}


