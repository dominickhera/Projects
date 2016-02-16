#ifndef __DHERA__PARSE__
#define __DHERA__PARSE__

typedef struct item
{
	int itemX;
	int itemY;
	char itemType;
}item;

typedef struct roomStruct {
    
    int x; 
    int y;

    char doorLocation[4];
    int doorPosition[4];
    int totalDoors; 

    item * roomItems;

}room;

room * parseFile(char * filename);
room * parseRoom(char * line, int length);

#endif
