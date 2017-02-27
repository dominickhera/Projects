#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simcpu.h"

int main(int argc, char **argv)
{
    Process * process = malloc(sizeof(int)* 5000);

    char line[256]; 
    char fileStorage[500][500];
    char * parse; 
    char *p; 
    process->detailFlag = 0;
    process->verboseFlag = 0;
    process->roundRobinFlag = 0;
    int count = 0;   
    int initCount = 0; 

    /*
       if(!feof(stdin))
       {
       printf("could not find file, exiting program...\n");
       exit(1);
       }
     */ 

    for(int i = 0; i < argc; i++)
    {
        // printf("2\n");
        if(strcmp(argv[i],"-d") == 0)
        {
            printf("detail mode enabled\n");
            process->detailFlag++;
        }

        if(strcmp(argv[i], "-v") == 0)
        {
            printf("verbose mode enabled\n"); 
            process->verboseFlag = 1;
        }

        if(strcmp(argv[i], "-r") == 0)
        {
            printf("round robin mode enabled\n");
            process->roundRobinFlag = 1;
            process->quantumInteger = strtol(argv[i+1], &p, 10); 
        }
    }  

    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        strcpy(fileStorage[count], line);
        count++;
    }

    parse = strtok(fileStorage[0], " ");
    while(parse != NULL)
    {
        switch(initCount)
        {
            case 0:
                process->processCount = strtol(parse, &p, 10);
                printf("Process Count: %d\n", process->processCount);
                break;
            case 1:
                process->threadSwitch = strtol(parse, &p, 10);
                printf("Thread Switch: %d\n", process->threadSwitch);
                break;
            case 2:
                process->processSwitch = strtol(parse, &p, 10);
                printf("Process Switch: %d\n", process->processSwitch);
                break;
            default:
                printf("default case\n");
                break;
        }
        parse = strtok(NULL, " \n");
        initCount++; 
    }

    for(int i = 1; i < count; i++)
    {
        initCount = 0;

        parse = strtok(fileStorage[i], " ");
        while(parse != NULL)
        {
            printf("line[%d]: %s\n", i, parse);
            parse = strtok(NULL, " \n");
            initCount++;
        }
    }

    // for(int i = 0; i < process->processCount; i++)
    // {
    //     for(int j = 0; j < process->)
    // }

    if(process->roundRobinFlag != 1)
    {
        printf("\nFCFS: \n\n");
    }
    else
    {
        printf("\nRound Robin (quantum = %d time units):\n\n", process->quantumInteger);
    }

    printf("Total Time required is %d time units\nAverage Turnaround Time is %d time units\nCPU Utilization is %d%%\n\n", process->totalTime, process->averageTurnAroundTime, process->cpuUtilization);
    
    if(process->detailFlag == 1)
    {
        printf("butts\n");
    }

    return 0;
}
