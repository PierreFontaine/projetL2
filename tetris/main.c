#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
  layout l_jeu;
  piece p_jeu[NB_PIECE];
  char key;
  pos a;

  a.x = 5;
  a.y = 3;

  makeBackGround(l_jeu);
  makeBorder(l_jeu);
  displayGame(l_jeu);
  displayPieceAt(a,l_jeu,I);
  displayGame(l_jeu);
  return 0;
}
