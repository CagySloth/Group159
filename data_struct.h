#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct equipment
{
    string name = "";
    int health = 0;
    int attack = 0;
    int attack_speed = 0;
    int defense = 0;
    int movement = 0;
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
    int day = 0;
    int coord[2];
    int max_movement = 5;
    int max_health = 100; //base stat
    int health = 100;
    int regeneration = 0; //base stat
    int attack = 25; //base stat
    int attack_speed = 10;
    int defense = 0; //base stat
    struct equipment equipment[4]; //weapon, helmet, armor, boots
    struct accessories * accessories = NULL;
    vector<int> cards = {0, 0, 0};
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
    //cards
    
}

struct mob
{
    string name;
    int health;
    int attack;
    int attack_speed;
    int defense;
};


#endif