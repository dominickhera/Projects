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
	char * p;
	// char parseStorage[500][500];
	char memory[127];
	char memoryValue[127];
	int memoryAmount[127];
	char * word;
	char emptyValue = '*';
	int count = 0;
	int processCount = 0;
	int cycleCount = 1;
	int emptyCount = 0;
	int parseCount = 0;
	// char test;

	fp = fopen(argv[1], "r");

	if(fp == NULL)
	{
		printf("couldn't find file\nexiting...\n");
		exit(1);
	}

	for(int i = 0; i < 128; i++)
	{
		strcpy(&memory[i], &emptyValue);
		// printf("line %d: %c\n", i, memory[i]);
	}

printf("\n\n");
	while(fgets(line, sizeof(line), fp))
	{
		if(line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		word = strtok(line, " ");

		while(word != NULL)
		{
			if (parseCount != 0)
			{
				parseCount--;
				memoryAmount[count] = strtol(word, &p, 10);
				printf("line %d: char: %c, num: %d\n", count, memoryValue[count], memoryAmount[count]);

			}
			else if(parseCount == 0)
			{
				parseCount++;
				count++;
				
				strcpy(&memoryValue[count], word);
			}
			word = strtok(NULL, " ");
		}
		memset(line, '\0', strlen(line));
	}

	fclose(fp);

	// for(int i = 1; i < count; i++)
	// {
	// 	printf("hi%c %d\n", memoryValue[i], memoryAmount[i]);
	// }
	printf("\n\n");

	for(int i = 0; i < 128; i++)
	{
		// printf("%c\n", memory[i]);
		// emptyCount = 0;
		if(strcmp(&memory[i], &emptyValue) > 0)
		{
				emptyCount++;
				// printf(" emptyCount: %d\n", emptyCount);
				if(emptyCount >= memoryAmount[cycleCount])
				{
					printf("Space Found for %c %d at %d\n", memoryValue[cycleCount], memoryAmount[cycleCount], emptyCount);
					for(int j = emptyCount;j > 0; j--)
					{
						// printf("Now at Memory Space %d\n", j);
						strcpy(&memory[j], &memoryValue[cycleCount]);
						// printf("Memory: %d, Value: %c\n", j, memory[j]);
					}
					break;
				}
		}
	}

	for(int i = 0; i < 128; i++)
	{
		// strcpy(&memory[i], &emptyValue);
		printf("Now line %d: %c\n", i, memory[i]);
	}


	return 0;
}
