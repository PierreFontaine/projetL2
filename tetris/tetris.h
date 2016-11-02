#ifndef tetris_h
#define tetris_h

#include "data.h"

void game();
int score();
piece selectPiece();
int isLineFull(layout l);
int canMoveToward(piece p,direction dir,pos a,layout l);
int gameOver(layout l, piece p, pos a);
void pieceMoveToward(piece p,direction dir,pos *a,layout l);
void rotatePiece(layout l,piece *p,pos a,int *compteur);
void reachFloor();
void resume();

#endif
