#include "data_struct.h"
#include "board.h"

using namespace std;


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


void print_hand(character player){

    cout << "You have " << player.cards[0] << " Shelters." << endl;
    cout << "You have " << player.cards[1] << " Barracks." << endl;
    cout << "You have " << player.cards[2] << " Forges." << endl;
}

bool card_count_not_zero(character player){
    int sum = 0;
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
    b[x][y] = 9;
}


void place_card(int b[][9], char p, int x, int y){
    
    if(p == 's'){
        player.cards[0]--;
        b[x][y] = 2;
    }
    else if (p == 'b'){
        player.cards[1]--;
        b[x][y] = 3;
    }
    else if (p == 'f'){
        player.cards[2]--;
        b[x][y] = 4;
    }
}


//include fog of war, cardtiles, player coord 
void print_board(int b[][9], character player){
    
    update_player_coord_on_board(b, player);
    
    for (int r=0; r<9; ++r){
        for (int c=0; c<9; ++c){
            /* if(cardTile(r,c)){
                cout << b[r][c] << " ";
            }
            else if(neighbouring_tiles(r,c, player.coord)){
                cout << b[r][c] << " ";
            }
            if (!cardTile(r,c)){
                cout << b[r][c] << " ";
            } */
            cout << b[r][c] << " ";
        }
        cout << endl;
    }
    
}

void card_detection(int b[][9], character &player, int r, int c){
    //sbf = 234
    if(b[r][c] == 2){
        if(b[r+1][c]==2 || b[r+1][c+1]==2 || b[r+1][c-1]==2 
        || b[r][c+1]==2 || b[r][c-1]==2 || b[r-1][c+1]==2 
        || b[r-1][c]==2 || b[r-1][c-1]==2){
            player.health++;
        }
    }
    if(b[r][c] == 3){
        if(b[r+1][c]==3 || b[r+1][c+1]==3 || b[r+1][c-1]==3 
        || b[r][c+1]==3 || b[r][c-1]==3 || b[r-1][c+1]==3 
        || b[r-1][c]==3 || b[r-1][c-1]==3){
            player.attack++;
        }
    }
    if(b[r][c] == 4){
        if(b[r+1][c]==4 || b[r+1][c+1]==4 || b[r+1][c-1]==4 
        || b[r][c+1]==4 || b[r][c-1]==4 || b[r-1][c+1]==4 
        || b[r-1][c]==4 || b[r-1][c-1]==4){
            player.defense++;
        }
    }
}

void reset_and_update_card_tile(int b[][9], character &player){
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
            card_holder_full = false;
        }
    }
    

    //update player stats
    if (card_holder_full == true){
        for (int r=0; r<9; ++r){
            for (int c=0; c<9; ++c){
                if(cardTile(r,c)){
                    card_detection(b, player, r, c);
                }
            }
        }
    }

    //reset cardtile
    if (card_holder_full == true){
        for (int r =0; r<9; ++r){
            for (int c=0; c<9; ++c){
                if(cardTile(r,c)){
                    b[r][c] = 0;
                }
            }
        }
        card_holder_full = false;
    }

}
void display_player_stat(character &player){
    update_character_stat(player);
    for (int i=0; i<4; ++i){
        if(player.equipment[i].name.length() == 0){
            player.equipment[i].name  = "Empty Slot";
        }
    }
    cout << "Your max health: " << player.max_health << endl;
    cout << "Your health: " << player.health << endl;
    cout << "Your attack: " << player.attack << endl;
    cout << "Your defense: " << player.defense << endl;
    cout << "Your equipments: " << player.equipment[0].name <<" "<<  
    player.equipment[1].name<<" " << player.equipment[2].name<<" "<< player.equipment[3].name
    << endl;
    if(player.accessories != NULL){
    cout << "Your accessories: " << player.accessories->name << endl;}
}

void restore_coords(int b[][9], character player, int prev_coord[2]){
    if(player.coord[0] != prev_coord[0] || player.coord[1] != prev_coord[1]){
        b[prev_coord[0]][prev_coord[1]] = 0;
    }
}