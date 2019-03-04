#include "plateau.h"
#include<cassert>

plateau::plateau()
{
    nb_ligne=4;
    nb_colonne=4;
    const char plat[nb_ligne][nb_colonne] = {"####","####","####","####"};
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

char plateau::getXY (const int x, const int y){
	assert(x>=0);
	assert(y>=0);
	assert(x<nb_ligne);
	assert(y<nb_colonne);
	return plat[x][y];
}

void plateau::setXY (const int x, const int y, char car){
	assert(x>=0);
	assert(y>=0);
	assert(x<nb_ligne);
	assert(y<nb_colonne);
	plat[x][y]= car;
}


