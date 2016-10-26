#ifndef affichage_h
#define affichage_h

#include "tetris.h"

#define clrscr() printf("\033[H\033[2J");
#define couleur(param) printf("\033[%sm",param)

#define GAME_HEIGHT         12
#define GAME_WIDTH          10
#define PIECE_MAX_WIDTH     4
#define PIECE_MAX_HEIGHT    4

#define UNIX_COLOR_BLACK    "30"
#define UNIX_COLOR_RED      "31"
#define UNIX_COLOR_GREEN    "32"
#define UNIX_COLOR_YELLOW   "33"
#define UNIX_COLOR_BLUE     "34"
#define UNIX_COLOR_MAGENTA  "35"
#define UNIX_COLOR_CYAN     "36"
#define UNIX_COLOR_WHITE    "37"
#define UNIX_COLOR_RESET    "0"

typedef struct figure{
  int heigth;
  int width;
  char forme[PIECE_MAX_HEIGHT][PIECE_MAX_WIDTH];
}figure;

typedef struct pos{
  int x;
  int y;
}pos;

typedef char layout[GAME_HEIGHT][GAME_WIDTH];

void makeBackGround(layout l); //creer une matrice hauteur+1*largeur+1 de type char
void makeBorder(layout l); //remplis les contours de la matrice pour délimiter
figure makeFigure(piece name); //creer des figures avec la bonne forme
void displayPieceAt(pos a,layout l, piece name); //affiche une piece à la pos{x,y}
void displayScore(); //permet d'afficher le score sur le terminal
void eraseLine();
void displayGame(layout l);
void erasePieceAt(pos a,layout l, piece name);

#endif
