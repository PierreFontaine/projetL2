#include "BN.h"



// Jeu Joueur contre ordi

int jeuJVsOrdi(/*int Taille,*/int joueur,int jeuj1[Taille][Taille],int jeuj2[Taille][Taille],int grillej1[Taille][Taille],int grillej2[Taille][Taille],int *scorej1,int *scorej2,int batcoulej1,int batcoulej2,int nbj){
	int a;
	int b;
	int c=0;
	int d;
	int e;
	int f;
	int g;
	int Bateau=5;
	int choix;
	int joue=0;
	save sauvegarde;
	initialiserGrille(jeuj1);
	initialiserGrille(jeuj2);
	do{
		if(joueur==1){
			do{

				do{

					printf("C'est le tour du joueur %d:\n",joueur);
					printf("Grille j2");
					afficherGrille(/*Taille,*/grillej2);
					printf("Jeu j1");
					afficherGrille(/*Taille,*/jeuj1);
					printf("Donnez une ligne pour la case");
					scanf("%d",&a);
					printf("Donnez une colonne pour la case");
					scanf("%d",&b);
					if ((a==-1)||(b==-1)){
						printf("Voulez vous sauvegarder?\n1.Oui\n2.Non");
						scanf("%d",&choix);
						if (choix==1){
							sauvegardeJeu(/*Taille,*/joueur,jeuj1,jeuj2,grillej1,grillej2,scorej1,scorej2,batcoulej1,batcoulej2,nbj);
					}
					if (a<0||b<0||a>=Taille||b>=Taille||(jeuj1[a][b]!=0)||(jeuj2[a][b]!=0)){
						printf("Erreur\n");
					}
				}while(a<0||b<0||a>=Taille||b>=Taille||(jeuj1[a][b]!=0)||(jeuj2[a][b]!=0));
				tcr(/*Taille,*/&batcoulej1,jeuj1,grillej2,a,b);
			}while(c!=1);
			system("clear");
		}else{
			if(joue==0){
				do{
					d=alea(0,10);
					e=alea(0,10);
					f=d;
					g=e;
				}while(jeuj2[d][e]!=0);
				jeuOrdi(/*Taille,*/&batcoulej2,jeuj2,grillej1,Bateau,d,e,&joue);
			}else if (joue==1){
				do{
					f++;
					if(jeuj2[f][e]==-1){
						joue=2;
						f=d;
					}
				}while(jeuj2[f][e]!=0);
				jeuOrdi(/*Taille,*/&batcoulej2,jeuj2,grillej1,Bateau,f,e,&joue);
			}else if (joue==2){
				do{
					f--;
					if(jeuj2[f][e]==-1){
						joue=3;
						f=d;
					}
				}while(jeuj2[f][e]!=0);
				jeuOrdi(/*Taille,*/&batcoulej2,jeuj2,grillej1,Bateau,f,e,&joue);
			}else if (joue==3){
				do{
					g++;
					if(jeuj2[d][g]==-1){
						joue=4;
						g=e;
					}
				}while(jeuj2[d][g]!=0);
				jeuOrdi(/*Taille,*/&batcoulej2,jeuj2,grillej1,Bateau,d,g,&joue);
			}else if (joue==4){
				do{
					g--;
					if(jeuj2[d][g]==-1){
						joue=0;
					}
				}while(jeuj2[d][g]!=0);
				jeuOrdi(/*Taille,*/&batcoulej2,jeuj2,grillej1,Bateau,d,g,&joue);

			}
			printf("Jeu joueur 2");
			afficherGrille(/*Taille,*/jeuj2);

		}

		if (joueur==1){
			joueur++;
		}else{
			joueur--;
		}
			printf("%d %d %d",batcoulej1,batcoulej2,Bateau);
	}while((batcoulej1!=Bateau)&&(batcoulej2!=Bateau));
	system("clear");
	printf("La partie est finie\n");
	if(batcoulej1==Bateau){
		printf("Vous avez gagné\n");
		(*scorej1)++;
		printf("%d",*scorej1);
	}else{
		printf("L'ordinateur a gagné\n");
		(*scorej2)++;
		printf("%d",*scorej2);
	}
}

//Jeu ordinateur

int jeuOrdi(/*int Taille,*/int *batcoule, int jeu[Taille][Taille],int grille[Taille][Taille],int Bateau,int a,int b, int *joue){
	int i;
	int j;
	int compteur=0;
	jeu[a][b]=grille[a][b];
	grille[a][b]=0;
	if(jeu[a][b]!=0){
		for(i=0;i<Taille;i++){
			for(j=0;j<Taille;j++){
				if(grille[i][j]==jeu[a][b]){
					compteur++;
				}
			}
		}
		if(compteur!=0){//touché
			if((*joue)==0){
				if(a>0){
					(*joue)=1;
				}else{
					(*joue)=2;
				}
			}else if((*joue)==1){
				if(a==0){
					(*joue)=2;
				}
			}else if((*joue)==2){
				if(a==9){
					(*joue)=0;
				}
			}else if((*joue)==3){
				if(b==0){
					(*joue)=4;
				}
			}else if((*joue)==4){
				if(b==9){
					(*joue)=0;
				}
			}
		}else{//coulé
			(*batcoule)++;
			(*joue)=0;
		}

	}else{//raté
		jeu[a][b]=-1;
		if((*joue)==1){
			if(a<9){
				(*joue)=2;
			}else if(b>0){
				(*joue)=3;
			}else if(b<9){
				(*joue)=4;
			}else{
				(*joue)=0;
			}
		}else if((*joue)==2){
			if(b>0){
				(*joue)=3;
			}else if(b<9){
				(*joue)=4;
			}else{
				(*joue)=0;
			}
		}else if((*joue)==3){
			if(b<9){
				(*joue)=4;
			}else{
				(*joue)=0;
			}
		}else if((*joue)==4){
			(*joue)=0;
		}
	}
}






//Jeu 2 joueurs new game


int jeuDeuxJ(/*int Taille,*/int joueur,int jeuj1[Taille][Taille],int jeuj2[Taille][Taille],int grillej1[Taille][Taille],int grillej2[Taille][Taille],int *scorej1,int *scorej2,int batcoulej1, int batcoulej2,int nbj){
	int a;
	int b;
	int i;
	int j;
	int Bateau=5;
	int choix;
	save sauvegarde;

	do{
		if (joueur==1){
			choisirCase(/*Taille,*/jeuj1,grillej2,&a,&b,joueur);
			if ((a==-1)||(b==-1)){
				printf("Voulez vous sauvegarder?\n1.Oui\n2.Non");
				scanf("%d",&choix);

			}
			if (choix==1){
				sauvegardeJeu(/*Taille,*/joueur,jeuj1,jeuj2,grillej1,grillej2,scorej1,scorej2,batcoulej1,batcoulej2,nbj);
			}else{
				tcr(Taille,&batcoulej1,jeuj1,grillej2,a,b);
			}
		}else{
			choisirCase(/*Taille,*/jeuj2,grillej1,&a,&b,joueur);
			if ((a==-1)||(b==-1)){
				printf("Voulez vous sauvegarder?\n1.Oui\n2.Non");
				scanf("%d",&choix);

			}
			if (choix==1){
				sauvegardeJeu(/*Taille,*/joueur,jeuj1,jeuj2,grillej1,grillej2,scorej1,scorej2,batcoulej1,batcoulej2,nbj);
			}else{
				tcr(/*Taille,*/&batcoulej2,jeuj2,grillej1,a,b);
			}
		}
		printf("%d %d %d",batcoulej1,batcoulej2,Bateau);
		system("clear");
		if (joueur==1){
			joueur++;
		}else{
			joueur--;
		}
		printf("%d %d %d",batcoulej1,batcoulej2,Bateau);
	}while((batcoulej1!=Bateau)&&(batcoulej2!=Bateau));
	system("clear");
	printf("La partie est finie\n");
	if(batcoulej1==Bateau){
		printf("Le joueur 1 a gagné\n");
		(*scorej1)++;
		printf("%d",*scorej1);

	}else{
		printf("Le joueur 2 a gagné\n");
		(*scorej2)++;
		printf("%d",*scorej2);
	}
}

//
int choisirCase(/*int Taille,*/int jeu[Taille][Taille],int grille[Taille][Taille],int *a,int *b,int joueur){
		do{

			printf("C'est le tour du joueur %d:\nSi vous souhaitez arreter le jeu, écrire la valeur -1\n",joueur);
			afficherGrille(/*Taille,*/grille);
			afficherGrille(/*Taille,*/jeu);
			printf("Donnez une ligne pour la case");
			scanf("%d",a);
			printf("Donnez une colonne pour la case");
			scanf("%d",b);
			if ((*a)<-1||(*b)<-1||(*a)>=Taille||(*b)>=Taille||(jeu[*a][*b]!=0)){
				printf("Erreur\n");
			}
		}while((*a)<-1||(*b)<-1||(*a)>=Taille||(*b)>=Taille||(jeu[*a][*b]!=0));
}


// Touché Coulé Raté

int tcr(/*int Taille,*/int *batcoule, int jeu[Taille][Taille],int grille[Taille][Taille],int a,int b){
	int i;
	int j;
	int compteur=0;
	jeu[a][b]=grille[a][b];
	grille[a][b]=0;
	if(jeu[a][b]!=0){
		for(i=0;i<Taille;i++){
			for(j=0;j<Taille;j++){
				if(grille[i][j]==jeu[a][b]){
					compteur++;
				}
			}
		}
		if(compteur!=0){
			printf("touché\n");
		}else{
			printf("coulé\n");
			(*batcoule)++;
			printf("Vous avez coulé %d bateaux\n",*batcoule);
		}

	}else{
		jeu[a][b]=-1;
		printf("raté\n");
		afficherGrille(/*Taille,*/jeu);
	}
}
