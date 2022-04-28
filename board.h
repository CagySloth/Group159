#ifndef BOARD_H
#define BOARD_H

void initBoard(int b[][9]);
bool cardTile(int x, int y);
bool validTile(int pos_x, int pos_y);
bool enterCombat(int b[][9],int pos_x, int pos_y);
void printBoard(int b[][9]);
int getMobsNum(int b[][9], int numOfMoves);
void setMobsLoc(int b[][9], int numOfMobs);
bool neighbouring_tiles(int x, int y, int coords[2]);
void print_board(int b[][9], int coord[2]);

#endif