#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "data_struct.h"
using namespace std;



void initBoard(int b[][9])
{
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)
        {
            b[i][j] = 0;
        }
    }
}

// whether for placing cards
bool cardTile(int x, int y)
{

    if (x == 0 || x == 1 || y == 0 || y == 1 || y == 7 || y == 8)
    {
        return true;
    }

    return false;
}

// max: 8 possible points; min: 3 possible points
bool validTile(int pos_x, int pos_y)
{   if(cardTile(pos_x, pos_y) == true){
        return false;
    }
    else if(pos_x>=2 && pos_x<=8 && pos_y>=0 && pos_y<=8){
        return true;
    }
}

bool enterCombat(int b[][9],int pos_x, int pos_y){
    if(b[pos_x][pos_y] == 1){
        return true;
    }
    return false;
}


// return number of monsters to be spawned
int getMobsNum(int b[][9], int numOfMoves)
{
    srand(time(NULL));
    int currMobs = numOfMoves / 5;
    if (currMobs == 0)
    {
        currMobs = 1;
    }
    else
    {
        if (currMobs > maxMobs)
        {
            currMobs = maxMobs;
        }
    }
    int numOfMobs = rand() % currMobs + 2;
    return numOfMobs;
}

void setMobsLoc(int b[][9], int numOfMobs)
{
    srand(time(NULL));
    for (int i = 0; i < numOfMobs; ++i)
    {
        int x = rand() % 7 + 2;
        int y = rand() % 5 + 2;
        b[x][y] = 1;
    }
}

bool neighbouring_tiles(int x, int y, int coords[2]){
    int x_coord = coords[0];
    int y_coord = coords[1];

    if(x>1){
        if(y>1 && y<8){
            if(x-x_coord<=1 && x-x_coord>=-1){
                if(y-y_coord <= 1 && y-y_coord>=-1){
                    return true;
                }
            }
        }
    }
    return false;
}




