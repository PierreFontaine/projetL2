#ifndef liste_h
#define liste_h

typedef struct cellule{
  struct cellule *suivant;
  int value;
}cellule;

typedef cellule* liste;

int estNul(liste l);



#endif
