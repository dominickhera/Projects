// #include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    FILE * openFile;
    char line[256];
    int length = 0;
    int argLenth = 0;
    int argNum = 0;

    openFile = fopen(argv[1], "r");
    if(openFile == NULL)
    {
        printf("Could not open %s\n", argv[1]);
    }
    printf("Successfully opened %s\n", argv[1]);

    while(fgets(line, 256, openFile) != NULL)
    {
        length = strlen(line);
        line[length+1] = '\0';
        for(int i = 0; i < length; i++)
        {
            while(line[i] == ',')
            {
                argLenth = i;
                i++;
                argNum++;
            }

        }
        printf("%s\n", line);
    }

    fclose(openFile);
}
