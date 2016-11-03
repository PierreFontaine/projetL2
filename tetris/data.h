#ifndef data_h
#define data_h


#define NB_PIECE 7

typedef enum piece {
  S,S_90,
  Z,Z_90,
  L,L_90,L_180,L_270,
  J,J_90,J_180,J_270,
  T,T_90,T_180,T_270,
  I,I_90,
  C,
  }piece;

typedef enum direction {SUD,WEST,EST}direction;

/* SPRITE */

/* PARAMETRE DE JEU */
#define GAME_HEIGHT         12
#define GAME_WIDTH          10
#define PIECE_MAX_WIDTH     4
#define PIECE_MAX_HEIGHT    4

#define UNIX_COLOR_BLACK    "30"
#define UNIX_COLOR_RED      "31"
#define UNIX_COLOR_GREEN    "32"
#define UNIX_COLOR_YELLOW   "33"
#define UNIX_COLOR_BLUE     "34"
#define UNIX_COLOR_MAGENTA  "35"
#define UNIX_COLOR_CYAN     "36"
#define UNIX_COLOR_WHITE    "37"
#define UNIX_COLOR_RESET    "0"

typedef struct figure{
  int heigth;
  int width;
  char forme[PIECE_MAX_HEIGHT][PIECE_MAX_WIDTH];
  int sprite;
}figure;

typedef struct pos{
  int x;
  int y;
}pos;

typedef char layout[GAME_HEIGHT][GAME_WIDTH];

#define KEY_PAUSE       'p'
#define KEY_MOVE_RIGHT  'd'
#define KEY_MOVE_LEFT   'q'
#define KEY_REACH_FLOOR 's'
#define KEY_ROTATE      'z'

#endif
