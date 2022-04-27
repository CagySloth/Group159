#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "struct.cpp"
#include "board.cpp"

character player;

int main()
{
    int board [9][9];
    initBoard(board); // set all entries = 0 

    // set player initial location to (4,4)
    player.coord[0] = 4; 
    player.coord[1] = 4;
    int moves_cnt = 0; // player move count
    int day = 0; //day count

    while (player.health != 0){
        int numOfMobs = getMobsNum(board, moves_cnt);
        
        setMobsLoc(board, numOfMobs);
        
    }
}