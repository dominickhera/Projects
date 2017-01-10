#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char filename[256];
	char line[256];

	printf("enter filename: ");
	scanf("%s", filename);

	FILE *fp;

	fp = fopen(filename, "r");

	if(fp == NULL)
	{
		printf("could not find file\n");
		return 0;
	}

	while(fgets(line, sizeof(line), fp))
	{
		printf("%s", line);

		memset(line, '\0', strlen(line));
	}

	return 0;
}