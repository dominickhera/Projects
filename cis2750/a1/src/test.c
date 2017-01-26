#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char fileName[256];
    char line[256];
    char fileStorage[500][500];
    char lineStore;
    char * store = malloc(sizeof(char) * 50000);
    int count = 0;   
    
    printf("enter file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r"); 
    
    if(fp == NULL)
    {
        printf("could not find file\n");
        return 0;
    }
    
   // strcpy(store, " ");
    
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        strcpy(fileStorage[count], line); 
        count++; 
        //strcat(store, line); 
    }    

    for(int i = 0; i < count; i++)
    {
        printf("line[%d]: %s", i, fileStorage[i]);
    }

    fclose(fp);

    return 0;
}
