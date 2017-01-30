#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern char **getln();

int main() 
{
	int i;
	char **args; 
	
	while(1) 
    {
      args = getln();
      for(i = 0; args[i] != NULL; i++)
      {
        printf("Argument %d: %s\n", i, args[i]);
        //if(strcmp(args[i], "exit") == 0)
        //{
         //   exit(input);
       // } 
      }
    }
}

