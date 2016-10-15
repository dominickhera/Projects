#ifndef __AVALIABLE_LINKEDLIST__
#define __AVALIABLE_LINKEDLIST__

struct Avaliable{
	char * avaliablePlateNum;
	int avaliableMileage;
	// int avaliableExpectedReturnDate;
	struct Avaliable * next;
};

typedef struct Avaliable Avaliable;


Avaliable * createRecord(char * avaliablePlateNum, int avaliableMileage);
char * printAvaliableRecord(Avaliable * toPrintAvaliable);
int isAvaliableEmpty(Avaliable * avaliableList);
// char * printList(Avaliable * to)

#endif	