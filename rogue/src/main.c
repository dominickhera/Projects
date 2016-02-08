#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>
#include "parse.h"
#include "draw.h"

void startGame();
void parse();
void draw();
void endGame();


int main(int argc, char* argv[]) {
    roomParse();
    startGame();
    endGame();
    fclose(openLevel);
    return 0;
}
