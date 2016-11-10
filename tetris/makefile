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
CFLAGS = -lSDL -lSDL_mixer
FRAMEWORK =
DEVLIB =
endif

all: affichage.o main.o tetris.o keyboard.o
	${CC} keyboard.o affichage.o main.o tetris.o ${DEVLIB} -o programme ${CFLAGS} ${FRAMEWORK} -lpthread

main.o : main.c
	${CC}  -c  -lpthread main.c -o main.o ${CFLAGS} ${FRAMEWORK}

affichage.o : affichage.c
	${CC} -c  affichage.c -o affichage.o ${CFLAGS} ${FRAMEWORK}

tetris.o : tetris.c
	${CC} -c  tetris.c -o tetris.o ${CFLAGS} ${FRAMEWORK}

keyboard.o : keyboard.c
	${CC} -c keyboard.c -o keyboard.o ${CFLAGS} ${FRAMEWORK}
