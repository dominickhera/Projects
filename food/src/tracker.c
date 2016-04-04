#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tracker.h"
#include "linkedList.h"


Food * parseFile(char * file)
{
    FILE * openFile;
    Food * foodArray;
    char line[500];
    char * items[4];
    int calorieCounter = 0;
    int listLength = 0;
    int meatTotalCount = 0;
    int dairyTotalCount = 0;
    int vegFruitTotalCount = 0;
    int grainTotalCount = 0;
    int fatTotalCount = 0;
    double meatCalCounter = 0;
    double dairyCalCounter = 0;
    double vegFruitCalCounter = 0;
    double grainCalCounter = 0;
    double fatCalCounter = 0;
    double meatAverage = 0;
    double dairyAverage = 0;
    double vegFruitAverage = 0;
    double grainAverage = 0;
    double fatAverage = 0;


    openFile = fopen(file, "r");
    if(openFile == NULL)
    {
        printf("Could not open %s\n", file);
    }

    while (fgets(line, 256, openFile) != NULL)
    {
        int index = 0;
        char * word;

        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        word = strtok(line, ",");

        items[index++] = word; 

        while((word = strtok(NULL, ",")) != NULL)
        {
            items[index++] = word;
        }

        //sending the parsed data to created into struct
        foodArray = createRecord(items[0], items[1], atoi(items[2]), items[3][0]);

        if(strcmp(items[1], "vegfruit") == 0)
        {
            vegFruitTotalCount++;
            vegFruitCalCounter += (double)atoi(items[2]);
        }
        else if(strcmp(items[1], "meat") == 0)
        {
            meatTotalCount++;
            meatCalCounter += (double)atoi(items[2]);
        }
        else if(strcmp(items[1], "dairy") == 0)
        {
            dairyTotalCount++;
            dairyCalCounter += (double)atoi(items[2]);
        }
        else if(strcmp(items[1], "grains") == 0)
        {
            grainTotalCount++;
            grainCalCounter += (double)(atoi(items[2]));
        }
        else if(strcmp(items[1], "fat") == 0)
        {
            fatTotalCount++;
            fatCalCounter += (double)(atoi(items[2]));
        }

        calorieCounter += atoi(items[2]);
        listLength += 1;

    }

    if(vegFruitTotalCount == 0)
    {
        vegFruitTotalCount++;
    }

    if(meatTotalCount == 0)
    {
        meatTotalCount++;
    }

    if(dairyTotalCount == 0)
    {
        dairyTotalCount++;
    }

    if(grainTotalCount == 0)
    {
        grainTotalCount++;
    }

    if(fatTotalCount == 0)
    {
        fatTotalCount++;
    }

    vegFruitAverage = (vegFruitCalCounter / vegFruitTotalCount);
    meatAverage = (meatCalCounter/ meatTotalCount);
    dairyAverage = (dairyCalCounter / dairyTotalCount);
    grainAverage = (grainCalCounter / grainTotalCount);
    fatAverage = (fatCalCounter / fatTotalCount);

    printf("%d\n", calorieCounter);
    printf("%.2lf\n", vegFruitAverage);
    printf("%.2lf\n", meatAverage);
    printf("%.2lf\n", dairyAverage);
    printf("%.2lf\n", grainAverage);
    printf("%.2lf\n", fatAverage);
    printf("%d\n", listLength);

    // printf("this shit worked brah\n");
    fclose(openFile);
    return foodArray;

}
