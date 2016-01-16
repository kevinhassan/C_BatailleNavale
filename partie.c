#include "partie.h"

Partie creerPartie()
{
	/* Créer une partie, complete la structure comme necessaire à l'initialisation */
    Partie *p=malloc(sizeof(Partie)); 
    p->j1->actif = True; // Le joueur qui commence la partie est le joueur 1
    return p;
}
Partie joueurSuivant(Partie p)
{
	/* Change le joueur actif et le joueur passif. Le joueur actif devient passif et inversement */
	//Si le joueur 1 est actif
	if(joueurActif(p) == j1){
		p->j1->actif = False;
		p->j2->actif = True;
	}
	//Le joueur 2 est actif
	else
	{
		p->j1->actif = True;
		p->j2->actif = False;	
	}
	return p;
}
Joueur joueurActif(Partie p)
{
	if(p->j1->actif == True)
	{
		Joueur j = p->j1;
	} 
	else
	{
		Joueur j = p->j2;
	}
	return j;
}
Joueur joueurPassif(Partie p)
{
	/* renvoie joueur passif */

	/*Cette methode est inutile car on a 2 joueurs et 
	on connaissant qui est actif on sait qui ne l'ai pas
	*/
	if(p->j1->actif == True)
	{
		Joueur j = p->j2;
	} 
	else
	{
		Joueur j = p->j1;
	}
	return j;
} 
char* phaseTir(Partie p, Position pos)
{	
	bool trouve = False;
	/* Determine si p touche un bateau du joueur passif(et lance dans ce cas la Phase de destruction), si un bateau est en vue ou si le tir est à l'eau ou coulé  */
	if(p->J1->actif == False)
	{
		if(p->J1->enVue(bateauxJoueur(p->J1),pos))	
		//Si dans l'ensembe de bateau de J1 un bateau est en vue
		{
			return 'v';
		}
		//Si l'entier renvoyer par trouverBateau n'est pas valide alors il n'existe pas
		//Dans ce cas il n'est pas touche donc a l'eau
		else if(p->J1->trouverBateau(bateauxJoueur(p->J1)) <=0)
		{
			return 'e';
		}
		else
		{
			//Dans ce cas le bateau est touche
			phaseDestruction(p, pos);
		}
	}
	else
	{
		if(p->J2->enVue(bateauxJoueur(p->J2),pos))	
		//Si dans l'ensembe de bateau de J1 un bateau est en vue
		{
			return 'v';
		}
		//Si l'entier renvoyer par trouverBateau n'est pas valide alors il n'existe pas
		//Dans ce cas il n'est pas touche donc a l'eau
		else if(p->J2->trouverBateau(bateauxJoueur(p->J2)) <=0)
		{
			return 'e';
		}
		else
		{
			//Dans ce cas le bateau est touche
			phaseDestruction(p, pos);
		}
	}
}
Partie phaseDestruction(Partie p, Position pos)
{ 
/*
	Si on est sur que la position touche, retire la position du bateau touche.
  	Si celui si n'a plus de position, le supprime de l'ensemble des bateaux.
  	Si le joueur passif n'a plus de bateau la condition de vitoire est remplie. 
*/

	//Si j1 est inactif c'est lui qui est affecté par le tir
	if(p->J1->actif == False)
	{
		int numBat = trouverBateau(bateauxJoueur(p->J1),pos);
		Bateau* batJ1 = bateauNumero(bateauxJoueur(p->J1),numBat);
		batJ1 = supprPosition(batJ1,pos);
		if(EstCoule(batJ1))
		{
			retirerBateau(bateauxJoueur(p->J1),numBat);
		}
	}
	else
	{
		int numBat = trouverBateau(bateauxJoueur(p->J2),pos);
		Bateau* batJ2 = bateauNumero(bateauxJoueur(p->J2),numBat);
		batJ2 = supprPosition(batJ2,pos);
		if(EstCoule(batJ2))
		{
			retirerBateau(bateauxJoueur(p->J2),numBat);
		}
	}
	//On vérifie que les deux joueurs possèdent un ensemble de bateau non vide
	p->finie = p->J1->bateauxJoueur(p->J1)->nombreBateaux(bateauxJoueur(p->J1)) == 0 || p->J2->bateauxJoueur(p->J1)->nombreBateaux(bateauxJoueur(p->J1)) == 0);
	return p;
}

bool partieFinie(Partie p )
{
	return p->finie;//Si l'ensemble des bateaux d'au moins un des joueurs est vide
} 
