#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

struct equipment
{
    string name;
    int health;
    int attack;
    int attack_speed;
    int defense;
    int movement;
    };


struct accessories
{
    string name;
    string description;
    int health;
    int attack;
    int defense;
    int movement;
    accessories * next;
};


struct character
{
    int day = 0;
    int coord[2] = {};
    int max_movement = 5;
    int max_health = 100;
    int health = 100;
    int regeneration = 0;
    int attack = 25;
    int attack_speed = 10;
    int defense = 0;
    equipment equipment[4] = {}; //weapon, helmet, armor, boots (increase number of movement per day)
    accessories * accessories = NULL;
    int cards[3] = {};
};

struct mob
{
    string name;
    int health;
    int attack;
    int attack_speed;
    int defense;
};