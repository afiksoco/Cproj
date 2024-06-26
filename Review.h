#pragma once
#ifndef __REVIEW__
#define __REVIEW__

#include "Guest.h"

typedef struct
{
	double		rating;
	char*		comment;
	Guest		reviewWriter;
}Review;

int initReview(Review *pReview);
void freeReview(Review *pReview);
void printReview(Review *pReview);

#endif
