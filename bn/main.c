#include "BN.h"


int main (int argc, char *argv[]) {
	SDL_Init((SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER));
	if (SDL_Init(SDL_INIT_VIDEO) == -1){
		fprintf(stderr, "Erreur d'initialisation de la SDL");
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	FILE *fichier = NULL;
	fichier = fopen("score.txt","r+");
	
	
	
	int grillej1 [Taille][Taille];
	int grillej2 [Taille][Taille];
	int jeuj1 [Taille][Taille];
	int jeuj2 [Taille][Taille];
	int scorej1=0;
	int scorej2=0;
	int batcoulej1=0;
	int batcoulej2=0;
	int continuer=0;
	int choix;
	int savescore;
	int sauvPartie;
	int Taille=10;
	save sauvegarde;
	
	/*FILE *enter;
	enter=fopen("options.txt","r");
	if(!(feof(enter))){
		fseek(enter,0,SEEK_SET);
		while(!feof(enter)){
			fread(&options,sizeof(opts),1,enter);
			}
	}
	//Taille=options.Taille;*/
	initialiserGrille(Taille,jeuj1);
	initialiserGrille(Taille,jeuj2);

	do{
		system("clear");
		printf("1. Nouvelle partie\n");
		printf("2. Charger la dernière partie\n");
		printf("3. Options\n");
		printf("4. Quitter\n");
		scanf("%d%*c", &choix);
		printf("\n");
		switch (choix)
		{
			case 1:
				system("clear");
				printf("Vous commencez une nouvelle partie\n");
				int nbj;
				int joueur;
				printf("Jouer seul ou à deux:\n");
				printf("1. Joueur contre ordi\n");
				printf("2. Deux joueurs\n");
				scanf("%d%*c", &nbj);
				printf("\n");

				switch (nbj)
				{
					case 1:
						do{
							system("clear");
							printf("Vous jouez contre l'ordinateur.\nVous êtes le joueur 1.\n");
        						joueur = alea(1,3);
        						printf("Le joueur %d commence\n",joueur);
        						printf("Le joueur 1 positionne ces navires\n");
							Postionnavire(Taille,grillej1);
							initialiserGrille(Taille,grillej2);
							modeAuto(Taille,grillej2);
							jeuJVsOrdi(Taille,joueur,jeuj1,jeuj2,grillej1,grillej2,&scorej1,&scorej2,batcoulej1,batcoulej2,nbj);
							printf("Voulez vous jouer une autre partie?\n1. Oui\n2. Non");
							scanf("%d%*c",&continuer);
						}while(continuer==1);
						printf("Voulez vous sauvegarder les scores?\n1. Oui\n2. Non");
						scanf("%d%*c",&savescore);
						if(savescore==1){
							rewind(fichier);
							fprintf(fichier,"%d %d \n",scorej1,scorej2);
						}


					break;
					case 2:
						system("clear");
       						printf("Vous jouez à deux joueurs.\n");

       						do{
        						joueur = alea(1,3);
        						printf("Le joueur %d commence.\n",joueur);
        						if(joueur==1){
								printf("Le joueur 1 positionne ces navires\n");
								Postionnavire(Taille,grillej1);
								system("clear");
								printf("Le joueur 2 positionne ces navires\n");
								Postionnavire(Taille,grillej2);
								system("clear");
							}else{
								printf("Le joueur 2 positionne ces navires\n");
								Postionnavire(Taille,grillej2);
								system("clear");
								printf("Le joueur 1 positionne ces navires\n");
								Postionnavire(Taille,grillej1);
								system("clear");
							}
							jeuDeuxJ(Taille,joueur,jeuj1,jeuj2,grillej1,grillej2,&scorej1,&scorej2,batcoulej1,batcoulej2,nbj);
							printf("Voulez vous jouer une autre partie?\n1. Oui\n2. Non");
							scanf("%d%*c",&continuer);
						}while(continuer==1);
						printf("Voulez vous sauvegarder les scores?\n1. Oui\n2. Non");
						scanf("%d%*c",&savescore);
						if(savescore==1){
							rewind(fichier);
							fprintf(fichier,"%d %d \n",scorej1,scorej2);
						}
       					break;
       				}
				printf("\n");
				break;
			case 2:
				printf("Voulez vous charger les anciens scores?\n1.Oui\n2.Non\n");
				scanf("%d%*c",&savescore);
				if (savescore==1){
					fscanf(fichier,"%d %d ",&scorej1,&scorej2);
					printf("Score joueur 1:%d\nScore joueur 2:%d\n",scorej1,scorej2);
				}
				printf("Voulez vous charger la dernière partie sauvegardée?\n1.Oui\n2.Non\n");
				scanf("%d%*c",&sauvPartie);
				if (sauvPartie==1){
					FILE *entree;
					entree=fopen("save.txt","r");
					if(!(feof(entree))){
						fseek(entree,0,SEEK_SET);
						while(!feof(entree)){
							fread(&sauvegarde,sizeof(save),1,entree);
						}
					}
					fclose(entree);
					afficherGrille(sauvegarde.Taille,sauvegarde.grillej1);
					afficherGrille(sauvegarde.Taille,sauvegarde.grillej2);
					afficherGrille(sauvegarde.Taille,sauvegarde.jeuj1);
					afficherGrille(sauvegarde.Taille,sauvegarde.jeuj2);
					if((sauvegarde.nbj)==1){
						jeuJVsOrdi(sauvegarde.Taille,sauvegarde.joueur,sauvegarde.jeuj1,sauvegarde.jeuj2,sauvegarde.grillej1,sauvegarde.grillej2,&(sauvegarde.scorej1),&(sauvegarde.scorej2),sauvegarde.batcoulej1,sauvegarde.batcoulej2,sauvegarde.nbj);
					}else if((sauvegarde.nbj)==2){	
						jeuDeuxJ(sauvegarde.Taille,sauvegarde.joueur,sauvegarde.jeuj1,sauvegarde.jeuj2,sauvegarde.grillej1,sauvegarde.grillej2,&(sauvegarde.scorej1),&(sauvegarde.scorej2),sauvegarde.batcoulej1,sauvegarde.batcoulej2,sauvegarde.nbj);
					}else{
						printf("Pas de sauvegarde");
					}
				}

       			break;
       			case 3:
				printf("Les options:\n");
				lesOptions(Taille);
       			break;
       			case 4:
				printf("Vous quittez la partie\n");
				return EXIT_SUCCESS;
       			break;
       		}
       	}while(choix!=4);
	printf("\n");
	fclose(fichier);
	printf("FIN.");
	return 0;
	SDL_Quit();
}

//make
//./BN
