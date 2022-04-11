#include <iostream>
#include <cstdlib>
#include <ctime>
#include "struct.cpp"

void cards(character player)
{
    srand(time(NULL));
    int idx;
    for (int i = 0; i < 20; ++i)
    {
        if (player.cards[i] == 0)
        {
            idx = i;
            break;
        }
    }
    player.cards[idx] = rand() % 3;
}