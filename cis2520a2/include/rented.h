#ifndef __RENTED_LINKEDLIST__
#define __RENTED_LINKEDLIST__

struct Rented{
	char * rentedPlateNum;
	int rentedMileage;
	int rentedExpectedReturnDate;
	struct Rented * next;
};

typedef struct Rented Rented;

#endif