#ifndef DATA_STRUCT
#define DATA_STRUCT

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
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

struct mob
{
    string name;
    int health;
    int attack;
    int attack_speed;
    int defense;
};

int board[9][9];
const int boardSize = 9;
const int maxMobs = 15;
character player;


#endif