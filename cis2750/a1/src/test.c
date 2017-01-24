#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char fileName[256];
    char line[256];
//    char store[5000];
    char * store = malloc(sizeof(char) * 500);
    printf("enter file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r"); 
    
    if(fp == NULL)
    {
        printf("could not find file\n");
        return 0;
    }
    
    strcpy(store, " ");
    
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        strcat(store, line); 
    }    

    printf("%s\n", store);

    return 0;
}
