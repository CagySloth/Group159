#include "data_struct.h"
#include <fstream>

void save(){
    
    ofstream fout;
    fout.open("savefile.txt");
    if(fout.fail()){
        cout << "error in opening file" << endl;
        exit(1);
    }

    //board
    for(int i=0; i<9 ; ++i){
        for (int j=0; j<9; ++j){
            fout << board[i][j] << " ";
        }
    }
    fout << endl;

    fout << player.coord[0] << player.coord[1] << player.max_movement << player.max_health 
    << player.health << player.regeneration << player.attack << player.attack_speed
    << player.defense << endl;

    for (int i=0; i<4 ; ++i){
        fout << player.equipment[i].name << player.equipment[i].health
        << player.equipment[i].attack << player.equipment[i].attack_speed
        << player.equipment[i].defense << player.equipment[i].movement;
    }
    fout << endl;

    fout << player.accessories->name << player.accessories->description << player.accessories->health
    << player.accessories->attack << player.accessories->defense << endl;



}

void load(){

}