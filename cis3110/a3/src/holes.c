#include "holes.h"

int main(int argc, char **argv)
{

	if(argc != 2)
	{
		printf("not enough arguments, exiting...\n");
		exit(1);
	}

	FILE *fp;
	char line[256];
	char * word;
	int parseCount = 0;

	fp = fopen(argv[1], "r");

	if(fp == NULL)
	{
		printf("couldn't find file\nexiting...\n");
		exit(1);
	}


	while(fgets(line, sizeof(line), fp))
	{
		if(line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		word = strtok(line, " ");
		
		while(word != NULL)
		{
			printf("%s\n", word);
			word = strtok(NULL, " ");
			if (parseCount != 0)
			{
				parseCount--;
				// printf("parseCount: %d\n", parseCount);
			}
			else if(parseCount == 0)
			{
				parseCount++;
				// printf("parseCount: %d\n", parseCount);
			}
		}
		memset(line, '\0', strlen(line));
	}

	fclose(fp);

	return 0;
}
