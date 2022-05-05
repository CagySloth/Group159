#ifndef CONTROL_H
#define CONTROL_H

bool move(int move_x, int move_y, int player_coord[2]);
void print_hand(character player);
bool card_count_not_zero(character player);
void update_player_coord_on_board(int b[][9],character player);
void place_card(int b[][9], char p, int x, int y);
void print_board(int b[][9], character player);
void card_detection(int b[][9], character &player, int r, int c);
void reset_and_update_card_tile(int b[][9], character &player);
void display_player_stat(character &player);
void restore_coords(int b[][9], character player, int prev_coord[2]);
void update_character_stat(character &player);

#endif