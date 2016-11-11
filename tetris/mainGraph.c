#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "termios.h"
#ifdef __APPLE__
#include "SDL.h"
#endif

#ifdef __linux__
#include "SDL/SDL.h"
#endif

void pause_game();

int main(int argc, char *argv[]) {
  SDL_Surface *ecran = NULL;

  ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
  pause_game();
  SDL_Quit();
  return 0;
}

void pause_game()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
