#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include "struct.cpp"
#include "board.cpp"
#include "combat.cpp"
#include "movement.cpp"

using namespace std;
character player;

int main()
{
    
    int board [9][9];
    initBoard(board); // set all entries = 0 

    // set player initial location to (4,4)
    player.coord[0] = 4; 
    player.coord[1] = 4;

    int moves_cnt = 0; // player move count
    int move_x = 0;
    int move_y = 0;
    int moving_path[2] = {};
    while (player.health != 0){
        int numOfMobs = getMobsNum(board, moves_cnt);
        
        setMobsLoc(board, numOfMobs);
        print_board(board, player.coord);

        
        cout <<"Select your paths from here: {(1 1),(1 0),(1 -1),(0 1),(0 -1),(-1 1),(-1 0),(-1 -1)} "<<endl;
        cout <<"Enter your moving path:" <<endl;
        cin >> move_x >> move_y;

        //player can move
        bool moving_state = move(move_x, move_y, player.coord);
        moves_cnt++;
        while (moving_state == false){
            cin >> move_x >> move_y;
            moving_state = move(move_x, move_y, player.coord);
        }


        if(enterCombat(board, player.coord[0], player.coord[1]) == true){
            combat(player);
        }


        

    



    }
}