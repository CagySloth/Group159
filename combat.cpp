#include <cstdlib>
#include <ctime>
#include "data_struct.h"
#include "equipment.h"
#include "accessories.h"
#include "cards.h"

using namespace std;

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
    srand(time(NULL));
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
    cout << "Input 'A' to attack and 'D' to dodge and heal, any other output will be interpreted as 'A': ";
    cin >> move;
    cout << endl;

    while (monster.health > 0)
    {
        time_counter++;
        if (time_counter % monster.attack_speed == 0)
        {
            if (move != 'D')
            {
                player.health -= monster.attack - player.defense;
                cout << "You are attacked by the " << monster.name << endl;
            }      
            else
            {
                srand(time(NULL));
                dodge_rng = rand() % 10;
                if (dodge_rng <= 1)
                {
                    player.health -= monster.attack - player.defense;
                    cout << "You failed to dodge the attack." << endl;
                }
                else
                {
                    cout << "You successfully dodged the attack!" << endl;
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
                cout << "You attacked the " << monster.name << "." << endl;
            }
            else
            {
                int regeneration = player.health/10;
                player.health += regeneration;
                cout << "You healed yourself for " << regeneration << "HPs." << endl;
            }
            if (monster.health > 0)
            {
                cout << "Monster's health: " << monster.health << endl;
                cout << "Your health: " << player.health << endl;
                cout << "You can choose to attack it or try to dodge and heal yourself" << endl;
                cout << "Input 'A' to attack and 'D' to dodge and heal, any other output will be interpreted as 'A': ";
                cin >> move;
                cout << endl;
            }
        }
    }
    if (player.health > 0)
    {
        cout << "You won! You have killed the " << monster.name << "!" << endl;
        cout << endl;
        loot(player);
    }
    else
    {
        cout << "You died, the " << monster.name << " destroyed you." << endl;
        //
    }
}
