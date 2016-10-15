#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "repair.h"

Repair * createRecord(char * repairPlateNum, int repairMileage)
{

	Repair * temp = malloc(sizeof(Repair));
	temp->repairPlateNum = malloc(char)*99);
	temp->repairMileage = repairMileage;
	strcpy(temp->repairPlateNum, repairPlateNumber);
	temp->next = NULL;

	if(temp == NULL || temp->repairPlateNum == NULL || temp->repairMileage)
	{
		return NULL;
	}

	return temp;

}

char * printRepairRecord(Repair * toPrintRepair)
{
	char * repairString = malloc(sizeof(char)*256);
	sprintf(repairString, "Plate Number: %s - Mileage: %d", toPrintRepair->repairPlateNum, toPrintRepair->repairMileage);

	if(repairString == NULL)
	{
		return NULL;
	}

	return repairString;
}

int isRepairEmpty(Repair * repairList)
{
	if(repairList == NULL)
	{
		return 1;

	}

	return 0;
}