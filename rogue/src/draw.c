#include "draw.h"

void initGame()
{
    initscr();
    noecho();
    cbreak(); 
 
    return;
}

int main(int argc, char ** argv){
    char ** room1;
    char input;
    char condition;
 
    int x1 = atoi(argv[1]);
    int y1 = atoi(argv[2]);

    int heroY = 5;
    int heroX = 5;
    room1 = createRoom(y1,x1);

    initscr();
    noecho();

    for(int i=0;i<y1;i++){
        for(int k=0;k<x1;k++){
            mvaddch(i, k, room1[i] [k]);
        }
    }

    mvaddch(heroY, heroX, '@');
    move(heroY, heroX);
    refresh();

    //game loop
    while(input != 'q'){
        refresh();
        input = getch();
        condition = checkInput(input, heroY, heroX);
        if(condition == 1){
            movePlayer(input,&heroY,&heroX);
        } 
        else if(condition == 2){
            move(30, 0);
        }
        else if (condition == 3){
            clear();

            for(int i=0;i<y1;i++){
                for(int k=0;k<x1;k++){
                    mvaddch(i, k, room1[i] [k]);
                }
            }
        }
        move(heroY, heroX);
        refresh();
    }

    endwin();

    destroyRoom(room1, y1);

    return 0;
}




char ** createRoom(int roomY, int roomX){

    char ** currentRoom;

    currentRoom = malloc(sizeof(char*) *roomY);
    if(currentRoom == NULL){
        printf("failed to allocate memory for room\n");
        exit(1);
    }

    for(int i=0;i<roomY;i++){
        currentRoom[i] = malloc(sizeof(char) *roomX);
        if(currentRoom[i] == NULL){
            printf("failed to allocate memory for room \n");
            exit(1);
        }
    }
    //walls
    for(int i=0;i<roomX;i++){
        currentRoom[0][i] = '-';
    }

    for(int i=0;i<roomX;i++){
        currentRoom[roomY - 1] [i] = '-';
    }

    for(int i=0;i<roomY;i++){
        currentRoom[i] [0] = '|';
    }

    for(int i=0;i<roomY;i++){
        currentRoom[i] [roomX - 1] = '|';
    }

    //floor
    for(int i=1;i<roomY-1;i++){
        for(int k=1;k<roomX-1;k++){
            currentRoom[i][k] = '.';
        }
    }


    return currentRoom;
}

int checkInput(char input, int posY, int posX){
    char space;
    switch(input){
        case 'w':
            posY -= 1;
            break;
        case 'a':
            posX -= 1;
            break;
        case 's':
            posY += 1;
            break;
        case 'd':
            posX += 1;
            break;
        case 'h':
            return 2;
        case 'r':
            return 3;
            break;
    }

    space = mvinch(posY, posX) & A_CHARTEXT;

    switch(space){
        case '#':
            return 0;
        case '.':
            return 1;
            break;
        default:
            return 0;
    }

    return 0;
}

void movePlayer(char input, int * posY, int * posX){
    switch(input){
        case 'w':
            mvaddch(*posY, *posX, '.');
            *posY -= 1;
            break;
        case 'a':
            mvaddch(*posY, *posX, '.');
            *posX -= 1;
            break;
        case 's':
            mvaddch(*posY, *posX, '.');
            *posY += 1;
            break;
        case 'd':
            mvaddch(*posY, *posX, '.');
            *posX += 1;
            break;
        default:
            return;
    }
    mvaddch(*posY, *posX, '@');
    move(*posY, *posX);
}

//free all memory given of a given room
void destroyRoom(char ** currentRoom, int roomY){
    for(int i=0;i<roomY;i++){
        free(currentRoom[i]);
    }
    free(currentRoom);
}

void endGame(){
	endwin();
}

