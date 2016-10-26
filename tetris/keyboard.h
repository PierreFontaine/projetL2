#ifndef keyboard_h
#define keyboard_h

#define KEY_PAUSE       'p'
#define KEY_MOVE_RIGHT  'd'
#define KEY_MOVE_LEFT   'q'
#define KEY_REACH_FLOOR 's'

void pause();
void moveRigth();
void moveLeft();
void drop();
void rotate(int angle);

#endif
