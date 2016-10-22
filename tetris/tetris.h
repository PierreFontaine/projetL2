#ifndef tetris_h
#define tetris_h

#define NB_PIECE 20

typedef enum piece {S,Z,L,J,T,I}piece;

int score();
void selectPiece(piece _p[NB_PIECE]);
int isLineFull();
#endif
