#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char fileName[256];

    fp = fopen(fileName, "r");  

    if(fp == NULL)
    {
        printf("could not find file, exiting program...\n");
        exit(1);
    } 

    return 0;
}
