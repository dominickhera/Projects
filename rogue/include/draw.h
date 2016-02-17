#ifndef __DHERA__DRAW__
#define __DHERA__DRAW__
#include <parse.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


void initCurses(room * Rooms);
void gameLoop();
char ** printRooms(int xVar, int yVar, room * Rooms, int index);
void endGame();
/*
void initCurses(room * Rooms);

//char ** printRooms(int yVar, int xVar, room * Rooms, int index);
void gameLoop();
//void printRooms();
//void printItems();
void endGame();
*/
/*
int checkInput(char input, int posY, int posX);
void movePlayer(char input, int * posY, int * posX);
void destroyRoom(char ** currentRoom, int roomY);
*/
#endif
