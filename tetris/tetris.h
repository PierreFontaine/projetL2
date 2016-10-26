#ifndef tetris_h
#define tetris_h

#include "data.h"

void game();
int score();
piece selectPiece();
int isLineFull(layout l);
#endif
