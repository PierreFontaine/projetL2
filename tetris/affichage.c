#include "affichage.h"
#include "stdio.h"

void makeBackGround(layout l){
  int i,j;

  for (i = 0; i < GAME_HEIGHT; i++) {
    for (j = 0; j < GAME_WIDTH; j++) {
      l[i][j] = ' ';
    }
  }
}

void makeBorder(layout l){
  int i,j;

  //de 0 à GAME_HEIGHT - 2 car on laisse une ligne pour les #
  for (i = 0; i < GAME_HEIGHT - 1; i++) {
    l[i][0] = '|';
    l[i][GAME_WIDTH - 1] = '|';
  }

  for (j = 0; j < GAME_WIDTH; j++) {
    l[GAME_HEIGHT - 1][j] = '#';
  }
}

void displayGame(layout l){
  int i,j;

  for (i = 0; i < GAME_HEIGHT; i++) {
    for (j = 0; j < GAME_WIDTH; j++) {
      printf("%c ", l[i][j]);
    }
    printf("\n");
  }
}
