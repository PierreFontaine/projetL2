#include "BN.h"


void saveJeu(save *sauvegarde){
	FILE *sortie;
	sortie=fopen("save.txt","w");
	if(sortie!=NULL){
		fwrite(sauvegarde,sizeof(save),1,sortie);
		fclose(sortie);
	}
}


void sauvegardeJeu(int Taille,int joueur,int jeuj1[Taille][Taille],int jeuj2[Taille][Taille],int grillej1[Taille][Taille],int grillej2[Taille][Taille],int scorej1,int scorej2,int batcoulej1, int batcoulej2,int nbj){
	sauvegarde.nbj=nbj;
	sauvegarde.Taille=Taille;
	sauvegarde.joueur=joueur;
	sauvegarde.scorej1=scorej1;
	sauvegarde.scorej2=scorej2;
	memcpy(sauvegarde.grillej1,grillej1,Taille*Taille*sizeof(int));
	memcpy(sauvegarde.grillej2,grillej2,Taille*Taille*sizeof(int));
	memcpy(sauvegarde.jeuj1,jeuj1,Taille*Taille*sizeof(int));
	memcpy(sauvegarde.jeuj2,jeuj2,Taille*Taille*sizeof(int));
	sauvegarde.batcoulej1=batcoulej1;
	sauvegarde.batcoulej2=batcoulej2;
	saveJeu(&sauvegarde);
	printf("%d",sauvegarde.joueur);
	afficherGrille(sauvegarde.grillej1);
	afficherGrille(sauvegarde.grillej2);
	afficherGrille(sauvegarde.jeuj1);
	afficherGrille(sauvegarde.jeuj2);
	return 0;
}


void saveOptions(opts *options){
	FILE *exit;
	exit=fopen("options.txt","w");
	if(exit!=NULL){
		fwrite(options,sizeof(opts),1,exit);
		fclose(exit);
	}
}

void sauvegardeOptions(int Taille){
	options.Taille=Taille;
	saveOptions(&options);
}

