#ifndef BATEAUX_H
#define BATEAUX_H
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "joueur.h"
#include "partie.h"
#include "bateau.h"
#include "position.h"
typedef struct Bateaux Bateaux;

Bateaux creerBateaux(); /* Creer un collection de bateaux vide.*/
int nombreBateaux(Bateaux bx); /*Indique le nombre de bateaux en jeu dans la collection Bx.*/
Bateau bateauNumero(Bateaux Bx, int i); /*Renvoie le bateau identifier par i.*/
Bateaux ajouterBateau(Bateaux Bx, Bateau B);/*Ajoute le bateau b � la collection Bx, et donc augmente le nombre de bateau de la liste.*/
Bateaux retirerBateau(Bateaux Bx, int i); /*Retire le bateau identifi� par i, on doit �tre sur que i est le bateau que l'on veut retirer. On reduit ainsi le nombre de bateaux*/
bool positionOccupee(Bateaux Bx, Position p);/* Renvoie True si un bateau de la collection Bx est � cette position.*/
bool enVue(Bateaux Bx, Position p); /* Renvoie True si un bateau de la collection Bx est en vue de la position p.*/
int trouverBateau(Bateaux bx, Position p); /* Renvoie un entier qui identifie le bateau qui se trouve � la position p, si on sait qu'un bateau y est*/
bool positionnnementBateauValide(Bateaux Bx, Position p, char s, int l); /* Verifie si un bateau de position de tete p, de longueur l et d'orientation s, sont valides et in-occup�es.*/

#endif
