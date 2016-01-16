#include <stdlib.h>
#include <stdio.h>

typedef struct TListeEntier TListeEntier ;
struct TListeEntier
{
    Bateau bat;
    struct TListeEntier *precedent;
    struct TListeEntier *suivant;
};

typedef TListeEntier* TListe;

TListe CreerListe();
bool EstVide(TListe l);
void AfficheListe(TListe l);

TListe AjoutDebut(TListe l, Bateau b) ;
TListe AjoutFin(TListe l, Bateau b) ;

Bateau Premier(TListe l);
Bateau Dernier(TListe l);

TListe SupprimerTete(TListe l);
TListe SupprimerFin(TListe l);

int NbOccurences(TListe l, Bateau b);
