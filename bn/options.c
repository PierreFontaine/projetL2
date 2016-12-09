#include "BN.h"


int lesOptions(int Taille){
	int opt;
	
	printf("Options:\n");
	printf("1. Taille grille\n");
	printf("2. Bateaux en diagonales\n");
	printf("3. Bateaux cases adjacentes\n");
	printf("4. Nombre bateaux\n");
	printf("5. Affichage coulé\n");
	printf("6. Durée d'un tour\n");
	printf("7. Distance bateau le plus proche\n");
	printf("8. Mode salvo\n");
	printf("9. Quitter option\n");
	do{
		scanf("%d%*c", &opt);
		printf("\n"); 
		switch (opt)
		{
			case 1:
				scanf("%d%*c", &Taille);
				options.Taille=Taille;
			break;
			case 2:

       			break;
       			case 3:

			break;
			case 4:

			break;
			case 5:

			break;
			case 6:

			break;
			case 7:

			break;
			case 8:

			break;
			case 9:
				sauvegardeOptions(Taille);
				return 0;
			break;		
       			default:
       				printf("Erreur redonnez un nombre entre 1 et 9");
		}
	}while(opt!=9);
	printf("\n");
}*/
