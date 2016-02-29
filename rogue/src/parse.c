#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parse.h"

//opens file, closes it to prevent memory leaks, begins paarsing file to a char array for actually parsing the info.
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
        Rooms[counter] = *parseRoom(line, length);
        memset(line, '\0', 256);
        counter++;

    }

    fclose(openLevel);

    return Rooms; 

}
//parses all the information provided  in the lines into a room struct that will be used to create the rooms in ncurses
room * parseRoom(char * line, int length)
{
    room * tempRoom = malloc(sizeof(room));
    tempRoom->roomItems = malloc(sizeof(item) * 10);
    tempRoom->totalDoors = 0;
    tempRoom->totalItems = 0;
    int numberOfItems = 0; 

    for(int i = 0; i < length; i++)
    {
        if (line[i] == 'X') 
        {
            //x
            if (line [i - 2] == 0) 
            {
                if (isdigit(line[i - 1]))
                {
                    tempRoom->x = atoi(&line[i-1]);
                }
            }
            else if (isdigit(line[i - 2])) //12X12
            {
                tempRoom->x = (line[i - 2] - '0') * 10 + (line[i - 1] - '0');

            }
            //y
            if (isdigit(line[i + 2])) 
            {
                tempRoom->y = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
            }
            else if (isdigit(line[i + 1])) //1 char
            {  
                tempRoom->y = atoi(&line[i + 1]);
            }

            continue; 
        }
        if (line[i] == 'd')
        {
            if (isalpha(line[i + 1]))
            {
                tempRoom->doorLocation[tempRoom->totalDoors] = line[i + 1];
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
                    tempRoom->doorPosition[tempRoom->totalDoors] = (line[i + 2] - '0') * 10 + (line[i + 3] - '0');
                }
                else //1 number
                {
                    tempRoom->doorPosition[tempRoom->totalDoors] = atoi(&line[i + 2]);
                }

            }
            else 
            {
                puts("yo missin a dig");
            }

            tempRoom->totalDoors++; 
            continue; 
        }

        if (isalpha(line[i]) && isdigit(line[i + 1]))
        {
            if (line[i] != 'e' && line[i] != 's' && line[i] != 'w')
            {
                if(line[i + 2] == ',')//e4,15
                {
                    tempRoom->roomItems[numberOfItems].itemX = atoi(&line[i + 1]); 
                    if (isdigit(line[i + 4]))
                    {
                        tempRoom->roomItems[numberOfItems].itemY = (line[i + 3] - '0') * 10 + (line[i +4] - '0');
                    }
                    else if (isdigit(line[i + 3]))
                    {
                        tempRoom->roomItems[numberOfItems].itemY = atoi(&line[i + 3]);

                    }
                }
                else if(isdigit(line[i + 2]))
                {
                    //2 numbers
                    if(line[i + 3] == ',')
                    {
                        tempRoom->roomItems[numberOfItems].itemX = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
                        if (isdigit(line[i + 5]))
                        {
                            tempRoom->roomItems[numberOfItems].itemY = (line[i + 6] - '0') * 10 + (line[i +5] - '0');
                        }
                        else if (isdigit(line[i + 4]))
                        {
                            tempRoom->roomItems[numberOfItems].itemY = atoi(&line[i + 4]);

                        }
                    }
                    else                    {   
                        puts("bro its done yo"); 
                        exit(1);
                    }
                }
                // g11,4   g4,11  g11,11

                tempRoom->roomItems[numberOfItems].itemType = line[i]; 

                numberOfItems++; 
                tempRoom->totalItems = numberOfItems;
                continue; 
            }
        }

    }

    printf("x:%d,y:%d\n", tempRoom->x, tempRoom->y);

    for(int i = 0; i < tempRoom->totalDoors; i++)
    {
        printf("doorNum[%d] = d%c%d\n", i, tempRoom->doorLocation[i], tempRoom->doorPosition[i]);
    }
    for (int i = 0; i < numberOfItems; i++)
    {
        printf("item[%d] = %c%d,%d\n", i , tempRoom->roomItems[i].itemType, tempRoom->roomItems[i].itemX, tempRoom->roomItems[i].itemY);
    }

    return tempRoom; 

}
