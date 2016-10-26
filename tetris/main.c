#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"


int main(int argc, char const *argv[]) {
  layout l_jeu;
  piece p_jeu;
  char key;
  pos p_posInit;

  p_posInit.x = 5;
  p_posInit.y = 3;

  makeBackGround(l_jeu);
  makeBorder(l_jeu);
  displayGame(l_jeu);

  while(1){
    p_jeu = selectPiece();

    displayPieceAt(p_posInit,l_jeu,p_jeu);
    displayGame(l_jeu);
    clrscr();
    sleep(1);
    erasePieceAt(p_posInit,l_jeu,p_jeu);
    displayGame(l_jeu);
    clrscr();
    
  }

  return 0;
}
