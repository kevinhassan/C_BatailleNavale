#ifndef JOUEUR_H
#define JOUEUR_H
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "bateauX.h"
#include "joueur.h"


typedef struct joueur joueur;
struct joueur{
	bool actif = False;//On impose aux joueurs d'�tre inactif en d�but de partie jusqu'au placement des bateaux
	int idJoueur;
	Bateaux ensembleBat;//?pointeur
};
typedef joueur *Joueur;

Joueur creerJoueur(int id); /*Cre� un joueur avec id pour l'identifier.*/
int idJoueur(Joueur j); /*Renvoie le nom du joueur pour qu'il se reconnaisse*/
bool bateauxNonCoulee(Joueur j); /*Renvoie True s'il reste des bateaux en jeu au joueur.*/
Joueur placementBateaux(Joueur j); /* Fait placer au joueur j ses bateaux de taille fix�e.*/
Bateaux bateauxJoueur(Joueur j);/*Recup�re la collection de bateaux de joueurs.*/

#endif
