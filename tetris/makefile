all: affichage.o main.o tetris.o liste.o
	gcc affichage.o liste.o main.o tetris.o -o programme

main.o : main.c
	gcc -c main.c -o main.o

affichage.o : affichage.c
	gcc -c affichage.c -o affichage.o

tetris.o : tetris.c
	gcc -c tetris.c -o tetris.o

liste.o : liste.c
	gcc -c liste.c -o liste.o
