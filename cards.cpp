#include <iostream>
#include <cstdlib>
#include <ctime>
#include "data_struct.h"
using namespace std;

void card_drop(character &player)
{
    srand(time(NULL));
    cout << endl;
    int new_card = rand() % 3;
    player.cards[new_card]++;
    switch (new_card)
    {
        case 0:
            cout << "You got a 'Shelter' card!" << endl;
            break;
        case 1:
            cout << "You got a 'Barrack' card!" << endl;
            break;
        case 2:
            cout << "You got a 'Forge' card!" << endl;
            break;
    }
}