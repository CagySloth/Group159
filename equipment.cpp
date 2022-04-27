#include <iostream>
#include <cstdlib>
#include <ctime>
#include "struct.cpp"

void sword(character &player)
{
    struct 
}

void helmet(character &player)
{

}

void armor(character &player)
{

}

void boots(character &player)
{

}

void equipment_drop(character &player)
{
    srand(time(NULL));
    switch (rand() % 4)
    {
        case 0: //sword
            sword(player);
            break;
        case 1: //helmet
            helmet(player);
            break;
        case 2: //armor
            armor(player);
            break;
        case 3: //boots
            boots(player);
            break;
    }
}