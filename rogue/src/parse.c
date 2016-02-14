#import <stdio.h>
#import <stdlib.h>
#import <ctype.h>
#import <string.h>
#import "parse.h"

#define TOTALROOMCOUNT  5

room * parseFile(char ) { 

FILE * openLevel;
room * roomThing;
roomThing = malloc(sizeof(room)); 

    if  (argc != 2) {
        printf("incorrect amount of arguments given\n");
        return 1;
    }

    openLevel = fopen(argv[1], "r");
   
   while(fgets(line, 256, openLevel) != NULL) {
        int counter = 0;
        length = strlen(line);
        line[length - 1] = '\0'

            for (int i = 0; i < length; i++) {
                while(line[i] != 'X') {
                    word[wordLength] = line[i];
                    wordLength++;
                    i++;
                }
            }

    }

    roomThing->x = xInt;
    roomThing->y = yInt;

    return roomThing;

}

room * createRoom(char * line, int length){

    
}

/*
for (int i = 0; i < length; i++) {
                while(line[i] != 'X') {
                    word[wordLength] = line[i];
                    wordLength++;
                    i++;
                }
            }
            */