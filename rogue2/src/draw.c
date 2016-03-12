#include "draw.h"
#include "parse.h"

//calls the room print function to print all the rooms, makes sure to print them at an offset so they all dont print right next to eachother
//also handles the game loop that looks for user interaction and checks the input against another function to see how to respond
void initCurses(room * Rooms)
{
    player Player;
    enemy Enemy;
    char ** roomMake[6];
    char input, condition;
    int yRoom, xRoom;
    int cols = 0;
    int rows = 0;
    int smallRandNum = 0;
    int bigRandNum = 0;
    int maxX = 0;
    int maxY = 0;
    int charY = 0;
    int charX = 0;
    Enemy.enemyCount = 0;
    /*int testOffset = 0;
    int midOffset = 0;
    int topOffset = 0;
    int botOffset = 0;
    int hallwayOne = 0;
    int hallwayTwo = 0;
    int hallwayThree = 0;
    int hallwayFour = 0;*/
    srand(time(NULL));
    initscr();
    noecho();

    for (int i = 0; i < 6; i ++)
    {
        xRoom = Rooms[i].x;
        yRoom = Rooms[i].y;
        roomMake[i] = printRooms(yRoom,xRoom, Rooms, i, &Enemy);
    }
    initPlayer(&Player);
    maxX = getMaxX(Rooms);
    maxY = getMaxY(Rooms);
    getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));

    getmaxyx(stdscr, rows, cols);

    int offset = 0;
    int maxTop = 0;
    int yOffset = 5;

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
                offset = offset + (Rooms[j - 1].x  + 7);
                if(Rooms[j].y > maxTop)
                {
                    maxTop = Rooms[j].y;
                }
            }

            for(int i=0;i<Rooms[j].y;i++)
            {
                for(int k=0;k<Rooms[j].x;k++)
                {
                    mvaddch(i + yOffset, k + offset + 6, roomMake[j][i] [k]);
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
                offset = offset + (Rooms[j - 1].x  + 7);
            }

            for(int i=0;i<Rooms[j ].y;i++)
            {
                for(int k=0;k<Rooms[j ].x;k++)
                {
                    mvaddch(i + (maxTop + (yOffset * 2)), k + offset + 6, roomMake[j][i] [k]);
                }
            }

        }

    }
    charX = (Rooms->heroX);
    charY = (Rooms->heroY);

    /*
    topOffset = (yOffset/2);
    midOffset = (getMaxYTop(Rooms) + (maxTop/2));
    botOffset = (getMaxYTop(Rooms) + getMaxYBot(Rooms) + (topOffset) + (midOffset/2));
    hallwayOne = (getMaxYRoom(Rooms, 2) + (yOffset * 1.5));
    hallwayTwo = ((getMaxYRoom(Rooms, 2) + getMaxYRoom(Rooms, 1) + (yOffset * 2.75)));
    hallwayThree = (getMaxYRoom(Rooms, 4) + (yOffset * 1.5));
    hallwayFour = ((getMaxYRoom(Rooms, 5) + getMaxYRoom(Rooms, 4) + (yOffset * 2.75)) + 2);
    move(0,0);
    printw("bot offset is %d", hallwayOne);
    testOffset = ((yOffset * 4) + rightHallwayNum(Rooms));
    printHorizontalHallway(testOffset, topOffset); //top horizontal hallway
    printHorizontalHallway(testOffset, midOffset); //middle horizontal hallway
    printHorizontalHallway(testOffset, botOffset); //bot horizontal hallyway
    printVerticalHallway((botOffset), topOffset);//most left hallway
    printVerticalHallway((botOffset), (testOffset));//most right hallway
    printVerticalHallway(midOffset, hallwayOne);
    printVerticalHallway(midOffset, hallwayTwo);
    printVerticalHallway(botOffset, hallwayThree);
    printVerticalHallway(botOffset, hallwayFour);
    */

    move(0,0);
    printw("hero x is %d, hero y is %d", Rooms->heroX, Rooms->heroY);

    connectDoors(roomMake, Rooms);
    mvaddch(charY, charX, '@');
    move(charY, charX);
    refresh();

    //main game loop
    do
    {
        refresh();
        input = getch();
        condition = checkInput(input, charY, charX);
        switch (condition)
        {
            case 1:
                clearNotifyLine();
                movePlayer(input,&charY,&charX);
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                break;
            case 2:
                clearNotifyLine();
                move(0, 0);
                printw("you walked through a door");
                movePlayerInHallways(input,&charY,&charX);
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                break;
            case 3:
                clearNotifyLine();
                smallRandNum = 0;
                smallRandNum = (rand() % 50);
                Player.goldTotal += smallRandNum;
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                movePlayer(input,&charY,&charX);
                getNotification(1,1, smallRandNum,'x');
                // move(0,0);
                //printw("You picked up %d gold!", smallRandNum);
                break;
            case 4:
                clearNotifyLine();
                bigRandNum = 0;
                bigRandNum = rand()%(250-50 + 1) + 50;
                Player.goldTotal += bigRandNum;
                movePlayer(input,&charY,&charX);
                getNotification(1,2,bigRandNum,'x');
                //move(0,0);
                //printw("You picked up %d gold!", bigRandNum);
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                break;
            case 5:
                movePlayer(input,&charY,&charX);
                input = 'q';
                break;
            case 6:
                clearNotifyLine();
                movePlayer(input,&charY,&charX);
                move(0, 0);
                printw("You picked up a potion!");
                Player.potionCount++;
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                break;
            case 7:
               // clearNotifyLine();
                if(Player.healthCount == 50)
                {
                    getNotification(7,1,0,'x');
                   // move(0,0);
                    //printw("You already have full health");
                    getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                }
                else if (Player.potionCount > 0)
                {
                    Player.potionCount--;
                    getNotification(7,2,0,'x');
                    //move(0,0);
                    //printw("You now have full health");
                    Player.healthCount = 50;
                    getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                } 
                else 
                {
                    getNotification(8,0,0,'x');
                    //move(0,0);
                    //printw("You have no potions left");
                    getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                }
                break;
            case 8:
                //clearNotifyLine();
                if (Player.inventoryTotal < 5)
                {
                   // movePlayer(input,&charY,&charX);  
                    clearNotifyLine();
                    Player.inventoryTotal++;
                    getNotification(1,3,0,'x');
                    //move(0,0);
                    //printw("You added an item to your inventory");
                    getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                }
                else
                {
                    //move(0,0);
                    //printw("Your inventory is already full! You can't pick up anymore items");
                    getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                }
            case 9:
                //clearNotifyLine();
                movePlayerInHallways(input,&charY,&charX);
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
                break; 
            case 10:
                clearNotifyLine();
                move(0,0);
                printw("you ran into a monster");
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
            case 11:
                clearNotifyLine();
                getStatus(Player, getNotifyY(Rooms), getNotifyX(Rooms));
            case 12:
            case 13:
            case 14:
            default:
                break;
        }
        move(charY, charX);
        refresh();
    }while(input != 'q');
    printf("Congratulations, you collected %d gold!\n", Player.goldTotal);
    freeLevels(roomMake, Rooms);
    freeRoom(Rooms);
    endGame();
    return;
}
// main function that actually prints out the rooms
//mallocs and then begins to assign each character to the cureRoom file
//prints out items, large switch case to determine what actual character to print out for each item
char ** printRooms(int yVar, int xVar, room * Rooms, int index, enemy * Enemy)
{
    char ** curseRoom;


    curseRoom = malloc(sizeof(char*) *yVar);
   // enemy = malloc(sizeof(int*)*60);
    Enemy = malloc(sizeof(Enemy)*60);
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

            if (randomNum == 0)
            {
                curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'A';
                Enemy[Enemy->enemyCount].enemyHealthCount = 5;
                Enemy[Enemy->enemyCount].enemyAttackCount = 1;
                Enemy[Enemy->enemyCount].enemyAttackSpeed = 2;
                Enemy->enemyCount++;
            }
            else if (randomNum == 1)
            {
                curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'B';
                Enemy[Enemy->enemyCount].enemyHealthCount = 2;
                Enemy[Enemy->enemyCount].enemyAttackCount = 5;
                Enemy[Enemy->enemyCount].enemyAttackSpeed = 4;
                Enemy->enemyCount++;
            }
            else if (randomNum == 2)
            {
                curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'Z';
                Enemy[Enemy->enemyCount].enemyHealthCount = 15;
                Enemy[Enemy->enemyCount].enemyAttackCount = 5;
                Enemy[Enemy->enemyCount].enemyAttackSpeed = 2;
                Enemy->enemyCount++;
            }
            else if (randomNum == 3)
            {
                curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = 'S';
                Enemy[Enemy->enemyCount].enemyHealthCount = 5;
                Enemy[Enemy->enemyCount].enemyAttackCount = 5;
                Enemy[Enemy->enemyCount].enemyAttackSpeed = 4;
                Enemy->enemyCount++;
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
            Enemy[Enemy->enemyCount].enemyHealthCount = 50;
            Enemy[Enemy->enemyCount].enemyAttackCount = 5;
            Enemy[Enemy->enemyCount].enemyAttackSpeed = 3;
            Enemy->enemyCount++;
        }
        else if (Rooms[index].roomItems[i].itemType == 'e')
        {
            curseRoom[Rooms[index].roomItems[i].itemY - 1][Rooms[index].roomItems[i].itemX - 1] = ']';
        }
    }
    //printf("%d\n", Rooms[index].totalItems);


    return curseRoom;
}

void printHorizontalHallway(int x, int y)
{
    move(y, 0);
    for(int i=2; i<x+1; i++)
    {
        mvaddch(y, i, '#');  
    }

}

void printVerticalHallway(int x, int y)
{
    move(y, 0);
    for(int i=2; i<x; i++)
    {
        mvaddch(i, y, '#');
    }
}

void printLowerVerticalHallway(int x, int y, int z)
{
    move(y, z);
    for(int i=2; i<x; i--)
    {
        mvaddch(i, y, '#');
    }
}

void connectDoors(char ** roomMake[], room * Rooms)
{
    int offset = 0;
    int maxTop = 0;
    int yOffset = 0;
    //int yVar = 0;
    //int countVar = 0;
    //char spaceVar;


    for(int i = 0; i<6; i++)
    {
        offset = offset + (Rooms[i - 1].x  + 6);
        if (i <= 2)
        {
            if (i == 0)
            {
                maxTop = Rooms[i].y;
                offset = 0;
            }
            else
            {
                offset = offset + (Rooms[i - 1].x  + 6);
                if(Rooms[i].y > maxTop)
                {
                    maxTop = Rooms[i].y;
                }
            }
            yOffset = 5;
        }
        else if (i > 2 && i < 6)
        {
            if(i == 3)
            {
                offset = 0;
            }
            else if (i > 3)
            {
                offset = offset + (Rooms[i - 1].x  + 6);
            }
            yOffset = maxTop + (yOffset * 2);
        }
        for(int j = 0; j < Rooms[i].totalDoors; j++)
        {
            if(j == 0)
            {
                switch(Rooms[i].doorLocation[j])
                {
                    case 'w':

                        break;
                    case 'e':
                        /*if(i <= 2)
                        {
                            while(1)
                            {
                                countVar++; 
                                printDeadEnds((Rooms[i].doorPosition[j] - 1 + offset + 5) ,(Rooms[i].y - 1 + yOffset), 1, 0, countVar);
                                yVar = (Rooms[i].y - 1 + yOffset + (countVar + 1));
                                spaceVar = mvinch(yVar, (Rooms[i].doorPosition[j] - 1 + offset + 5)) & A_CHARTEXT;
                                if (spaceVar == '|')
                                {
                                    break;
                                }
                            }
                        }*/
                        break;
                    case 'n':

                        break;
                    case 's':

                        break;
                }
            }
            else 
            if (j > 0)
            {

                switch(Rooms[i].doorLocation[j])
                {
                    case 'n':
                        printDeadEnds( (Rooms[i].doorPosition[j] + 5 + offset), (0 + yOffset), 0, -1, 3);
                        break;
                    case 's':
                        printDeadEnds((Rooms[i].doorPosition[j] + offset + 5) ,(Rooms[i].y - 1 + yOffset), 0, 1, 5);
                        break;
                    case 'w':
                        printDeadEnds((1 + 5 + offset), (Rooms[i].doorPosition[j] - 1 + yOffset), -1, 0, 3);
                        break;
                    case 'e':
                        printDeadEnds((Rooms[i].x - 1 + 5 + offset), (Rooms[i].doorPosition[j] - 1 + yOffset), 1, 0, 3);
                        break;
                }

            }

        }

    }

}
/*
void randomizeHallway(char ** roomMake[], room * Rooms)
{
    int yHall = 0;
    int xHall = 0;
    char charFind;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < Rooms[i].totalDoors; j++)
        {
            switch(Rooms[index].doorLocation[i]) == 'e')
            {
                case 'e':
                    while( != '|')
                    {
                      mvaddch( yHall, xHall,'#');
                    }
                    if ()
                    break;
            }
        }
    }
}
*/
void printDeadEnds(int startX, int startY, int xIncrement, int yIncrement, int randNum)
{
    move((startY), (startX));
    for(int i = 0; i < randNum; i++)
    { 
        startY = startY + yIncrement;
        startX = startX + xIncrement;
        mvaddch((startY), (startX), '#');
    }
}

//checks the input of what character the user typed and responds accordingly
//also deals with collision control to make sure the hero doesnt go through walls
//also contains conditions for numerous possible items that the user can run into
int checkInput(char input, int posY, int posX)
{
    char space;
    switch(input)
    {
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
        case 'p':
            return 7;
            break;
    }

    space = mvinch(posY, posX) & A_CHARTEXT;

    switch(space)
    {
        case '#':
            return 9;
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
        case '<':
            return 5;
        case '>':
            return 5;
        case '!':
            return 6;
        case ')':
            return 8;
        case '(':
            return 8;
        case ']':
            return 8;
        case ' ':
            return 0;
        case 'Z':
            return 10;
        case 'A':
            return 10;
        case 'B':
            return 10;
        case 'S':
            return 10;
        case 'T':
            return 10;
        default:
            return 1;
    }

    return 0;
}

//basic move function to move player around in rooms
void movePlayer(char input, int * posY, int * posX)
{
    switch(input)
    {
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

//seperate move function to handle moving around within hallways
void movePlayerInHallways(char input, int * posY, int * posX)
{
    switch(input)
    {
        case 'w':
            mvaddch(*posY, *posX, '#');
            *posY -= 1;
            break;
        case 'a':
            mvaddch(*posY, *posX, '#');
            *posX -= 1;
            break;
        case 's':
            mvaddch(*posY, *posX, '#');
            *posY += 1;
            break;
        case 'd':
            mvaddch(*posY, *posX, '#');
            *posX += 1;
            break;
        default:
            return;
    }
    mvaddch(*posY, *posX, '@');
    move(*posY, *posX);
}

int getMaxX(room * Rooms)
{
    int maxX = 0;
    for(int i = 0; i<6; i++)
    {
        if (Rooms[i].x > maxX)
        {
            maxX = Rooms[i].x;
        }
    }
    return maxX;
}

int getMaxY(room * Rooms)
{
    int maxY = 0;
    for(int i = 0; i<6; i++)
    {
        if (Rooms[i].y > maxY)
        {
            maxY = Rooms[i].y;
        }
    }
    return maxY;
}
int getMaxYRoom(room * Rooms, int x)
{
    int maxY = 0;
    maxY = Rooms[x].y;
    Rooms[x].y = maxY;

    return maxY;
}

int getMaxYTop(room * Rooms)
{
    int maxY = 0;
    for(int i = 0; i<3; i++)
    {
        if (Rooms[i].y > maxY)
        {
            maxY = Rooms[i].y;
        }
    }
    return maxY;
}

int getMaxYBot(room * Rooms)
{
    int maxY = 0;
    for(int i = 3; i<6; i++)
    {
        if (Rooms[i].y > maxY)
        {
            maxY = Rooms[i].y;
        }
    }
    return maxY;
}

int getTotalY(room * Rooms)
{
    int maxY = 0;
    int temp = 0;
    for(int i = 0; i<6; i++)
    {
        if (Rooms[i].y > maxY)
        {
            maxY = Rooms[i].y;
        }
        temp += maxY;
    }
    return temp;
}

int getTotalYTop(room * Rooms)
{
    int maxY = 0;
    int temp = 0;
    for(int i = 0; i<3; i++)
    {
        if (Rooms[i].y > maxY)
        {
            maxY = Rooms[i].y;
        }
        temp += maxY;
    }
    return temp;
}

int getTotalYBot(room * Rooms)
{
    int maxY = 0;
    int temp = 0;
    for(int i = 0; i<3; i++)
    {
        if (Rooms[i].y > maxY)
        {
            maxY = Rooms[i].y;
        }
        temp += maxY;
    }
    return temp;
}

int rightHallwayNum(room * Rooms)
{

    int maxYTop = 0;
    int maxYBot = 0;
    int tempTop = 0;
    int tempBot = 0;
    int finalTemp = 0;
    for(int i = 0; i<3; i++)
    {
        if (Rooms[i].y > maxYTop)
        {
            maxYTop = Rooms[i].y;
        }
        tempTop += maxYTop;
    }

    for(int i = 3; i<6; i++)
    {
        if (Rooms[i].y > maxYBot)
        {
            maxYBot = Rooms[i].y;
        }
        tempBot += maxYBot;
    }

    if(tempTop > tempBot)
    {
        finalTemp = tempTop;
    }
    else
    {
        finalTemp = tempBot;
    }

    return finalTemp;

}

//clears the notification line
void clearNotifyLine()
{
    move(0,0);
    clrtoeol();
}

//prints the status bar with all the player information in it
void getStatus(player Player, int x, int y)
{
    move(x, y);
    printw(" Health: %d | Potions: %d | Attack: %d | Inventory: %d/5 | Gold: %d ", Player.healthCount, Player.potionCount, Player.attackCount, Player.inventoryTotal, Player.goldTotal);
}

//initialises all the parts of the player struct to their starting amounts as specified by the requirements provided
void initPlayer(player * Player)
{
    Player->healthCount = 50;
    Player->goldTotal = 0;
    Player->potionCount = 1;
    Player->inventoryTotal = 0;
    Player->attackCount = 5;
}

void getNotification(int event, int subEvent, int var, char letter)
{
    switch (event) 
    {
        case 1: // picking up event
            switch (subEvent)
            {
                case 1:
                    move(0,0);
                    printw("Hero picked up a small gold pile of %d gold!", var);
                    break;
                case 2:
                    move(0,0);
                    printw("Hero picked up a large gold pile of %d gold!", var);
                    break;
                case 3:
                    move(0,0);
                    printw("Hero picked up a common weapon!");
                    break;
                case 4:
                    move(0,0);
                    printw("Hero picked up a rare weapon!");
                case 5:
                    move(0,0);
                    printw("Hero picked up equipment!");
                    break;
                default:
                    move(0,0);
                    printw("error");
                    break;
            }
            break;
        case 2: //bag full
            move(0,0);
            printw("Hero's stepped on %c and broke it", letter);
            break;
        case 3: // take damage
            move(0,0);
            printw("Hero has taken %d damage!", var);
        case 4: //give damage
            switch(subEvent)
            {
                case 1:
                    move(0,0);
                    printw("error");
                    break;
                case 2:
                    move(0,0);
                    printw("error");
                    break;
                case 3:
                    move(0,0);
                    printw("error");
                    break;
                case 4:
                    move(0,0);
                    printw("error");
                    break;
                default:
                    move(0,0);
                    printw("error");
                    break;
            }
            break;
        case 5: //kill
            switch(subEvent)
            {
                case 1:
                    move(0,0);
                    printw("error");
                    break;
                case 2:
                    move(0,0);
                    printw("error");
                    break;
                case 3:
                    move(0,0);
                    printw("error");
                    break;
                case 4:
                    move(0,0);
                    printw("error");
                    break;
                default:
                    move(0,0);
                    printw("error");
                    break;
            }
            break;
        case 6: //door
            switch(subEvent)
            {
                case 1:
                    move(0,0);
                    printw("error");
                    break;
                case 2:
                    move(0,0);
                    printw("error");
                    break;
                case 3:
                    move(0,0);
                    printw("error");
                    break;
                case 4:
                    move(0,0);
                    printw("error");
                    break;
                default:
                    move(0,0);
                    printw("error");
                    break;
            }
            break;
        case 7: //pot use 
            switch(subEvent)
            {
                case 1:
                    move(0,0);
                    printw("Hero already has full health");
                    break;
                case 2:
                    move(0,0);
                    printw("Hero used a potion to gain full health");
                    break;
            }
            break;
        case 8: //pot empty
            move(0,0);
            printw("Hero has no potions left");
            break;
    }
}

int midHallwayNum(room * Rooms)
{
    int midHallwayNum = 0;
    //int temp = 0;
    for(int i = 0; i<2; i++)
    {
        if (Rooms[i].y > midHallwayNum)
        {
            midHallwayNum = Rooms[i].y;
        }
        // temp += maxY;
    }
    midHallwayNum = midHallwayNum + 5;
    // move(0,50);
    //printw("second %d", midHallwayNum);
    return midHallwayNum;
}

//gets the x barring of the notifications
int getNotifyX(room * Rooms)
{
    int notifyX = 0;

    return notifyX;
}

//gets the y barring of the notifications
int getNotifyY(room * Rooms)
{

    int notifyY = 0;

    notifyY = ((getTotalY(Rooms)/2) + 5);
    //move(0,30);
    //  printw("thing: %d", notifyY);

    return notifyY;

}

//frees all the memory used to prevent memory leaks if only the program compiled on pi that is
void freeLevels(char ** curseRoom[], room * Rooms)
{
    for(int i=0;i<6;i++)
    {
        for(int j=0; j < Rooms[i].y; j++)
        {
            free(curseRoom[i][j]);   
        }
        free(curseRoom[i]);
    }
    //free(curseRoom);
}

void freeRoom (room * Rooms)
{
    for (int i = 0; i < 6; i++)
    {
        free(Rooms[i].roomItems);
        free(Rooms[i].doorPosition);
        free(Rooms[i].doorLocation);
    }
    free(Rooms);
}

//merely ends the game and gets out of ncurses
void endGame()
{
    endwin();
}
