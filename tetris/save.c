#include "save.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "fcntl.h"
#include "data.h"
#include "ncurses.h"

/*
* @{param} joueur [player]
*   permet d'écrire à la fin du fichier des scores
*/
void appendScore(player *joueur){
  printf("%s\n","on rentre dans la fonction");
  FILE *sortie;
  sortie = fopen("./score.data","aw");

  if(sortie != NULL){
    fwrite(joueur,sizeof(player),1,sortie);
    fclose(sortie);
  } else {
    printf("le fichier n'existe pas\n");
  }
}

/*
*   permet d'afficher les scores contenus dans score.data
*/
void readScore(){
  FILE *entree;
  player joueur;

  entree = NULL;

  entree = fopen("score.data","r");

  if(!(feof(entree))){
    fseek(entree,sizeof(player)*0,SEEK_SET);
    while (!feof(entree)) {
			fread(&joueur,sizeof(player),1,entree);
			if (!feof(entree)) {
				printw("%s\t",joueur.nom);
        printw("%d\t",joueur.score);
        printw("%d\t",joueur.ligne);
        printw("\n");
        refresh();
			}
		}

		fclose(entree);
  }
}

int getNbScore(){
  FILE *fichier;

  player joueur;
  int i;

  i = 0;

  fichier = fopen("score.data","r");
  fseek(fichier,0,SEEK_SET);//position du la ligne 0
  while(!(feof(fichier))){
    fread(&joueur,sizeof(player),1,fichier);
    if(!feof(fichier)){
      i++;
    }
  }
  fclose(fichier);
  return i;

}

void sortScore(){
  int min,length,i;
  player joueur;
  player *joueurTab;

  length = getNbScore();
  i = 0;
  joueurTab = (player*)malloc(length*sizeof(player));

  FILE *fichier;
  fichier = fopen("score.data","r");
  fseek(fichier,0,SEEK_SET);//position du la ligne 0
  while(!(feof(fichier))){
    fread(&joueur,sizeof(player),1,fichier);
    strcpy(joueurTab[i].nom,joueur.nom);
    joueurTab[i].score = joueur.score;
    joueurTab[i].ligne = joueur.ligne;
  }
  fclose(fichier);

}
