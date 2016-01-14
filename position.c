#include "position.h";

Position creerPosition(int x, int y)
{
    /* Creer une position en x,y */
    Position* p = malloc(sizeof(Position));
    setXPos(p, x);
    setYPos(p, y);
    return p;
}
int getXPos(Position p)
{
    /*Retourne la coordonnee x*/
    return p->x;
}
int getYPos(Positionosition p)
{
    /*retourne la coordonnee y*/
    return p->y;
}
void setXPos(Position p,int x)
{
    /*change la coordonnee x*/
    p->x = x;
}
void setYPos(Position p,int y)
{
    /*change la coordonnee y*/
    p->y = y;
}
bool comparerPosition(Position p1, Position p2)
{
    /* Retourne True si les position correspondent*/
    return getXPos(p1)==getXPos(p2) && getYPos(p1)==getYPos(p2);
}
bool enVuePosition(Position p1, Position p2)
{
    /* Retourne True si les position ont au moins une coordonnée identique*/
    return (getXPos(p1)==getXPos(p2) && getYPos(p1)!=getYPos(p2)) || (getXPos(p1)!=getXPos(p2) && getYPos(p1)==getYPos(p2));
}

bool positionValide(Position p)
{
    /* Retourne True si la position est dans la grille et donc valide.*/
    return ((getXPos(p) >=0) && (getXPos(p)<= 20)) && ((getYPos(p) >=0) && (getYPos(p) <=20));
}

/*
    Il manquait les valeurs à inserer sur les setXPos et setYPos
*/
