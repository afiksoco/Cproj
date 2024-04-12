#include <stdio.h>
#include <ctype.h>

#include "Address.h"
#include "General.h"

void printAddress(Address* pAddress) {

    printf("%s, ", pAddress->state);
    printf("%-20s", pAddress->city);

}

void initAddress(Address* pAddress)
{
    pAddress->state = getStrExactName("\nEnter state\n");
    pAddress->city = getStrExactName("\nEnter city\n");
    toTitleCase(pAddress->state);
    toTitleCase(pAddress->city);


}