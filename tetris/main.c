#include "affichage.h"
//#include "keyboard.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
//#include "pthread.h"
#include "termios.h"
#ifdef __APPLE__
#include "SDL.h"
#endif

#ifdef __linux__
#include "SDL/SDL.h"
#endif

layout l_jeu;
piece p_jeu;
pos p_posInit;

int main(int argc, char *argv[]) {
  static struct termios oldt, newt;


/*
  if(pthread_create(&thread1, NULL, thread_1, NULL) == -1){
  	perror("pthread_create");
  	return EXIT_FAILURE;
  }
*/
  /**
  * Changement du comportement du terminal sur le buffer
  * On veut pouvoir dans le thread capturer le dernier caractère sans attendre le retour chariot
  * cf man termios
  *
  **/
  tcgetattr(STDIN_FILENO, &oldt);//On place les paramètre du terminal dans une struct termios
  newt = oldt; //initialisation de newt avec oldt
  newt.c_lflag &= ~(ICANON); //mise a jour du mode canonique sur newt
  //TCSANOW change occurs immediately | cf : man tcsetattr
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); //le terminal prend les paramètre de newt
  SDL_Init(SDL_INIT_VIDEO);

    SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
  game(l_jeu,&p_jeu,&p_posInit);
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
  SDL_Quit();
  return 0;
}
