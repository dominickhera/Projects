#ifndef __DHERA__PARSE__
#define __DHERA__PARSE__

typedef struct itemStruct
{
	int itemX;
	int itemY;
	char itemType;
}item;

typedef struct roomStruct {
    int x;
    int y;
    char doorSize[4];
    int doorLocation[4];
    item * roomItems;
}room;

room * parseFile(char *openLevel);
room * createRoom(char * line, int length);

#endif