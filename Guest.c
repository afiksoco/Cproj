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
    printf("");
}

void freeGuest(Guest *pGuest)
{
    free(pGuest->name);
    free(pGuest->lastName);
    free(pGuest->phoneNumber);
}