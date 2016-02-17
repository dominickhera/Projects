#include "draw.h"
#include <ncurses.h>

void initCurses(room * Rooms)
{
    char ** roomMake[5];

    char input = getch();
    int xRoom;
    int yRoom;
    int offset = 0;
    int maxTop = 0;
    
       for (int i = 0; i < 6; i ++)
       {
       xRoom = Rooms[i].x;
       yRoom = Rooms[i].y;
       roomMake[i] = printRooms(xRoom,yRoom, Rooms, i);
       }


        //roomMake = printRooms(xRoom, yRoom);

        initscr();
        noecho();

        for(int j=0;j<6;j++)
        {
            if(j<=2)
            {
                if(j == 0)
                {
                    maxTop = Rooms[j].y;
                    offset = 0;
                }
                else 
                {
                    offset = offset + (Rooms[j - 1].x + 6);
                    if(Rooms[j].y > maxTop)
                    {
                        maxTop = Rooms[j].y;
                    }
                }
                for(int i=0;i<Rooms[j].y;i++)
                {
                    for(int k=0;k<Rooms[z].y;i++)
                    {
                        mvaddch(i, k + offset, roomMake[j][i] [k]);
                    }
                }
            }
            else if(j>2 && j<6)
            {
                if(j == 3)
                {
                    offset = 0;
                }
                else if (j > 3)
                {
                    offset = offset + (Rooms[j - 1].x +6);
                }
                for(int i=0;i<Rooms[j].y;i++)
                {
                    for(int k=0;k<Rooms[j].y;k++)
                    {
                        mvaddch(i + (maxTop +6), k + offset, roomMake[j][i] [k]);
                    }
                }
            }
        }
/*
        for(int i=0;i<yRoom;i++)
        {
            for(int k=0;k<xRoom;k++)
            {
                mvaddch(i, k, roomMake[i] [k]);
            }
        }
*/
        refresh();

        while(input != 'q')
        {
            refresh();
            input = getch();
        }

        endGame();

        return;
    }



 char ** printRooms(int roomY, int roomX, room * Rooms, int index)     
    {
        char ** curseRoom;

        curseRoom = malloc(sizeof(char*) *yVar);

        if(curseRoom == NULL){
            printf("failed to allocate memory for your bitch ass room");
            exit(1);
        }

        for(int i=0;i<yVar;i++){
            curseRoom[i] = malloc(sizeof(char) *xVar);
            if(curseRoom == NULL) {
                printf("failed to allocate memory for your bitch ass room");
                exit(1);
            }
        }

        for(int i=0;i<xVar;i++){
            curseRoom[0] [i] = '-';
        }

        for(int i=0;i<xVar;i++){
            curseRoom[yVar - 1] [i] = '-';
        }

        for(int i=0;i<yVar;i++){
            curseRoom[i] [0] = '|';
        }

        for(int i=0;i<yVar;i++){
            curseRoom[i] [xVar - 1] = '|';
        }

        for(int i=1;i<yVar - 1;i++){
            for(int k=1;k<xVar - 1;k++){
                curseRoom[i] [k] = '.';
            }
        }

        /*
           for (int i = 3; i < 6; i ++)
           {
        //bottom row rows
        }


        for(int i=0;i<xVar;i++){
        curseRoom[0] [i] = '-';
        }

        for(int i=0;i<xVar;i++){
        curseRoom[yVar - 1] [i] = '-';
        }

        for(int i=0;i<yVar;i++){
        curseRoom[i] [0] = '|';
        }

        for(int i=0;i<yVar;i++){
        curseRoom[i] [xVar - 1] = '|';
        }

        for(int i=1;i<yVar - 1;i++){
        for(int k=1;k<xVar - 1;k++){
        curseRoom[i] [k] = '.';
        }
        }*/
        return curseRoom;





        //print items 

    }
    /*
       void printItems(){

       }*/

    void endGame()
    {
        endwin();
    }



