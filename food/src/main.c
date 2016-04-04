#include <stdio.h>
#include <stdlib.h>
#include "tracker.h"

int main(int argc, char* argv[]) 
{

char * file = argv[1]; 

	if (argc != 1)
	{
		parseFile(file);
	}
	else
	{
		printf("wrong numbah hoe");
	}

    return 0;
}

