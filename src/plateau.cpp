#include "Plateau.h"
#include<cassert>

Plateau::Plateau()
{
    nb_ligne=4;
    nb_colonne=4;
    plat[nb_ligne][nb_colonne];
    for (int i = 0; i < nb_ligne; i++)
        for (int j = 0; j < nb_colonne; j++)
            plat[i][j]= new Piece();
}

Plateau::~Plateau()
{
    //dtor
}

int Plateau::getNbLignes ()
{
    return nb_ligne;
}

int Plateau::getNbColonnes ()
{
    return nb_colonne;
}

Piece* Plateau::getXY (const int x, const int y)
{
    assert(x>=0);
    assert(y>=0);
    assert(x<nb_ligne);
    assert(y<nb_colonne);
    return plat[x][y];
}

void Plateau::setXY (const int x, const int y, Piece p)
{
    assert(x>=0);
    assert(y>=0);
    assert(x<nb_ligne);
    assert(y<nb_colonne);
    *plat[x][y]= p;
}

void Plateau::placer(Piece p, int x, int y)
{
    setXY(x,y,p);
}


