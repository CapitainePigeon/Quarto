#include "plateau.h"
#include<cassert>

plateau::plateau()
{
    nb_ligne=4;
    nb_colonne=4;
    plat[nb_ligne][nb_colonne];
    for (int i = 0; i < nb_ligne; i++)
        for (int j = 0; j < nb_colonne; j++)
            plat[i][j]= new piece();
}

plateau::~plateau()
{
    //dtor
}

int plateau::getNbLignes () {
	return nb_ligne;
}

int plateau::getNbColonnes (){
	return nb_colonne;
}

piece* plateau::getXY (const int x, const int y){
	assert(x>=0);
	assert(y>=0);
	assert(x<nb_ligne);
	assert(y<nb_colonne);
	return plat[x][y];
}

void plateau::setXY (const int x, const int y, piece p){
	assert(x>=0);
	assert(y>=0);
	assert(x<nb_ligne);
	assert(y<nb_colonne);
	*plat[x][y]= p;
}

void plateau::placer(piece p, int x, int y){
    setXY(x,y,p);
}


