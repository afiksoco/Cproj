#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "General.h"
#include "Guest.h"

int initGuest(Guest *pGuest)
{
    pGuest->name = getStrExactName("Enter name");
    pGuest->lastName = getStrExactName("Enter last name");
    pGuest->phoneNumber = getStrExactName("Enter phone number");
}

void printGuest(Guest *pGuest)
{
    printf("Name : %s\n", pGuest->name);
    printf("Last name : %s\n", pGuest->lastName);
    printf("Phone number : %s\n", pGuest->lastName);


}

void freeGuest(Guest *pGuest)
{
    free(pGuest->name);
    free(pGuest->lastName);
    free(pGuest->phoneNumber);
}