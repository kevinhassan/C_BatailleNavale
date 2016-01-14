Bateau creerBateau(Position p, char sens, int l)
{
    /*Creer un bateau de position de tete p, avec les nouvelles position qui suivent le sens de s.*/
    Bateau *Bat=malloc(sizeof(int)+ sizeof(Position)+2*sizeof(*TListe)); //Car la liste contiendra des positions et elle est constituée de 2 pointeurs suivant et précédent du type liste doublement chainée
    Bat->longueur=l;
    Position *p1=creerPosition(getXPos(p),getYPos(p));
    AjoutDebut(Bat->positions, p1);
    int i;
    for (i=1;i<l;i++){
        if (sens=='v'){
            setYPos(p1,getYPos(p1)+1);
        }
        else if (sens=='h'){
            setXPos(p1,getXPos(p1)+1);
        }
        AjoutDebut (Bat->positions, p1);
    }
    return Bat;
}
Bateau supprPosition(Bateau b, Position p)
{
    /* Supprime la position p du bateau quand on sait qu'elle est la et diminue ainsi la longueur du bateau*/
    b->longueur = b->longueur-1;
}
bool positionPresente(Bateau b, Position p)
{
    /* Retourne True si cette position appartient au bateau. */
}
bool bateauEnVue(Bateau b, Position p)
{
    /* retourne True si le bateau est en vue de la position p.*/
}
bool EstCoule(Bateau b)
{
    /* Retourne True si le bateau n'est plus de position 'en vie'.*/
}
int getTaille(Bateau b)
{
    /*On récupère la taille du bateau*/
    return b->longueur;
}

