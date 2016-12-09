#ifndef BN
#define BN
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>


typedef struct save_str{
	int nbj;
	int Taille;
	int joueur;
	int scorej1;
	int scorej2;
	int grillej1[Taille][Taille];
	int grillej2[Taille][Taille];
	int jeuj1[Taille][Taille];
	int jeuj2[Taille][Taille];
	int batcoulej1;
	int batcoulej2;
}save;

typedef struct option_str{
	int Taille;
}opts;

int Postionnavire(int Taille,int grille[Taille][Taille]);

void initialiserGrille(int Taille,int grille[Taille][Taille]);

void afficherGrille(int Taille,int grille[Taille][Taille]);

int alea(int a, int b);

int modeAuto(int Taille,int grille[Taille][Taille]);

int bateauxgrilleauto(int Taille,int grille[Taille][Taille], int Nbc, int bat);

int modeManuel(int Taille,int grille[Taille][Taille]);

int bateauxgrillemanuel(int Taille,int grille[Taille][Taille], int Nbc, int bat);

int jeuJVsOrdi(int Taille,int joueur,int jeuj1[Taille][Taille],int jeuj2[Taille][Taille],int grillej1[Taille][Taille],int grillej2[Taille][Taille],int *scorej1,int *scorej2,int batcoulej1, int batcoulej2,int nbj);

int jeuOrdi(int Taille,int *batcoule, int jeu[Taille][Taille],int grille[Taille][Taille],int Bateau,int a,int b, int *joue);

int jeuDeuxJ(int Taille,int joueur,int jeuj1[Taille][Taille],int jeuj2[Taille][Taille],int grillej1[Taille][Taille],int grillej2[Taille][Taille],int *scorej1,int *scorej2,int batcoulej1, int batcoulej2,int nbj);

int choisirCase(int Taille,int jeu[Taille][Taille],int grille[Taille][Taille],int *a,int *b,int joueur);

int tcr(int Taille,int *batcoule,int jeu [Taille][Taille],int grille[Taille][Taille],int a,int b);

void saveJeu(save *sauvegarde);

void sauvegardeJeu(int Taille,int joueur,int jeuj1[Taille][Taille],int jeuj2[Taille][Taille],int grillej1[Taille][Taille],int grillej2[Taille][Taille],int scorej1,int scorej2,int batcoulej1, int batcoulej2,int nbj);

int lesOptions(int Taille);

#endif
