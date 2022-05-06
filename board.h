#ifndef BOARD_H
#define BOARD_H

void initBoard(int b[][9]);
bool cardTile(int y, int x);
bool validTile(int pos_x, int pos_y);
bool neighbouring_tiles(int x, int y, int coords[2]);
bool move(int move_x, int move_y, int player_coord[2]);

#endif