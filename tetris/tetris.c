#include "tetris.h"
#include "affichage.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "data.h"
#include "string.h"
#include "termios.h"
#include "save.h"
#include "ncurses.h"

int createRandomNumberInRange(int max){
  unsigned int
      // max <= RAND_MAX < ULONG_MAX, so this is okay.
      num_bins = (unsigned int) max + 1,
      num_rand = (unsigned int) RAND_MAX + 1,
      bin_size = num_rand / num_bins,
      defect   = num_rand % num_bins;

      int x;
      do{
        x = random();
      }while(num_rand - defect <= (unsigned int)x);
  return x/bin_size;
}

/*
* @{return} piece [res]
*   retourne une piece choisie aléatoirement
*/
piece selectPiece() {
  int alea;
  piece res;


  alea = createRandomNumberInRange(7);
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
void rotatePiece(layout l,direction dir,piece *p,pos a){
  if (dir == EST) {
    if (canRotate(l,EST,*p,a) == 1) {
      erasePieceAt(a,l,*p);
      *p = makeFigure(*p).suivante;
      displayPieceAt(a,l,*p);
    }
  } else {
    if (canRotate(l,WEST,*p,a) == 1) {
      erasePieceAt(a,l,*p);
      *p = makeFigure(*p).precedente;
      displayPieceAt(a,l,*p);
    }
  }

}

/*
* retourne 1 si la piece est en dehors du layout sinon 0
* @{param} piece [p]
*   donne la piece sur laquel on effectue la verification
* @{param} pos [a]
*   donne la pos de la piece
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
* @{param} layout [a]
*   donne le layout du jeu
* @{param} layout [b]
*   layout dans lequel on copie l'instance du jeu
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
* @{param} piece [p]
*   donne la piece sur laquel on effectue la verification
* @{param} pos [a]
*   donne la position de la piece à l'instant ou la fonction est appelée
* @{param} layout [l]
*   donne le layout du jeu
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
int canRotate(layout l,direction dir, piece p,pos a){
  //verification de débordement de jeu
  int res;
  piece p_aux;
  figure f_aux,f_act;

  if (dir == EST) {
    f_act = makeFigure(p);
    p_aux = f_act.suivante;
    f_aux = makeFigure(p_aux);
    res = 1;
    if (pieceIsOutOfLayout(p_aux,a) == 1 || pieceOverlap(p,a,l) == 1) {
      res = 0;
    }
    return res;
  } else {
    f_act = makeFigure(p);
    p_aux = f_act.precedente;
    f_aux = makeFigure(p_aux);
    res = 1;
    if (pieceIsOutOfLayout(p_aux,a) == 1 || pieceOverlap(p,a,l) == 1) {
      res = 0;
    }
    return res;
  }
}

/*
* permet de mettre le jeu sur pose
* Remarque : Ne fonctionne pas encore, il faudrait que le thread bloque le main
*/
int resume(gameState *etat){
  char touche;
  system("clear");
  printf("####################\n");
  printf("#######PAUSE########\n");
  printf("####################\n");
  printf("#APPUYEZ SUR UNE ###\n");
  printf("#TOUCHE POUR #######\n");
  printf("#REPRENDRE##########\n");

  while (*etat == PAUSE) {

  }
  return 0;
}

/*
* @{param} int* [score]
*   donne le score à incrémenter
*/
void scoreUp(int *score){
  (*score) += 10;
}

void keyboardListener(){
  extern piece p_jeu;
  extern pos p_posInit;
  extern layout l_jeu;
  extern int s_jeu;
  extern gameState etat;
  initscr(); // initialiser la lib ncurses
  noecho();
  cbreak(); //n'attend pas ENTREE
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
  nodelay(stdscr, TRUE);

  int touche;
  touche = getch();
  if (touche == 'q') {
    pieceMoveToward(p_jeu,WEST,&p_posInit,l_jeu);
  }
  if (touche == KEY_RIGHT) {
    pieceMoveToward(p_jeu,EST,&p_posInit,l_jeu);
  }
  if (touche == KEY_LEFT) {
    rotatePiece(l_jeu,WEST,&p_jeu,p_posInit);
  }
  if (touche == 'x') {
    rotatePiece(l_jeu,EST,&p_jeu,p_posInit);
  }
  if (touche == 'p') {
    if (etat == PAUSE) {
      etat = RESUME;
    } else {
      etat = PAUSE;
    }
  }
  if (touche == 'z') {
    reachFloor(l_jeu,p_jeu,&p_posInit);
  }
  if(touche == 's') {
    s_jeu = 600000;
  }
  //nodelay(stdscr, FALSE);
  endwin();
}


/*
* @{param} layout [l]
*   donne le layout du jeu
* @{param} piece [p]
*   donne la piece qui doit atteindre la position la plus basse
* @{param} pos* [a]
*   donne la position de la piece à l'instant ou la fonction est appelée
*/
void reachFloor(layout l,piece p, pos *a){
  while(canMoveToward(p,SUD,*a,l) == 1){
    pieceMoveToward(p,SUD,a,l);
  }
}

int game(layout l_jeu,piece *p_jeu,pos *p_posInit,int *s_jeu,gameState *etat){
  int score;
  char key,underPiece;
  figure f_jeu;
  player joueur;

  joueur.ligne = 0;
  joueur.score = 0;
  strcpy(joueur.nom,"pierre");

  makeBackGround(l_jeu);
  makeBorder(l_jeu);
  displayGame(l_jeu);

  score = 0;
  *etat = RESUME;
  while(1){
    *s_jeu = 300000;
    p_posInit->x = 5;
    p_posInit->y = 0;

    *p_jeu = selectPiece(); //selection d'une piece au hasard
    f_jeu = makeFigure(*p_jeu); //mise en mémoire de cette piece pour accès aux params

    clrscr();
    displayPieceAt(*p_posInit,l_jeu,*p_jeu);//Affichage de la piece en haut
    displayGame(l_jeu); //affichage du jeux
    printf("score : %d\n",score);
    clrscr(); //effacage écran
    sleep(1);
    if (gameOver(l_jeu,*p_jeu,*p_posInit)) {
      joueur.score = score;
      appendScore(&joueur);
      printf("game over \n");
      return 0;
    }
    while(canMoveToward(*p_jeu,SUD,*p_posInit,l_jeu) == 1){

      keyboardListener();

      if(*etat == PAUSE){
        resume(etat);
      }
      pieceMoveToward(*p_jeu,SUD,p_posInit,l_jeu);
      displayGame(l_jeu);
      printf("score : %d\n",score);
      //clrscr();
      if (isLineFull(l_jeu) != (-1)) {
        eraseLine(isLineFull(l_jeu),l_jeu);
        scoreUp(&score);
        joueur.ligne += 1;
      }
      usleep(*s_jeu);
    }
  }
}
