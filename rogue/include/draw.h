#ifndef __DHERA__DRAW__
#define __DHERA__DRAW__
#include <parse.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


void initCurses(room * Rooms);
char ** printRooms(int xVar, int yVar, room * Rooms, int index);
void movePlayer(char input, int * posY, int * posX);
int checkInput(char input, int posY, int posX);
void freeLevels(char ** curseRoom[], room * Rooms);
void freeRoom (room * Rooms);
void endGame();

#endif
