#include "affichage.h"
#include "keyboard.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "termios.h"

layout l_jeu;
piece p_jeu;
pos p_posInit;

void *thread_1(void *arg){
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

int main(int argc, char const *argv[]) {
  static struct termios oldt, newt;

  pthread_t thread1;

  if(pthread_create(&thread1, NULL, thread_1, NULL) == -1) {
  	perror("pthread_create");
  	return EXIT_FAILURE;
  }

  /**
  * Changement du comportement du terminal sur le buffer
  * On veut pouvoir dans le thread capturer le dernier caractère sans attendre le retour chariot
  * cf man termios
  *
  **/
  tcgetattr(STDIN_FILENO, &oldt);//On place les paramètre du terminal dans une struct termios
  newt = oldt; //initialisation de newt avec oldt
  newt.c_lflag &= ~(ICANON); //mise a jour du mode canonique sur newt
  //TCSANOW change occurs immediately | cf : man tcsetattr
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); //le terminal prend les paramètre de newt

  game(l_jeu,&p_jeu,&p_posInit);

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
  return 0;
}
