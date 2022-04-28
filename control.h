#ifndef CONTROL_H
#define CONTROL_H

bool move(int move_x, int move_y, int player_coord[2]);
void print_hand(character player);
bool card_count_not_zero(character player);
void place_card(character &player, char s);

#endif