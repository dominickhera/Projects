#include "parse.h"
#include "avaliable.h"
#include "rented.h"
#include "repair.h"
#include <stdio.h>
#include <stdlin.h>
#include <ctype.h>
#include <string.h>

Avaliable * parseAvaliableFile(char * file)
{
	File * openFile;
	Avaliable * avaliableList;
	Avaliable * avaliableVar = NULL;
	char line[500];
	char * items[4];

	openFile = fopen(file, "r");
	if(openFile == NULL)
	{
		printf("Could not open file: %s\n", file);
	}

	while(fgets(line, 256, openFile) != NULL)
	{
		int index = 0;
		char * var;

		if(line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}

		var = strtok(line, ":");

		avaliableItems[index++] = var;

		while((var = strtok(NULL, ":")) != NULL)
		{
			avaliableItems[index++] = var;
		}

		avaliableList = createRecord(avaliableItems[0], avaliableItems[1], avaliableItems[2]);

		if(avaliableList->avaliableInd == '')
	}
}