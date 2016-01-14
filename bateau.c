Bateau creerBateau(Position p, char sens, int l)
{
    Bateau *Bat=malloc(sizeof(int)+ sizeof(Position)+2*sizeof(*dll)); //Car la liste contiendra des positions et elle est constituée de 2 pointeurs suivant et précédent du type liste doublement chainée
    Bat->longueur=l;
    Position p1=creerPosition(getXPos(p),getYPos(p));
    dll_insert (Bat->positions **, &p1);
    int i;
    for (i=1;i<l;i++){
        if (sens=='v'){
            setYPos(p1,getYPos(p1)+1);
        }
        else if (sens=='h'){
            setXPos(p1,getXPos(p1)+1);
        }
        dll_insert (Bat->positions **, &p1);
    }
    return Bat;
}

Bateau supprPosition(Bateau b, Position p)//A la suppression on recondance les positions
{

}
bool positionPresente(Bateau b, Position p)
{

}
bool bateauEnVue(Bateau b, Position p)
{

}
bool EstCoule(Bateau b)
{

}
int getTaille(Bateau b)
{

}

