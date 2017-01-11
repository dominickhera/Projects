#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[256];
    char line[256];
    char word[256];

    printf("enter filename: ");
    scanf("%s", filename);

    FILE *fp;
    char * stringThing;

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("could not find file\n");
        return 0;
    }

    while(fgets(line, sizeof(line), fp) != NULL)
    {

        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }
        stringThing = strtok(line, " ");

        while(stringThing != NULL)
        {
            printf("%s\n", stringThing);

            stringThing = strtok(NULL, " ");
        }

        memset(line, '\0', strlen(line));

    }

    fclose(fp);

    return 0;
}
