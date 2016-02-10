#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct roomStruct {
    int x;
    int y;
    int width;
    int height;
}room;
/*
enum itemsEnum {
    z,
    a,
    g,
    G,
    w,
    W,
    m,
    e,
    M,
    P,
};*/

int main (int argc, char* argv[])
{
    FILE * openLevel;
    char text[200];
    room * roomThing;
    room x[6];
    room y[6];
    room width[6];
    room height[6];
   // enum itemsEnum items;
    openLevel = fopen(argv[1], "r");

    if (argc != 2){
      printf("not enough arguments provided\n");
      return 1;
      }

    if (openLevel == NULL){
        printf("couldn't open file\n");
    }
roomThing = malloc(sizeof(room));
    while (fscanf(openLevel, "%s", text) != EOF)
    {
        char * pch;
        pch = strtok (text," ");
        //roomThing->x = atoi(pch);
        //pch = strtok (text, "X");
        //roomThing->y = atoi(pch);
       // printf("%d", roomThing->x);
        //pch = strtok (text," X de dw ds g , M h p");
		//printf("%d", roomThing->y);
        while (pch != NULL)
        {
            printf ("%s\n",pch);
           // pch = strtok (NULL, " X de dw ds g , M h p");
            pch = strtok (NULL, " ");
          //  roomThing->y = atoi(pch);
            //printf("%d", roomThing->y);
        }
   roomThing->x = atoi(pch);
    roomThing->y = atoi(pch);
    }
  //  roomThing->x = atoi(pch);
    //roomThing->y = atoi(pch);
printf("%d", roomThing->x);
printf("%d", roomThing->y);
    return 0;
}