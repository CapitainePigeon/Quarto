#include "Plateau.h"
#include<cassert>
#include <iostream>
using namespace std;

Plateau::Plateau()
{
    nb_ligne=4;
    nb_colonne=4;
    plat[nb_ligne][nb_colonne];
   /* for (int i = 0; i < nb_ligne; i++)
        for (int j = 0; j < nb_colonne; j++)
            plat[i][j]= new Piece();*/
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

Piece* Plateau::getXY ( int x, int y)
{
    assert(x>=0);
    assert(y>=0);
    assert(x<nb_ligne);
    assert(y<nb_colonne);
    //printf("%c \n",plat[x][y]->getCaractere());
    return plat[x][y];
}

void Plateau::setXY ( int x, int y, Piece* p)
{
    assert(x>=0);
    assert(y>=0);
    assert(x<nb_ligne);
    assert(y<nb_colonne);
    plat[x][y]= p;
}
void Plateau::emptyXY ( int x, int y)
{
    assert(x>=0);
    assert(y>=0);
    assert(x<nb_ligne);
    assert(y<nb_colonne);

    plat[x][y]=new Piece(true);
    //printf("%d \n",plat[x][y]->isnull);
}

void Plateau::placer(Piece* p, int x, int y)
{
    plat[x][y]->couleur=p->couleur;
    plat[x][y]->forme=p->forme;
    plat[x][y]->pleine=p->pleine;
    plat[x][y]->taille=p->taille;
    plat[x][y]->isnull=false;
    p->isnull=true;
    setXY(x,y,p);
}

void Plateau::affiche () {
    for(int i=0 ; i<nb_ligne;i++){
        for(int j=0 ; j<nb_colonne;j++){
            cout<<plat[i][j]->getCaractere();
        }
        cout<<endl;
    }
}


