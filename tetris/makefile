OS := $(shell uname)

ifeq ($(OS),Darwin)
#option de compilation
CFLAGS = `sdl-config --cflags --libs`
#option liens
LDFLAGS = `sdl-config --libs`
FRAMEWORK = -framework Cocoa
DEVLIB = SDLMain.m
#compilateur utilisé
CC = gcc

else
CC = gcc
CFLAGS = `sdl-config --cflags --libs`
FRAMEWORK =
DEVLIB =
endif

all: affichage.o mainGraph.o main.o tetris.o keyboard.o
	${CC} affichage.o mainGraph.o tetris.o ${DEVLIB} -o programmeGraph ${CFLAGS} ${FRAMEWORK}
	${CC} keyboard.o affichage.o main.o tetris.o -o programme -lpthread

main.o : main.c
	${CC}  -c main.c -o main.o

mainGraph.o : mainGraph.c
	${CC} -c mainGraph.c -o mainGraph.o ${CFLAGS} ${FRAMEWORK}


affichage.o : affichage.c
	${CC} -c  affichage.c -o affichage.o ${CFLAGS} ${FRAMEWORK}

tetris.o : tetris.c
	${CC} -c  tetris.c -o tetris.o ${CFLAGS} ${FRAMEWORK}

keyboard.o : keyboard.c
	${CC} -c keyboard.c -o keyboard.o ${CFLAGS} ${FRAMEWORK}
