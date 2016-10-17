#ifndef __AVALIABLE_LINKEDLIST__
#define __AVALIABLE_LINKEDLIST__

typedef struct Available
{
	int availableMileage;
	char * availablePlateNum;
	struct Available * next;
} node;

typedef struct list
{
	node * next;
}list;

typedef struct Top
{
	list * listHead;
}head;

//creates the node for the avaliable list with the plate number and miles variables
node * createNewNode(int miles, char * plate);

//adds the mileage and plate number to the avalible struct
void addtoAvailableList(node** head, int mileage, char * plate);

//prints out the avaliable list.
void printList(node * head);

#endif	
