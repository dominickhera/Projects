#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct roomStruct {
    int x;
    int y;
    int width;
    int height;
}room;

int main (int argc, char* argv[])
{
    FILE * openLevel;
    char text[200];
	char line[255];
    char value[255];
    char key[255];
    char word[25];
    int argLength = 0;
    int length = 0;
    int argNum = 0;
    int i = 0;
    room * roomThing;
    room x[6];
    room y[6];
    room width[6];
    room height[6];
    openLevel = fopen(argv[1], "r");

    if (argc != 2){
        printf("not enough arguments provided\n");
        return 1;
    }

    if (openLevel == NULL){
        printf("couldn't open file\n");
    }

    while (fgets(line, 900, openLevel) != NULL){
    	while(line[i] == ' ') 
            {
                argLength = i;
                i++;
                argNum++;
            }
    }

        strncpy(key, line, argLength);
        strncpy(value, line + (argLength + 1), (length + 1));
       // sucNum = setValue(key, value);
        //memset(key, 0, length);
        //memset(value, 0, length);
    printf("%s", key);
    printf("%s", value);
    /*
    while (fscanf(openLevel, "%s", text) != EOF)
    {
        char * pch;
        pch = strtok (text," X");

        while (pch != NULL)
        {
            printf ("%s\n",pch);
            pch = strtok (NULL, " ");
        }

    }*/

    roomThing = malloc(sizeof(room));
    
    return 0;
}
