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
    void emptyXY ( int x, int y);
    int nb_colonne;
    int nb_ligne;
    Piece* plat[4][4] ;

protected:

private:



};

#endif // PLATEAU_H
