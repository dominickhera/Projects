#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Food * createRecord(char * name, char * group, int calories, char theType)
{


    /**
     * createRecord
     * Allocates memory for a food struct, and initalizes it's members to the
     * supplied parameters.
     * ->next is set to NULL.
     * The value for name and group are copied into new memory, the passed in
     * strings should be destroyed
     * Returned record should be destroyed with destroyRecord()
     * @param  name     String (<50 length)
     * @param  group    String (<50 length)
     * @param  calories int (>0)
     * @param  theType  char (h for healthy, or j for junk)
     * @return          Food* to malloc'd memory
     *                  NULL on failure
     */

    Food * temp = malloc(sizeof(Food));
    temp->name = name;
    temp->group = group;
    temp->calories = calories;
    temp->theType = theType;
    temp->next = NULL;

    if(Food * temp == NULL)
    {
        printf("failed to allocate memory for record\n");
        exit(1);
    }
    else
    {
        return temp;
    }
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

/**
 * addToBack
 * Takes a pointer to the head of the list, and a created Food* record
 * Adds record to the tail of the list
 * In the event theList is NULL, it's assumed that the list is empty
 * and toBeAdded becomes a new list with one element
 * Returns the head of the list after the operation is performed
 * @param  theList   Food* representing the head of the list
 * @param  toBeAdded Food* to add to the front of the list
 * @return           Food* new head of the list
 */

}

Food * addToBack(Food * theList, Food * toBeAdded)
{

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
