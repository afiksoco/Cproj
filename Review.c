#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Review.h"
#include "General.h"

int initReview(Review *pReview)
{
    pReview->comment = getStrExactName("Write review\n");
    printf("Add rating ( 1.0 - 5.0 )\n");
    scanf("%lf", &pReview->rating);
    printf("Guest details :\n");
    initGuest(&pReview->reviewWriter);
}

void freeReview(Review *pReview)
{
    free(pReview->comment);
    freeGuest(&pReview->reviewWriter);

}

void printReview(Review *pReview)
{
    printf("Comment : \n");
    printf("%s\n", pReview->comment);
    printf("Rating : %f\n", pReview->rating);
    printGuest(&pReview->reviewWriter);


}

