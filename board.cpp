#include <iostream>
using namespace std;

void initBoard(int b[][9])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            b[i][j] = 0;
        }
    }
}

bool cardTile(int y, int x)
{
    if (x == 0 || x == 1 || y == 0 || y == 1 || x == 7 || x == 8)
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
    return false;
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

bool move(int move_x, int move_y, int player_coord[2]){
    
    int dest_x;
    int dest_y;
    dest_x = player_coord[0]+move_x;
    dest_y = player_coord[1]+move_y;

    if(neighbouring_tiles(dest_x,dest_y,player_coord) == true && validTile(dest_x,dest_y)){
        player_coord[0] = dest_x;
        player_coord[1] = dest_y;
        return true;
    }
    else{
        cout << "Invalid movement. Enter coordinates again." << endl;
        return false;
    }
}
