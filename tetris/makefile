all: affichage.o main.o tetris.o keyboard.o
	gcc keyboard.o affichage.o main.o tetris.o -o programme -lpthread

main.o : main.c
	gcc -c main.c -o main.o

affichage.o : affichage.c
	gcc -c affichage.c -o affichage.o

tetris.o : tetris.c
	gcc -c tetris.c -o tetris.o

keyboard.o : keyboard.c
	gcc -c keyboard.c -o keyboard.o
