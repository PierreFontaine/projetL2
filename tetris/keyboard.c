#include "data.h"
#include "keyboard.h"
#include "stdio.h"
#include "stdlib.h"
#include "tetris.h"
#include "pthread.h"

void *thread_1(void *arg){
  extern piece p_jeu;
  extern pos p_posInit;
  extern layout l_jeu;

  printf("Nous sommes dans le thread.\n");
  char touche;
  while(1){
    touche = fgetc(stdin);
    if (touche == 'q') {
      pieceMoveToward(p_jeu,WEST,&p_posInit,l_jeu);
    }
    if (touche == 'd') {
      pieceMoveToward(p_jeu,EST,&p_posInit,l_jeu);
    }
    if (touche == 'z') {
      rotatePiece(l_jeu,&p_jeu,p_posInit);
    }
    if (touche == 'p') {
      resume();
    }
    if (touche == 's') {
      reachFloor(l_jeu,p_jeu,&p_posInit);
    }
  }

  /* Pour enlever le warning */
  (void) arg;
  pthread_exit(NULL);
}
