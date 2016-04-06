#include "main.h"
#include "open.h"

char parseData (FILE * openData)
{

    int argNum = 0;
    int argLength = 0;
    int sucNum = 0;
    int length = 0;
    char line [256];
    char value[255];
    char key[255];

    while(fgets(line, 256, openData) != NULL)
    {

        length = strlen(line);
        line[length+1] = '\0';

        for (int i = 0; i < length; i++) 
        {
            while(line[i] == '=') 
            {
                argLength = i;
                i++;
                argNum++;
            }
        }

        strncpy(key, line, argLength);
        printf("%s\n", key);
        if(!isalpha(line[argLength + 1])){
            strncpy(value, "MISSING_DATA ", 15);
            argNum--;
        }
        else
        {
            strncpy(value, line + (argLength + 1), (length + 1));
        }
        printf("%s\n", value);
        sucNum = setValue(key, value);
        memset(key, 0, length);
        memset(value, 0, length);
    }
    // checks to make sure that all variables were found and stored correctly, terminates program if not correct.
    if (sucNum != 1) 
    {
        printf(" Unsufficient Amount of Variables Found");
    } 

    printf("%d Variables Found\n", argNum);

    return sucNum;
}

void parseTemplate(FILE * openTemplate, FILE * outputFile)
{

   char word[25];
   char line[255];
   int updateCounter = 0;
   int length = 0;
   int wordLength = 0;
    while(fgets(line, 256, openTemplate) != NULL) 
    {
        char finalLine[256]; 
        char wordUpdate[256];;
        int counter = 0;
        memset(word, '\0', strlen(word));
        length = strlen(line);
        line[length - 1] = '\0';

        for (int i = 0; i < length; i++) 
        {
            if (line[i] == '{') 
            {
                i++;
                printf("i work\n");

                while (line[i] != '}') 
                {
                    printf("i also work\n");
                    word[wordLength] = line[i];
                    wordLength++;
                    i++;

                }
                strcpy(wordUpdate, getValue(word));
                wordUpdate[strlen(wordUpdate) - 1] = '\0'; 
                for (int j = 0; j < strlen(wordUpdate); j++)
                {
                    finalLine[counter] = wordUpdate[j];
                    counter++; 
                }
                wordLength = 0;
                updateCounter++;
            }
            else 
            {
                finalLine[counter] = line[i];
                counter++;
            } 

        }
        fprintf(outputFile, "%s\n", finalLine);
    } 
    printf("done\n");
}

// void closeFiles(FILE * templateFile, FILE * dataFile, FILE * outputFile)
// {
//     fclose(templateFile);
//     fclose(dataFile);
//     fclose(outputFile);
// }
