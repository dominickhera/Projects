#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include "avaliable.h"

int main()
{

	node * head;

	int inputNum = 0;
	char availablePlateNumString[256];
	int availableMileageInt = 0;

	while (inputNum != 7)
	{
		printf("(1) add a new car to the avaliable-for rent list\n(2) add a returned car to the avaliable-for-rent list\n(3) add a returned car to the repair list\n(4) transfer a car from the repair list to the avaliable-for-rent list\n(5) rent the first avaliable car\n(6) print all the lists\n(7) quit\n\n");
		scanf("%d", &inputNum);	
		switch(inputNum)
		{
			case 1:

				printf("Enter the Plate Number of the car: ");
				scanf("%s", availablePlateNumString);
				printf("Enter the mileage of the car: ");
				scanf("%d", &availableMileageInt);
				printf("\n");
				addtoAvailableList(&head, availableMileageInt, availablePlateNumString);
				break;
			case 2:
				printf("you pressed 2\n");
				break;
			case 3:
				printf("you pressed 3\n");
				break;
			case 4:
				printf("you pressed 4\n");
				break;
			case 5:
				printf("you pressed 5\n");
				break;
			case 6:
				printf("Available:\n========\n\n");
				printList(head);
				printf("Rented:\n========\n\n");
				printf("None.\n");
				printf("Repair:\n========\n\n");
				printf("None.\n");
				break;
			case 7:
				printf("goodbye\n");
				break;
			default:
				printf("please enter a number between 1 - 7\n");
				break;
		}
	}


	// printf("call print all lists function here\n");

	return 0;
}
