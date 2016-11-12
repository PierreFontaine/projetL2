#include "save.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "fcntl.h"
#include "data.h"

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
				printf("%s\t",joueur.nom);
        printf("%d\t",joueur.score);
        printf("%d\t",joueur.ligne);
        printf("\n");
			}
		}
		fclose(entree);
  }
}
