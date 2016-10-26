#ifndef tetris_h
#define tetris_h

#define NB_PIECE 20

typedef enum piece {S,Z,L,J,T,I}piece;

void game();
int score();
piece selectPiece();
int isLineFull();
#endif
