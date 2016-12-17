#ifndef affichage_h
#define affichage_h

#include "data.h"

#define clrscr() printf("\033[H\033[2J");
#define couleur(param) printf("\033[%sm",param)

void makeBackGround(layout l); //creer une matrice hauteur+1*largeur+1 de type char
void makeBorder(layout l); //remplis les contours de la matrice pour délimiter
figure makeFigure(piece name); //creer des figures avec la bonne forme
void displayPieceAt(pos a,layout l, piece name); //affiche une piece à la pos{x,y}
void eraseLine(int n,layout l);
void displayGame(layout l,int score);
void erasePieceAt(pos a,layout l, piece name);
int getCharAt(pos a,layout l,char *res);
void init_ncurses();
void gameOverAnim();
void tetris();
#endif
