#ifndef data_h
#define data_h


#define NB_PIECE 20

typedef enum piece {S,Z,L,J,T,I}piece;

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

#endif
