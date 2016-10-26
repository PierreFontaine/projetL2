#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"


int main(int argc, char const *argv[]) {
  layout l_jeu;
  piece p_jeu;
  char key,underPiece;
  pos p_posInit,p_posUnderPiece;
  figure f_jeu;



  makeBackGround(l_jeu);
  makeBorder(l_jeu);
  displayGame(l_jeu);

  while(1){

    p_posInit.x = 5;
    p_posInit.y = 0;

    p_jeu = selectPiece(); //selection d'une piece au hasard
    f_jeu = makeFigure(p_jeu); //mise en mémoire de cette piece pour accès aux params
    clrscr();
    displayPieceAt(p_posInit,l_jeu,p_jeu);//Affichage de la piece en haut
    displayGame(l_jeu); //affichage du jeux
    clrscr(); //effacage écran
    sleep(1);
    p_posUnderPiece.y = p_posInit.y + f_jeu.heigth;
    p_posUnderPiece.x = p_posInit.x;
    underPiece = getCharAt(p_posUnderPiece,l_jeu,&underPiece);
    while(underPiece != '#' && underPiece != '@'){
      erasePieceAt(p_posInit,l_jeu,p_jeu);
      p_posInit.y += 1;
      displayPieceAt(p_posInit,l_jeu,p_jeu);
      displayGame(l_jeu);
      p_posUnderPiece.y = p_posInit.y + f_jeu.heigth;
      p_posUnderPiece.x = p_posInit.x;
      getCharAt(p_posUnderPiece,l_jeu,&underPiece);
      clrscr();
      sleep(1);
    }




  }

  return 0;
}
