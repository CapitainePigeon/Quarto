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
        int nbligne;
        int nbcolone;
        piece *reserve;

};

#endif // RESERVEDEPIECE_H
