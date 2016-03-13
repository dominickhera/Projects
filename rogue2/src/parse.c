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
    room * Rooms = malloc(sizeof(room) * 6); 

    int counter = 0;
    char line [256]; 
    int length = 0;


    while(fgets(line, 256, openLevel) != NULL) 
    {

        length = strlen(line);
        if (line[length - 1] == '\n'){
            line[length - 1] = '\0';
        } else {
            line[length] = '\0';
        }
        //parseRoom(line, length);
        realParse(&Rooms[counter], line, length);
        memset(line, '\0', 256);
        counter++;

    }

    fclose(openLevel);

    return Rooms; 

}

void realParse(room * Rooms, char * line, int length)
{

    Rooms->totalDoors = 0;
    Rooms->totalItems = 0;
    Rooms->x = 0;
    Rooms->y = 0;
    Rooms->roomItems = NULL;
    Rooms->doorPosition = NULL;
    Rooms->doorLocation = NULL;

    for(int i = 0; i < length; i++)
    {
        if (line[i] == 'X') 
        {
            //x
            if (line [i - 2] == 0) 
            {
                if (isdigit(line[i - 1]))
                {
                    Rooms->x = atoi(&line[i-1]);
                }
            }
            else if (isdigit(line[i - 2])) //12X12
            {
                Rooms->x = (line[i - 2] - '0') * 10 + (line[i - 1] - '0');

            }
            //y
            if (isdigit(line[i + 2])) 
            {
                Rooms->y = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
            }
            else if (isdigit(line[i + 1])) //1 char
            {  
                Rooms->y = atoi(&line[i + 1]);
            }

            continue; 
        }

        if (line[i] == 'd')
        {
            if (isalpha(line[i + 1]))
            {
                if(Rooms->totalDoors == 0){
                    Rooms->doorLocation = malloc(sizeof(char)* 1);
                } else {
                    Rooms->doorLocation = realloc(Rooms->doorLocation, sizeof(char)* (Rooms->totalDoors + 1));
                }
                Rooms->doorLocation[Rooms->totalDoors] = line[i + 1];
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
                    if(Rooms->totalDoors == 0) {
                        Rooms->doorPosition = malloc(sizeof(int)* 1);
                    } else {
                        Rooms->doorPosition = realloc(Rooms->doorPosition, sizeof(int)* (Rooms->totalDoors + 1));
                    }
                    Rooms->doorPosition[Rooms->totalDoors] = (line[i + 2] - '0') * 10 + (line[i + 3] - '0');
                }
                else //1 number
                {
                    if(Rooms->totalDoors == 0) {
                        Rooms->doorPosition = malloc(sizeof(int)* 1);
                    } else {
                        Rooms->doorPosition = realloc(Rooms->doorPosition, sizeof(int)* (Rooms->totalDoors + 1));
                    }
                    Rooms->doorPosition[Rooms->totalDoors] = atoi(&line[i + 2]);
                }

            }
            else 
            {
                puts("yo missin a dig");
            }

            Rooms->totalDoors++; 
            continue; 
        }

        if (isalpha(line[i]) && isdigit(line[i + 1]))
        {


            //  if (line[i] != 'e' && line[i] != 's' && line[i] != 'w' && line[i] != 'n')
            if (line[i - 1] != 'd')
            {
                /*if (line[i] == 'h')
                {
                    if(line[i + 2] == ',')//e4,15
                    {
                        Rooms->heroX = atoi(&line[i + 1]); 
                        if (isdigit(line[i + 4]))
                        {
                            Rooms->heroY = (line[i + 3] - '0') * 10 + (line[i +4] - '0');
                        }
                        else if (isdigit(line[i + 3]))
                        {
                            Rooms->heroY = atoi(&line[i + 3]);

                        }
                    }
                    else if(isdigit(line[i + 2]))
                    {
                        //2 numbers
                        if(line[i + 3] == ',')
                        {
                            Rooms->heroX = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
                            if (isdigit(line[i + 5]))
                            {
                                Rooms->heroY = (line[i + 4] - '0') * 10 + (line[i + 5] - '0');
                            }
                            else if (isdigit(line[i + 4]))
                            {
                                Rooms->heroY = atoi(&line[i + 4]);

                            }
                        }
                    }
                    continue; 
                }*/
                //else 
                    if(Rooms->totalItems == 0){
                    Rooms->roomItems = malloc(sizeof(item)* 1);
                } else {
                    Rooms->roomItems = realloc(Rooms->roomItems, sizeof(item)* (Rooms->totalItems + 1));
                }
                if(line[i + 2] == ',')//e4,15
                {
                    Rooms->roomItems[Rooms->totalItems].itemY = atoi(&line[i + 1]); 
                    if (isdigit(line[i + 4]))
                    {
                        Rooms->roomItems[Rooms->totalItems].itemX = (line[i + 3] - '0') * 10 + (line[i +4] - '0');
                    }
                    else if (isdigit(line[i + 3]))
                    {
                        Rooms->roomItems[Rooms->totalItems].itemX = atoi(&line[i + 3]);

                    }
                }
                else if(isdigit(line[i + 2]))
                {
                    //2 numbers
                    if(line[i + 3] == ',')
                    {
                        Rooms->roomItems[Rooms->totalItems].itemY = (line[i + 1] - '0') * 10 + (line[i + 2] - '0');
                        if (isdigit(line[i + 5]))
                        {
                            Rooms->roomItems[Rooms->totalItems].itemX = (line[i + 4] - '0') * 10 + (line[i + 5] - '0');
                        }
                        else if (isdigit(line[i + 4]))
                        {
                            Rooms->roomItems[Rooms->totalItems].itemX = atoi(&line[i + 4]);

                        }
                    }
                    else                    {   
                        puts("bro its done yo"); 
                        exit(1);
                    }
                }
                // g11,4   g4,11  g11,11

                Rooms->roomItems[Rooms->totalItems].itemType = line[i]; 

                Rooms->totalItems++; 
                continue; 
            }
        }
    }

        /*    

       printf("x:%d,y:%d\n", Rooms->x, Rooms->y);

       for(int i = 0; i < Rooms->totalDoors; i++)
       {
       printf("doorNum[%d] = d%c%d\n", i, Rooms->doorLocation[i], Rooms->doorPosition[i]);
       }

       for (int i = 0; i < Rooms->totalItems; i++)
       {
       printf("item[%d] = %c%d,%d\n", i , Rooms->roomItems[i].itemType, Rooms->roomItems[i].itemX, Rooms->roomItems[i].itemY);*/
       }

