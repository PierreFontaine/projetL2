#include "tetris.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"


piece selectPiece() {
  int alea;
  piece res;

  srand(time(NULL));
  alea = rand()%(6);
  switch (alea) {
    case 0:
      res = S;
      break;
    case 1:
      res = Z;
      break;
    case 2:
      res = L;
      break;
    case 3:
      res = J;
      break;
    case 4:
      res = T;
      break;
    case 5:
      res = I;
      break;
    default:
      printf("error somewhere\n");
  }
  return res;
}
