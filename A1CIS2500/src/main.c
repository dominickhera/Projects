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
    int argNum = 0;
    int argLength = 0;
    int sucNum = 0;
    int updateCounter = 0;
    int failCounter = 0;

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
        strncpy(value, line + (argLength + 1), (length + 1));
        sucNum = setValue(key, value);
        memset(key, 0, length);
        memset(value, 0, length);
    }
    if (sucNum != 1) 
    {
        printf(" Unsufficient Amount of Variables Found");
    } 

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

                while (line[i] != '}') 
                {
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
         printf("%s\n", finalLine);
        fprintf(outputFile, "%s\n", finalLine);
    } 
    printf("%d Variables Found\n%d Variables Successfully Replaced\n", argNum, updateCounter);
    fclose(openTemplate);
    fclose(openData);
    fclose(outputFile);
    return 0;
}
