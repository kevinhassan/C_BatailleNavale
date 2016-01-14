#ifndef POSITION_H
#define POSITION_H
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "joueur.h"
#include "partie.h"
#include "bateauX.h"
#include "bateau.h"

typedef struct Position;
struct Position{
    int x;
    int y;
};
typedef Position *Position;

Position creerPosition(int x, int y); /* creer une position en x,y*/
int getXPos(Position p); /*retourne la coordonnee x*/
int getYPos(Position p); /*retourne la coordonnee y*/
void setXPos(Position p,x); /*change la coordonnee x*/
void setYPos(Position p,y); /*change la coordonnee y*/
bool comparerPosition(Position p1, Position p2); /* Retourne True si les position correspondent*/
bool enVuePosition(Position p1, Position p2); /* Retourne True si les position ont au moins une coordonnée identique*/
bool positionValide(Position p); /* Retourne True si la position est dans la grille et donc valide.*/


#endif
