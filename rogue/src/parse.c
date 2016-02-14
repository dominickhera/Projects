#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parse.h"

#define TOTALROOMCOUNT  5

room * parseFile(char * filename) 
{ 

    FILE * openLevel;

    openLevel = fopen(filename, "r");
    room * rooms = malloc(sizeof(room) * 5); 

    int counter = 0;

    while(fgets(line, 256, openLevel) != NULL) 
    {

        length = strlen(line);
        line[length - 1] = '\0'
            rooms[counter] = createRoom(line, length);
        counter++;

    }
    fclose(openLevel);

    return roomThing;

}

room * createRoom(char * line, int length)
{
    room * tmpRoom = malloc(sizeof(room));
    room->roomItems = malloc(sizeof(item) * 4);

    //Roo Sizes, 12X12 or 2X12 or 12X2) 
    for(int i = 0; i < length; i++)
    {
        if (line[i] == 'X') 
        {
            //x
            if (line [i - 2] == 0) 
            {
                if (isdigit(line[i - 1]))
                {
                    tmpRoom->x = atoi(&line[i-1]);
                }
            }
            else if (isdigit(line[i - 2]))
            {
                tmpRoom->x = (line[i - 1] - '0') * 10 + (line[i + 2] - '0');

            }
            //y
            if (isdigit(line[i + 2])) 
            {
                tmpRoom->y = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
            }
            else if (isdigit(line[i + 1])) //1 char
            {  
                tmpRoom->x = atoi(&line[i + 1]);
            }

        }
        if (line[i] == '')

    }

    printf("x:%d,y:%d\n", tmpRoom->x, tmpRoom->y);

    return tmpRoom; 

}



