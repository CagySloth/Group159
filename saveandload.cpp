#include "data_struct.h"
#include <fstream>

//mob =1 
//sbf = 234
//p = 9

void load(character &player, int board[][9])
{
    ifstream fin;
    fin.open("save.txt");
    if (fin.fail())
    {
        cout << "Welcome to (we need to think a name for the game). In this place, you goal is to survive as long as you can." << endl;
        cout << "You will be surrounded by monster trying to kill you, by killing monster, you may find useful item to help you survive." << endl;
        cout << "Now if you are ready, input your name to start the game!" << endl;
        cin >> player.name;
        cout << endl;
    }
    else
    {
        string player_name, equip_name, flag, descrip;
        getline(fin, player_name);
        player.name = player_name;
        fin >> player.day >> player.coord[0] >> player.coord[1] >> player. max_movement >> player.move_count >> player.max_health >> player.health >> player.regeneration >> player.attack >> player.attack_speed >> player.defense;
        //still working until here
        for (int i = 0; i < 4; ++i)
        {
            fin.ignore();
            getline(fin, equip_name);
            cout << equip_name << endl;
            player.equipment[i].name = equip_name;
            fin >> player.equipment[i].health >> player.equipment[i].attack >> player.equipment[i].attack_speed >> player.equipment[i].defense;
        }
        
        for (int i = 0; i < 20; ++i)
        {
            fin.ignore();
            getline(fin, flag);
            cout << flag << endl;
            if (flag == "end")
            {
                break;
            }
            else
            {
                accessories * p = new accessories;
                p->name = flag;
                fin.ignore();
                getline(fin, descrip);
                p->description = descrip;
                fin >> p->health >> p->attack >> p->defense;
                p->next = player.accessories;
                player.accessories = p;

                cout << "else " << descrip << endl;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            fin >> player.cards[i];
        }

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                fin >> board[i][j];
            }
        }
        string startgame;
        cout << "Welcome back " << player.name << "!" << endl;
        cout << "If you are ready, input anything to start the game!" << endl;
        cin >> startgame;
        cout << endl;
    }
    fin.close();
}

void save(const character player, int board[][9])
{
    ofstream fout;
    fout.open("save.txt");
    fout << player.name << endl << player.day << endl << player.coord[0] << endl << player.coord[1] << endl << player.max_movement << endl << player.move_count << endl << player.max_health << endl << player.health << endl << player.regeneration << endl << player.attack << endl << player.attack_speed << endl << player.defense << endl;
    for (int i = 0; i < 4; ++i)
    {
        fout << player.equipment[i].name << endl << player.equipment[i].health << endl << player.equipment[i].attack << endl << player.equipment[i].attack_speed << endl << player.equipment[i].defense << endl;
    }
    if (player.accessories != NULL)
    {
        struct accessories * current = player.accessories;
        while (current->next != NULL)
        {
            fout << current->name << endl << current->description << endl << current->health << endl << current->attack << endl << current->defense << endl;
            current = current->next;
        }
    }
    fout << "end" << endl;
    for (int i = 0; i < 3; ++i)
    {
        fout << player.cards[i] << endl;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            fout << board[i][j] << endl;
        }
    }
    fout.close();
}