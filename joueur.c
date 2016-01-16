#include "joueur.h"

Joueur creerJoueur(int id)
{
	/*Creé un joueur avec id pour l'identifier.*/
	Joueur* j = malloc(sizeof(Joueur));
	j->idJoueur = id;
	return j;
}

int idJoueur(Joueur j){
	/*Renvoie le nom du joueur pour qu'il se reconnaisse*/
	return j->idJoueur;
}
bool bateauxNonCoulee(Joueur j)
{
	/*Renvoie True s'il reste des bateaux en jeu au joueur.*/
	return !EstVide(j->ensembleBat);//Méthode du type de la liste chainée
}
Joueur placementBateaux(Joueur j)
{
	/* Fait placer au joueur j ses bateaux de taille fixée.*/
	//----------------------------------
	//Cette fonction n'est pas utilisée dans le main
	
}
Bateaux bateauxJoueur(Joueur j)
{
	/*Recupère la collection de bateaux de joueurs.*/
	return j->ensembleBat;
}

