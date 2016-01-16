#include "bateauX.h"

Bateaux creerBateaux()
{
	Bateaux* bx = malloc(sizeof(BateauX));
	return bx;
}
int nombreBateaux(Bateaux bx)
{
	return bx->NbOccurences();
}
Bateau bateauNumero(Bateaux Bx, int i)
{
	Bateau* bateau = bx->ensembleBat->bat;
	if(bateau->numero == i)
	{
		return bateau;	
	}
	else
	{
		return NULL;
	}
} 
Bateaux ajouterBateau(Bateaux Bx, Bateau B)
{
	/*Ajoute le bateau b à la collection Bx, et donc augmente le nombre de bateau de la liste.*/
	if (EstVide(Bx->ensembleBat))
	{
		AjoutDebut(Bx->ensembleBat,B);
	}
	else
	{
		AjoutFin(Bx->ensembleBat,B);
	}
	return Bx;
}
Bateaux retirerBateau(Bateaux Bx, int i)
{
	/*Retire le bateau identifié par i, on doit être sur que i est le bateau que l'on veut retirer. On reduit ainsi le nombre de bateaux*/
}
bool positionOccupee(Bateaux Bx, Position p)
{
	/* Renvoie True si un bateau de la collection Bx est à cette position.*/
}
bool enVue(Bateaux Bx, Position p)
{
	/* Renvoie True si un bateau de la collection Bx est en vue de la position p.*/
	return Bx->bat->positions->x == p->x || Bx->bat->positions->y == p->y; 
} 
int trouverBateau(Bateaux bx, Position p)
{
	/* Renvoie un entier qui identifie le bateau qui se trouve à la position p, si on sait qu'un bateau y est*/
}
bool positionnnementBateauValide(Bateaux Bx, Position p, char s, int l)
{
	/* Verifie si un bateau de position de tete p, de longueur l et d'orientation s, sont valides et in-occupées.*/
}
