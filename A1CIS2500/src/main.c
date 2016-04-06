#include"main.h"

int main(int argc, char* argv[]) 
{

    FILE * openData;
    FILE * openTemplate;
    FILE * outputFile;
    char line[255];
    char value[255];
    char key[255];
    char word[25];
    int wordLength = 0;
    int length = 0;
    // int argNum = 0;
    // int argLength = 0;
    // int sucNum = 0;
    int updateCounter = 0;

    //makes sure 4 arguements are included, opens all the necessary files based on what the user enters
    if (argc != 4) 
    {
        printf(" incorrect number of arguments given\n");
        return 1;
    }
    openData = fopen(argv[1], "r");
    if (openData == NULL)
    {
        printf("couldn't open template text file\n");
        return 1;
    }
    openTemplate = fopen(argv[2], "r");
    if (openTemplate == NULL)
    {
        printf("couldn't open template text file\n");
        return 1;
    }

    outputFile = fopen(argv[3], "w");
    if (openData == NULL)
    {
        printf("couldn't open template text file\n");
        return 1;
    }

    parseData(openData, value, key);
   

    //scans the template.txt file for all the variable entires and inputs the variables with similar names from the data.txt file, searching for the brackets that each variable name is in for reference. also counts amount of variables replaced for stats. 

    parseTemplate(openTemplate, outputFile);
    // while(fgets(line, 256, openTemplate) != NULL) 
    // {
    //     char finalLine[256]; 
    //     char wordUpdate[256];;
    //     int counter = 0;
    //     memset(word, '\0', strlen(word));
    //     length = strlen(line);
    //     line[length - 1] = '\0';

    //     for (int i = 0; i < length; i++) 
    //     {
    //         if (line[i] == '{') 
    //         {
    //             i++;

    //             while (line[i] != '}') 
    //             {
    //                 word[wordLength] = line[i];
    //                 wordLength++;
    //                 i++;

    //             }
    //             strcpy(wordUpdate, getValue(word));
    //             wordUpdate[strlen(wordUpdate) - 1] = '\0'; 
    //             for (int j = 0; j < strlen(wordUpdate); j++)
    //             {
    //                 finalLine[counter] = wordUpdate[j];
    //                 counter++; 
    //             }
    //             wordLength = 0;
    //             updateCounter++;
    //         }
    //         else 
    //         {
    //             finalLine[counter] = line[i];
    //             counter++;
    //         } 

    //     }
    //     fprintf(outputFile, "%s\n", finalLine);
    // } 
    // // prints out stats about program execution, and closes all files to prevent memory leaks
    // printf("%d Variables Successfully Replaced\nProcess Executed Successfully\n", updateCounter);

    closeFiles(openTemplate, openData, outputFile);

    return 0;
}
