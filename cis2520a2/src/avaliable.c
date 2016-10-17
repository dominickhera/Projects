#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "avaliable.h"

node * createNewNode(int miles, char * plate)
{
	node * newNode = malloc(sizeof(*newNode)); 
	newNode->availablePlateNum = malloc(sizeof(char) * (strlen(plate)) + 1);
	strcpy(newNode->availablePlateNum, plate);
	newNode->availableMileage = miles;

	return newNode; 	
}

void addtoAvailableList(node** head, int mileage, char * plate )
{
	node dummy, *new, *p;

	new = createNewNode(mileage, plate);
	p = &dummy;
	dummy.next = *head;

	while(p->next && mileage > p->next->availableMileage)
	{
		p = p->next;
	} 

	new->next = p->next;
	p->next = new;
	*head = dummy.next;

}


void printList(node * head)
{
	if(head)
	{
		printf("Plate Number: %s, Mileage: %d\n", head->availablePlateNum, head->availableMileage);
		printList(head->next);
	}
}
