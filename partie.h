#ifndef PARTIE_H
#define PARTIE_H
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "joueur.h"
#include "bateauX.h"
#include "bateau.h"
#include "position.h"
typedef struct Partie Partie ;



Partie creerPartie(); /* Créer une partie, complete la structure comme necessaire à l'initialisation */
Partie joueurSuivant(Partie p); /* Change le joueur actif et le joueur passif. Le joueur actif devient passif et inversement */
Joueur joueurActif(Partie p);/* Renvoie le joueur actif */
Joueur joueurPassif(Partie p); /* renvoie joueur passif */
char* phaseTir(Partie p, Position pos); /* Determine si p touche un bateau du joueur passif(et lance dans ce cas la Phase de destruction), si un bateau est en vue ou si le tir est à l'eau ou coulé  */
Partie phaseDestruction(Partie p, Position pos); /*Si on est sur que la position touche, retire la position du bateau touche.
                                                    Si celui si n'a plus de position, le supprime de l'ensemble des bateaux.
                                                    Si le joueur passif n'a plus de bateau la condition de vitoire est remplie. */
bool partieFinie(Partie p ); /* Declare que la partie est finie si True. */

#endif
