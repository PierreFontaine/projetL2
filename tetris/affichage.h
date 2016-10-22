#ifndef affichage_h
#define affichage_h

#define GAME_HEIGHT       12
#define GAME_WIDTH        10
#define PIECE_MAX_WIDTH   4
#define PIECE_MAX_HEIGHT  4

typedef struct figure{
  int heigth;
  int width;
  char forme[PIECE_MAX_WIDTH][PIECE_MAX_HEIGHT];
}block_s;

typedef struct pos{
  int x;
  int y;
}pos;

void makeBackGround(); //creer une matrice hauteur+1*largeur+1 de type char
void makeBorder(); //remplis les contours de la matrice pour délimiter
void makeFigure(); //creer des figures avec la bonne forme
void displayPieceAt(pos a); //affiche une piece à la pos{x,y}
void clearScreen(); //efface le terminal
void displayScore(); //permet d'afficher le score sur le terminal
void eraseLine();

#endif
