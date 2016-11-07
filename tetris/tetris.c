#include "tetris.h"
#include "affichage.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "data.h"
#include "string.h"
/*
* @{return} piece [res]
*   retourne une piece choisie aléatoirement
*/
piece selectPiece() {
  int alea;
  piece res;

  srand(time(NULL));
  alea = rand()%6;
  printf("%d\n",alea);
  switch (alea) {
    case 0:
      res = S;
      break;
    case 1:
      res = Z;
      break;
    case 2:
      res = L;
      break;
    case 3:
      res = J;
      break;
    case 4:
      res = T;
      break;
    case 5:
      res = I;
      break;
    case 6:
      res = C;
      break;
    default:
      printf("error in tetris.c selectPiece()\n");
  }
  return res;
}

/*
*  @{param} layout [l]
*    donne le layout sur lequel on cherche les lignes remplies
*  @{return}
*    retourne le n° de la ligne si elle est remplie
*    si aucune ligne remplie alors retourne -1
*/

int isLineFull(layout l){
  int i,j;
  int isFull;

  //initialisation boucle externe
  i = 1;

  isFull = 0; //Iniatialisation à 0
  //Warn: l[GAME_HEIGHT - 1][x] vaut '#' pour tout x
  while(isFull == 0 && i < GAME_HEIGHT-1){
    //tant qu'on a pas prouvé le contraire c'est vrai
    isFull = 1;
    //initialisation boucle interne
    j = 1;
    //Warn: l[x][GAME_WIDTH - 1] vaut '|' pour tout x
    while (isFull == 1 && j < GAME_WIDTH-1) {
      if (l[i][j] != '@') {
        isFull = 0;
      }
      j++;
    }
    i++;
  }
  if (isFull == 1) {
    return i;
  } else {
    return -1;
  }
}

/*
* Determine si une piece peut se déplacer vers la direction souhaité
* @{param} piece [p]
*   donne la piece sur laquel on souhaite tiré des infos
* @{param} direction [dir]
*   donne la direction vers laquelle on souhaite verifier le mouvement
* @{param} pos [a]
*   donne la position de la piece dans le layout
* @{param} layout [l]
*   donne le layout dans lequel on travail
* @{return} int [canMove]
    retourne 1 si la piece peut se diriger dans la direction souhaité, O sinon
*/
int canMoveToward(piece p,direction dir,pos a, layout l){
  figure f;
  int canMove,i,j;

  f = makeFigure(p);
  canMove = 1;
  switch (dir) {
    case SUD:
      i = 0;
      while(canMove == 1 && i < f.width){
        j = f.heigth - 1;
        while((f.forme[j][i] != '@') && j > 0){
          j--;
        }
        if (l[a.y + j+1][a.x + i] == '@' || l[a.y + j+1][a.x + i] == '#') {
          canMove = 0;
        }
        i++;
      }
      break;

    case EST:
      j = 0;
      while (canMove == 1 && j < f.heigth) {
        i = f.width - 1;
        while ((f.forme[j][i] != '@') && i > 0) {
          i--;
        }
        if (l[a.y + j][a.x + i+1] == '@' || l[a.y + j][a.x + i+1] == '|') {
          canMove = 0;
        }
        j++;
      }
      break;

    case WEST:
      j = 0;
      while(canMove == 1 && j < f.heigth){
        i = 0;
        while ((f.forme[j][i] != '@') && i < f.width){
          i++;
        }
        if(l[a.y + j][a.x +i-1] == '@' || l[a.y + j][a.x + i-1] == '|'){
          canMove = 0;
        }
        j++;
      }
      break;
  }
  return canMove;
}

/*
* @{param} piece [p]
*   donne la piece qui doit bouger
* @{param} direction [dir]
*   donne la direction [EST,WEST,SUD] souhaité pour bouger la piece
* @{param} pos [a]
*   passage par ref de la position de la piece
* @{param} layout [l]
*   donne le layout du jeu
*/
void pieceMoveToward(piece p,direction dir,pos *a,layout l){
  if (canMoveToward(p,dir,*a,l)) {
    erasePieceAt(*a,l,p); //on supp la piece dans le layout du jeu à la pos actuelle
    switch (dir) {
      //cas issu de l'interaction H/M
      case EST:
        a->x = a->x+ 1;
        break;
      case WEST:
        a->x = a->x - 1;
        break;
      //cas par défaut
      case SUD:
        a->y = a->y + 1;
        break;
    }
    displayPieceAt(*a,l,p);
  }
}

/*
* @{param} layout [l]
*   donne le layout dans lequel on travail
* @{param} piece [p]
*   donne la piece qui vient d'etre généré
* @{return} int
*   1 si gameover sinon 0
*/
int gameOver(layout l, piece p,pos a){
  if (!canMoveToward(p,SUD,a,l) && a.y == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

/*
* @{param} layout [l]
*   donne le layout du jeu
* @{param} piece [p]
*   donne par ref la piece
* @{param} pos [a]
*   donne la position de la piece
* @{param} int [compteur]
*   donne par ref la valeur du compteur pour connaitre la prochaine version du sprite
*/
void rotatePiece(layout l,piece *p,pos a,int *compteur){
  if (canRotate(l,*p,a) == 1) {
    erasePieceAt(a,l,*p);
    *p = makeFigure(*p).suivante;
    displayPieceAt(a,l,*p);
  }
}

/*
* retourne 1 si la piece est en dehors du layout sinon 0
*/
int pieceIsOutOfLayout(piece p,pos a){
  figure fig;
  int res;

  fig = makeFigure(p); //recuperation des propriétes

  res = 0;

  if (((a.y + (fig.heigth)) > GAME_HEIGHT-1) || ((a.x + (fig.width)) > GAME_WIDTH-1)) {
    res = 1;
  }

  return res;
}

/*
* permet de copier le layout a dans le layout b
*/
void copieLayout(layout a,layout b){
  int i,j;

  for (i = 0; i < GAME_HEIGHT; i++) {
    for (j = 0; j < GAME_WIDTH; j++) {
      b[i][j] = a[i][j];
    }
  }
}

/*
* retourne 1 si la piece superpose une autre piece 0 sinon
*/
int pieceOverlap(piece p,pos a,layout l){
  layout copie;
  piece p_suiv;
  figure f_suiv,f_act;
  int i,j,res;

  copieLayout(l,copie);
  erasePieceAt(a,copie,p);

  f_act = makeFigure(p);
  p_suiv = f_act.suivante;
  f_suiv = makeFigure(p_suiv);

  res = 0;

  for (i = 0; i < f_suiv.heigth; i++) {
    for (j = 0; j < f_suiv.width; j++) {
      if (f_suiv.forme[i][j] == '@' && copie[a.y + i][a.x + j] == '@') {
        res = 1;
      }
    }
  }

  return res;
}

/*
* @{param} layout [l]
*   donne le layout du jeu
* @{param} piece [p]
*   donne par ref la piece
* @{param} pos [a]
*   donne la position de la piece
* @{param} int [compteur]
*   donne par ref la valeur du compteur pour connaitre la prochaine version du sprite
* @{return} int
*   retourne 1 si la piece peut faire une rotation 0 sinon
*/
int canRotate(layout l, piece p,pos a){
  //verification de débordement de jeu
  int res;
  piece p_suiv;
  figure f_suiv,f_act;

  f_act = makeFigure(p);
  p_suiv = f_act.suivante;
  f_suiv = makeFigure(p_suiv);
  res = 1;
  if (pieceIsOutOfLayout(p_suiv,a) == 1 || pieceOverlap(p,a,l) == 1) {
    res = 0;
  }
  return res;
}

/*
* permet de mettre le jeu sur pose
* Remarque : Ne fonctionne pas encore, il faudrait que le thread bloque le main
*/
void resume(){
  char touche;
  system("cls");
  printf("####################\n");
  printf("#######PAUSE########\n");
  printf("####################\n");
  printf("#APPUYEZ SUR UNE ###\n");
  printf("#TOUCHE POUR #######\n");
  printf("#REPRENDRE##########\n");

  sleep(10);
}

void scoreUp(int *score){
  (*score) += 10;
}

void reachFloor(layout l,piece p, pos *a){
  while(canMoveToward(p,SUD,*a,l) == 1){
    pieceMoveToward(p,SUD,a,l);
  }
}
