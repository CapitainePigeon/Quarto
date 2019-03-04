#ifndef PLATEAU_H
#define PLATEAU_H
#include "piece.h"

class plateau
{
    public:
        plateau();
        virtual ~plateau();

    protected:

    private:
        int nb_colonne;
        int nb_ligne;
        int getNbColonnes();
        int getNbLignes();
        char plat[100][100] ;
        char getXY(const int x, const int y);
        void setXY(const int x,const int y, char car);
        void placer(piece p, int x, int y);
};

#endif // PLATEAU_H
