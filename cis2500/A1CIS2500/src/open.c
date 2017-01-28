#include "scan.h"
#include "open.h"


void dataOpen(char * openData, char * key, char * value)
{
	FILE * newOpenData;
 newOpenData = fopen(openData, "r");
    if (newOpenData == NULL)
    {
        printf("couldn't open template text file\n");
        exit(1);
    }

    parseData(newOpenData, key, value);
    fclose(newOpenData);
}

void templateOpen(char * openTemplate, char * outputFile, char * key, char * value)
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

    parseTemplate(newOpenTemplate, newOutputFile, key, value);
    fclose(newOpenTemplate);
    fclose(newOutputFile);
}