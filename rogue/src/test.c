#include <stdlib.h>
#include <ncurses.h>

void printRec(int y, int x, int h, int w);

void printMsg(const char* msg);

int main() {
    int rows;
    int cols;
    char input[5];
    int tall;
    int wide;

    initscr(); //initalize ncurses

    getmaxyx(stdscr, rows, cols); //get size of screen
    printw("Screen size is %dX%d", rows, cols);

    //Move to position, and print
    mvprintw(2, 3, "Enter the height: ");
    getstr(input); //get string from user, store in input
    tall = (int)strtol(input, NULL, 10);
    move(2,0); //move to beginning of line
    clrtoeol(); //clear line


    mvprintw(2, 3, "Enter the width: ");
    getstr(input);
    wide = (int)strtol(input, NULL, 10);

    erase(); //clear entire screen

    printRec(2,3,tall,wide);
    getch();
    printRec(6,7,tall,wide);
    getch();
    printRec(12,23,tall,wide);
    getch();

    /* Pause for input.
       This really does nothing. It's just hear so you can see the screen
       before the program exits. Hit any key to continue*/
    printMsg("End of program. Push any key to quit.");
    getch();


    /* Important. Don't forget to do this: */
    endwin(); //deinitalize ncurses

    return 0;
}

void printRec(int y, int x, int h, int w) {
    for (int i=x; i<w+x; i++) {
        mvaddch(y, i, '#');
    }

    //THIS IS THE BUGGY LOOP
    for (int i=y; i<h+y; i++) {
        mvaddch(i, y, '#');
        mvaddch(i, w+x, '#');
    }

    for (int i=x; i<=w+x; i++) {
        mvaddch(h+y, i, '#');
    }
    printMsg("Printed one rectangle");
}

void printMsg(const char* msg) {
    int x, y;
    getyx(stdscr, y, x);
    mvprintw(0,0,msg);
    move(y,x);
}
