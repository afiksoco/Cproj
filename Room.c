#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Room.h"


eRoomType getRoomType() {
    int option;
    printf("\n\n");
    do {
        printf("Please enter one of the following types\n");
        for (int i = 0; i < eNofRoomTypes; i++)
            printf("%d for %s\n", i, RoomTypeStr[i]);
        scanf("%d", &option);
    } while (option < 0 || option >= eNofRoomTypes);
    getchar();
    return (eRoomType) option;
}


void initRoom(Room *pRoom, int roomCount) {
    pRoom->type = getRoomType();
    if (pRoom->type == 0)
        pRoom->capacity = 1;
    if (pRoom->type == 1)
        pRoom->capacity = 2;
    if (pRoom->type == 2) {
        printf("Suite chosen! enter capacity");
        scanf("%d", &pRoom->capacity);
    }
    pRoom->guests = NULL;

    pRoom->roomNumber = roomCount + 1;
}


void printRoom(Room *pRoom) {
    printf("%-15s %-15d %-15d\n", RoomTypeStr[pRoom->type], pRoom->roomNumber, pRoom->capacity);
}

void freeRoom(Room *pRoom) {

}