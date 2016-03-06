#include "draw.h"
#include "parse.h"

//calls the room print function to print all the rooms, makes sure to print them at an offset so they all dont print right next to eachother
//also handles the game loop that looks for user interaction and checks the input against another function to see how to respond
void initCurses(room * Rooms)
{
    char ** roomMake[6];
    char input, condition;
    int yRoom, xRoom;
    int goldTotal = 0;
    int inventoryTotal = 0;
    int smallRandNum = 0;
    int bigRandNum = 0;
    int charY = 5;
    int charX = 5;
    srand(time(NULL));
    initscr();
    noecho();

    for (int i = 0; i < 6; i ++)
    {
        xRoom = Rooms[i].x;
        yRoom = Rooms[i].y;
        roomMake[i] = printRooms(yRoom,xRoom, Rooms, i);
    }

    int offset = 0;
    int maxTop = 0;

    for (int j = 0; j < 6; j++)
    {
        if (j <= 2)
        {
            if (j == 0)
            {
                maxTop = Rooms[j].y;
                offset = 0;
            }
            else
            {
                offset = offset + (Rooms[j - 1].x  + 3);
                if(Rooms[j].y > maxTop)
                {
                    maxTop = Rooms[j].y;
                }
            }

            for(int i=0;i<Rooms[j].y;i++)
            {
                for(int k=0;k<Rooms[j].x;k++)
                {
                    mvaddch(i, k + offset, roomMake[j][i] [k]);
                }
            }

        }
        else if (j > 2 && j < 6)
        {
            if(j == 3)
            {
                offset = 0;
            }
            else if (j > 3)
            {
                offset = offset + (Rooms[j - 1].x  + 3);
            }

            for(int i=0;i<Rooms[j ].y;i++)
            {
                for(int k=0;k<Rooms[j ].x;k++)
                {

                    mvaddch(i + (maxTop + 5), k + offset, roomMake[j][i] [k]);
                }
            }

        }

    }

    mvaddch(charY, charX, '@');
    move(charY, charX);
    refresh();

    //main game loop
    do
    {
        refresh();
        input = getch();
        condition = checkInput(input, charY, charX);
        /*   if(condition == 1)
             {
             movePlayer(input,&charY,&charX);
             } 
             else if(condition == 2)
             {
             move(30, 0);
             printw("you hit a wall");
             }*/
        switch (condition)
        {
            case 1:
                movePlayer(input,&charY,&charX);
                break;
            case 2:
                move(0, 0);
                printw("you hit a door");
                break;
            case 3:
                smallRandNum = 0;
                movePlayer(input,&charY,&charX);
                smallRandNum = (rand() % 50);
                goldTotal = goldTotal + smallRandNum;
                move(30, 0);
                printw("random number: %d current gold total: %d\n", smallRandNum, goldTotal);
                //printf("random number: %d current gold total: %d\n", smallRandNum, goldTotal);
                break;
            case 4:
                bigRandNum = 0;
                movePlayer(input,&charY,&charX);
                bigRandNum = rand()%(250-50 + 1) + 50;
                goldTotal = goldTotal + bigRandNum;
                move(30, 0);
                printw("random number: %d current gold total: %d\n", bigRandNum, goldTotal);
                break;
            default:
                break;
        }
        move(charY, charX);
        refresh();
    }while(input != 'q');
    endGame();
    printf("Congratulations, you collected %d gold!\n", goldTotal);
    freeLevels(roomMake, Rooms);
    freeRoom(Rooms);

    return;
}
// main function that actually prints out the rooms
//mallocs and then begins to assign each character to the cureRoom file
//attempts to create the doors can also be seen commented out.
char ** printRooms(int yVar, int xVar, room * Rooms, int index)
{
    char ** curseRoom;

    curseRoom = malloc(sizeof(char*) *yVar);
    if(curseRoom == NULL)
    {
        printf("failed to allocate memory for room\n");
        exit(1);
    }

    for(int i=0;i<yVar;i++)
    {
        curseRoom[i] = malloc(sizeof(char) *xVar);
        if(curseRoom[i] == NULL)
        {
            printf("failed to allocate memory for room \n");
            exit(1);
        }
    }

    for(int i=0;i<xVar;i++)
    {
        curseRoom[0][i] = '-';

    }

    for(int i=0;i<xVar;i++)
    {
        curseRoom[yVar - 1] [i] = '-';
    }

    for(int i=0;i<yVar;i++)
    {
        curseRoom[i] [0] = '|';//|
    }

    for(int i=0;i<yVar;i++)
    {
        curseRoom[i] [xVar - 1] = '|';
    }


    for(int i=1;i<yVar-1;i++)
    {
        for(int k=1;k<xVar-1;k++)
        {
            curseRoom[i][k] = '.';
        }
    }

    for(int i=0; i<Rooms[index].totalDoors; i++)
    {
        if((Rooms[index].doorLocation[i]) == 'e')
        {
            curseRoom[Rooms[index].doorPosition[i] - 1][xVar - 1] = '+';
        }
        else if((Rooms[index].doorLocation[i]) == 'n')
        {
            curseRoom[0][Rooms[index].doorPosition[i] - 1] = '+';
        }
        else if((Rooms[index].doorLocation[i]) == 's')
        {
            curseRoom[yVar - 1][Rooms[index].doorPosition[i] - 1] = '+';
        }
        else if((Rooms[index].doorLocation[i]) == 'w')
        {
            curseRoom[Rooms[index].doorPosition[i] - 1][0] = '+';
        }

    }

    for(int i=0; i<Rooms[index].totalItems; i++)
    {
        if (Rooms[index].roomItems[i].itemType == 'g')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = '*';

        } 
        else if (Rooms[index].roomItems[i].itemType == 'G')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = '8';
        }
        else if (Rooms[index].roomItems[i].itemType == 'z')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = '<';
        }
        else if (Rooms[index].roomItems[i].itemType == 'w')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = ')';
        }
        else if (Rooms[index].roomItems[i].itemType == 'W')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = '(';
        }
        else if (Rooms[index].roomItems[i].itemType == 'm')
        {
            int randomNum = 0;
            randomNum = rand() % 4;

            switch (randomNum)
            {
                case 0:
                    curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'A';
                case 1:
                    curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'B';
                case 2:
                    curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'Z';
                case 3:
                    curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'S';
                default:
                    curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'Z';
            }
            randomNum = 0;
        }
        else if (Rooms[index].roomItems[i].itemType == 'p')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = '!';
        }
        else if (Rooms[index].roomItems[i].itemType == 'a')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = '<';
        }
        else if (Rooms[index].roomItems[i].itemType == 'M')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'T';
        }
        else if (Rooms[index].roomItems[i].itemType == 'e')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = ']';
        }/*
            else
            {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = Rooms[index].roomItems[i].itemType;
            }*/
    }
    printf("%d\n", Rooms[index].totalItems);


    return curseRoom;
}

//checks the input of what character the user typed and responds accordingly
//also deals with collision control to make sure the hero doesnt go through walls
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
    }

    space = mvinch(posY, posX) & A_CHARTEXT;

    switch(space){
        case '#':
            return 0;
        case '.':
            return 1;
            break;
        case '+':
            return 2;
        case '|':
            return 0;
        case '-':
            return 0;
        case '*':
            return 3;
        case '8':
            return 4;
        case ' ':
            return 0;
        default:
            return 1;
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
//frees all the memory used to prevent memory leaks if only the program compiled on pi that is

void freeLevels(char ** curseRoom[], room * Rooms)
{
    for(int i=0;i<6;i++)
    {
        for( int j=0; j < Rooms[0].y; j++){
            //   free(curseRoom[i][j]);   
        }
        // free(curseRoom[i]);
    }
    //free(curseRoom);
}

void freeRoom (room * Rooms){
    for (int i = 0; i < 6; i++)
    {
        free(Rooms[i].roomItems);
        free(Rooms[i].doorPosition);
        free(Rooms[i].doorLocation);
    }
    free(Rooms);
}

//merely ends the game and gets out of ncurses
void endGame(){
    endwin();
}
