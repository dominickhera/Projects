#include <stdio.h>
#include "draw.h"


void startGame(){
    initscr();
    noecho();
    cbreak(); 
    refresh();
    getch();
}

void endGame(){
    endwin();
}

char ** createRoom(int roomY, int roomX){

    char ** currentRoom;

    currentRoom = malloc(sizeof(char*) *roomY);
    if(currentRoom == NULL){
        printf("failed to allocate memory for room\n");
        exit(1);
    }

    for(int i=0;i<roomY;i++){
        currentRoom[i] = malloc(sizeof(char) *roomX);
        if(currentRoom[i] == NULL){
            printf("failed to allocate memory for room \n");
            exit(1);
        }
    }
    //walls
    for(int i=0;i<roomX;i++){
        currentRoom[0][i] = '-';
    }

    for(int i=0;i<roomX;i++){
        currentRoom[roomY - 1] [i] = '-';
    }

    for(int i=0;i<roomY;i++){
        currentRoom[i] [0] = '|';
    }

    for(int i=0;i<roomY;i++){
        currentRoom[i] [roomX - 1] = '|';
    }

    //floor
    for(int i=1;i<roomY-1;i++){
        for(int k=1;k<roomX-1;k++){
            currentRoom[i][k] = '.';
        }
    }


    return currentRoom;
}

int checkInput(char input, int posY, int posX){
    char space;
    switch(input){
        case 'w':
            posY -= 1;
            break;
        case 'a':
            posX -= 1;
            break;
        case 's':
            posY += 1;
            break;
        case 'd':
            posX += 1;
            break;
        case 'h':
            return 2;
        case 'r':
            return 3;
            break;
    }

    space = mvinch(posY, posX) & A_CHARTEXT;

    switch(space){
        case '#':
            return 0;
        case '.':
            return 1;
            break;
        default:
            return 0;
    }

    return 0;
}

void movePlayer(char input, int * posY, int * posX){
    switch(input){
        case 'w':
            mvaddch(*posY, *posX, '.');
            *posY -= 1;
            break;
        case 'a':
            mvaddch(*posY, *posX, '.');
            *posX -= 1;
            break;
        case 's':
            mvaddch(*posY, *posX, '.');
            *posY += 1;
            break;
        case 'd':
            mvaddch(*posY, *posX, '.');
            *posX += 1;
            break;
        default:
            return;
    }
    mvaddch(*posY, *posX, '@');
    move(*posY, *posX);
}

//free all memory given of a given room
void destroyRoom(char ** currentRoom, int roomY){
    for(int i=0;i<roomY;i++){
        free(currentRoom[i]);
    }
    free(currentRoom);
}
