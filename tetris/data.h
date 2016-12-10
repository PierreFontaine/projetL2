#ifndef data_h
#define data_h

#define NB_PIECE 7

typedef enum piece_str {
  S,S_90,
  Z,Z_90,
  L,L_90,L_180,L_270,
  J,J_90,J_180,J_270,
  T,T_90,T_180,T_270,
  I,I_90,
  C,
  }piece;

typedef enum gameState_enum {PAUSE,RESUME}gameState;

typedef enum direction_enum {SUD,WEST,EST}direction;

typedef struct player_str{
  char nom[100];
  int score;
  int ligne;
}player;

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

#define COLOR_BLACK   0
#define COLOR_RED     1
#define COLOR_GREEN   2
#define COLOR_YELLOW  3
#define COLOR_BLUE    4
#define COLOR_MAGENTA 5
#define COLOR_CYAN    6
#define COLOR_WHITE   7

typedef struct figure_str{
  int heigth;
  int width;
  char forme[PIECE_MAX_HEIGHT][PIECE_MAX_WIDTH];
  piece suivante;
  piece precedente;
}figure;

typedef struct pos_str{
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
