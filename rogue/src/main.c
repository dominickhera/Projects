#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parse.h>
#include <draw.h>

void freeRoom (room * Rooms);

//sets file name to the second arguement, mallocs the room struct to 6, and puts it though the parser and then after the whole part that creates the ncurses UI
int main(int argc, char* argv[]) 
{

	room * Rooms;
    char * filename = argv[1]; 

    Rooms = parseFile(filename); 
    freeRoom(Rooms);
  //  initCurses(Rooms);

    return 0;
}


void freeRoom (room * Rooms){
	for (int i = 0; i < 6; i++)
	{
		free(Rooms[i].roomItems);
   		free(Rooms[i].doorPosition);
    	free(Rooms[i].doorLocation);
	}
	free(Rooms);
}

