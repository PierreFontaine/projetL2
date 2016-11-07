#ifndef tetris_h
#define tetris_h

#include "data.h"

void game();
void scoreUp(int *score);
piece selectPiece();
int isLineFull(layout l);
int canMoveToward(piece p,direction dir,pos a,layout l);
int gameOver(layout l, piece p, pos a);
void pieceMoveToward(piece p,direction dir,pos *a,layout l);
void rotatePiece(layout l,piece *p,pos a,int *compteur);
int canRotate(layout l, piece p,pos a);
void reachFloor(layout l,piece p, pos *a);
void resume();
int pieceIsOutOfLayout(piece p,pos a);
int pieceOverlap(piece p,pos a,layout l);
void copyLayout(layout a,layout b);
#endif
