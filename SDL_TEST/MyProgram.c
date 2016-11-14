#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <OpenGL/gl3.h>

#define WIDTH 640
#define HEIGHT 480
#define NAME "Ma première application SDL2"

void resume()
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


int main(int argc, char *argv[])
{
  SDL_Window *pWindow = NULL;

  if(SDL_Init(SDL_INIT_VIDEO) != 0){
    fprintf(stdout,"echec d'init SDL (%s) \n", SDL_GetError());
    return -1;
  }

  pWindow = SDL_CreateWindow("test",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    620,400,
    SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED
  );
  resume();
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return EXIT_SUCCESS;
}
