#include <stdio.h>


void startGame(){
    initscr();
    noecho();
    cbreak(); 
    refresh();
    getch();
}

void endGame(){
    endwin();
}
