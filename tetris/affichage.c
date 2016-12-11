#include "affichage.h"
#include "stdio.h"
#include "string.h"
#include "data.h"
#include "ncurses.h"
#include "stdlib.h"
#include "sys/types.h"
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
    spécifie le layout à afficher
*/
void displayGame(layout l,int score){
  int i,j;
  clear();
  for (i = 0; i < GAME_HEIGHT; i++) {
    printw("|");
    for (j = 0; j < GAME_WIDTH; j++) {

      printw("%c ", l[i][j]);
    }
    printw("|");
    printw("\n");
  }
  printw(" ");
  for (i = 0; i < GAME_WIDTH; i++) {
    printw("# ");
  }
  printw("\n");
  mvprintw(LINES - 2, 0, "Score : %d ",score);
  refresh();
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
      res.suivante = S_90;
      res.precedente = S_90;
      break;

    case S_90:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0],"@ ");
      strcpy(res.forme[1],"@@");
      strcpy(res.forme[2]," @");
      res.suivante = S;
      res.precedente = S;
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
      res.suivante = Z_90;
      res.precedente = Z_90;
      break;

    case Z_90:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0]," @");
      strcpy(res.forme[1],"@@");
      strcpy(res.forme[2],"@ ");
      res.suivante = Z;
      res.precedente = Z;
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
      res.suivante = L_90;
      res.precedente = L_270;
      break;
    case L_90:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0],"  @");
      strcpy(res.forme[1],"@@@");
      res.suivante = L_180;
      res.precedente = L;
      break;
    case L_180:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0],"@@");
      strcpy(res.forme[1]," @");
      strcpy(res.forme[2]," @");
      res.suivante = L_270;
      res.precedente = L_90;
    case L_270:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0],"@@@");
      strcpy(res.forme[1],"@  ");
      res.suivante = L;
      res.precedente = L_180;
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
      res.suivante = J_90;
      res.precedente =J_270 ;
      break;

    case J_180:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0],"@@");
      strcpy(res.forme[1],"@ ");
      strcpy(res.forme[2],"@ ");
      res.suivante = J_270;
      res.precedente = J_90;
      break;

    case J_90:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0],"@@@");
      strcpy(res.forme[1],"  @");
      res.suivante = J_180;
      res.precedente = J;
      break;

    case J_270:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0],"@  ");
      strcpy(res.forme[1],"@@@");
      res.suivante = J;
      res.precedente = J_180;
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
      res.suivante = T_90;
      res.precedente = T_270;
      break;

    case T_90:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0],"@ ");
      strcpy(res.forme[1],"@@");
      strcpy(res.forme[2],"@ ");
      res.suivante = T_180;
      res.precedente = T;
      break;

    case T_180:
      res.heigth = 2;
      res.width = 3;
      strcpy(res.forme[0]," @ ");
      strcpy(res.forme[1],"@@@");
      res.suivante = T_270;
      res.precedente = T_90;
      break;

    case T_270:
      res.heigth = 3;
      res.width = 2;
      strcpy(res.forme[0]," @");
      strcpy(res.forme[1],"@@");
      strcpy(res.forme[2]," @");
      res.suivante = T;
      res.precedente = T_180;
      break;
    /*
      @
      @
      @
      @
    */
    case I:
      res.heigth = 3;
      res.width = 1;
      strcpy(res.forme[0],"@");
      strcpy(res.forme[1],"@");
      strcpy(res.forme[2],"@");
      res.suivante = I_90;
      res.precedente = I_90;
      break;

    case I_90:
      res.heigth = 1;
      res.width = 3;
      strcpy(res.forme[0],"@@@");
      res.suivante = I;
      res.precedente = I;
      break;
    /*
    * @@
    * @@z
    */
    case C:
      res.heigth = 2;
      res.width = 2;
      strcpy(res.forme[0],"@@");
      strcpy(res.forme[1],"@@");
      res.suivante = C;
      res.precedente = C;
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

/*
* @{param} int [n]
*   donne le numéro de la ligne à supp entre 0 et GAME_HEIGHT
* @{param} layout [l]
*   donne le layout dans lequel on travail
*/
void eraseLine(int n,layout l){
  int i,j;

  for (i = n-1; i > 0; i--) {
    for (j = 1; j < GAME_WIDTH-1; j++) {
      l[i][j] = l[i-1][j];
    }
  }
  for (i = 1; i < GAME_WIDTH-1; i++) {
    l[0][i] = ' ';
  }
}

/*
* Initialiser l'affichage en ncurses
*/
void init_ncurses(){
  initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */
  nodelay(stdscr,TRUE);
}

void gameOverAnim(){
  FILE *entree;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  entree = fopen("assets/bomb.txt","r");

  if (entree == NULL)
    exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, entree)) != -1) {
      //printf("Retrieved line of length %zu :\n", read);
      printw("%s", line);
      refresh();
      sleep(1);
    }
    free(line);
    fclose(entree);
}
