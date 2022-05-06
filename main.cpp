#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include "board.h"
#include "mobs.h"

using namespace std;

struct equipment
{
    string name = "";
    int health = 0;
    int attack = 0;
    int attack_speed = 0;
    int defense = 0;
};


struct accessories
{
    string name;
    string description;
    int health;
    int attack;
    int defense;
    accessories * next;
};

struct character
{
    string name;
    int day = 0;
    int coord[2];
    int max_movement = 5;
    int move_count = 0;
    int max_health = 100; //base stat
    int health = 100;
    int regeneration = 0; //base stat
    int attack = 25; //base stat
    int attack_speed = 10;
    int defense = 0; //base stat
    struct equipment equipment[4]; //weapon, helmet, armor, boots
    struct accessories * accessories = NULL;
    vector<int> cards;
};

struct character player;

void update_character_stat(character &player)
{
    const int equipment_count = 4;
    int temp_health = 100, temp_attack = 25, temp_defense = 0;
    //equipment
    for (int i = 0; i < equipment_count; ++i)
    {
        temp_health += player.equipment[i].health;
        temp_attack += player.equipment[i].attack;
        temp_defense += player.equipment[i].defense;
    }
    //accessories
    if (player.accessories != NULL)
    {
        accessories * current = player.accessories;
        temp_health += current->health;
        temp_attack += current->attack;
        temp_defense += current->defense;
        while (current->next != NULL)
        {
            current = current->next;
            temp_health += current->health;
            temp_attack += current->attack;
            temp_defense += current->defense;
        }
    }
    player.max_health = temp_health;
    player.attack = temp_attack;
    player.defense = temp_defense;
}

struct mob
{
    string name;
    int health;
    int attack;
    int attack_speed;
    int defense;
};

int board[9][9];

bool pickup(accessories * &ptr, accessories * &p)
{
    //interaction
    char option;
    cout << "The monster dropped something on the ground..." << endl;
    cout << p->description << endl;
    bool valid_option = false, picked;
    while (!valid_option)
    {
        cout << "Input 'Y' to pick it up or 'N' to leave it: ";
        cin >> option;
        cout << endl;
        if (option == 'Y')
        {
            valid_option = true;
            p->next = ptr;
            ptr = p;
            cout << "You picked up the " << p->name << "." << endl;
            picked = true;
            break;
        }
        else if (option == 'N')
        {
            valid_option = true;
            delete p;
            cout << "The mysterious item slowly fade away in the wind..." << endl;
            picked = false;
            break;
        }
        cout << "Invalid command. ";
    }
    return picked;
}

void health_accessories(accessories * &ptr, int d)
{
    accessories *p = new accessories;
    p->health = 30 + d * 3;
    p->attack = 0;
    p->defense = 0;
    p->next = NULL;
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Vitus Essence Ring";
            break;
        case 1:
            p->name = "Blessed Crucifix";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "The item is looming in boiling blood.";
            break;
        case 1:
            p->description = "The item is surrounded by beaming flowers.";
            break;
    }
    //interaction
    bool picked = pickup(ptr, p);
    if (picked)
    {
        cout << "Your health is increased by " << p->health << "HP." << endl;
        string continue_input;
        cout << "Enter anything to continue..." << endl;
        cin >> continue_input;
        cout << endl << endl;
    }
}

void attack_accessories(accessories * &ptr, int d)
{
    accessories *p = new accessories;
    p->health = 0;
    p->attack = 5 + d * 1;
    p->defense = 0;
    p->next = NULL;
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Ares Ring";
            break;
        case 1:
            p->name = "Celestial Ring";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "The item is burning in blazing flame.";
            break;
        case 1:
            p->description = "You can feel a suffocating heat from the item.";
            break;
    }
    //interaction
    bool picked = pickup(ptr, p);
    if (picked)
    {
        cout << "Your attack is increase by " << p->attack << "." << endl;
        string continue_input;
        cout << "Enter anything to continue..." << endl;
        cin >> continue_input;
        cout << endl << endl;
    }
}

void defense_accessories(accessories * &ptr, int d)
{
    accessories *p = new accessories;
    p->health = 0;
    p->attack = 0;
    p->defense = (rand() % 2) + (d % 3) + 2;
    p->next = NULL;
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Ring of Soteria";
            break;
        case 1:
            p->name = "Dragonscale Ring";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "You can hear a metallic sound resonating from the item.";
            break;
        case 1:
            p->description = "You can feel an ominous power from the item.";
            break;
    }
    //interaction
    bool picked = pickup(ptr, p);
    if (picked)
    {
        cout << "Your defense is increased by " << p->defense << "." << endl;
        string continue_input;
        cout << "Enter anything to continue..." << endl;
        cin >> continue_input;
        cout << endl << endl;
    }
}

void negative_health_accessories(accessories * &ptr, int d)
{
    accessories *p = new accessories;
    p->health = -(10 + d * 2);
    p->attack = 0;
    p->defense = 0;
    p->next = NULL;
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Serpant's Curse";
            break;
        case 1:
            p->name = "Dusk Crown";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "The item is looming in boiling blood.";
            break;
        case 1:
            p->description = "The item is surrounded by sere and dull plants.";
            break;
    }
    //interaction
    bool picked = pickup(ptr, p);
    if (picked)
    {
        cout << "Your health is reduced by " << p->health * -1 << "HP." << endl;
        string continue_input;
        cout << "Enter anything to continue..." << endl;
        cin >> continue_input;
        cout << endl << endl;
    }
}

void negative_attack_accessories(accessories * &ptr, int d)
{
    accessories *p = new accessories;
    p->health = 0;
    p->attack = -(2 + d);
    p->defense = 0;
    p->next = NULL;
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Prisoner's Chain";
            break;
        case 1:
            p->name = "Bloodmoon Ring";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "You can feel an ominous power from the item.";
            break;
        case 1:
            p->description = "You can feel a suffocating heat from the item.";
            break;
    }
    //interaction
    bool picked = pickup(ptr, p);
    if (picked)
    {
        cout << "Your attack is reduced by " << p->attack * -1 << "." << endl;
        string continue_input;
        cout << "Enter anything to continue..." << endl;
        cin >> continue_input;
        cout << endl << endl;
    }
}

void negative_defense_accessories(accessories * &ptr, int d)
{
    accessories *p = new accessories;
    p->health = 0;
    p->attack = 0;
    p->defense = -(rand() % 2) + (d % 6) + 1;
    p->next = NULL;
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Lamed Crucifix";
            break;
        case 1:
            p->name = "Hydra's Scale";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "You can hear a metallic sound resonating from the item.";
            break;
        case 1:
            p->description = "You heard a loud screech, like if something hit your head.";
            break;
    }
    //interaction
    bool picked = pickup(ptr, p);
    if (picked)
    {
        cout << "Your defense is reduced by " << p->defense * -1 << "." << endl;
        string continue_input;
        cout << "Enter anything to continue..." << endl;
        cin >> continue_input;
        cout << endl << endl;
    }
}

void accessories_drop(accessories * &ptr, int d)
{
    if (rand() % 4 != 0)
    {
        //positive
        switch (rand() % 3)
        {
            case 0:
                health_accessories(ptr, d);
                break;
            case 1:
                attack_accessories(ptr, d);
                break;
            case 2:
                defense_accessories(ptr, d);
                break;
        }
    }
    else
    {
        //negative
        switch (rand() % 3)
        {
            case 0:
                negative_health_accessories(player.accessories, player.day);
                break;
            case 1:
                negative_attack_accessories(player.accessories, player.day);
                break;
            case 2:
                negative_defense_accessories(player.accessories, player.day);
                break;
        }
    }
}

void sword(equipment equipment[], int d)
{
    switch (rand() % 8)
    {
        case 0:
            equipment[0].name = "Claymore";
            break;
        case 1:
            equipment[0].name = "Katana";
            break;
        case 2:
            equipment[0].name = "Broadsword";
            break;
        case 3:
            equipment[0].name = "Hand Axe";
            break;
        case 4:
            equipment[0].name = "Machete";
            break;
        case 5:
            equipment[0].name = "Greatsword";
            break;
        case 6:
            equipment[0].name = "Scythe";
            break;
        case 7:
            equipment[0].name = "Spear";
            break;
    }
    equipment[0].attack = 10 + d * 3;
    cout << "The monster dropped a " << equipment[0].name << "." << endl;
    cout << "You picked it up and replaced your old weapon with it." << endl;
}

void helmet(equipment equipment[], int d)
{
    switch (rand() % 4)
    {
        case 0:
            equipment[1].name = "Copper Helmet";
            break;
        case 1:
            equipment[1].name = "Steel Helmet";
            break;
        case 2:
            equipment[1].name = "Iron Helmet";
            break;
        case 3:
            equipment[1].name = "Tungsten Helmet";
            break;
    }
    equipment[1].defense = 1 + d/4;
    cout << "The monster dropped a " << equipment[1].name << "." << endl;
    cout << "You picked it up and replaced your old helmet with it." << endl;
}

void armor(equipment equipment[], int d)
{
    switch (rand() % 4)
    {
        case 0:
            equipment[2].name = "Copper Armor";
            break;
        case 1:
            equipment[2].name = "Steel Armor";
            break;
        case 2:
            equipment[2].name = "Iron Armor";
            break;
        case 3:
            equipment[2].name = "Tungsten Armor";
            break;
    }
    equipment[2].defense = 4 + d/4;
    cout << "The monster dropped a " << equipment[2].name << "." << endl;
    cout << "You picked it up and replaced your old armor with it." << endl;
}

void boots(equipment equipment[], int d)
{
    switch (rand() % 3)
    {
        case 0:
            equipment[3].name = "Leather Boots";
            break;
        case 1:
            equipment[3].name = "Turnshoes";
            break;
        case 2:
            equipment[3].name = "Ankle Boots";
            break;
    }
    equipment[3].defense = 2 + d/4;
    cout << "The monster dropped a pair of " << equipment[3].name << "." << endl;
    cout << "You picked it up and replaced your old boots with it." << endl;
}

void equipment_drop(equipment equipment[], int d)
{
    cout << endl;
    switch (rand() % 4)
    {
        case 0: //sword
            sword(equipment, d);
            break;
        case 1: //helmet
            helmet(equipment, d);
            break;
        case 2: //armor
            armor(equipment, d);
            break;
        case 3: //boots
            boots(equipment, d);
            break;
    }
    string continue_input;
    cout << "Enter anything to continue..." << endl;
    cin >> continue_input;
    cout << endl << endl;
}

void card_drop(character &player)
{
    cout << endl;
    int temp = rand() % 3;
    switch (temp)
    {
        case 0:
            cout << "You got a \"Shelter\" card!" << endl;
            player.cards[0]++;
            break;
        case 1:
            cout << "You got a \"Barrack\" card!" << endl;
            player.cards[1]++;
            break;
        case 2:
            cout << "You got a \"Forge\" card!" << endl;
            player.cards[2]++;
            break;
    }
}

void slime(character player, mob &monster)
{
    //slime high defense low attack
    monster.name = "slime";
    monster.health = 40 + player.day * 5;
    monster.attack = 5 + player.day * 3;
    monster.attack_speed = 12;
    monster.defense = 5 + player.day/3;
}

void skeleton(character player, mob &monster)
{
    //skeleton low defense low hp high attack
    monster.name = "skeleton";
    monster.health = 30 + player.day * 7;
    monster.attack = 7 + player.day * 3;
    monster.attack_speed = 6;
    monster.defense = 0;
}

void wolf(character player, mob &monster)
{
    //wolf low defense low hp high attack speed
    monster.name = "wolf";
    monster.health = 15 + player.day * 7;
    monster.attack = 3 + player.day * 1;
    monster.attack_speed = 4;
    monster.defense = 5;
}

//testing cards, remember to change back code
void loot(character &player)
{
    srand(time(NULL));
    int temp = rand() % 3;
    switch (temp)
    {
        case 0:
            equipment_drop(player.equipment, player.day);
            break;
        case 1:
            accessories_drop(player.accessories, player.day);
            break;
        case 2:
            card_drop(player);
            break;
    }
}

//monsters always moves before player

void combat(character &player)
{
    //randomize the monster type
    int temp = rand() % 3;
    struct mob monster;
    switch (temp)
    {
        case 0:
            slime(player, monster);
            break;
        case 1:
            skeleton(player, monster);
            break;
        case 2:
            wolf(player, monster);
            break;
    }
    //combat starts
    cout << "Monster Type: " << monster.name << endl;
    cout << "Monster Health: " << monster.health << endl;
    int time_counter = 0, dodge_rng;
    char move;

    cout << "The " << monster.name << " is approaching!" << endl;
    cout << "You can choose to attack it or try to dodge and heal yourself" << endl;
    cout << "Enter 'A' to attack and 'D' to dodge and heal, any other output will be interpreted as 'A':" << endl;
    cin >> move;
    cout << endl;

    while (monster.health > 0)
    {
        time_counter++;
        cout << endl;
        if (time_counter % monster.attack_speed == 0)
        {
            if (move != 'D')
            {
                player.health -= monster.attack - player.defense;
                cout << "You are attacked by the " << monster.name << endl;
            }      
            else
            {
                dodge_rng = rand() % 10;
                if (dodge_rng <= 1)
                {
                    player.health -= monster.attack - player.defense;
                    cout << "You failed to dodge the attack." << endl << endl;
                }
                else
                {
                    cout << "You successfully dodged the attack!" << endl << endl;
                }
            }      
        }
        if (player.health <= 0)
        {
            break;
        }
        if (time_counter % player.attack_speed == 0)
        {
            if (move != 'D')
            {
                monster.health -= player.attack - monster.defense;
                cout << "You attacked the " << monster.name << "." << endl << endl;
            }
            else
            {
                int regeneration = player.health/10;
                player.health += regeneration;
                cout << "You healed yourself for " << regeneration << "HPs." << endl << endl;
            }
            if (monster.health > 0)
            {
                cout << "Monster's health: " << monster.health << endl;
                cout << "Your health: " << player.health << endl;
                cout << "You can choose to attack it or try to dodge and heal yourself" << endl;
                cout << "Enter 'A' to attack and 'D' to dodge and heal, any other output will be interpreted as 'A':" << endl;
                cin >> move;
                cout << endl;
            }
        }
    }
    if (player.health > 0)
    {
        string continue_input;
        cout << "You won! You have killed the " << monster.name << "!" << endl << endl;
        cout << "Enter anything to see what the monster dropped..." << endl;
        cin >> continue_input;
        cout << endl << endl;
        loot(player);
    }
    else
    {
        cout << "You died, the " << monster.name << " destroyed you." << endl;
        //
    }
}

const int boardSize = 9;

/* //count of cards(global)
int shelter_count = player.cards[0];
int barrack_count = player.cards[1];
int forge_count = player.cards[2]; */

bool card_command_check(char card, character player)
{
    if (card == 'S')
    {
        if (player.cards[0] > 0)
        {
            return true;
        }
    }
    else if (card == 'B')
    {
        if (player.cards[1] > 0)
        {
            return true;
        }
    }
    else if (card == 'F')
    {
        if (player.cards[2] > 0)
        {
            return true;
        }
    }
    return false;
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
    
    if(p == 'S'){
        player.cards[0]--;
        b[x][y] = 2;
    }
    else if (p == 'B'){
        player.cards[1]--;
        b[x][y] = 3;
    }
    else if (p == 'F'){
        player.cards[2]--;
        b[x][y] = 4;
    }
}

void print_hand(vector<int> cards)
{
    cout << "You have " << cards[0] << " Shelters." << endl;
    cout << "You have " << cards[1] << " Barracks." << endl;
    cout << "You have " << cards[2] << " Forges." << endl;
}

//include fog of war, cardtiles, player coord 
void print_board(int b[][9], character player)
{
    update_player_coord_on_board(b, player);
    
    for (int r=0; r<9; ++r){
        for (int c=0; c<9; ++c){
            switch (b[r][c])
            {
                case 0:
                    cout << '-' << ' ';
                    break;
                case 1:
                    cout << 'M' << ' ';
                    break;
                case 2:
                    cout << 'S' << ' ';
                    break;
                case 3:
                    cout << 'B' << ' ';
                    break;
                case 4:
                    cout << 'F' << ' ';
                    break;
                case 9:
                    cout << 'P' << ' ';
                    break;
            }
        }
        cout << endl;
    }
    cout << "P: player's location  M: monster  S: shelter  B: barracks  F: forge  -: empty" << endl;
}

void print_board_card_placement(int b[][9], character player)
{
    update_player_coord_on_board(b, player);

    cout << "       Column" << endl;
    cout << "       0 1 2 3 4 5 6 7 8" << endl;
    for (int r=0; r<9; ++r)
    {
        if (r == 0)
        {
            cout << "Row  ";
        }
        else
        {
            cout << "     ";
        }
        cout << r << " ";
        for (int c=0; c<9; ++c)
        {
            //card tile
            if (r == 0 || r == 1 || c == 0 || c == 1 || c == 7 || c == 8)
            {
                switch (b[r][c])
                {
                    case 0:
                        cout << '_' << ' ';
                        break;
                    case 2:
                        cout << 'S' << ' ';
                        break;
                    case 3:
                        cout << 'B' << ' ';
                        break;
                    case 4:
                        cout << 'F' << ' ';
                        break;
                }
            }
            else
            {
                cout << 'X' << ' ';
            }
        }
        cout << endl;
    }
    cout << "_: valid location  X: invalid location  S: shelter  B: barracks  F: forge" << endl;

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

void display_player_stat(character &player)
{
    update_character_stat(player);
    for (int i=0; i<4; ++i)
    {
        if(player.equipment[i].name.length() == 0){
            player.equipment[i].name  = "Empty Slot";
        }
    }
    cout << "Your max health: " << player.max_health << endl;
    cout << "Your health: " << player.health << endl;
    cout << "Your attack: " << player.attack << endl;
    cout << "Your defense: " << player.defense << endl;
    cout << "Your equipments: " << player.equipment[0].name <<" | "<<  
    player.equipment[1].name<< " | " << player.equipment[2].name<<" | "<< player.equipment[3].name
    << endl;
    if(player.accessories != NULL)
    {
        cout << "Your accessories: ";
        struct accessories * current = player.accessories;
        int count = 1;
        while (true)
        {
            cout << current->name;
            if (count == 3)
            {
                cout << endl;
                count = 0;
            }
            else if (current->next == NULL)
            {
                cout << endl;
            }
            else if (current->next != NULL)
            {
                cout << " | ";
            }
            if (current->next != NULL)
            {
                current = current->next;
            }
            else
            {
                break;
            }
        }
    }
}

void stats_command(character &player)
{
    for (int i=0; i<4; ++i)
    {
        if(player.equipment[i].name.length() == 0){
            player.equipment[i].name  = "Empty Slot";
        }
    }
    cout << "Your max health: " << player.max_health << endl;
    cout << "Your health: " << player.health << endl;
    cout << "Your attack: " << player.attack << endl;
    cout << "Your defense: " << player.defense << endl;
    cout << "Your equipments: " << player.equipment[0].name <<" | "<< player.equipment[1].name<< " | " << player.equipment[2].name<<" | "<< player.equipment[3].name << endl;
    if(player.accessories != NULL)
    {
        cout << "Your accessories: ";
        struct accessories * current = player.accessories;
        int count = 1;
        while (true)
        {
            cout << current->name;
            if (count == 3)
            {
                cout << endl;
                count = 0;
            }
            else if (current->next == NULL)
            {
                cout << endl;
            }
            else if (current->next != NULL)
            {
                cout << " | ";
            }
            if (current->next != NULL)
            {
                current = current->next;
            }
            else
            {
                break;
            }
        }
    }
}

// copy to control.cpp
void restore_coords(int b[][9], character player, int prev_coord[2]){
    if(player.coord[0] != prev_coord[0] || player.coord[1] != prev_coord[1]){
        b[prev_coord[0]][prev_coord[1]] = 0;
    }
}


void save(const character player, int board[][9])
{
    ofstream fout;
    fout.open("save.txt");
    fout << player.name << endl << player.day << endl << player.coord[0] << endl << player.coord[1] << endl << player.max_movement << endl << player.move_count << endl << player.max_health << endl << player.health << endl << player.regeneration << endl << player.attack << endl << player.attack_speed << endl << player.defense << endl;
    for (int i = 0; i < 4; ++i)
    {
        fout << player.equipment[i].name << endl << player.equipment[i].health << endl << player.equipment[i].attack << endl << player.equipment[i].attack_speed << endl << player.equipment[i].defense << endl;
    }
    if (player.accessories != NULL)
    {
        struct accessories * current = player.accessories;
        while (current->next != NULL)
        {
            fout << current->name << endl << current->description << endl << current->health << endl << current->attack << endl << current->defense << endl;
            current = current->next;
        }
    }
    fout << "end" << endl;
    for (int i = 0; i < 3; ++i)
    {
        fout << player.cards[i] << endl;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            fout << board[i][j] << endl;
        }
    }
    fout.close();
}

void load(character &player, int board[][9])
{
    ifstream fin;
    fin.open("save.txt");
    if (fin.fail())
    {
        cout << "Welcome to Enslaved. In this place, you goal is to survive as long as you can." << endl;
        cout << "You will be surrounded by monster trying to kill you, by killing monster, you may find useful item to help you survive." << endl;
        cout << "Now if you are ready, enter your name to start the game!" << endl;
        cin >> player.name;
        cout << endl;
    }
    else
    {
        string player_name, equip_name, flag, descrip;
        getline(fin, player_name);
        player.name = player_name;
        fin >> player.day >> player.coord[0] >> player.coord[1] >> player. max_movement >> player.move_count >> player.max_health >> player.health >> player.regeneration >> player.attack >> player.attack_speed >> player.defense;
        //still working until here
        for (int i = 0; i < 4; ++i)
        {
            fin.ignore();
            getline(fin, equip_name);
            player.equipment[i].name = equip_name;
            fin >> player.equipment[i].health >> player.equipment[i].attack >> player.equipment[i].attack_speed >> player.equipment[i].defense;
        }
        
        for (int i = 0; i < 20; ++i)
        {
            fin.ignore();
            getline(fin, flag);
            if (flag == "end")
            {
                break;
            }
            else
            {
                accessories * p = new accessories;
                p->name = flag;
                fin.ignore();
                getline(fin, descrip);
                p->description = descrip;
                fin >> p->health >> p->attack >> p->defense;
                p->next = player.accessories;
                player.accessories = p;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            fin >> player.cards[i];
        }

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                fin >> board[i][j];
            }
        }
        string startgame;
        cout << "Welcome back " << player.name << "!" << endl;
        cout << "If you are ready, enter anything to start the game!" << endl;
        cin >> startgame;
        cout << endl;
    }
    fin.close();
}

int main()
{
    srand(time(NULL));
    
    int board[9][9];
    initBoard(board); // set all entries = 0

    for (int i=0; i<3; ++i){
        player.cards.push_back(0);
    }
    int prev_player_coord[2] = {};

    // set player initial location to (4,4)
    player.coord[0] = 4;
    player.coord[1] = 4;

    load(player, board);

    string command;
    int move_x = 0, move_y = 0;
    int moving_path[2] = {};
    while (player.health > 0)
    {
        int numOfMobs = getMobsNum(board, player.move_count);
        setMobsLoc(board, numOfMobs);
        cout << "------------------" <<endl;
        print_board(board, player);
        cout << "------------------" <<endl;

        prev_player_coord[0] = player.coord[0];
        prev_player_coord[1] = player.coord[1];

        cout << "Select your paths from here:" << endl << endl;
        cout << "UL = Up Left    U = Up    UR = Up Right" << endl;
        cout << "L  = Left                 R  = Right" << endl;
        cout << "DL = Down Left  D = Down  DR = Down Right" << endl << endl;
        cout << "Or enter \"EXIT\" to leave the game and \"STATS\" to see your character statistics" << endl;
        cout << "Enter your moving path:" << endl;
        
        bool moving_state = false;
        
        while (!moving_state)
        {
            cin >> command;
            cout << endl;
            if (command == "EXIT")
            {
                save(player, board);
                return 0;
            }
            else if (command == "STATS")
            {
                cout << "You have survived " << player.day << " days." << endl;
                stats_command(player);
            }
            else
            {
                if (command == "UL")
                {
                    move_y = -1;
                    move_x = -1;
                }
                if (command == "U")
                {
                    move_y = 0;
                    move_x = -1;
                }
                if (command == "UR")
                {
                    move_y = 1;
                    move_x = -1;
                }
                if (command == "L")
                {
                    move_y = -1;
                    move_x = 0;
                }
                if (command == "R")
                {
                    move_y = 1;
                    move_x = 0;
                }
                if (command == "DL")
                {
                    move_y = -1;
                    move_x = 1;
                }if (command == "D")
                {
                    move_y = 0;
                    move_x = 1;
                }
                if (command == "DR")
                {
                    move_y = 1;
                    move_x = 1;
                }
            }
            if (move(move_x, move_y, player.coord) == true)
            {
                break;
            }
        }
        // player can move
        
        player.move_count++;
        if (player.move_count == 5)
        {
            player.day++;
            player.move_count = 0;
            player.health += player.max_health/3;
            if (player.health >= player.max_health)
            {
                player.health = player.max_health;
            }
            cout << endl << endl << "You have survived " << player.day << " days." << endl << endl;
        }

        cout << endl << endl;
        restore_coords(board, player, prev_player_coord);
        // enter combat flag
        bool enter_combat = enterCombat(board, player.coord[0], player.coord[1]);

        if (enter_combat == true)
        {
            combat(player);
            // space for accumulate player stats after receiving items/cards

            if (card_count_not_zero(player) == true)
            {
                cout << "Card placement round!" << endl;
                print_hand(player.cards);
                cout << "You may now place your cards (S: Shelter, B: Barracks, F: Forge)." << endl;
                cout << "Enter the card you wish to place: S or B or F" << endl;
                char card_command;
                bool card_command_valid = false;
                while (!card_command_valid)
                {
                    cin >> card_command;
                    if (card_command == 'S' || card_command == 'B' || card_command == 'F')
                    {
                        card_command_valid = card_command_check(card_command, player);
                        if (card_command_valid == false)
                        {
                            cout << endl << "You do not have that card yet! Pick another one!" << endl;
                            cout << "Enter the card you wish to place: S or B or F" << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid command!" << endl;
                        cout << "Enter the card you wish to place: S or B or F" << endl;
                    }
                }
                cout << endl;
                int row, col;
                bool coord_valid = false;
                while (!coord_valid)
                {
                    print_board_card_placement(board, player);
                    cout << "Enter the row you wish to place your card on:" << endl;
                    cin >> row;
                    cout << "Enter the column you wish to place your card on:" << endl;
                    cin >> col;
                    if (cardTile(row, col))
                    {
                        coord_valid = true;
                        place_card(board, card_command, row, col);
                    }
                    else
                    {
                        cout << "Invalid coordinates!" << endl;
                    }
                }
                enter_combat = false;
            }
        }
    }
    if (player.health <= 0)
    {
        remove("save.txt");
        cout << "Your character data has been deleted." << endl;
    }
    else
    {
        update_character_stat(player);
        reset_and_update_card_tile(board, player);
        display_player_stat(player);
        save(player, board);
    }
    return 0;
}