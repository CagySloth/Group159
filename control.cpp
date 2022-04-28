#include <iostream>
#include <string>
#include "struct.cpp"
#include "board.cpp"

using namespace std;
//count of cards(global)
int shelter_count = player.cards[0];
int barrack_count = player.cards[1];
int forge_count = player.cards[2];

bool move(int move_x, int move_y, int player_coord[2]){
    
    int dest_x;
    int dest_y;
    dest_x = player_coord[0]+move_x;
    dest_y = player_coord[1]+move_y;

    if(neighbouring_tiles(dest_x,dest_y,player_coord) == true){
        player_coord[0] = dest_x;
        player_coord[1] = dest_y;
        return true;
    }
    else{
        cout << "Invalid movement. Enter coordinates again." << endl;
        return false;
    }
    
}


void print_hand(character player){

    cout << "You have " << shelter_count << " Shelters." << endl;
    cout << "You have " << barrack_count << " Barracks." << endl;
    cout << "You have " << forge_count << " Forges." << endl;
}

bool card_count_not_zero(character player){
    int sum;
    for (int i=0; i<3; ++i){
        sum += player.cards[i];
    }
    if(sum == 0){
        return false;
    }
    return true;
}



void place_card(character &player, char s){
    if(s == 's'){
        player.cards[0]--;

    }
    else if (s == 'b'){

    }
    else if (s == 'f'){

    }
}