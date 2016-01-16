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
} 
char* phaseTir(Partie p, Position pos)
{
	/* Determine si p touche un bateau du joueur passif(et lance dans ce cas la Phase de destruction), si un bateau est en vue ou si le tir est à l'eau ou coulé  */

}
Partie phaseDestruction(Partie p, Position pos); /*Si on est sur que la position touche, retire la position du bateau touche.
                                                    Si celui si n'a plus de position, le supprime de l'ensemble des bateaux.
                                                    Si le joueur passif n'a plus de bateau la condition de vitoire est remplie. */
bool partieFinie(Partie p )
{
	/* Declare que la partie est finie si True. */
	if(p->J1->ensembleBat->nombreBateaux(ensembleBat) == 0 || p->J2->ensembleBat->nombreBateaux(ensembleBat) == 0 )
	{
		//Si J1 ou J2 n'a plus de bateau la partie est terminée
		p->finie = True;
	}
	return p->finie;//Si l'ensemble des bateaux d'au moins un des joueurs est vide
} 
