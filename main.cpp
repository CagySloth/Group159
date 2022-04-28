#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>
#include "struct.h"
#include "board.h"
#include "combat.h"
#include "control.h"

using namespace std;
// number rep of mobs = 1
// number rep of {s,b,f} = {2,3,4}
// number rep of player = 9
int main()
{

    int board[9][9];
    initBoard(board); // set all entries = 0

    // set player initial location to (4,4)
    player.coord[0] = 4;
    player.coord[1] = 4;

    print_board(board, player);
    int moves_cnt = 0; // player move count
    int move_x = 0;
    int move_y = 0;
    int moving_path[2] = {};
    while (player.health != 0)
    {
        int numOfMobs = getMobsNum(board, moves_cnt);

        setMobsLoc(board, numOfMobs);
        print_board(board, player);

        cout << "Select your paths from here: {(1 1),(1 0),(1 -1),(0 1),(0 -1),(-1 1),(-1 0),(-1 -1)} " << endl;
        cout << "Enter your moving path:" << endl;
        cin >> move_x >> move_y;

        // player can move
        bool moving_state = move(move_x, move_y, player.coord);
        moves_cnt++;
        while (moving_state == false)
        {
            cin >> move_x >> move_y;
            moving_state = move(move_x, move_y, player.coord);
        }
        // enter combat flag
        bool enter_combat = enterCombat(board, player.coord[0], player.coord[1]);

        if (enter_combat == true)
        {
            combat(player);
            // space for accumulate player stats after receiving items/cards

            if (card_count_not_zero(player) == true)
            {
                cout << "Card placement round!" << endl;
                cout << "You may now place your cards (s: Shelter, b: Barracks, f: Forge)" << endl;
                cout << "Enter card tile's coordinates (Eg: 1 2)" << endl;
                cout << "Input should be in the following form: char x_coord y_coord" << endl;
                char card_command;
                int card_x_pos;
                int card_y_pos;
                cin >> card_command >> card_x_pos >> card_y_pos;

                bool placed_card = false; //flags for checking
                bool valid_coordinates = false;

                while (placed_card == false && valid_coordinates == false)
                {
                    if (card_command == 's' || card_command == 'b' || card_command == 'f')
                    {
                        valid_coordinates = cardTile(card_x_pos,card_y_pos); //update flag
                        placed_card = true;
                        place_card(player, card_command, card_x_pos, card_y_pos);
                        print_board(board, player);
                    }
                    else
                    {
                        cout << "Invalid card or coordinates. Enter again." << endl;
                        cin >> card_command >> card_x_pos >> card_y_pos;
                    }
                }
                enter_combat = false;
            }
        }

    reset_card_tile(board);

    }
}