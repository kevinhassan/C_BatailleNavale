#include <stdlib.h>
#include <stdio.h>

typedef struct TListePosition TListePosition ;
struct TListePosition
{
    Position coordonnees;
    struct TListePosition *precedent;
    struct TListePosition *suivant;
};

typedef TListePosition* TListe;

TListe CreerListe();
Position EstVide(TListe l);
void AfficheListe(TListe l);

TListe AjoutDebut(TListe l, Position coord) ;
TListe AjoutFin(TListe l, Position coord) ;

Position Premier(TListe l);
Position Dernier(TListe l);

TListe SupprimerTete(TListe l);
TListe SupprimerFin(TListe l);

int NbOccurences(TListe l, Position coord);
