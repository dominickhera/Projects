#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    FILE *fo;
    char fileName[256];
    char line[256];
    char buffer[500]; 
    char fileStorage[500][500];
    char * store = malloc(sizeof(char) * 50000);
    char * variableStore = malloc(sizeof(char) * 256); 
    char * finalVariable = malloc(sizeof(char) * 256); 
    char **functionArray = malloc(sizeof(char *) * 500); 
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
    int loopCount = 0; 
    int intCount = 0; 
    int floatCount = 0;
    int charCount = 0;
    int doubleCount = 0; 
    int shortCount = 0;
    int longCount = 0; 
    int structOpen = 0; 
    int functionOpen = 0;
    int variableLoop = 0; 
    int totalVariableCount = 0;
    int variableFindCount = 0; 
    int count = 0;   
    int functionStorageCount = 0; 
    int i;

    for(i = 0; i < 500; i++)
    {
        functionArray[i] = malloc(sizeof(char) * 500);
    }

    printf("enter file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");
    fo = fopen("./assets/convertedFile.c", "w");

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


    for(i = 0; i < count; i++)
    {
        if((classCheck = strstr(fileStorage[i], "class ")) && (!(commentCheck = strstr(fileStorage[i], "//"))))        
        {
            strncpy(buffer, fileStorage[i], classCheck - fileStorage[i]);
            buffer[classCheck - fileStorage[i]] = 0;
            sprintf(buffer + (classCheck - fileStorage[i]), "%s%s", "struct ", classCheck + strlen("class "));
            strcpy(fileStorage[i], buffer);
            printf("line[%d]: %s", i, fileStorage[i]); 
            if((structCheck = strstr(fileStorage[i], "{")))
            {
                structOpen++;
            }
        }
        else if((structCheck = strstr(fileStorage[i], ") {")) && (!(mainCheck = strstr(fileStorage[i], "int main"))))
        {
            functionOpen++;
            variableLength = 0;
            variableFindCount = 0;
            variableSize = 0;
            totalVariableCount = 0;
            strcpy(variableStore, "");
            strcpy(variableStore, fileStorage[i]);
            strcpy(store, fileStorage[i]);

            for(variableLoop = 0; variableLoop < strlen(variableStore); variableLoop++)
            {
                if(variableStore[variableLoop] == '(')
                {
                    memset(finalVariable, '\0', 256); 

                    while(variableStore[variableLoop] != ')')
                    {
                        variableLoop++;
                        finalVariable[variableFindCount] = variableStore[variableLoop];
                        variableFindCount++; 
                    }
                } 
            }

            if((intCheck = strstr(finalVariable, "int ")))
            {
                intCount = 0;
                while(intCheck != NULL)
                {
                    intCheck = strstr(intCheck + 1, "int ");
                    intCount++;
                    totalVariableCount++; 
                }

            }

            if((floatCheck = strstr(finalVariable, "float ")))
            {
                floatCount = 0;
                while(floatCheck != NULL)
                {
                    floatCheck = strstr(floatCheck + 1, "float ");
                    floatCount++;
                    totalVariableCount++;
                }
            }

            if((charCheck = strstr(finalVariable, "char ")))
            {
                charCount = 0;
                while(charCheck != NULL)
                {
                    charCheck = strstr(charCheck + 1, "char ");
                    charCount++;
                    totalVariableCount++;
                }
            }

            if((doubleCheck = strstr(finalVariable, "double ")))
            {
                doubleCount = 0;
                while(doubleCheck != NULL)
                {
                    doubleCheck = strstr(doubleCheck + 1, "double ");
                    doubleCount++;
                    totalVariableCount++;
                }
            }

            if((shortCheck = strstr(finalVariable, "short ")))
            {
                shortCount = 0;
                while(shortCheck != NULL)
                {
                    shortCheck = strstr(shortCheck + 1, "short ");
                    shortCount++;
                    totalVariableCount++;
                }
            }

            if((longCheck = strstr(finalVariable, "long ")))
            {
                longCount = 0;
                while(longCheck != NULL)
                {
                    longCheck = strstr(longCheck + 1, "long ");
                    longCount++;
                    totalVariableCount++;
                }
            }

            if(intCount != 0)
            {
                for(loopCount = 0; loopCount < intCount; loopCount++)
                {
                    printf("i");
                }
                intCount = 0;             
            }  

            if(charCount != 0)
            {
                for(loopCount = 0; loopCount < charCount; loopCount++)
                {
                    printf("c");
                } 
                charCount = 0;
            }

            if(floatCount != 0)
            {
                for(loopCount = 0; loopCount < floatCount; loopCount++)
                {
                    printf("f");
                }
                floatCount = 0;
            }

            if(doubleCount != 0)
            {
                for(loopCount = 0; loopCount < doubleCount; loopCount++)
                {
                    printf("d");
                }
                doubleCount = 0;
            }

            if(shortCount != 0)
            {
                for(loopCount = 0; loopCount < shortCount; loopCount++)
                {
                    printf("s");
                }
                shortCount = 0;
            }

            if(longCount != 0)
            {
                for(loopCount = 0; loopCount < longCount; loopCount++)
                {
                    printf("l");
                }
                longCount = 0;
            }

            printf("\n");

            printf("line[%d]: %s", i, fileStorage[i]);
        }

        else if((bracketCheck = strstr(fileStorage[i], "}")) && structOpen == 1 && functionOpen == 1)
        {
            printf("line[%d]: %s", i, fileStorage[i]);
            strcat(store, fileStorage[i]);
            /* printf("store: %s\n", store);    */
            functionOpen--;
            /*sprintf(functionArray[functionStorageCount], "%s", store);
              strcpy(functionArray[functionStorageCount], store); */
            functionStorageCount++;
            /* printf("function[%d]: %s\n", functionStorageCount, functionArray[functionStorageCount]); */

        }
        else if(structOpen == 1 && functionOpen == 1)
        {
            /*printf("line[%d] copied :%s\n", i, fileStorage[i]);*/
            printf("line[%d]: %s", i, fileStorage[i]);
            strcat(store, fileStorage[i]); 
        } 
        else
        {
            printf("line[%d]: %s", i, fileStorage[i]);
        }
    }

    for(i = 0; i < count; i++)
    {
        fprintf(fo, "%s", fileStorage[i]);
    }

    fclose(fp);
    fclose(fo);

    return 0;
}
