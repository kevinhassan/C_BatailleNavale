#include "bateau.h"

Bateau creerBateau(Position p, char sens, int l)
{
    /*Creer un bateau de position de tete p, avec les nouvelles position qui suivent le sens de s.*/
    Bateau *Bat=malloc(sizeof(int)+ sizeof(Position)+2*sizeof(*TListe)); //Car la liste contiendra des positions et elle est constituée de 2 pointeurs suivant et précédent du type liste doublement chainée
    Bat->longueur=l;
    Position *p1=creerPosition(getXPos(p),getYPos(p));
    AjoutDebut(Bat->positions, p1);
    int i;
    for (i=1;i<l;i++){
        if (sens=='v'){
            setYPos(p1,getYPos(p1)+1);
        }
        else if (sens=='h'){
            setXPos(p1,getXPos(p1)+1);
        }
        AjoutDebut (Bat->positions, p1);
    }
    return Bat;
}
Bateau supprPosition(Bateau b, Position p)
{
    bool flag = False;
    /* Supprime la position p du bateau quand on sait qu'elle est la et diminue ainsi la longueur du bateau*/
    if(positionPresente(b, p))
    {
        //Si l'une des positions du bateau est égale à celle cherché (tant qu'on est pas arrivé au bout)
        while (b->positions != p & b->positions != NULL)
        {
            b->positions->suivant;
        }
        b->positions->x = NULL;
        b->positions->y = NULL;
        b->longueur = b->longueur-1;
    }
    //Chainage arriere à faire ?
}
bool positionPresente(Bateau b, Position p)
{
    /* Retourne True si cette position appartient au bateau. */
    bool present = False;
    while (b->positions != p & b->positions != NULL){
        b->positions->suivant;
    }
    return b->positions == p;
    //Chainage arriere à faire ?
}
bool bateauEnVue(Bateau b, Position p)
{
    /* retourne True si le bateau est en vue de la position p.*/
    return b->positions->x == p->x || b->positions->y != p->y; 
}
bool EstCoule(Bateau b)
{
    /*  Retourne True si le bateau n'a plus de position 'en vie'.*/
    /*  On enleve les positions et on décremente la longueur => Si longueur
        nulle => bateau coule
    */
    return b->longueur == 0;
}
int getTaille(Bateau b)
{
    /*On récupère la taille du bateau*/
    return b->longueur;
}

/*
    Il manque la fonction a l'eau
*/ 