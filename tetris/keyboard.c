#include "keyboard.h"
#include "stdio.h"
#include "stdlib.h"
#include "tetris.h"

void capture(piece p, layout l, pos a){
  char choix;

  scanf("%c\n",&choix);

  switch (choix) {
    case KEY_PAUSE:
      resume();
      break;
    case KEY_MOVE_RIGHT:
      pieceMoveToward(p,EST,&a,l);
      break;
    case KEY_MOVE_LEFT:
      pieceMoveToward(p,WEST,&a,l);
      break;
    case KEY_ROTATE:
      rotatePiece();
    default:
      printf("%s\n","mauvaise touche");
      break;
  }
}
