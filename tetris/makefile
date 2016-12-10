OS := $(shell uname)

ifeq ($(OS),Darwin)
#option de compilation
CFLAGS =`sdl-config --cflags --libs`
#option liens
LDFLAGS =`sdl-config --libs` -lSDLmain -lSDL
FRAMEWORK =-framework Cocoa
DEVLIB = SDLMain.m
#compilateur utilisé
CC = gcc

else
CC = gcc
LDFLAGS = -lSDLmain -lSDL
CFLAGS =
FRAMEWORK =
DEVLIB =
endif

all: affichage.o main.o tetris.o save.o
	${CC} -std=c99 affichage.o main.o tetris.o save.o -o programme -lncurses -lmenu -lSDL_mixer ${LDFLAGS}
	rm *.o

main.o : main.c
	${CC} -std=c99  -c main.c -o main.o -lSDL_mixer

mainGraph.o : mainGraph.c
	${CC} -std=c99 -c mainGraph.c -o mainGraph.o


affichage.o : affichage.c
	${CC} -std=c99 -c  affichage.c -o affichage.o ${CFLAGS} ${FRAMEWORK}

tetris.o : tetris.c
	${CC} -std=c99 -c  tetris.c -o tetris.o -lncurses ${CFLAGS} ${FRAMEWORK}

save.o : save.c
	${CC} -std=c99 -c save.c -o save.o ${CFLAGS} ${FRAMEWORK}
