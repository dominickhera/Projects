#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[256];
    char line[256];
    int structOpen = 0;
    int functionOpen = 0;
    char * classReplace;
    char * structCheck;
    char * functionCheck;
    char * openBracketCheck;
    char * mainCheck;
    char buffer[500];
    char lineBuffer[500];
    char lineSave[500]; 
    char **functionArray;

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

        if((classReplace = strstr(line, "class ")) && (structCheck = strstr(line, "{")))
        {
            strncpy(buffer, line, classReplace - line);
            buffer[classReplace - line] = 0;
            sprintf(buffer + (classReplace - line), "%s%s", "struct ", classReplace + strlen("class "));
            printf("%s\n", buffer);
            if((structCheck = strstr(line, "{")))
            {
                // printf("fam this is the start of a struct\n");
                structOpen++;
                // printf("struct open is %d\n", structOpen);
            }
        }
        else if((structCheck = strstr(line, ") {")) && (!(mainCheck = strstr(line, "int main"))) && (openBracketCheck = strstr(line,"("))  &&  (structOpen <= 1))
        {
            strcpy(lineSave, line); 
            strncpy(lineBuffer, line, structCheck - line);
            lineBuffer[structCheck - line] = 0;
            sprintf(lineBuffer + (structCheck - line), "%s%s", "();", structCheck + strlen(") {"));
            printf("%s\n", lineBuffer);
            printf("the saved line is %s\n", lineSave);
            structOpen++;
            //printf("function inside a struct fam & structOpen is %d ", structOpen);
            //printf("%s\n", line);

        }
        else if((structCheck = strstr(line, "{")))
        {
            structOpen++;
            // printf("struct open is %d ", structOpen);
            printf("%s\n", line);
        }
        else if((structCheck = strstr(line, "}")))
        {
            structOpen--;
            // printf("struct open is %d ", structOpen);
            printf("%s\n", line);
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
