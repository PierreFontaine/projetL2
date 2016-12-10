#ifndef tetris_h
#define tetris_h

#include "data.h"

int game(layout l_jeu,piece *p_jeu,pos *p_posInit,float *s_jeu,gameState *etat);
void scoreUp(int *score,int wasDropped,int comboLine);
piece selectPiece();
int isLineFull(layout l);
int canMoveToward(piece p,direction dir,pos a,layout l);
int gameOver(layout l, piece p, pos a);
void pieceMoveToward(piece p,direction dir,pos *a,layout l);
void rotatePiece(layout l,direction dir,piece *p,pos a);
int canRotate(layout l,direction dir, piece p,pos a);
void reachFloor(layout l,piece p, pos *a);
int resume(layout l_jeu,piece *p_jeu,pos *p_posInit,float *s_jeu,gameState *etat,int *wasDropped);
int pieceIsOutOfLayout(piece p,pos a);
int pieceOverlap(piece p,pos a,layout l);
void copyLayout(layout a,layout b);
void keyboardListener(layout l_jeu,piece *p_jeu,pos *p_posInit,float *s_jeu,gameState *etat,int *wasDropped);
void init_ncurses();
void init_save(player *joueur);
void init_game(int *score,layout l_jeu,gameState *etat);
#endif
