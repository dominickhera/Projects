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

typedef struct bat
{
	int batHealth;
	int batAttackCount;
	int batAttackSpeed;
}bat;

typedef struct troll
{
	int trollHealth;
	int trollAttackCount;
	int trollAttackSpeed;
}troll;

typedef struct snake
{
	int snakeHealth;
	int snakeAttackCount;
	int snakeAttackSpeed;
}snake;

typedef struct zombie
{
	int zombieHealth;
	int zombieAttackCount;
	int zombieAttackSpeed;
}zombie;

typedef struct aquator
{
	int aquatorHealth;
	int aquatorAttackCount;
	int aquatorAttackSpeed;
}aquator;

void initCurses(room * Rooms);
char ** printRooms(int xVar, int yVar, room * Rooms, int index);
void printHallway(int x, int y);
void connectDoors(char ** roomMake[], room * Rooms);
void printDeadEnds(int startX, int startY, int xIncrement, int yIncrement, int randNum);
void movePlayer(char input, int * posY, int * posX);
void movePlayerInHallways(char input, int * posY, int * posX);
int checkInput(char input, int posY, int posX);
int getMaxX(room * Rooms);
int getMaxY(room * Rooms);
void getNotification(int event, int x);
void initPlayer(player * Player);
void getStatus(player Player, int x, int y);
void clearNotifyLine();
int midHallwayNum(room * Rooms);
int getNotifyY(room * Rooms);
int getNotifyX(room * Rooms);
void freeLevels(char ** curseRoom[], room * Rooms);
void freeRoom (room * Rooms);
void endGame();

#endif
