#include "plateau.h"

plateau::plateau()
{
    nb_ligne=4;
    nb_colonne=4;
    const char plateau[nb_ligne][nb_colonne] = {"####","####","####","####"};
}

plateau::~plateau()
{
    //dtor
}

int plateau::getNbLignes () const {
	return nb_ligne;
}

int plateau::getNbColonnes () const {
	return nb_colonne;
}

char plateau::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<nb_ligne);
	assert(y<nb_colonne);
	return plateau[x][y];
}

void plateau::setXY (const int x, const int y, char car) {
	assert(x>=0);
	assert(y>=0);
	assert(x<nb_ligne);
	assert(y<nb_colonne);
	plateau[x][y]= car;
}

void plateau::placer(piece p,int x,int y){

    setXY(x,y,car);

}
