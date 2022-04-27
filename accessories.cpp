#include <iostream>
#include <cstdlib>
#include <ctime>
#include "struct.cpp"

void pickup(accessories * &ptr, accessories * &p)
{
    //interaction
    char option = ' ';
    cout << "The monster dropped something on the ground..." << endl;
    cout << p->description << endl;
    while (option != 'Y' || option != 'N')
    {
        cout << "Input 'Y' to pick it up or 'N' to leave it: ";
        cin >> option;
    }
    if (option == 'Y')
    {
        p->next = ptr;
        ptr = p;
        cout << "You picked up the " << p->name << "." << endl;
    }
    else
    {
        delete p;
        cout << "The mysterious item slowly fade away in the wind..." << endl;
    }
}

void health_accessories(accessories * &ptr, int d)
{
    accessories *p = new accessories;
    p->health = 30 + d * 3;
    p->attack = 0;
    p->defense = 0;
    p->next = NULL;
    srand(time(NULL));
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Vitus Essence Ring";
            break;
        case 1:
            p->name = "Blessed Crucifix";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "The item is looming in boiling blood.";
            break;
        case 1:
            p->description = "The item is surrounded by beaming flowers.";
            break;
    }
    //interaction
    pickup(ptr, p);
    cout << "Your health is increased by " << p->health << "HP." << endl;
}

void attack_accessories(accessories * ptr, int d)
{
    accessories *p = new accessories;
    p->health = 0;
    p->attack = 5 + d * 1;
    p->defense = 0;
    p->next = NULL;
    srand(time(NULL));
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Ares Ring";
            break;
        case 1:
            p->name = "Ring of the Sun";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "The item is burning in neverending flame.";
            break;
        case 1:
            p->description = "You can feel a suffocating heat from the item.";
            break;
    }
    //interaction
    pickup(ptr, p);
    cout << "Your attack is increase by " << p->attack << "." << endl;
}

void defense_accessories(accessories * ptr, int d)
{
    srand(time(NULL));
    accessories *p = new accessories;
    p->health = 0;
    p->attack = 0;
    p->defense = (rand() % 2) + (d % 3);
    p->next = NULL;
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Ring of Soteria";
            break;
        case 1:
            p->name = "Dragonscale Ring";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "You can hear a metallic sound resonating from the item.";
            break;
        case 1:
            p->description = "You can feel an ominous power from the item.";
            break;
    }
    //interaction
    pickup(ptr, p);
    cout << "Your defense is increased by " << p->defense << "." << endl;
}

void negative_health_accessories(accessories * ptr, int d)
{
    accessories *p = new accessories;
    p->health = -(20 + d * 4);
    p->attack = 0;
    p->defense = 0;
    p->next = NULL;
    srand(time(NULL));
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Serpant's Curse";
            break;
        case 1:
            p->name = "Dusk Crown";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "The item is looming in boiling blood.";
            break;
        case 1:
            p->description = "The item is surrounded by sere and dull plants.";
            break;
    }
    //interaction
    pickup(ptr, p);
    cout << "Your health is reduced by " << p->health * -1 << "HP." << endl;
}

void negative_attack_accessories(accessories * ptr, int d)
{
    accessories *p = new accessories;
    p->health = 0;
    p->attack = -(5 + d * 2);
    p->defense = 0;
    p->next = NULL;
    srand(time(NULL));
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Prisoner's Chain";
            break;
        case 1:
            p->name = "Bloodmoon Ring";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "You can feel an ominous power from the item.";
            break;
        case 1:
            p->description = "You can feel a suffocating heat from the item.";
            break;
    }
    //interaction
    pickup(ptr, p);\
    cout << "Your attack is reduced by " << p->attack * -1 << "." << endl;
}

void negative_defense_accessories(accessories * ptr, int d)
{
    accessories *p = new accessories;
    p->health = 0;
    p->attack = 0;
    p->defense = -(rand() % 2) + (d % 6);
    p->next = NULL;
    srand(time(NULL));
    //name
    switch (rand() % 2)
    {
        case 0:
            p->name = "Lamed Crucifix";
            break;
        case 1:
            p->name = "Hydra's Scale";
            break;
    }
    //description
    switch (rand() % 2)
    {
        case 0:
            p->description = "You can hear a metallic sound resonating from the item.";
            break;
        case 1:
            p->description = "You heard a loud screech, like if something hit your head.";
            break;
    }
    //interaction
    pickup(ptr, p);
    cout << "Your defense is reduced by " << p->defense * -1 << "." << endl;
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