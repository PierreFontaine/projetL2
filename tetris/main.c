#include "affichage.h"
//#include "keyboard.h"
#include "tetris.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "termios.h"
#include "string.h"
#include "save.h"
#include "ncurses.h"
#include "menu.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

int launchGame();

void menu(){
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

  choix = 1;

	n_choices = ARRAY_SIZE(choices); //recuperation de la taille du tableau
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));  //allocation des items
  //affichage des items
	for(i = 0; i < n_choices; ++i){
    my_items[i] = new_item("    ",choices[i]);
  }

	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "F1 to Exit");
	post_menu(my_menu);
	refresh();

	while((c = getch()) != KEY_F(1)){
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
        } else if (choix == 2) {
          readScore();
        } else {
          break;
        }
      }
		}
	}


  //Liberation des espaces mémoires
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
}

int launchGame(){
  layout l_jeu;
  piece p_jeu;
  pos p_posInit;
  int s_jeu;
  gameState etat;

  game(l_jeu,&p_jeu,&p_posInit,&s_jeu,&etat);
  return 1;
}

int main(int argc, char const *argv[]) {
  init_ncurses();
  menu();
  endwin();
  return 0;
}
