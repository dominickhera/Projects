#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simcpu.h"

int main(int argc, char **argv)
{
    Process * process = malloc(sizeof(int)* 5000);

    char line[256]; 
    // char fileName[256];
    char fileStorage[500][500];
    char * parse; 
    char *p; 
    process->processCount = 0;
    // int detailFlag = 0;
    // int verboseFlag = 0;
    // int roundRobinFlag = 0;
    int count = 0;   
    int initCount = 0; 
    // int quantumInteger = 0;

    // printf("1\n");

    /*
       if(!feof(stdin))
       {
       printf("could not find file, exiting program...\n");
       exit(1);
       }
     */ 

    for(int i = 0; i < argc - 1; i++)
    {
        // printf("2\n");
        if(strcmp(argv[i],"-d") == 0)
        {
            // printf("3\n");
            printf("detail mode enabled\n");
            process->detailFlag = 1;
        }

        if(strcmp(argv[i], "-v") == 0)
        {
            // printf("4\n");
            printf("verbose mode enabled\n"); 
            process->verboseFlag = 1;
        }

        if(strcmp(argv[i], "-r") == 0)
        {
            // printf("5\n");
            // printf("round robin mode enabled\n");
            process->roundRobinFlag = 1;
            // printf("6\n");
            process->quantumInteger = strtol(argv[i+1], &p, 10);
            // printf("7\n");
            printf("Round Robin (quantum = %d time units): \n", process->quantumInteger);
            // printf("8\n"); 
        }
    }  
    // printf("9\n");

    while(fgets(line, sizeof(line), stdin) != NULL)
    {

        if ()
        // printf("10\n");
        // strcpy(fileStorage[count], line);
        // printf("%s", fileStorage[count]);
        // count++;
        // printf("11\n");
    }
    // printf("12\n");
    // parse = strtok(fileStorage[0], " ");
    // while(parse != NULL)
    // {
    //     // printf("13\n");
    //     printf("%s, initCount: %d\n", parse, initCount);

    //     // printf("14\n");
    //     parse = strtok(NULL, " \n");
    //     // printf("15\n");
    //     initCount++;
    //     // printf("16\n"); 
    // }
    // printf("17\n");

    // process->processCount = 10;

    // printf("processCount is %d\n", process->processCount);

    return 0;
}
