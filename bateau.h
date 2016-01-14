#ifndef BATEAU_H
#define BATEAU_H
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "joueur.h"
#include "partie.h"
#include "bateauX.h"
#include "position.h"

typedef struct bateau bateau;
struct bateau {
    int longueur;
    TListe positions;
};
typedef bateau* Bateau;


Bateau creerBateau(Position p, char sens, int l); /*Creer un bateau de position de tete p, avec les nouvelles position qui suivent le sens de s.*/
Bateau supprPosition(Bateau b, Position p); /* Supprime la position p du bateau quand on sait qu'elle est la et diminue ainsi la longueur du bateau*/
bool positionPresente(Bateau b, Position p); /* Retourne True si cette position appartient au bateau. */
bool bateauEnVue(Bateau b, Position p); /* retourne True si le bateau est en vue de la position p.*/
bool EstCoule(Bateau b); /* Retourne True si le bateau n'est plus de position 'en vie'.*/
int getTaille(Bateau b); /*On récupère la taille du bateau
#endif
