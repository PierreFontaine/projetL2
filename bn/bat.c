#include "BN.h"


//Initialiser la grille

void initialiserGrille(/*int Taille,*/int grille[Taille][Taille]){

	int i;
	int j;
	for(i=0;i<Taille;i++){
		for(j=0;j<Taille;j++){
			grille[i][j]=0;
		}
	}
}


//Afficher la grille

void afficherGrille(/*int Taille,*/int grille[Taille][Taille]){

	int i;
	int j;
	int k;
	printf(" |");
	for(k=0;k<Taille;k++){
		printf(" %d |",k);
	}
	printf("\n");
	printf("-|");
	for(k=0;k<Taille;k++){
		printf("---|");
	}
	printf("\n");
	for(i=0;i<Taille;i++){
	printf("%d|",i);
		for(j=0;j<Taille;j++){
			if(grille[i][j]==0){
				printf("   |");
			}else if(grille[i][j]==-1){
				printf(" X |");
				}else{
					printf(" %d |",grille[i][j]);
			}
		}
		printf("\n");
		printf("-|");
		for(k=0;k<Taille;k++){
			printf("---|");

		}
		printf("\n");

	}
}


//Choix aléatoire

int alea(int a, int b){
    return (rand()%(b-a)+a);
}


//Positionnement navire

int Postionnavire(/*int Taille,*/int grille [Taille][Taille]){
	int posnav;
	int content;
	printf("Positionnement navire:\n");
	printf("1. Automatique\n");
	printf("2. Manuel\n");
	do{
		scanf("%d%*c", &posnav);
		printf("\n");
		switch (posnav)
		{
			case 1:
				printf("Vous avez choisi le mode automatique\n");
				do{
					// Initialisation de la grille
					initialiserGrille(Taille,grille);
					modeAuto(Taille,grille);
					afficherGrille(Taille,grille);
					printf("Etes-vous satisfait du placement?\n0.Oui\n1.Non\n");
					scanf("%d%*c", &content);
				}while(content!=0);
			break;
			case 2:
       				printf("Vous avez choisi le mode manuel\n");
       				do{
					// Initialisation de la grille
					initialiserGrille(Taille,grille);
					// Affichage de la grille vide
					printf("Grille vide:\n \n");
					afficherGrille(Taille,grille);
       					// Demander à l'utilisateur les bateaux
					printf("Placer les bateaux:\n \n");
					modeManuel(Taille,grille);
					printf("Etes-vous satisfait du placement?\n0.Oui\n1.Non\n");
					scanf("%d%*c", &content);
				}while(content!=0);
       			break;
       			default:
       				printf("Erreur redonnez un nombre entre 1 et 2");
		}
	}while((posnav!=1)&&(posnav!=2));
	printf("\n");
}


//Les bateaux :

// Bateaux automatique

int modeAuto(/*/*int Taille,*/*/int grille[Taille][Taille]){
	//Porte Avion
	int bat1=1;
	int Nbc1=5;
	bateauxgrilleauto(Taille,grille,Nbc1,bat1);
	//Croiseur
	int bat2=2;
	int Nbc2=4;
	bateauxgrilleauto(Taille,grille,Nbc2,bat2);
	//contre torpilleurs
	int bat3=3;
	int Nbc3=3;
	bateauxgrilleauto(Taille,grille,Nbc3,bat3);
	//sous marin
	int bat4=4;
	int Nbc4=3;
	bateauxgrilleauto(Taille,grille,Nbc4,bat4);
	//torpilleur
	int bat5=5;
	int Nbc5=2;
	bateauxgrilleauto(Taille,grille,Nbc5,bat5);

}


int bateauxgrilleauto(/*int Taille,*/int grille [Taille][Taille], int Nbc, int bat){
	int a;
	int b;
	int c;
	int i;
	int j;
	int houv;
	c = (Taille-Nbc);
        houv=alea(1,3);
	switch (houv)
	{
		case 1:
			do{
				//ligne
        			a = alea(0,Taille);
        			//colonne
        			b = alea(0,c);
			}while(grille[a][b]!=0);
			i=b;
			while((i>=b)&&(i<(b+Nbc))){
				if(grille[a][i]==0){
					grille[a][i]=bat;
					i++;
				}else{
					for(j=b;j<i;j++){
						grille[a][j]=0;
					}
					//ligne
        				a = alea(0,Taille);
        				//colonne
        				b = alea(0,c);
					i=b;
				}
			}
		break;
		case 2:
			do{
				//ligne
        			a = alea(0,c);
        			//colonne
        			b = alea(0,Taille);
			}while(grille[a][b]!=0);
			i=a;
			while((i>=a)&&(i<(a+Nbc))){
				if(grille[i][b]==0){
					grille[i][b]=bat;
					i++;
				}else{
					for(j=a;j<i;j++){
						grille[j][b]=0;
					}
					//ligne
        				a = alea(0,c);
        				//lcolonne
        				b = alea(0,Taille);
					i=a;
				}
			}
       		break;
       	}
}


//Bateaux manuels

int modeManuel(/*int Taille,*/int grille [Taille][Taille]){
	int Nbc;
	int bat;
	//Porte Avion
	printf("Porte avion(5 cases):\n");
	bat=1;
	Nbc=5;
	bateauxgrillemanuel(Taille,grille,Nbc,bat);
	afficherGrille(Taille,grille);
	//Croiseur
	printf("croiseur(4 cases):\n");
	bat++;
	Nbc=4;
	bateauxgrillemanuel(Taille,grille,Nbc,bat);
	afficherGrille(Taille,grille);
	//contre torpilleurs
	printf("contre torpilleurs(3 cases):\n");
	bat++;
	Nbc=3;
	bateauxgrillemanuel(Taille,grille,Nbc,bat);
	afficherGrille(Taille,grille);
	//sous marin
	printf("sous marin(3 cases):\n");
	bat++;
	Nbc=3;
	bateauxgrillemanuel(Taille,grille,Nbc,bat);
	afficherGrille(Taille,grille);
	//torpilleur
	printf("torpilleur(2 cases):\n");
	bat++;
	Nbc=2;
	bateauxgrillemanuel(Taille,grille,Nbc,bat);
	afficherGrille(Taille,grille);
}


int bateauxgrillemanuel(/*int Taille,*/int grille [Taille][Taille], int Nbc, int bat ){
	int a;
	int b;
	int i;
	int j;
	int houv;

	printf("Positionnement bateau:\n");
	printf("1. Horizontal\n");
	printf("2. Vertical\n");
	do{
		scanf("%d%*c", &houv);
		printf("\n");
		switch (houv)
		{
			case 1:
				printf("Horizontal\n");
				do{
					printf("Donnez une ligne pour la première case");
					scanf("%d%*c",&a);
					printf("Donnez une colonne pour la première case");
					scanf("%d%*c",&b);
					if((grille[a][b]!=0)||(b>(Taille-Nbc))){
						printf("Erreur, redonnez les coordonées de la première case.");
					}
				}while((grille[a][b]!=0)||(b>(Taille-Nbc)));
				i=b;
				while((i>=b)&&(i<(b+Nbc))){
					if(grille[a][i]==0){
						grille[a][i]=bat;
						i++;
					}else{
						printf("Erreur, redonnez les coordonées de la première case.");
						for(j=b;j<i;j++){
							grille[a][j]=0;
						}
						printf("Donnez une ligne pour la première case");
						scanf("%d%*c",&a);
						printf("Donnez une colonne pour la première case");
						scanf("%d%*c",&b);
						i=b;

					}
				printf("\n");

				}
			break;
			case 2:
       				printf("Vertical\n");
				do{
					printf("Donnez une ligne pour la première case");
					scanf("%d%*c",&a);
					printf("Donnez une colonne pour la première case");
					scanf("%d%*c",&b);
					if((grille[a][b]!=0)||(a>(Taille-Nbc))){
						printf("Erreur, redonnez les coordonées de la première case.");
					}
				}while((grille[a][b]!=0)||(a>(Taille-Nbc)));
				i=a;
				while((i>=a)&&(i<(a+Nbc))){
					if(grille[i][b]==0){
						grille[i][b]=bat;
						i++;
					}else{
						printf("Erreur, redonnez les coordonées de la première case.");
						for(j=a;j<i;j++){
							grille[j][b]=0;
						}
						printf("Donnez une ligne pour la première case");
						scanf("%d%*c",&a);
						printf("Donnez une colonne pour la première case");
						scanf("%d%*c",&b);
						i=a;

					}
				printf("\n");

				}
       			break;
       			}
		}while((houv!=1)&&(houv!=2));
	printf("\n");
}
