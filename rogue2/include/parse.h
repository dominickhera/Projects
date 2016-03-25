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
    int heroX;
    int heroY;

    char * doorLocation;
    int  * doorPosition; 
    int totalDoors; 
    int totalItems;


    item * roomItems;

}room;

room * parseFile(char * filename);
void realParse(room * Rooms, char * line, int length);

#endif
