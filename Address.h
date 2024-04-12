#pragma once
#ifndef __ADDRESS__
#define __ADDRESS__


typedef struct
{
	char*		state;
	char*		city;
}Address;


void printAddress(Address* pAddress);
void initAddress(Address* pAddress);
void freeAddress(Address* pAddress);

#endif