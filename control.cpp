#include <iostream>
#include <string>
#include "struct.cpp"
#include "board.cpp"

using namespace std;

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

bool by_name(Card a, Card b){
    return a.name < b.name;
}

void print_hand(vector<Card> hand){
    sort(hand.begin(), hand.end(),by_name);
    for (int i=0; i<hand.size(); ++i){
        cout << "Your cards: " << hand[i].name<< "| "; 
    }
    cout <<endl;
}
