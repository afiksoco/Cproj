#include <stdio.h>
#include <stdlib.h>
#include "HotelSystem.h"
#include "Date.h"
#include "Hotel.h"
#include "General.h"

typedef enum {
    eUploadFromFile, eShowSystem, eAddHotel, eAddRoomToHotel, eShowAllData, eAddReservation, eAddReview,
    eCancelReservation, eSort, eFind, eNofOptions
} eMenuOptions;

const char *str[eNofOptions] = {"Upload from file", "Show system", "Add Hotel", "Add room to hotel", "Show all data",
                                "Make reservation", "Add review",
                                "Cancel reservation", "Sort", "Find"};

int menu();


#define EXIT -1


int main() {
    HotelSystem hs;
    initHotelSystem(&hs);
    // User* pUser = userInfo(&hs);


    int option;
    int stop = 0;
    //Date d;
    //initDate(&d);
    //printDate(&d);

    do {
        option = menu();
        switch (option) {
            case eUploadFromFile:
                //
                break;

            case eShowSystem:

                printAllHotels(&hs);
                break;

            case eAddHotel:
                if (addHotelToSystem(&hs))
                    printf("Hotel added successfully.\n");
                else
                    printf("Error! try again.\n");
                break;
            case eAddRoomToHotel:
                if (hs.numOfHotels == 0) {
                    printf("No hotels in system! Exiting...\n");
                    break;
                }
                addRoom(hotelInfo(&hs));
                printf("Room inserted successfully\n");
                break;
            case eShowAllData:
                printSystem(&hs);
                break;

            case eAddReservation: ////////?????
                if (hs.numOfHotels == 0) {
                    printf("No hotels in system! Exiting...\n");
                    break;
                }
                if (!createReservation(hotelInfo(&hs)))
                    printf("Error creating reservation");


                break;

            case eAddReview: /// maybe to specific hotel ?

                break;

            case eCancelReservation:

                break;
                // maybe show history ?

            case eSort:
                break;


            case eFind:

                break;

                /*	case eTest:
                        break;*/

                ///// print all reservations for speccific date ??? maybe tomorrow?

            case EXIT:
                printf("Bye bye\n");
                stop = 1;
                break;

            default:
                printf("Wrong option\n");
                break;
        }
    } while (!stop);


    return 1;
}


int menu() {
    int option;
    printf("\n\n");
    printf("Please choose one of the following options\n");
    for (int i = 0; i < eNofOptions; i++)
        printf("%d - %s\n", i, str[i]);
    printf("%d - Quit\n", EXIT);
    scanf("%d", &option);
    //clean buffer
    char tav;
    scanf("%c", &tav);
    return option;
}