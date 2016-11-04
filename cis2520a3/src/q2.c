#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char * file = argv[1]; 
	char line[256];
	int numArray[20][10];
	int i = 0;
	int j = 0;
	char *token;
	const char space[2] = " ";
	FILE *openFile;
	openFile = fopen(file, "r");

	if(openFile == NULL)
    {
        printf("Could not open %s\n", file);
        return 0;
    }

    if (argc != 1)
    {
    	printf("%s loaded\n", file);

    }
    else
   	{
    	printf("wrong numbah hoe\n");
    }

    while(fgets(line, 256, openFile))
    {
    	// printf("%s", line);
    	token = strtok(line, space);
    	while(token != NULL)
    	{
    		if (strcmp(token,"\n") == 0)
    		{
    			j = 0;
    			token = strtok(NULL, space);
    			printf("\n");
    		}
    		else
    		{
    			numArray[i][j] = atoi(token);
    			printf( "numArray[%d][%d]: %s\n", i, j, token );
    			j++;
    			if (j > 9)
    			{
    				i++;
    				j = 0;
    			}
     			 token = strtok(NULL, space);
     		}
    	}

    }


	return 0;
}