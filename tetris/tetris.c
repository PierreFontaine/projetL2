#include "tetris.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"


void selectPiece(piece _p[NB_PIECE]) {
  int alea;
  srand(time(NULL));
  alea = rand()%(5-1)+1;
  printf("%d\n", alea);
}
