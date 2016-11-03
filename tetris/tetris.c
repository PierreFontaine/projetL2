#include "tetris.h"
#include "affichage.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "data.h"

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
      if (l[i][j] == '@') {
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

void rotatePiece(layout l,piece *p,pos a,int *compteur){
  piece spriteS[] = {S,S_90,S,S_90};
  piece spriteZ[] = {Z,Z_90,Z,Z_90};
  piece spriteL[] = {L,L_90,L_180,L_270};
  piece spriteJ[] = {J,J_90,J_180,J_270};
  piece spriteT[] = {T,T_90,T_180,T_270};
  piece spriteI[] = {I,I_90,I,I_90};
  piece spriteC[] = {C,C,C,C};

  *compteur = ((*compteur + 1) % 5);

  printf("%d",*compteur);
  switch (*p) {
    case S:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteS[*compteur]);
      *p = spriteS[*compteur % 6];
      break;
    case S_90:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteS[*compteur]);
      *p = spriteS[*compteur % 6];
      break;
    case Z:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteZ[*compteur]);
      *p = spriteZ[*compteur];
      break;
    case Z_90:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteZ[*compteur]);
      *p = spriteZ[*compteur];
      break;
    case L:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteL[*compteur]);
      *p = spriteL[*compteur];
      break;
    case L_90:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteL[*compteur]);
      *p = spriteL[*compteur];
      break;
    case L_180:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteL[*compteur]);
      *p = spriteL[*compteur];
      break;
    case L_270:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteL[*compteur]);
      *p = spriteL[*compteur];
      break;
    case J:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteJ[*compteur]);
      *p = spriteJ[*compteur];
      break;
    case J_90:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteJ[*compteur]);
      *p = spriteJ[*compteur];
      break;
    case J_180:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteJ[*compteur]);
      *p = spriteJ[*compteur];
      break;
    case J_270:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteJ[*compteur]);
      *p = spriteJ[*compteur];
      break;
    case T:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteT[*compteur]);
      *p = spriteT[*compteur];
      break;
    case T_90:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteT[*compteur]);
      *p = spriteT[*compteur];
      break;
    case T_180:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteT[*compteur]);
      *p = spriteT[*compteur];
      break;
    case T_270:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteT[*compteur]);
      *p = spriteT[*compteur];
      break;
    case I:
      erasePieceAt(a,l,*p);
      printf("après erase piece\n");
      displayPieceAt(a,l,spriteI[*compteur]);
      printf("après display piece\n");
      *p = spriteI[*compteur];
      break;
    case I_90:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteI[*compteur]);
      *p = spriteI[*compteur];
      break;
    case C:
      erasePieceAt(a,l,*p);
      displayPieceAt(a,l,spriteC[*compteur]);
      *p = spriteC[*compteur];
      break;
    default:
      perror("erreur rotate piece\n");
  }
}

void resume(){
  char touche;
  system("cls");
  printf("####################\n");
  printf("#######PAUSE########\n");
  printf("####################\n");
  printf("#APPUYEZ SUR UNE ###\n");
  printf("#TOUCHE POUR #######\n");
  printf("#REPRENDRE##########\n");

  scanf("%c",&touche);
}
