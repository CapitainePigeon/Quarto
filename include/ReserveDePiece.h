#ifndef RESERVEDEPIECE_H
#define RESERVEDEPIECE_H
#include "piece.h"


class ReserveDePiece
{

    public:
        ReserveDePiece();
        virtual ~ReserveDePiece();
        void affiche();


protected:


    private:
        int nb_ligne;
        int nb_colonne;
        Piece *reserve[4][4];

};

#endif // RESERVEDEPIECE_H
