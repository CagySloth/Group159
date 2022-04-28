#include <iostream>
#include <string>
#include "data_struct.h"
#include "board.h"

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

void update_player_coord_on_board(int b[][9],character player){
    int x = player.coord[0];
    int y = player.coord[1];
    b[x][y] == 9;
}




void place_card(int b[][9], char p, int x, int y){
    if(p == 's'){
        player.cards[0]--;
        b[x][y] == p;
    }
    else if (p == 'b'){
        player.cards[1]--;
        b[x][y] == p;
    }
    else if (p == 'f'){
        player.cards[2]--;
        b[x][y] == p;
    }
}


//include fog of war, cardtiles, player coord 
void print_board(int b[][9], character player){
    update_player_coord_on_board(b, player);
    for (int r=0; r<9; ++r){
        for (int c=0; c=9; ++c){
            if(cardTile(r,c)){
                cout << b[r][c] << " ";
            }
            else if(neighbouring_tiles(r,c, player.coord)){
                cout << b[r][c] << " ";
            }
        }
        cout << endl;
    }
    
}

void reset_card_tile(int b[][9]){
    vector<int> card_holder;
    for (int r=0; r<9; ++r){
        for (int c=0; c<9; ++c){
            if(cardTile(r,c)){
                //should pushback all card tiles
                card_holder.push_back(b[r][c]);
            }
        }
    }

    bool card_holder_full = true;

    //if one cardtiles value = 0 >> not full
    for (int i=0; i<card_holder.size(); ++i){
        if(card_holder[i] == 0){
            card_holder_full == false;
        }
    }
    //reset all cardtiles value = 0
    if (card_holder_full == false){
        for (int r =0; r<9; ++r){
            for (int c=0; c<9; ++c){
                if(cardTile(r,c)){
                    b[r][c] = 0;
                }
            }
        }
    }

}