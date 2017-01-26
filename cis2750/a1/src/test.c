#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char fileName[256];
    char line[256];
    char buffer[500]; 
    char fileStorage[500][500];
    char lineStore;
    char * store = malloc(sizeof(char) * 50000);
    char * classCheck;
    char * commentCheck; 
    char * intCheck;
    char * floatCheck;
    char * charCheck;
    char * doubleCheck; 
    char * structCheck;
    char * mainCheck; 
    int bracketCount = 0; 
    int intCount = 0; 
    int floatCount = 0;
    int charCount = 0;
    int doubleCount = 0; 
    int structOpen = 0; 
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
        if((classCheck = strstr(fileStorage[i], "class ")) && (!(commentCheck = strstr(fileStorage[i], "//"))))
        {
           strncpy(buffer, fileStorage[i], classCheck - fileStorage[i]);
           buffer[classCheck - fileStorage[i]] = 0;
           sprintf(buffer + (classCheck - fileStorage[i]), "%s%s", "struct ", classCheck + strlen("class "));
           printf("line[%d]: %s", i, buffer); 
           if((structCheck = strstr(fileStorage[i], "{")))
           {
            structOpen++;
           }
        }
        else if((structCheck = strstr(fileStorage[i], ") {")) && (!(mainCheck = strstr(fileStorage[i], "int main"))) && (structOpen = 1))
        {
            if((intCheck = strstr(fileStorage[i], "int ")))
            {
                intCount = 0;
                while(intCheck != NULL)
                {
                    intCheck = strstr(intCheck + 1, "int ");
                    intCount++; 
                }
                printf("intCount: %d for line[%d]\n", intCount, i);
            }
            
            if((floatCheck = strstr(fileStorage[i], "float ")))
            {
                floatCount = 0;
                while(floatCheck != NULL)
                {
                   floatCheck = strstr(floatCheck + 1, "float ");
                   floatCount++;
                }
                printf("floatCount: %d for line[%d]\n", floatCount, i);
            }
            
             
        } 
        else
        {
            printf("line[%d]: %s", i, fileStorage[i]);
        }
    }

    fclose(fp);

    return 0;
}
