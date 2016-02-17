#ifndef __DHERA__DRAW__
#define __DHERA__DRAW__
#include <parse.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>



void initCurses(room * Rooms);
char ** printRooms(int xVar, int yVar);
//void printRooms();
//void printItems();
void endGame();

/*
char ** createRoom(int roomY, int roomX);
int checkInput(char input, int posY, int posX);
void movePlayer(char input, int * posY, int * posX);
void destroyRoom(char ** currentRoom, int roomY);
*/
#endif
