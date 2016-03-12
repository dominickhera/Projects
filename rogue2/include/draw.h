#ifndef __DHERA__DRAW__
#define __DHERA__DRAW__
#include <parse.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>

typedef struct character
{
    int healthCount;
    int potionCount;
    int inventoryTotal;
    int attackCount;
    int goldTotal;

}player;

typedef struct enemyStruct
{
	int enemyCount;
	int enemyHealthCount;
	int enemyAttackCount;
	int enemyAttackSpeed;
	int enemyY;
	int enemyX;

}enemy;

void initCurses(room * Rooms);
char ** printRooms(int xVar, int yVar, room * Rooms, int index, enemy * Enemy);
void printHorizontalHallway(int x, int y);
void printVerticalHallway(int x, int y);
void printLowerVerticalHallway(int x, int y, int z);
void connectDoors(char ** roomMake[], room * Rooms);
void printDeadEnds(int startX, int startY, int xIncrement, int yIncrement, int randNum);
void movePlayer(char input, int * posY, int * posX);
void movePlayerInHallways(char input, int * posY, int * posX);
int checkInput(char input, int posY, int posX);
void combat(player * Player, enemy * Enemy);
int getMaxX(room * Rooms);
int getMaxY(room * Rooms);
int getMaxYRoom(room * Rooms, int x);
int getMaxYTop(room * Rooms);
int getMaxYBot(room * Rooms);
int getTotalY(room * Rooms);
int getTotalYTop(room * Rooms);
int rightHallwayNum(room * Rooms);
void getNotification(int event, int subEvent, int var, char letter);
void initPlayer(player * Player, enemy * Enemy);
void getStatus(player Player, int x, int y);
void clearNotifyLine();
int midHallwayNum(room * Rooms);
int getNotifyY(room * Rooms);
int getNotifyX(room * Rooms);
void freeLevels(char ** curseRoom[], room * Rooms);
void freeRoom (room * Rooms);
void endGame();

#endif
