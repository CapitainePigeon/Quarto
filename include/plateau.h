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
    void setXY(const int x,const int y, Piece* p);
    void placer(Piece* p, int x, int y);
    Piece* getXY(const int x, const int y);
    void affiche();

protected:

private:
    int nb_colonne;
    int nb_ligne;
    Piece* plat[100][100] ;


};

#endif // PLATEAU_H
