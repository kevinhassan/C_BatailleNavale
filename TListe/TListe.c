#include <stdlib.h>
#include <stdio.h>
#include "TListe.h"


/*CréerListe: → TListeEntier – – retourne la liste vide : EstVide(CréerListe()) retourne true.*/
TListe CreerListe()
{
  return NULL;
}



/* EstVide: TListeEntier → bool – – retourne true si la liste est vide, false sinon. */
int EstVide(TListe l)
{
  return l==NULL;
}


/* AjoutDébut: TListeEntier × int → TListeEntier */
TListe AjoutDebut(TListe l, int val)
{
  TListe liTemp = malloc(sizeof(TListeEntier));
  liTemp->valeur = val;
  liTemp->suivant = l;
  liTemp->precedent = CreerListe();
  return liTemp;
}


/* AfficheListe(TListe l) ->  : Affiche le contenu de la liste */
void AfficheListe(TListe l)
{
  TListe liTemp = l;
  printf("Affichage de la liste :\n");
  while(!EstVide(liTemp)) {
    printf("%d", liTemp->valeur);
    liTemp = liTemp->suivant;
    if(!EstVide(liTemp)) {
      printf(" -> ");
    }
  }
  printf("\n\n");
}


/* AjoutFin: TListeEntier × int → TListeEntier – – retourne la liste obtenue en ajoutant l’entier donnée en fin de
liste ; si la liste est vide, se comporte comme AjoutDébut. */
TListe AjoutFin(TListe l, int val)
{
  if (EstVide(l)) {
    return AjoutDebut(l, val);
  }
  else {
    TListe liTemp = malloc(sizeof(TListeEntier));
    TListe k = l;
    while (!EstVide(k->suivant)) {
      k = k-> suivant;
    }
    k->suivant = liTemp;
    liTemp->precedent = k;
    liTemp->valeur = val;
    liTemp->suivant = CreerListe();
    return l;
  }
}


/* Premier: TListeEntier → int – – retourne le premier élément de la liste ; renvoie une erreur si la liste est vide. */
int Premier(TListe l)
{
  if (!EstVide(l)) {
    return l->valeur;
  }
  else {
    /* ERREUR */
    printf("ERREUR : Liste vide !\n");
    return -1;
  }
}


/*Dernier: TListeEntier → int – – retourne le dernier élément de la liste ; renvoie une erreur si la liste est vide.*/
int Dernier(TListe l)
{
  if (!EstVide(l)) {
    TListe k = l;
    while (!EstVide(k->suivant)) {
      k = k->suivant;
    }
    return k->valeur;
  }
  else {
    /* ERREUR */
    printf("ERREUR : Liste vide !\n");
    return -1;
  }
}


/* SupprimerTête: TListeEntier → TListeEntier – – retourne la liste obtenue en ayant supprimé le premier élément
de la liste ; Erreur si la liste est vide. */
TListe SupprimerTete(TListe l)
{
  if (!EstVide(l)) {
    if (!EstVide(l->suivant))
      l->suivant->precedent = CreerListe();
    free(l);
    return l->suivant;
  }
  else {
    /* ERREUR */
    printf("ERREUR : Liste vide !\n");
    return CreerListe();
  }
}

/* SupprimerFin: TListeEntier → TListeEntier – – retourne la liste obtenue en ayant supprimé le dernier élément
de la liste ; Erreur si la liste est vide. */
TListe SupprimerFin(TListe l)
{
  if (!EstVide(l)) {
    if (EstVide(l->suivant)) {
      l->suivant = CreerListe();
      free(l->suivant);
    }
    else {
      TListe k = l;
      while (!EstVide(k->suivant->suivant)) {
        k = k->suivant;
      }
      free(k->suivant);
      k->suivant = CreerListe();
    }
    return l;
  }
  else {
    /* ERREUR */
    printf("ERREUR : Liste vide !\n");
    return CreerListe();
  }
}

/* NbOccurences: TListeEntier × int → int – – retourne le nombre de fois où l'entier en paramètre apparaît dans la liste.
Erreur si la liste est vide. */
int NbOccurences(TListe l, int val)
{
  if (!EstVide(l)) {
    TListe k = l;
    int nbOcc = 0;
    while (!EstVide(k)) {
      if (k->valeur == val)
        nbOcc = nbOcc + 1;
      k = k->suivant;
    }
    return nbOcc;
  }
  else {
    /* ERREUR */
    printf("ERREUR : Liste vide !\n");
    return 0;
  }
}


/**************************************************/
/* A vous de completer pour les fonctions         */
/* SupprimerFin                                   */
/* NbOccurence                                    */
/**************************************************/
