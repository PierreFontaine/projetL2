#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
  layout l_jeu;
  piece p_jeu[NB_PIECE];

  makeBackGround(l_jeu);
  makeBorder(l_jeu);
  displayGame(l_jeu);
  selectPiece(p_jeu);
  return 0;
}
