#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parse.h>
#include <draw.h>

//sets file name to the second arguement, mallocs the room struct to 6, and puts it though the parser and then after the whole part that creates the ncurses UI
int main(int argc, char* argv[]) 
{

	room * Rooms;
    char * filename = argv[1]; 

    Rooms = parseFile(filename); 
    initCurses(Rooms);

    return 0;
}

