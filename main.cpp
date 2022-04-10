#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "combat.cpp"
#include "equipment.cpp"
#include "accessories.cpp"

struct character
{
    int day = 0;
    int coord[2] = {4, 4};
    int max_movement = 5;
    int max_health = 100;
    int health = 100;
    int regeneration = 0;
    int attack = 25;
    int attack_speed = 1;
    int defense = 0;
    int equipment[4] = {}; //weapon, helmet, armor, boots (increase number of movement per day)
    int accessories[20] = {};
    int cards[10] = {};
};

struct mob
{
    int health;
    int attack;
    int attack_speed;
    int defense;
};

character player;

int main()
{

}