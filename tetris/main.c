#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
  layout l_jeu;

  makeBackGround(l_jeu);
  makeBorder(l_jeu);
  displayGame(l_jeu);
  return 0;
}
