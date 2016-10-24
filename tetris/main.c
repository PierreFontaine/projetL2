#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
  layout l_jeu;
  piece p_jeu[NB_PIECE];
  char key;

  makeBackGround(l_jeu);
  makeBorder(l_jeu);
  displayGame(l_jeu);
  scanf("%c",&key);
  clrscr();
  couleur("34");
  printf("%s\n", "au revoir");
  return 0;
}
