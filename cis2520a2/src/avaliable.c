#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "avaliable.h"

Avaliable * createRecord(char * avaliablePlateNum, int avaliableMileage)
{

	Avaliable * temp = malloc(sizeof(Avaliable));
	temp->avaliablePlateNum = malloc(char)*99);
	temp->avaliableMileage = avaliableMileage;
	strcpy(temp->avaliablePlateNum, avaliablePlateNumber);
	temp->next = NULL;

	if(temp == NULL || temp->avaliablePlateNum == NULL || temp->avaliableMileage)
	{
		return NULL;
	}

	return temp;

}

char * printAvaliableRecord(Avaliable * toPrintAvaliable)
{
	char * avaliableString = malloc(sizeof(char)*256);
	sprintf(avaliableString, "Plate Number: %s - Mileage: %d", toPrintAvaliable->avaliablePlateNum, toPrintAvaliable->avaliableMileage);

	if(avaliableString == NULL)
	{
		return NULL;
	}

	return avaliableString;
}

int isAvaliableEmpty(Avaliable * avaliableList)
{
	if(avaliableList == NULL)
	{
		return 1;

	}

	return 0;
}