#include <iostream>
#include <cstdlib>
#include <ctime>
#include "struct.cpp"
#include "equipment.cpp"
#include "accessories.cpp"
#include "cards.cpp"

using namespace std;

int monster_type = 3; //can adjust later

void slime(character player, mob monster)
{
    //slime high defense low attack
    monster.name = "slime";
    monster.health = 40 + player.day * 5;
    monster.attack = 20 + player.day * 3;
    monster.attack_speed = 12;
    monster.defense = 10 + player.day * 1;
}

void skeleton(character player, mob monster)
{
    //skeleton low defense low hp high attack
    monster.name = "skeleton";
    monster.health = 30 + player.day * 4;
    monster.attack = 30 + player.day * 4;
    monster.attack_speed = 1;
    monster.defense = 0;
}

void wolf(character player, mob monster)
{
    //wolf low defense low hp high attack speed
    monster.name = "wolf";
    monster.health = 15 + player.day * 3;
    monster.attack = 10 + player.day * 2;
    monster.attack_speed = 4;
    monster.defense = 5;
}

void loot(character player)
{
    srand(time(NULL));
    int temp = rand() % 3;
    switch (temp)
    {
        case 0:
            equipment(player);
            break;
        case 1:
            accessories(player);
            break;
        case 2:
            cards(player);
            break;
    }
}

//monsters always moves before player

void combat(character player)
{
    //randomize the monster type
    srand(time(NULL));
    int temp = rand() % monster_type;
    mob monster;
    string monster_name;
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
    cout << "Monster Type: " << monster_name << endl;
    cout << "Monster Health: " << monster.health << endl;
    int time_counter = 0;
    while (monster.health > 0)
    {
        time_counter++;
        if (time_counter % monster.attack_speed == 0)
        {
            player.health -= monster.attack - player.defense;
            cout << "The " << monster_name << " dealt " << monster.attack - player.defense << " damage to you!" << endl;
            cout << "Your health: " << player.health << endl;
            cout << "Monster's health: " << monster.health << endl;
        }
        if (player.health <= 0)
        {
            break;
        }
        if (time_counter % player.attack_speed == 0)
        {
            monster.health -= player.attack - monster.defense;
            cout << "You dealt " << player.attack - monster.defense << " damage to the " << monster_name << "!" << endl;
            cout << "Your health: " << player.health << endl;
            cout << "Monster's health: " << monster.health << endl;
        }
    }
    if (player.health > 0)
    {
        cout << "You won! You have killed the " << monster.name << "!";
        loot(player);
    }
    else
    {
        cout << "You died, the " << monster.name << " destroyed you.";
        //
    }
}