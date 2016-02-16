#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parse.h>
#include <draw.h>

int main(int argc, char* argv[]) 
{

	char * filename = argv[1]; 

	room * Rooms = malloc(sizeof(room)  * 6);
    Rooms = parseFile(filename); 

    initGame();

    // endGame();

    return 0;
}
