// #include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    FILE * openFile;
    char line[500];
    char name[50];
    char group[50];
    char type;
    int calorieCount = 0;
    char word[25];
    int length = 0;
    int argLength = 0;
    int argNum = 0;
    int wordLength = 0;
    int commaCheck = 0;
    int newStart = 0;

    openFile = fopen(argv[1], "r");
    if(openFile == NULL)
    {
        printf("Could not open %s\n", argv[1]);
    }

    while(fgets(line, 256, openFile) != NULL)
    {

        char newWord[256];
        char otherWord[26];
        length = strlen(line);

        if (line[length - 1] == '\n')
        {
        	line[length - 1] = '\0';
        }
        

        for (int i = 0; i < length; i++)
        {


            if(commaCheck == 0)
            {
                while(line[i] != ',')
                {
                    argLength = i;
                    i++;
                    argNum++;
                }
                strncpy(newWord, line, argLength + 1);
                printf("%s\n", newWord);
                commaCheck++;
            }
            else if(commaCheck == 1)
            {
                while(line[i] != ',')
                {
                    argLength = i;
                    i++;
                    argNum++;
                }
                strncpy(newWord, line, argLength + 1);
                printf("%s\n", newWord);
                commaCheck++;
            }
            else if(commaCheck == 2)
            {
                while(line[i] != ',')
                {
                    argLength = i;
                    i++;
                    argNum++;
                }
                strncpy(newWord, line, argLength + 1);
                printf("%s\n", newWord);
                commaCheck++;
            }
            else if(commaCheck == 3)
            {
                while(line[i] != ',')
                {
                    argLength = i;
                    i++;
                    argNum++;
                }
                strncpy(newWord, line, argLength + 1);
                printf("%s\n", newWord);
                commaCheck++;
            }

        }

        printf("%s\n", line);
    }

    fclose(openFile);
}
