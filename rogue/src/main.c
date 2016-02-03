#include"main.h"

void endGame();
void startGame();
void gameLoop();
void moveCursor(char input);

int main(int argc, char* argv[]) {

    if  (argc != 1) {
        printf("incorrect amount of arguments given\n");
        return 1;
    }

    startGame();
    gameLoop();
    endGame();

    return 0;
}

void startGame(){
    initscr();
    noecho();
    cbreak(); 
    printw("hello world");
    refresh();
    getch();
}

void gameLoop() {
    char input;
    do {
        input = getch();
        moveCursor(input);
    } while (input != 'q');

}

void moveCursor(char input) {
    int xpos, ypos;
    int oldX, oldy;
    getyx(stdscr, ypos, xpos);

    switch(input) {
        case 'w':
            ypos--;
            break;
        case 'a':
            xpos--;
            break;
        case 's':
            ypos++;
            break;
        case 'd':
            xpos++;
            break;
        default:
            break;
    }
    move(ypos, xpos);
}

void endGame(){
    endwin();
}
