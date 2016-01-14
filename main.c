#include <stdlib.h>
#include <stdio.h>
#include "joueur.h"
#include "partie.h"
#include "bateauX.h"
#include "bateau.h"
#include "position.h"
#include "bool.h"

int main (void) {
    Position positionDeTravail =  creerPosition(0,0);
    Joueur joueurActif;
    Partie partie = CreerPartie(); /* cree une partie, la partie crée eux joueurs, les joueurs créent leurs ensembles BateauX qui sont vides */
    /* Phase de placement des bateaux des deux joueurs dans leurs ensemble.*/
    int nombreBateaux = 5;
    int longueurs[nombreBateaux] = {1, 2, 3, 3, 4};
    for (int i=1; i<3; i++)/*Pour le premier joueur puis le suivant*/
    {
        for(int j=1; j  < 1+nombreBateaux; j++)/*Ainsi que pour chaque longueur de bateau*/
        {
            do{
                printf("C'est au joueur %d :", idJoueur(joueurActif(partie)));
                printf("\n Votre bateau fait %d en longueur, entrez ses coordonnees svp :", longueurs[j]);
                positionDeTravail = acquerirPosition();
                char sens  =  sensPosition();
            }while( !positionnnementBateauValide( bateauxJoueur( joueurActif(partie) ),positionDeTravail, sens, j ));
            Bateau bateau = creerBateau(positionDeTravail, sens, longueurs[j]);
            bateauxJoueur( joueurActif( partie ) ) =  ajouterBateau(bateau);
        }
        partie = joueurSuivant( partie );
    }

    printf("Tous les bateaux sont correctement placés, la partie commence ! ");

    do{/*Phase de jeu, tirer chacun son tour tant que la partie n'est pas finie*/
            printf("C'est au joueur %d de tirer:", idJoueur(joueurActif(partie)));
            positionDeTravail = acquerirPosition();
            char* affichage = phaseTir(partie, positionDeTravail);
            printf("%d", affichage);
            partie = joueurSuivant( partie );

    }while (!partieFinie(partie));
    printf("PARTIE FINIE !! ");
    return 0;
}
/*Fonctions d'interface.*/
Position acquerirPosition() {
    Position positionPlacement =  CreerPositon(0,0);
    int tailleMaxGrille = 20;
    int X = 0;
    int Y = 0;
    do{
        println("Creation d'une position, entrez la coordonnée X entre 1 et %d", tailleMaxGrille);
        scanf("%d", X);
        println("Entrez la coordonnée Y entre 1 et %d", tailleMaxGrille);
        scanf("%d", Y);
        setPosition(positionPlacement, X, Y);
    }while( !positionValide(positionPlacement) );
    return positionPlacement;
}

char sensPosition() {
    char sens = "";
    println("Entrer le sens de votre bateau :\n(D : droite, G : gauche, H :  haut, B: bas):");
        scanf("%d", sens);

};
