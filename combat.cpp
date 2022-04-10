#include <iostream>
#include <cstdlib>
#include <ctime>
#include "main.cpp"
#include "equipment.cpp"
#include "accessories.cpp"

using namespace std;

int monster_type = 3; //can adjust later

void slime(character player, mob monster)
{
    //slime high defense low attack
    monster.health = 40 + player.day * 5;
    monster.attack = 20 + player.day * 3;
    monster.attack_speed = 1.2;
    monster.defense = 10 + player.day * 1;
}

void skeleton(character player, mob monster)
{
    //skeleton low defense low hp high attack
    monster.health = 30 + player.day * 4;
    monster.attack = 30 + player.day * 4;
    monster.attack_speed = 1;
    monster.defense = 0;
}

void wolf(character player, mob monster)
{
    //wolf low defense low hp high attack speed;
    monster.health = 15 + player.day * 3;
    monster.attack = 10 + player.day * 2;
    monster.attack_speed = 0.4;
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
        case 2:
            accessories(player);
            break;
    }
}

//monsters always moves before player

void combat(character player)
{
    srand(time(NULL));
    int temp = rand() % monster_type;
    mob monster;
    string monster_name;
    switch (temp)
    {
        case 0:
            slime(player, monster);
            monster_name = "slime";
            break;
        case 1:
            skeleton(player, monster);
            monster_name = "skeleton";
            break;
        case 2:
            wolf(player, monster);
            monster_name = "wolf";
            break;
    }
    //combat starts
    cout << "Monster Type: " << monster_name << endl;
    cout << "Monster Health: " << monster.health << endl;
    double time_counter = 0;
    while (monster.health > 0)
    {
        time_counter += 0.1;
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
        cout << "You won! You have killed the " << monster_name << "!";
        loot(player);
    }
    else
    {
        cout << "You died, the " << monster_name << " destroyed you.";
    }
}