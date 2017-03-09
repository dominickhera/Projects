#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dine.h"


int main(int argc, char **argv)
{
    Philosopher * philosopher = malloc(sizeof(int)* 256);
    
    char *p;

	if(argc != 3)
	{
		printf("not enough arguments, exiting...\n");
		exit(1);
	}

    philosopher->philosopherCount = strtol(argv[1], &p, 10);
    philosopher->processCount = strtol(argv[2], &p, 10);

/*	for(int i = 0; i < argc; i++)
	{
		printf("arg[%d]: %s\n", i, argv[i]);
	}
*/
    printf("amount of philosophers: %d\namount of times they eat: %d\n", philosopher->philosopherCount, philosopher->processCount);

	return 0;
}
