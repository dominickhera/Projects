#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "holes.h"

int main(int argc, char **argv)
{

	if(argc != 2)
	{
		printf("not enough arguments, exiting...\n");
		exit(1);
	}

	for(int i = 0; i < argc; i++)
	{
		printf("arg[%d]: %s\n", i, argv[i]);
	}

	return 0;
}
