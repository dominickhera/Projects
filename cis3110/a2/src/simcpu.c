#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simcpu.h"

int main(int argc, char **argv)
{
    char line[256]; 
    char fileName[256];
    char fileStorage[500][500];
    char * parse; 
    char *p; 
    int detailFlag = 0;
    int verboseFlag = 0;
    int roundRobinFlag = 0;
    int count = 0;   
    int initCount = 0; 
    int quantumInteger = 0;

/*
    if(!feof(stdin))
    {
    printf("could not find file, exiting program...\n");
    exit(1);
    }
     */ 

    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i],"-d") == 0)
        {
            printf("detail mode enabled\n");
            detailFlag++;
        }

        if(strcmp(argv[i], "-v") == 0)
        {
            printf("verbose mode enabled\n"); 
            verboseFlag++;
        }

        if(strcmp(argv[i], "-r") == 0)
        {
            printf("round robin mode enabled\n");
            roundRobinFlag++;
            quantumInteger = strtol(argv[i+1], &p, 10);
            printf("quantum integer is %d\n", quantumInteger); 
        }
    }  

 
     while(fgets(line, sizeof(line), stdin) != NULL)
    {
        strcpy(fileStorage[count], line);
        // printf("%s", fileStorage[count]);
        count++;
    }

    parse = strtok(fileStorage[0], " ");
    while(parse != NULL)
    {
        printf("%s\n", parse);
        parse = strtok(NULL, " ");
        initCount++; 
     }
    
  process->processCount = 10;

printf("processCount is %d\n", process.processCount);
 
    return 0;
}
