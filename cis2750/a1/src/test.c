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
    char * variableStore = malloc(sizeof(char) * 256); 
    char * finalVariable = malloc(sizeof(char) * 256); 
    char **functionArray = malloc(sizeof(char *) * 500); 
    char value[256]; 
    char * classCheck;
    char * commentCheck; 
    char * intCheck;
    char * floatCheck;
    char * charCheck;
    char * doubleCheck; 
    char * shortCheck;
    char * longCheck; 
    char * structCheck;
    char * mainCheck; 
    char * bracketCheck; 
    int variableLength = 0; 
    int variableSize = 0; 
    int bracketCount = 0; 
    int intCount = 0; 
    int floatCount = 0;
    int charCount = 0;
    int doubleCount = 0; 
    int shortCount = 0;
    int longCount = 0; 
    int structOpen = 0; 
    int functionOpen = 0; 
    int variableFindCount = 0; 
    int count = 0;   
    int functionStorageCount = 0; 
 
    for(int i = 0; i < 500; i++)
    {
        functionArray[i] = malloc(sizeof(char) * 500);
    }
 
    printf("enter file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r"); 
    
    if(fp == NULL)
    {
        printf("could not find file\n");
        return 0;
    }
    
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        strcpy(fileStorage[count], line); 
        count++;
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
            strcpy(store, fileStorage[i]);
            functionOpen++;
            variableLength = 0;
            variableFindCount = 0;
            variableSize = 0;
            strcpy(variableStore, "");
            strcpy(variableStore, fileStorage[i]);
            strcpy(store, variableStore);
            for(int i = 0; i < strlen(variableStore); i++)
            {
                if(variableStore[i] == '(')
                {
                    memset(finalVariable, '\0', 256); 
                    while(variableStore[i] != ')')
                    {
                        i++;
                        finalVariable[variableFindCount] = variableStore[i];
                        variableFindCount++; 
                    }
                } 
            }

            //printf("variables: %s for line[%d]\n", finalVariable, i);


            if((intCheck = strstr(finalVariable, "int ")))
            {
                intCount = 0;
                while(intCheck != NULL)
                {
                    intCheck = strstr(intCheck + 1, "int ");
                    intCount++; 
                }
                //printf("intCount: %d for line[%d]\n", intCount, i);
            }

            if((floatCheck = strstr(finalVariable, "float ")))
            {
                floatCount = 0;
                while(floatCheck != NULL)
                {
                    floatCheck = strstr(floatCheck + 1, "float ");
                    floatCount++;
                }
               // printf("floatCount: %d for line[%d]\n", floatCount, i);
            }

            if((charCheck = strstr(finalVariable, "char ")))
            {
                charCount = 0;
                while(charCheck != NULL)
                {
                    charCheck = strstr(charCheck + 1, "char ");
                    charCount++;
                }
                //printf("charCount: %d for line[%d]\n", charCount, i);
            }

            if((doubleCheck = strstr(finalVariable, "double ")))
            {
                doubleCount = 0;
                while(doubleCheck != NULL)
                {
                    doubleCheck = strstr(doubleCheck + 1, "double ");
                    doubleCount++;
                }
                //printf("doubleCount: %d for line[%d]\n", doubleCount, i);
            }

            if((shortCheck = strstr(finalVariable, "short ")))
            {
                shortCount = 0;
                while(shortCheck != NULL)
                {
                    shortCheck = strstr(shortCheck + 1, "short ");
                    shortCount++;
                }
                //printf("shortCount: %d for line[%d]\n", shortCount, i);
            }

            if((longCheck = strstr(finalVariable, "long ")))
            {
                longCount = 0;
                while(longCheck != NULL)
                {
                    longCheck = strstr(longCheck + 1, "long ");
                    longCount++;
                }
                //printf("longCount: %d for line[%d]\n", longCount, i);
            }

           // printf("line[%d]: %s", i, fileStorage[i]);
        }
       /* else if(structOpen == 1)
        {
            strcat(store,fileStorage[i]);
        }*/
        else if((bracketCheck = strstr(fileStorage[i], "}")) && structOpen == 1 && functionOpen == 1)
        {
           strcat(store, fileStorage[i]);
           printf("store: %s\n", store);    
           functionOpen--;
           sprintf(functionArray[functionStorageCount], "%s", store);
           //strcpy(functionArray[functionStorageCount], store); 
           functionStorageCount++;
          // printf("function[%d]: %s", functionStorageCount, functionArray[functionStorageCount]); 
        }
        else if(structOpen == 1 && functionOpen == 1)
        {
            //printf("line[%d] copied :%s\n", i, fileStorage[i]);
            strcat(store, fileStorage[i]); 
        } 
        else
        {
           // printf("line[%d]: %s", i, fileStorage[i]);
        }
    }
      /*  
    for(int i = 0; i < functionStorageCount; i++)
    {
        for(int j = 0; i < functionStorageCount; j++)
        {
            printf("functionArray[%d][%d]: %c\n", i, j, functionArray[i][j]);
        }
    }*/

    fclose(fp);

    return 0;
}
