#include <iostream>
#include <cstdlib>
#include <ctime>
#include "struct.cpp"

void sword(equipment equipment[], int d)
{
    srand(time(NULL));
    switch (rand() % 8)
    {
        case 0:
            equipment[0].name = "Claymore";
            break;
        case 1:
            equipment[0].name = "Katana";
            break;
        case 2:
            equipment[0].name = "Broadsword";
            break;
        case 3:
            equipment[0].name = "Hand Axe";
            break;
        case 4:
            equipment[0].name = "Machete";
            break;
        case 5:
            equipment[0].name = "Greatsword";
            break;
        case 6:
            equipment[0].name = "Scythe";
            break;
        case 7:
            equipment[0].name = "Spear";
            break;
    }
    equipment[0].attack = 10 + d * 3;
    cout << "The monster dropped a " << equipment[0].name << "." << endl;
    cout << "You picked it up and replaced your old weapon with it." << endl;
}

void helmet(equipment equipment[], int d)
{
    srand(time(NULL));
    switch (rand() % 4)
    {
        case 0:
            equipment[1].name = "Copper Helmet";
            break;
        case 1:
            equipment[1].name = "Steel Helmet";
            break;
        case 2:
            equipment[1].name = "Iron Helmet";
            break;
        case 3:
            equipment[1].name = "Tungsten Helmet";
            break;
    }
    equipment[1].defense = 1 + d/4;
    cout << "The monster dropped a " << equipment[0].name << "." << endl;
    cout << "You picked it up and replaced your old helmet with it." << endl;
}

void armor(equipment equipment[], int d)
{
    srand(time(NULL));
    switch (rand() % 4)
    {
        case 0:
            equipment[2].name = "Copper Armor";
            break;
        case 1:
            equipment[2].name = "Steel Armor";
            break;
        case 2:
            equipment[2].name = "Iron Armor";
            break;
        case 3:
            equipment[2].name = "Tungsten Armor";
            break;
    }
    equipment[2].defense = 4 + d/4;
    cout << "The monster dropped a " << equipment[0].name << "." << endl;
    cout << "You picked it up and replaced your old armor with it." << endl;
}

void boots(equipment equipment[], int d)
{
    srand(time(NULL));
    switch (rand() % 4)
    {
        case 0:
            equipment[3].name = "Leather Boots";
            break;
        case 1:
            equipment[3].name = "Turnshoes";
            break;
        case 2:
            equipment[3].name = "Ankle Boots";
            break;
    }
    equipment[3].defense = 2 + d/4;
    cout << "The monster dropped a pair of " << equipment[0].name << "." << endl;
    cout << "You picked it up and replaced your old boots with it." << endl;
}

void equipment_drop(character &player)
{
    srand(time(NULL));
    switch (rand() % 4)
    {
        case 0: //sword
            sword(player.equipment, player.day);
            break;
        case 1: //helmet
            helmet(player.equipment, player.day);
            break;
        case 2: //armor
            armor(player.equipment, player.day);
            break;
        case 3: //boots
            boots(player.equipment, player.day);
            break;
    }
}