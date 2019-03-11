#ifndef PLATEAU_H
#define PLATEAU_H
#include "piece.h"

class plateau
{
public:
    plateau();
    virtual ~plateau();
    int getNbColonnes();
    int getNbLignes();
    void setXY(const int x,const int y, piece p);
    void placer(piece p, int x, int y);
    piece* getXY(const int x, const int y);

protected:

private:
    int nb_colonne;
    int nb_ligne;
    piece* plat[100][100] ;


};

#endif // PLATEAU_H
