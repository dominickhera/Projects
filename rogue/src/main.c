#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parse.h>
#include <draw.h>

int main(int argc, char* argv[]) 
{

	char * filename = argv[1]; 

    roomParse();

    startGame();

    endGame();

    return 0;
}
