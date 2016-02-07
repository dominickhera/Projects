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
    roomParse();
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
    roomThing = malloc(sizeof(room));    

    while(fgets(line, 256, openLevel) != NULL) {
        char finalLine[256];
        char wordUpdate[256];
        int counter = 0;
        memset(word, '\0', strlen(word));
        length = strlen(line);
        line[length - 1] = '\0'

            for (int i = 0; i < length; i++) {
                while(line[i] != 'X') {
                    word[wordLength] = line[i];
                    wordLength++;
                    i++;
                }
            }
    }

    roomThing->x = xInt;
    roomThing->y = yInt;
    roomThing->width = widthInt;
    roomThing-height = heighInt;

    return roomThing;

}

void endGame(){
    endwin();
}
