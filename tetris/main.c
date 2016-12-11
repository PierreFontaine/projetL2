#include "affichage.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "termios.h"
#include "string.h"
#include "save.h"
#include "ncurses.h"
#include "menu.h"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

int launchGame();

int menu(){
  //tableaux des options
  char *choices[] = {
    "jouer",
    "score",
    "quitter",
  };

  ITEM **my_items;
	int c;
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;
  int choix;
  bool quitter;

  quitter = false;

  choix = 1;
	n_choices = ARRAY_SIZE(choices); //recuperation de la taille du tableau
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));  //allocation des items
  //affichage des items
	for(i = 0; i < n_choices; ++i){
    my_items[i] = new_item("    ",choices[i]);
  }

	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
  attron(COLOR_PAIR(1));
	mvprintw(LINES - 2, 0, "F1 to Exit");
  attroff(COLOR_PAIR(1));
	post_menu(my_menu);
	refresh();

	while((c = getch()) != quitter){
    switch(c){
      case KEY_DOWN:
		    menu_driver(my_menu, REQ_DOWN_ITEM);
        if (choix < n_choices) {
          choix ++;
        }
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
        if (choix > 1) {
          choix--;
        }
				break;
      case 10:{
        if(choix == 1){
          launchGame();
          erase();
          refresh();
        } else if (choix == 2) {
          erase();
          sortScore();
          refresh();
        } else  if (choix == 3){
          free_item(my_items[0]);
        	free_item(my_items[1]);
        	free_menu(my_menu);
          return 0;
        }
      }
		}
	}


  //Liberation des espaces mémoires
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
  return 0;
}

int launchGame(){
  layout l_jeu;
  piece p_jeu;
  pos p_posInit;
  float s_jeu;
  gameState etat;
  game(l_jeu,&p_jeu,&p_posInit,&s_jeu,&etat);
  return 1;
}

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_AUDIO);
  if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1) {
    printf("%s", Mix_GetError());
  }
  Mix_Music *musique;
  musique = Mix_LoadMUS("./assets/reputation.wav");
  Mix_PlayMusic(musique, -1);
  init_ncurses();
  menu();
  endwin();
  Mix_FreeMusic(musique);
  Mix_CloseAudio();
  SDL_Quit();
  return 0;
}
