// #include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    FILE * openFile;
    char line[256];
    char word[25];
    int length = 0;
    int argLength = 0;
    int argNum = 0;
    int wordLength = 0;
    int updateCounter = 0;
    int commaCheck = 0;
    int newStart = 0;

    openFile = fopen(argv[1], "r");
    if(openFile == NULL)
    {
        printf("Could not open %s\n", argv[1]);
    }
    // printf("Successfully opened %s\n", argv[1]);

    while(fgets(line, 256, openFile) != NULL)
    {

        // char finalLine[256]; 
        // char wordUpdate[256];;
        // int counter = 0;
        // memset(word, '\0', strlen(word));
        // length = strlen(line);
        // line[length - 1] = '\0';

        // for (int i = 0; i < length; i++) 
        // {
        //     if (commaCheck == 0) 
        //     {
        //         i++;
        //         commaCheck = 1;

        //         while (line[i] == ',') 
        //         {
        //             word[wordLength] = line[i];
        //             wordLength++;
        //             i++;

        //         }
        //         strcpy(wordUpdate, word);
        //         // wordUpdate[strlen(wordUpdate) - 1] = '\0'; 
        //         for (int j = 0; j < strlen(wordUpdate); j++)
        //         {
        //             finalLine[counter] = wordUpdate[j];
        //             counter++; 
        //         }
        //         wordLength = 0;
        //         updateCounter++;
        //     }
        //     else 
        //     {
        //         finalLine[counter] = line[i];
        //         counter++;
        //     } 

        // }
        // printf("%s\n", finalLine);




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
            else
            {
                if(line[i] == ',')
                {
                   i++;
                   newStart = i;
                   while(line[i] != ',')
                   {
                    argLength = i;
                    i++;
                   } 
                   strncpy(newWord, line, (argLength - newStart));
                   printf("%s\n", newWord);
                }
            }
            // else
            // {
                // if(line[i] == ',')
                // {
                //     i++;
                //     while (line[i] != ',')
                //     {
                //         otherWord[wordLength] = line[i];
                //         wordLength++;
                //         i++; 
                //     }
                //     strncpy(otherWord, line, wordLength);
                //     printf("%s\n", otherWord);
                // }
            // }

        }

        printf("%s\n", line);
    }

    fclose(openFile);
}
