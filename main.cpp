#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>
#include "mobs.h"
#include "board.h"

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
        cout << "Enter anythig to continue..." << endl;
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
        cout << "Enter anythig to continue..." << endl;
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
        cout << "Enter anythig to continue..." << endl;
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
        cout << "Enter anythig to continue..." << endl;
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
        cout << "Enter anythig to continue..." << endl;
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
        cout << "Enter anythig to continue..." << endl;
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
