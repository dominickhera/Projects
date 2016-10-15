#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    // char * file = argv[1];
	int inputNum = 0;
    int initInput = 0;
    while(initInput != 3)
    {
        printf("(1) Car Rental\n(2) Post Fix Addition\n(3) Exit\n");
        scanf("%d", &initInput);
        switch(initInput)
        {
            case 1:
                inputNum = 0;
                while (inputNum != 7)
                {
                    printf("(1) add a new car to the avaliable-for rent list\n(2) add a returned car to the avaliable-for-rent list\n(3) add a returned car to the repair list\n(4) transfer a car from the repair list to the avaliable-for-rent list\n(5) rent the first avaliable car\n(6) print all the lists\n(7) quit\n\n");
                    scanf("%d", &inputNum);	
                    switch(inputNum)
                    {
                        case 1:
                            printf("you pressed 1\n");
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
                            printf("you pressed 6\n");
                            break;
                        case 7:
                            printf("goodbye\n");
                            printf("call print all lists function here\n");
                            break;
                        default:
                            printf("please enter a number between 1 - 7\n");
                            break;
                    }
                }
                break;

            case 2:
                printf("\npost fix goes here\n\n");
                break;

            case 3:
            	printf("goodbye\n");
            	exit(1);

            default:
                printf("\nplease enter a number between 1-3\n\n");
                break;
        }
    }

    return 0;
}
