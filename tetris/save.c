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
  int min,length;
  player joueur,aux;
  player *joueurTab;
  int i,j;

  i = 0;

  length = getNbScore();//on recupt la longueur du fichier
  joueurTab = (player*)malloc(length*sizeof(player));//on créé un tableau de taille suffisante

  //on met le fichier dans un tableau
  FILE *fichier;
  fichier = fopen("score.data","r");
  fseek(fichier,0,SEEK_SET);//position du la ligne 0
  while(!(feof(fichier))){
    fread(&joueur,sizeof(player),1,fichier);
    joueurTab[i] = joueur;
    i++;
  }
  fclose(fichier);

  //on trie le tableau par insertion
  for(i = 0; i < length - 1; i++){
    min = i;
    for (j = i+1; j < length; j++) {
      if(joueurTab[j].score > joueurTab[min].score){
        min = j;
      }
    }
    if (min != i) {
      aux = joueurTab[min];
      joueurTab[min] = joueurTab[i];
      joueurTab[i] = aux;
    }
  }
  printw("\t#######\n");
  printw("\tTOP TEN\n");
  printw("\t#######\n\n");
  printw("%s\t%s\t%s\n","nom","score","ligne");
  for (i = 0; i < length && i< 10; i++) {
    printw("%s\t%d\t%d\n",joueurTab[i].nom,joueurTab[i].score,joueurTab[i].ligne);
  }


}
