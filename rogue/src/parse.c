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
    room * Rooms = malloc(sizeof(room) * 5); 

    int counter = 0;
    char line [256]; 
    int length = 0;


    while(fgets(line, 256, openLevel) != NULL) 
    {

        length = strlen(line);
        line[length - 1] = '\0';
        Rooms[counter] = *createRoom(line, length);
        memset(line, '\0', 256);
        counter++;

    }

    fclose(openLevel);

    return Rooms; 

}

room * createRoom(char * line, int length)
{
    room * tmpRoom = malloc(sizeof(room));
    tmpRoom->roomItems = malloc(sizeof(item) * 10);
    tmpRoom->totalDoors = 0;
    int numberOfItems = 0; 

    //Room Sizes, 12X12 or 2X12 or 12X2) 
    for(int i = 0; i < length; i++)
    {
        //we have done size!
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
            else if (isdigit(line[i - 2])) //12X12
            {
                tmpRoom->x = (line[i - 2] - '0') * 10 + (line[i - 1] - '0');

            }
            //y
            if (isdigit(line[i + 2])) 
            {
                tmpRoom->y = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
            }
            else if (isdigit(line[i + 1])) //1 char
            {  
                tmpRoom->y = atoi(&line[i + 1]);
            }

            continue; 
        }
        //This is doors de4
        if (line[i] == 'd')
        {
            if (isalpha(line[i + 1]))
            {
                tmpRoom->doorLocation[tmpRoom->totalDoors] = line[i + 1];
            }
            else 
            {
                puts("Missing baring");
                exit(1);
            }
            if (isdigit(line[i + 2]))
            {
                if (isdigit(line[i + 3])) //2 number
                {
                    tmpRoom->doorPosition[tmpRoom->totalDoors] = (line[i + 2] - '0') * 10 + (line[i + 3] - '0');
                }
                else //1 number
                {
                    tmpRoom->doorPosition[tmpRoom->totalDoors] = atoi(&line[i + 2]);
                }

            }
            else 
            {
                puts("yo missin a dig");
            }

            tmpRoom->totalDoors++; 
            continue; 
        }

        if (isalpha(line[i]) && isdigit(line[i + 1]))
        {
            if (line[i] != 'e' && line[i] != 's' && line[i] != 'w')
            {
                if(line[i + 2] == ',')//e4,15
                {
                    tmpRoom->roomItems[numberOfItems].itemX = atoi(&line[i + 1]); 
                    if (isdigit(line[i + 4]))
                    {
                        tmpRoom->roomItems[numberOfItems].itemY = (line[i + 3] - '0') * 10 + (line[i +4] - '0');
                    }
                    else if (isdigit(line[i + 3]))
                    {
                        tmpRoom->roomItems[numberOfItems].itemY = atoi(&line[i + 3]);

                    }
                }
                else if(isdigit(line[i + 2]))
                {
                    //2 numbers
                    if(line[i + 3] == ',')
                    {
                        tmpRoom->roomItems[numberOfItems].itemX = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
                        if (isdigit(line[i + 5]))
                        {
                            tmpRoom->roomItems[numberOfItems].itemY = (line[i + 6] - '0') * 10 + (line[i +5] - '0');
                        }
                        else if (isdigit(line[i + 4]))
                        {
                            tmpRoom->roomItems[numberOfItems].itemY = atoi(&line[i + 4]);

                        }
                    }
                    else                    {   
                        puts("bro its done yo"); 
                        exit(1);
                    }
                }
                // g11,4   g4,11  g11,11

                tmpRoom->roomItems[numberOfItems].itemType = line[i]; 

                numberOfItems++; 
                continue; 
            }
        }

    }

    printf("x:%d,y:%d\n", tmpRoom->x, tmpRoom->y);

    for(int i = 0; i < tmpRoom->totalDoors; i++)
    {
        printf("doorNum[%d] = d%c%d\n", i, tmpRoom->doorLocation[i], tmpRoom->doorPosition[i]);
    }
    for (int i = 0; i < numberOfItems; i++)
    {
        printf("item[%d] = %c%d,%d\n", i , tmpRoom->roomItems[i].itemType, tmpRoom->roomItems[i].itemX, tmpRoom->roomItems[i].itemY);
    }

    return tmpRoom; 

}



