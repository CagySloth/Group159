#include <iostream>
#include <cstdlib>
#include <ctime>
#include "struct.cpp"

void health_accessories(accessories * ptr, int d)
{
    accessories *p = new accessories;
    p->health = 30 + d * 3
    p->attack = 0;
    
}

void attack_accessories(accessories * ptr, int d)
{

}

void defense_accessories(accessories * ptr, int d)
{

}

void negative_health_accessories(accessories * ptr, int d)
{

}

void negative_attack_accessories(accessories * ptr, int d)
{

}

void negative_defense_accessories(accessories * ptr, int d)
{

}

void accessories_drop(character &player)
{
    srand(time(NULL));
    if (rand() % 4 != 0)
    {
        //positive
        switch (rand() % 3)
        {
            case 0:
                health_accessories(player.accessories, player.day);
                break;
            case 1:
                attack_accessories(player.accessories, player.day);
                break;
            case 2:
                defense_accessories(player.accessories, player.day);
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