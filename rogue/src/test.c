#include<stdlib.h>
#include<ncurses.h>
#include<stdio.h>

void printRec(int y, int x, int h, int w);
void printMsg(const char* msg);

int main(){

    int rows;
    int cols;
    char input[5];
    int tall;
    int wide;

    initscr();
    getmaxyx(stdscr, rows, cols);
    printw("Screen size is %dX%d", rows, cols);

    mvprintw(2, 3, "enter the height: ");
    getstr(input);
    tall = (int)strtol(input, NULL, 10);
    move(2, 0);
    clrtoeol(); //clears line

    mvprintw(2, 3, "Enter the width: ");
    getstr(input);
    wide = (int)strtol(input, NULL, 10);

    erase();
    /*
       for (int i = 0; i < wide; i++) {
       mvaddch(0, i, '_');
       }

       for (int i=0; i <tall; i++) {
       mvaddch(i, 0, '|');
       mvaddch(i, wide, '|');
       }

       for (int i=0; i <= wide; i++) {
       mvaddch(tall, i, '_');
       }*/

    printRec(2,3,tall,wide);
    printRec(6,7,tall,wide);
    printRec(12,23,tall,wide);

    getch();

    endwin();

    return 0;
}

void printRec(int y, int x, int h, int w) {
    for (int i=x; i < w; i++){
        mvaddch(x, i, '#');
    }
    for (int i=0; i <h+y; i++) {
        mvaddch(i, y, '#');
        mvaddch(i, w+x , '#');
    }
    for ( int i =x; i <=w+x; i++){
        mvaddch(h+y, i, '#');
    }

printMsg("printed one rectangle");
getch();
}

void printMsg(const char* msg) {
    int x, y;
    getyx(stdscr, y, x);
    mvprintw(0,0,msg);
    move(y,x);
}
