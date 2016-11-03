#include "linkedList.h"
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

Food * createRecord(char * name, char * group, int calories, char theType)
{
    Food * temp = malloc(sizeof(Food));
    temp->name = malloc(sizeof(char)*50);
    temp->foodGroup = malloc(sizeof(char)*50);
    temp->calories =  calories;
    temp->type = theType;
    strcpy(temp->name, name);
    strcpy(temp->foodGroup, group);
    temp->next = NULL;

    if(temp == NULL || temp->name == NULL || temp->foodGroup == NULL)
    {
        return NULL;
    }

    return temp;
}

char * printRecord(Food * toPrint)
{

    char * foodString = malloc(sizeof(char)*256);
    sprintf(foodString, "%s (%s): %d[%c]",  toPrint->name, toPrint->foodGroup, toPrint->calories, toPrint->type);

    if(foodString == NULL)
    {
        return NULL;
    }

    return foodString;
}

void destroyRecord(Food * toDie)
{
    free(toDie->name);
    free(toDie->foodGroup);
    free(toDie);
}

Food * addToFront(Food * theList, Food * toBeAdded)
{
    if(isEmpty(theList) == 0)
    {
        toBeAdded->next = theList;
    }

    return toBeAdded;
}

Food * addToBack(Food * theList, Food * toBeAdded)
{
    Food * temp;
    temp = theList;

    if(isEmpty(theList) == 1)
    {
        return toBeAdded;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = toBeAdded;
    temp->next->next = NULL;

    return theList;
}

Food * removeFromFront(Food * theList)
{
    Food * temp;
    temp = getFirstItem(theList);
    theList = theList->next;
    destroyRecord(temp);

    return theList;
}

Food * removeFromBack(Food * theList)
{

    Food * temp;
    temp = theList;

    getLastItem(theList);
    destroyRecord(temp);

    return theList;  
}

Food * getLastItem(Food * theList)
{
    Food * temp;
    temp = theList;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

Food * getFirstItem(Food * theList)
{
    if(theList == NULL)
    {
        return NULL;
    }

    return theList;
}

int isEmpty(Food * theList)
{
    if(theList == NULL)
    {
        return 1;
    }


return 0;

}

void printList(Food * theList)
{
    Food * temp;
    temp = theList;
    while(temp != NULL)
    {
        printf("%s\n", printRecord(temp));
        temp = temp->next;
    }
}

void destroyList(Food * theList)
{
    Food * temp;
    temp = theList;
    while(temp->next != NULL)
    {
        // temp = theList;
        theList = theList->next;
        free(temp->name);
        free(temp->foodGroup);
        free(temp);
    }

    // return NULL;
    printf("list has been destroyed\n");
}
