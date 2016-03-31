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
    char calorie[10];
    char tempType[2];
    char type;
    int calorieCount = 0;
    char word[25];
    int length = 0;
    int argLength = 0;
    int argNum = 0;
    int wordLength = 0;
    int commaCheck = 0;
    int newStart = 0;
    int otherStart = 1;

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
                    newStart++; 
                    // printf("%d\n",argNum);
                }
                strncpy(name, line, argLength + 1);
                printf("%s\n", name);
                 argNum++;
                newStart++;
                commaCheck++;
            }
            else if(commaCheck == 1)
            {
                while(line[i] != ',')
                {
                    argLength = i;
                    i++;
                    argNum++;
                    otherStart++;
                    // newStart++;
                    // printf(" new start %d  argNum %d\n", newStart, argNum);
                }
                strncpy(group, line + newStart, argNum - newStart + 1);
                printf("%s\n", group);
                otherStart++;
                commaCheck++;
                // otherStart++;
                 argNum++;

            }
              else if(commaCheck == 2)
            {
                  while(line[i] != ',')
                {
                    argLength = i;
                    i++;
                    argNum++;
                    newStart++;
                    // printf("%d\n", newStart);
                }
                printf("argNum %d otherstart %d\n", argNum, otherStart);
                strncpy(calorie, line + newStart, argNum - newStart);
                printf("%s\n", calorie);
                commaCheck++;
                argNum++;
            }

            else if(commaCheck == 3)
            {
                // newStart = 0;
                // while(line[i] != ',')
                // {
                //     argLength = i;
                //     i++;
                //     argNum++;
                //     newStart++;
                //     // printf("%d\n", newStart);
                // }
                // strncpy(tempType, line + newStart + otherStart, argNum - otherStart);
                // printf("%s\n", tempType);
                // commaCheck++;
                // argNum++;
            }
          

        }

        printf("%s\n", line);
    }

    fclose(openFile);
}
