#include"main.h"

void endGame();
void startGame();

int main(int argc, char* argv[]) {

    if  (argc != 1) {
        printf("incorrect amount of arguments given\n");
        return 1;
    }

startGame();
/*
    initscr();

    printw("hello world");

    refresh();

    getch();*/

    endGame();

    return 0;
}

void startGame(){
initscr();
printw("hello world");
refresh();
getch();
}

void endGame(){
    endwin();
}
