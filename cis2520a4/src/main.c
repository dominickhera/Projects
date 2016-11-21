#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    int userInput = 0;
    char fileName[256];
    char word[30];

    while(userInput != 7)
    {
        printf("1. Initialization\n2. Find\n3. Insert\n4. Remove\n5. Check Height and Size\n6. Find All (above a given frequency)\n7. Exit\n");
        scanf("%d", &userInput);

        switch(userInput)
        {
            case 1:
                printf("enter file name: ");
                scanf("%s", fileName);
                FILE *fp;
                fp = fopen(fileName, "r");
                
                if(fp == NULL)
                {
                    printf("could not find file\n");
                    return 0;
                }
                
                while(fscanf(fp, "%s", word) != EOF)
                {
                    printf("%s\n", word);
                }
                break;
            case 2:
                printf("2\n");
                break;
            case 3:
                printf("3\n");
                break;
            case 4:
                printf("4\n");
                break;
            case 5:
                printf("5\n");
                break;
            case 6:
                printf("6\n");
                break;
            case 7:
                printf("goodbye!\n"); 
                exit(1);
                break;
        }
    }


    return 0;
}
