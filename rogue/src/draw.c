#include "draw.h"
#include <ncurses.h>

void initCurses(room * Rooms)
{
    char ** roomMake;
    char userInput;

    int xRoom = Rooms->x;
    int yRoom = Rooms->y;

    roomMake = printRooms(xRoom, yRoom);

    initscr();
    noecho();

    for(int i=0;i<yRoom;i++){
        for(int k=0;k<xRoom;k++){
            mvaddch(i, k, roomMake[i] [k]);
        }
    }
    refresh();

    input = getch();

    if(input = 'q'){
    	endGame();
    }
    /*

    //Game ends 
    //endGame();

    //  printf("x is %d, y is %d", Rooms->x, Rooms->y);
     */
    return ;
}


char ** printRooms(int xVar, int yVar) 
{
    char ** curseRoom;

    curseRoom = malloc(sizeof(char*) *yVar);

        if(curseRoom == NULL){
            printf("failed to allocate memory for your bitch ass room");
            exit(1);
        }

    for(int i=0;i<yVar;i++){
        curseRoom[i] = malloc(sizeof(char) *xVar);
        if(curseRoom == NULL) {
            printf("failed to allocate memory for your bitch ass room");
            exit(1);
        }
    }

    for(int i=0;i<xVar;i++){
        curseRoom[0] [i] = '-';
    }

    for(int i=0;i<xVar;i++){
        curseRoom[yVar - 1] [i] = '-';
    }

    for(int i=0;i<yVar;i++){
        curseRoom[i] [0] = '|';
    }

    for(int i=0;i<yVar;i++){
        curseRoom[i] [xVar - 1] = '|';
    }

    for(int i=1;i<yVar - 1;i++){
        for(int k=1;k<xVar - 1;k++){
            curseRoom[i] [k] = '.';
        }
    }
    return curseRoom;
/*

   for (int i = 0; i < 3; i++)
   {	
   asdasdas
   printItems(room[i], )
   }

   for (int i = 3; i < 6; i ++)
   {
//bottom row rows
}*/


//print items 

}
/*
   void printItems(){

   }*/

void endGame(){
    endwin();
}

