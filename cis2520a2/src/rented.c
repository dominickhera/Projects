#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rented.h"

Rented * createRecord(char * rentedPlateNum, int rentedMileage, int rentedExpectedReturnDate)
{

    Rented * temp = malloc(sizeof(Rented));
    temp->rentedPlateNum = malloc(char)*99);
    temp->rentedMileage = rentedMileage;
    strcpy(temp->rentedPlateNum, rentedPlateNumber);
    temp->next = NULL;

    if(temp == NULL || temp->rentedPlateNum == NULL || temp->rentedMileage)
    {
        return NULL;
    }

    return temp;

}

char * printRentedRecord(Rented * toPrintRented)
{
    char * rentedString = malloc(sizeof(char)*256);
    sprintf(rentedString, "Plate Number: %s - Mileage: %d - Expected Return Date: %d", toPrintRented->rentedPlateNum, toPrintRented->rentedMileage, toPrintRented->rentedExpectedReturnDate);

    if(rentedString == NULL)
    {
        return NULL;
    }

    return rentedString;
}

int isRentedEmpty(Rented * rentedList)
{
    if(rentedList == NULL)
    {
        return 1;

    }

    return 0;
}
