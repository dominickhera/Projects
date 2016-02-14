#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
​
#include "parse.h"
​
#define MAX_ROOMS 5
​
/* int parseDrawFile(char *filename); src/parse.c
 * Function grabs filename, opens stream and finds data to make room.
 * IN: character array, the filename of the datafile
 * OUT:
 * ERROR:
 */
Room * parseDrawFile(char *filename)
{
    FILE * drawStream;
    char line[256];
    int currLength = 0;
    int j = 0;
    ​
        drawStream = fopen(filename, "r");
    if (drawStream == NULL)
    {
        puts("error opening file");
        exit(1);
    }
    ​
        Room * rooms = malloc(sizeof(Room) * 5);
    ​
        ​
        ​
        while (fgets(line, 256, drawStream) != NULL)
        {
            currLength = strlen(line);
            line[currLength - 1] = '\0';
            rooms[j] = *initRoom(line, currLength);
            j++;
        }
    ​
        ​
        ​
        ​
        fclose(drawStream);
    ​
        return rooms;
}
​
/* Room * parseTemplate(char * line, int length)
 * Grabs the current line, and returns a room built based on the template of that room.
 * IN: current line, length of that line.
 * OUT: An initalized room
 * ERROR:
 */
Room * initRoom(char * line, int length)
{
    ​
        int rows = 0;
    int columns = 0;
    Room * tmpRoom;
    tmpRoom = malloc(sizeof(Room));
    if (tmpRoom == NULL) {
        puts("Room memory on the heap.");
    }
    ​
        ​
        ​
        tmpRoom->indexDoor = 0;
    ////printf("\n%s\n", line);
    char * tmpRows = malloc(sizeof(char) * 2);
    char * tmpColumns = malloc(sizeof(char) * 2);
    ​
        12X6 
        4X77
        12x10
        ​
        ​
        ​
        ​
        //ROOM SIZE FINDER ALGORITHM
        for (int i = 0; i < length; i++)
        {
            if(line[i] == 'X')
            {
                ​
                    if ((i - 2) == 0) //first index was 2 ago
                    {
                        if (isdigit(line[i - 2]) && isdigit(line[i - 1]))
                        {
                            tmpRows[0] = line[i - 2];
                            tmpRows[1] = line[i - 1];
                        }
                        else
                        {
                            puts("Your rows data is not integer convertable! Quitting...");
                            exit(1);
                        }
                    }
                    else
                    {
                        if (isdigit(line[i - 1]))
                        {
                            tmpRows[0] = line[i - 1];
                            tmpRows[1] = '\0';
                        }
                        else
                        {
                            puts("Your rows data is not integer convertable! Quitting...");
                            exit(1);
                        }
                    }
                if (line[i + 3] == ' ') //12x12 x
                {
                    if (isdigit(line[i + 1]) && isdigit(line[i + 2]))
                    {
                        tmpColumns[0] = line[i + 1];
                        tmpColumns[1] = line[i + 2];
                    }
                    else
                    {
                        puts("Your columns data is not integer convertable. Quitting...");
                        exit(0);
                    }
                    ​
                }
                else
                {
                    if (isdigit(line[i + 1]))
                    {
                        tmpColumns[0] = line[i + 1];
                        tmpColumns[1] = '\0';
                        ​
                    }
                    else
                    {
                        puts("Your columns data is not integer convertable. Quitting...");
                        exit(0);
                    }
                    ​
                }
                ​
            }
            if(line[i] == 'd')
            {
                if (isalpha(line[i + 1]))
                {
                    tmpRoom->doorsBar[tmpRoom->indexDoor] = line[i + 1];
                }
                else
                {
                    puts("Your doors BAR position is not character. Quitting...");
                    exit(0);
                    ​
                }
                if (isdigit(line[i + 2]))
                {
                    tmpRoom->doorsPos[tmpRoom->indexDoor] = atoi(&line[i + 2]);
                }
                else
                {
                    puts("Your doors Position is not a number. Quitting...");
                    exit(0);
                }
                //printf("Doors: #%d : On Side: %c, At Point: %d\n", tmpRoom->indexDoor, tmpRoom->doorsBar[tmpRoom->indexDoor], tmpRoom->doorsPos[tmpRoom->indexDoor]);
                ​
                    tmpRoom->indexDoor++;
                ​
            }
        }
    ​
        ​
        rows = atoi(tmpRows);
    columns = atoi(tmpColumns);
    free(tmpRows);
    free(tmpColumns);
    ​
        tmpRoom->rows = rows;
    tmpRoom->columns = columns;
    ​
        return tmpRoom;
}
​
​
​
​
/*
   ​
   if (line[i] == 'g')
   {
//REMINDER! If it turns out that there are more than one gold per room
//Make X/Y arrays and create an indexing counter
if(line[i + 2] == ',')
{
if(isdigit(line[i + 1]))
{
tmpRoom->goldx = atoi(&line[i + 1]);
}
else
{
puts("missing integer x value for goldx in txt. Quitting...");
exit(0);
}
if(isdigit(line[i + 3]))
{
tmpRoom->goldy = atoi(&line[i + 3]);
}
else
{
puts("missing integer y value for goldy in txt. Quitting...");
exit(0);
}
}
else
{
puts ("gold input not formated with ',' between x and y! Quitting....");
exit(0);
}
//printf("Gold @ x:%d , y:%d\n", tmpRoom->goldx, tmpRoom->goldy);
}
 */
