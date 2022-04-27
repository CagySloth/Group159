#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

const int boardSize = 9;
const int maxMobs = 15;

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
    else if(pos_x>=0 && pos_x<=8 && pos_y>=0 && pos_y<=8){
        return false;
    }
    return true;
}

bool enterCombat(int b[][9],int pos_x, int pos_y){
    if(b[pos_x][pos_y] == 1){
        return true;
    }
    return false;
}

void printBoard(int b[][9])
{
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
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
    int numOfMobs = rand() % currMobs;
    return numOfMobs;
}

void setMobsLoc(int b[][9], int numOfMobs)
{
    srand(time(NULL));
    for (int i = 0; i < numOfMobs; ++i)
    {
        int x = rand() % 9;
        int y = rand() % 9;
        b[x][y] = 1;
    }
}

bool neighbouring_tiles(int x, int y, int coords[2]){
    int x_coord = coords[0];
    int y_coord = coords[1];

    if(x_coord+1 == x && y_coord == y+1 && validTile(x,y)){
        return true;
    }
    if(x_coord+1 == x && y_coord == y && validTile(x,y)){
        return true;
    }
    if(x_coord+1 == x && y_coord == y-1 && validTile(x,y)){
        return true;
    }

    if(x_coord-1 == x && y_coord == y+1 && validTile(x,y)){
        return true;
    }
    if(x_coord-1 == x && y_coord == y && validTile(x,y)){
        return true;
    }
    if(x_coord-1 == x && y_coord == y-1 && validTile(x,y)){
        return true;
    }

    if(x_coord == x && y_coord == y+1 && validTile(x,y)){
        return true;
    }
    if(x_coord == x && y_coord == y && validTile(x,y)){
        return true;
    }
    if(x_coord == x && y_coord == y-1 && validTile(x,y)){
        return true;
    }
    return false;

}

//include fog of war
void print_board(int b[][9], int coord[2]){

    for (int r=0; r<9; ++r){
        for (int c=0; c=9; ++c){
            if(cardTile(r,c)){
                cout << b[r][c] << " ";
            }
            if(neighbouring_tiles(r,c, coord)){
                cout << b[r][c] << " ";
            }

        }
        cout << endl;
    }
}



