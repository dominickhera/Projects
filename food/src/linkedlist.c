#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

Food * createRecord(char * name, char * group, int calories, char theType)
{

    Food * temp = malloc(sizeof(Food));
    temp->name = malloc(sizeof(char)*50);
    temp->group = malloc(sizeof(char)*50);
    temp->calories = calories;
    temp->theType = theType;
    temp->next = NULL;

    if(temp == NULL || temp->name == NULL || temp->group == NULL)
    {
        return NULL;
    }

    return temp;

}

char * printRecord(Food * toPrint)
{

    /**
     * printRecord
     * Returns allocated memory containing a string filled with Food data in the
     * following format:
     * Name (Food Group):calories[type]
     * Note: The string should not contain a newline.
     * The string memory is allocated in this function and must be freed by the
     * caller.
     * @param  toPrint Food* (not NULL)
     * @return         char* to malloc'd memory
     *                 NULL on failure
     */

}

void destroyRecord(Food * toDie)
{

    /**
     * destroyRecord
     * Frees memory associated with a Food* record
     * Note: This function also frees the internal variables
     * @param toDie Address to memory that should be freed (not NULL)
     */

}

Food * addToFront(Food * theList, Food * toBeAdded)
{
    if(!isEmpty(theList))
    {
        toBeAdded->next = theList;
    }

    return toBeAdded;
}

Food * addToBack(Food * theList, Food * toBeAdded)
{

    Food * temp;
    temp = theList;

    if(isEmpty(theList))
    {
        return toBeAdded;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ToBeAdded;
    temp->next->next = NULL;

    return theList;

}

Food * removeFromFront(Food * theList)
{
    Food * temp;
    temp = theList;
    head = head->next;
    free(temp);
    return theList;
}

Food * removeFromBack(Food * theList)
{

    /**
     * removeFromBack
     * Takes a pointer to the head of the list. Removes the front
     * item from the list. Does not free the memory for
     * the item removed. You will need to have previously gotten it
     * with getFirstItem, so that you can free it after removal.
     * @param  theList Food* representing the head of the list
     * @return         Food* new head of the list
     */

}

Food * getLastItem(Food * theList)
{
    /**
     * getLastItem
     * Takes a pointer to the head of the list. Returns the last item in the list.
     * Does not remove the item from the list. Do not destroy the record until
     * it is removed from the list.
     * @param  theList Food* representing the head of the list
     * @return         Food* last item in the list.
     */
}

Food * getFirstItem(Food * theList)
{

    /**
     * getFirstItem
     * Takes a pointer to the head of the list. Returns the first item in the list.
     * Does not remove the item from the list. Do not destroy the record until
     * it is removed from the list.
     * @param  theList Food* representing the head of the list
     * @return         Food* first item in the list.
     */

}

int isEmpty(Food * theList)
{

    /**
     * isEmpty
     * Takes a pointer to a list, and checks if it's empty
     * @param  theList Food* representing the head of the list
     * @return         1 if list is empty
     *                 0 if list has elements
     */

}

void printList(Food * theList)
{

    /**
     * printList
     * Takes a pointer to the head of the list. Prints each element to stdout,
     * following the format specified for printRecord seperated by newlines.
     * @param theList Food* representing head of the list
     */

}

void destroyList(Food * theList)
{

    Food * temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp->group);
        free(temp->calories);
        free(temp->theType);
        free(temp);
    }
    return NULL;
    printf("list has been destroyed\n");

}
