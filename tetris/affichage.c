#include "affichage.h"
#include "stdio.h"
#include "tetris.h"
#include "string.h"

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

figure makeFigure(piece name){
  figure res;
  switch (name) {
    /*
       @@
      @@
    */
    case S:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0]," @@");
      strcpy(res.forme[1],"@@ ");
      break;

    /*
      @@
       @@
    */
    case Z:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0],"@@ ");
      strcpy(res.forme[1]," @@");
      break;

    /*
      @
      @
      @@
    */
    case L:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0],"@ ");
      strcpy(res.forme[1],"@ ");
      strcpy(res.forme[2],"@@");
      break;

    /*
       @
       @
      @@
    */
    case J:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0]," @");
      strcpy(res.forme[1]," @");
      strcpy(res.forme[2],"@@");
      break;

    /*
      @@@
       @
    */
    case T:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0],"@@@");
      strcpy(res.forme[1]," @ ");
      break;

    /*
      @
      @
      @
      @
    */
    case I:
      res.heigth = 4;
      res.width = 1;
      strcpy(res.forme[0],"@");
      strcpy(res.forme[1],"@");
      strcpy(res.forme[2],"@");
      strcpy(res.forme[3],"@");
      break;
    default:
      printf("%s\n","error somewhere");
  }

  return res;
}

void displayPieceAt(pos a,layout l, piece name){
  figure shape;
  int i,j;

  shape = makeFigure(name);

  for (i = 0; i < shape.heigth; i++) {
    for(j = 0; j < shape.width; j++) {
      l[a.y+i][a.x + j] = shape.forme[i][j];
    }
  }
}
