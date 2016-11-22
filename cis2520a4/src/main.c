#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    int userInput = 0;
    char fileName[256];
    char line[256];
    
    char frequencyCompare[10];
    char keyRemove[25];
    char keyInsert[25];
    char keySearch[25];
    
    while(userInput != 7)
    {
        printf("1. Initialization\n2. Find\n3. Insert\n4. Remove\n5. Check Height and Size\n6. Find All (above a given frequency)\n7. Exit\n\navl/> ");
        scanf("%d", &userInput);

        switch(userInput)
        {
            case 1:
                printf("filename: ");
                scanf("%s", fileName);
                FILE *fp;
                fp = fopen(fileName, "r");
                
                if(fp == NULL)
                {
                    printf("could not find file\n");
                    return 0;
                }
                
                while(fgets(line, sizeof(line), fp))
                {
                    printf("%s", line);
                }
                break;
            case 2:
                printf("find key: ");
                scanf("%s", keySearch);
                printf("key: %s, frequency: someNumber\n", keySearch);
                break;
            case 3:
                printf("insert key: ");
                scanf("%s", keyInsert);
                printf("key: %s, frequency: someNumber\n", keyInsert);
                break;
            case 4:
                printf("remove key: ");
                scanf("%s", keyRemove);
                printf("key: %s, frequency: someNumber-1\n", keyRemove);
                break;
            case 5:
                printf("height : someNumber, size: someNumber\n");
                break;
            case 6:
                printf("frequency: ");
                scanf("%s", frequencyCompare);
                printf("key: someKey, frequency: someNumber\n");
                break;
            case 7:
                printf("goodbye!\n"); 
                exit(1);
                break;
        }
    }


    return 0;
}
