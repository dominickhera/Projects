#include "open.h"
#include "main.h"

void dataOpen(char * openData)
{
	FILE * newOpenData;
 newOpenData = fopen(openData, "r");
    if (newOpenData == NULL)
    {
        printf("couldn't open template text file\n");
        exit(1);
    }

    parseData(newOpenData);
    fclose(newOpenData);
}

void templateOpen(char * openTemplate, char * outputFile)
{
	FILE * newOpenTemplate;
	FILE * newOutputFile;
 	newOpenTemplate = fopen(openTemplate, "r");
    newOutputFile = fopen(outputFile, "w");
    if (newOpenTemplate == NULL)
    {
        printf("couldn't open template text file\n");
        exit(1);
    }

    if (newOutputFile == NULL)
    {
        printf("couldn't open output text file\n");
        exit(1);
    }

    parseTemplate(newOpenTemplate, newOutputFile);
    fclose(newOpenTemplate);
    fclose(newOutputFile);
}