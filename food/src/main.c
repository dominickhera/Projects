#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[])
{
	FILE * openFile;


	openFile = fopen(argv[1], "r");
	if(openFile == NULL)
	{
		printf("Could not open %s", argv[1]);
	}
		printf("Successfully opened %s", argv[1]);
}