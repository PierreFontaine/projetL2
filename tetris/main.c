#include "affichage.h"
//#include "keyboard.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "termios.h"
#include "string.h"
#include "save.h"
#include "ncurses.h"


int launchGame();

layout l_jeu;
piece p_jeu;
pos p_posInit;
int s_jeu;
gameState etat;


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
  strcpy(tab[1][1],"afficher meilleurs scores");
  strcpy(tab[2][1],"quitter");

  *tab[0][0] = '>';
  *tab[1][0] = ' ';
  *tab[2][0] = ' ';

  do {
    system("clear");
    printf("##################\n");
    printf("z : monter\n");
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
  switch (nbChoix) {
    case 0:
      launchGame();
      break;
    case 1:
      readScore();
      break;
    case 2:
      printf("%s\n", "a bientot !");
      break;

  }
}

int launchGame(){
  game(l_jeu,&p_jeu,&p_posInit,&s_jeu,&etat);
  return 1;
}

int main(int argc, char const *argv[]) {
  menu();
  return 0;
}
