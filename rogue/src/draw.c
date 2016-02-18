#include "draw.h"
#include "parse.h"

//calls the room print function to print all the rooms, makes sure to print them at an offset so they all dont print right next to eachother
//also handles the game loop that looks for user interaction and checks the input against another function to see how to respond
void initCurses(room * Rooms)
{
    char ** roomMake[6];
    char input, condition;
    int yRoom, xRoom;
    int charY = 5;
    int charX = 5;
    for (int i = 0; i < 6; i ++)
    {
        xRoom = Rooms[i].x;
        yRoom = Rooms[i].y;
        roomMake[i] = printRooms(yRoom,xRoom, Rooms, i);
    }



    initscr();
    noecho();

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
        if(condition == 1)
        {
            movePlayer(input,&charY,&charX);
        } 
        else if(condition == 2)
        {
            move(30, 0);
            printw("you pressed hit a wall");
        }
        move(charY, charX);
        refresh();
    }while(input != 'q');
    endGame();
    //freeLevels(roomMake[i], yVar);

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
/*
for(int i=0; i<3; i++)
{
	if((Rooms[index].door[i].doorLocation) == 'e')
	{
		curseRoom[Rooms[index].doorPosition[i].doorLocation][0] = '+';
	}
	else if((Rooms[index].totalDoors[i].doorLocation) == 'n')
	{
		curseRoom[Rooms[index].doorPosition[i].DoorLocation][0] = '+';
	}
	else if((Rooms[index].totalDoors[i].doorLocation) == 's')
	{
		curseRoom[Rooms[index].doorPosition[i].doorLocation][0] = '+';
	}
	else if((Rooms[index].totalDoors[i].doorLocation) == 'w')
	{
		curseRoom[Rooms[index].doorPosition[i].doorLocation][0] = '+';
	}

}
*/


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
//frees all the memory used to prevent memory leaks if only the program compiled on pi that is
/*
   void freeLevels(char ** curseRoom, int yVar)
   {
   int i = 0;
   for(int i=0;i<yVar;i++)
   {
   free(curseRoom[i]);
   }
   free(curseRoom);
   }
 */
 //merely ends the game and gets out of ncurses
void endGame(){
    endwin();
}
