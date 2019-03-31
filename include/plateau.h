#ifndef PLATEAU_H
#define PLATEAU_H
#include "Piece.h"

class Plateau
{
public:
    Plateau();
    virtual ~Plateau();
    int getNbColonnes();
    int getNbLignes();
    void setXY( int x, int y, Piece* p);
    void placer(Piece* p, int x, int y);
    Piece* getXY( int x,  int y);
    void affiche();

protected:

private:
    int nb_colonne;
    int nb_ligne;
    Piece* plat[4][4] ;


};

#endif // PLATEAU_H
