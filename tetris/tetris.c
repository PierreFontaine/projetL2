#include "tetris.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"


void selectPiece(piece _p[NB_PIECE]) {
  int alea;
  srand(time(NULL));
  alea = rand();
  printf("%d\n", alea);
}
