#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "avaliable.h"
// #include "rented.h"
// #include "repair.h"
typedef struct Available *ptr;
typedef struct Available
{
    char * availablePlateNum;
    int availableMileage;
    struct Available * next;
}Available;


// Available * addToAvaliableList(Available *head, int mileage){
//     Available new;
//     new = *head;
//     Available T = (Available)malloc(sizeof(Available));

//     T->availableMileage = mileage;
//     while (new->next)
//     {
//     	new = new->next;
//     }
//     new->next = T;
//     // new = list_nodes(mileage);
//     // head->next = new;
//     // printf("%d\n%d\n", new->availableMileage, new);
//     // return(new);
// }

void addToAvaliableList(ptr *head, int mileage)
{
	while(*head)
	{
		head = &(*head)->next;
	}
	*head = malloc(sizeof(**head));
	(*head)->availableMileage = mileage;
	(*head)->next = NULL;

}


int main()
{
    // char * file = argv[1];
	Available * head;

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
            	head = malloc(sizeof(Available));
            	// char avaliablePlateNumString[256];
            	// int avaliableMileageInt = 0;
                printf("Enter the Plate Number of the car: ");
                scanf("%s", availablePlateNumString);
                printf("inputed string = %s", availablePlateNumString);
                printf("\nEnter the mileage of the car: ");
                scanf("%d", &availableMileageInt);
                printf("inputted mileage = %d\n", availableMileageInt);

                addToAvaliableList(&head, availableMileageInt);
                printf("%d is the mileage\n", head->availableMileage);

                // addToAvaliableList("A", avaliablePlateNumString, avaliableMileageInt);

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
                // printAvaliableList();
                // printRentedList();
            printf("you pressed 6\n");
                break;
            case 7:
                printf("goodbye\n");
                break;
            default:
                printf("please enter a number between 1 - 7\n");
                break;
        }
    }


    printf("call print all lists function here\n");

    return 0;
}
