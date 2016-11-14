#ifndef tetris_h
#define tetris_h

#include "data.h"

int game(layout l_jeu,piece *p_jeu,pos *p_posInit,int *s_jeu,gameState *etat);
void scoreUp(int *score);
piece selectPiece();
int isLineFull(layout l);
int canMoveToward(piece p,direction dir,pos a,layout l);
int gameOver(layout l, piece p, pos a);
void pieceMoveToward(piece p,direction dir,pos *a,layout l);
void rotatePiece(layout l,direction dir,piece *p,pos a);
int canRotate(layout l,direction dir, piece p,pos a);
void reachFloor(layout l,piece p, pos *a);
int resume(gameState *etat);
int pieceIsOutOfLayout(piece p,pos a);
int pieceOverlap(piece p,pos a,layout l);
void copyLayout(layout a,layout b);
#endif
