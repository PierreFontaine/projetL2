#include "tetris.h"
#include "affichage.h"
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

/*
  @{param} layout [l]
    donne le layout sur lequel on cherche les lignes remplies
  @{return}
    retourne le n° de la ligne si elle est remplie
    si aucune ligne remplie alors retourne -1
*/
/*
int isLineFull(layout l){
  int i,j;
  int isFull;

  //initialisation boucle externe
  i = 1;

  isFull = 0; //Iniatialisation à 0
  //Warn: l[GAME_HEIGHT - 1][x] vaut '#' pour tout x
  while(isFull == 0 && i < GAME_HEIGHT-1){
    //tant qu'on a pas prouvé le contraire c'est vrai
    isFull = 1;
    //initialisation boucle interne
    j = 1;
    //Warn: l[x][GAME_WIDTH - 1] vaut '|' pour tout x
    while (isFull == 1 && j < GAME_WIDTH-1) {
      if (l[i][j] == '@') {
        isFull = 0;
      }
      j++;
    }
    i++;
  }
  if (isFull == 1) {
    return i;
  } else {
    return -1;
  }
}
*/
