#include"main.h"

typedef struct roomStruct {
    int x;
    int y;
    int width;
    int height;
    itemContents[10];
}room;

void endGame();
void startGame();
room* roomParse();
int main(int argc, char* argv[]) {
    FILE * openLevel;
    if  (argc != 1) {
        printf("incorrect amount of arguments given\n");
        return 1;
    }

    openLevel = fopen(argv[1], "r");

    //    startGame();
    //    endGame();
    fclose(openLevel);
    return 0;
}

void startGame(){
    initscr();
    noecho();
    cbreak(); 
    refresh();
    getch();
}

room* roomParse() {
    room * roomThing;
    int counter = 0;
    

    roomThing = malloc(sizeof(room));
    roomThing->x = xInt;
    roomThing->y = yInt;
    roomThing->width = widthInt;
    roomThing-height = heighInt;

    return roomThing;

}

void endGame(){
    endwin();
}
