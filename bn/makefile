BN:main.o bat.o jeu.o options.o sauvegarde.o
	gcc -o BN main.o bat.o jeu.o options.o sauvegarde.o -lSDLmain -lSDL
main.o: main.c
	gcc -c main.c  -lSDLmain -lSDL
bat.o: bat.c
	gcc -c bat.c -lSDLmain -lSDL
jeu.o: jeu.c
	gcc -c jeu.c -lSDLmain -lSDL
options.o: options.c
	gcc -c options.c -LSDLmain -LSDL
sauvegarde.o: sauvegarde.c
	gcc -c sauvegarde.c -LSDLmain -LSDL
	
