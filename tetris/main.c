#include "affichage.h"
#include "keyboard.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "termios.h"
#include "string.h"

layout l_jeu;
piece p_jeu;
pos p_posInit;
int s_jeu;

void menu(){
  int i,j,nbChoix;
  char select;

  char *tab[3][2];
  nbChoix = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      tab[i][j] = malloc(100*sizeof(char));
    }
  }

  strcpy(tab[0][1],"jouer");
  strcpy(tab[1][1],"afficher score");
  strcpy(tab[2][1],"quitter");

  *tab[0][0] = '>';
  *tab[1][0] = ' ';
  *tab[2][0] = ' ';

  do {
    system("clear");
    printf("##################\n");
    printf("s : descendre\n");
    printf("s : descendre\n");
    printf("c : choisir\n");
    printf("##################\n");
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 2; j++) {
        printf("%s",tab[i][j]);
      }
      printf("\n");
    }
    scanf("%c%*c",&select);
    switch (select) {
      case 's':
        *tab[nbChoix][0] = ' ';
        nbChoix = (nbChoix + 1)%3;
        *tab[nbChoix][0] = '>';
        break;
      case 'z':
        *tab[nbChoix][0] = ' ';
        if (nbChoix == 0) {
          nbChoix = 2;
        } else {
          nbChoix -= 1;
        }
        *tab[nbChoix][0] = '>';
    }

  } while(select != 'c');

}

int main(int argc, char const *argv[]) {
  static struct termios oldt, newt;

  menu();

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

  game(l_jeu,&p_jeu,&p_posInit,&s_jeu);

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
  return 0;
}
