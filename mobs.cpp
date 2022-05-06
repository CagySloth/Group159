#include <cmath>

const int maxMobs = 15;
bool enterCombat(int b[][9],int pos_x, int pos_y){
    if(b[pos_x][pos_y] == 1){
        return true;
    }
    return false;
}

// return number of monsters to be spawned
int getMobsNum(int b[][9], int numOfMoves)
{
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
    for (int i = 0; i < numOfMobs; ++i)
    {
        int x = rand() % 7 + 2;
        int y = rand() % 5 + 2;
        b[x][y] = 1;
    }
}
