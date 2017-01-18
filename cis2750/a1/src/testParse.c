#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[256];
    char line[256];
    int length;
    char * classReplace;
    char buffer[500];

    printf("enter filename: ");
    scanf("%s", filename);

    FILE *fp;

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

        length = strlen(line);

        	if((classReplace = strstr(line, "class ")))
        	{
        		// printf("found a class ");
        		// printf("%ld cr is\n", classReplace - line);
        		strncpy(buffer, line, classReplace-line);
        		buffer[classReplace-line] = 0;
        		// printf("%s\n", line);
        		sprintf(buffer+(classReplace-line), "%s%s", line, classReplace + strlen("class "));
        	}
        	else
        	{
        		printf("%s\n", line);
        	}

        memset(line, '\0', strlen(line));

    }

    fclose(fp);

    return 0;
}