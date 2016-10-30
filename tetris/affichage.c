#include "affichage.h"
#include "stdio.h"
#include "tetris.h"
#include "string.h"

/*
  @{param} layout [l]
    donne le layout sur lequel on travail
*/
void makeBackGround(layout l){
  int i,j;

  for (i = 0; i < GAME_HEIGHT; i++) {
    for (j = 0; j < GAME_WIDTH; j++) {
      l[i][j] = ' ';
    }
  }
}

/*
  @{param} layout [l]
    donne le layout sur lequel on travail
*/
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

/*
  @{param} layout [l]
    spécifie le layout à afficher
*/
void displayGame(layout l){
  int i,j;

  for (i = 0; i < GAME_HEIGHT; i++) {
    for (j = 0; j < GAME_WIDTH; j++) {
      if (l[i][j] == '#') {
        couleur(UNIX_COLOR_BLUE);
      }
      if (l[i][j] == '|') {
        couleur(UNIX_COLOR_RED);
      }
      printf("%c ", l[i][j]);
      couleur(UNIX_COLOR_RESET);
    }
    printf("\n");
  }
}

/*
  @{param} piece [name]
    spécifie le nom de la piece à créer
  @{return} figure
    retourne la figure
*/
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
    case C:
      res.heigth = 2;
      res.width = 2;
      strcpy(res.forme[0],"@@");
      strcpy(res.forme[1],"@@");
      break;
    default:
      printf("%s\n","error in piece choice");
  }

  return res;
}

/*
  @{param} pos [a]
    spécifie les coordonnées où afficher la pièce
  @{param} layout [l]
    donne le layout du jeu
  @{param} piece [name]
    donne le nom de la pièce a aff cf enum pièce
*/
void displayPieceAt(pos a,layout l, piece name){
  figure shape;
  int i,j;

  shape = makeFigure(name);
  for (i = 0; i < shape.heigth; i++) {
    for(j = 0; j < shape.width; j++) {
      if (shape.forme[i][j] == '@') {
        l[a.y+i][a.x + j] = shape.forme[i][j];
      }
    }
  }
}

/*
  @{param} pos [a]
    spécifie les coordonnées où afficher la pièce
  @{param} layout [l]
    donne le layout du jeu
  @{param} piece [name]
    donne le nom de la pièce a aff cf enum pièce
*/
void erasePieceAt(pos a, layout l, piece name){
  figure shape;
  int i,j;

  shape = makeFigure(name);

  for (i = 0; i < shape.heigth; i++) {
    for(j = 0; j < shape.width; j++) {
      if (shape.forme[i][j] == '@') {
        l[a.y+i][a.x + j] = ' ';
      }
    }
  }
}

/*
  @{param} pos [a]
    spécifie les coordonnées où afficher la pièce
  @{param} layout [l]
    donne le layout du jeu
  @{param} char [elt]
    donne le resultat de la recherche
  @{return} int
    renvoi 1 si correct, 0 si incorrect
*/
int getCharAt(pos a,layout l, char *elt){
  if ((a.x < 0 && a.y<0) || (a.x < 0 && a.y >= GAME_HEIGHT) || (a.x >= GAME_WIDTH && a.y < 0) || (a.x >= GAME_WIDTH && a.y >= GAME_HEIGHT) ) {
    perror("erreur de position\n");
    return 0;
  } else {
    *elt = l[a.y][a.x];
    return 1;
  }
}

void eraseLine(int n,layout l){
  //ToDo
}
