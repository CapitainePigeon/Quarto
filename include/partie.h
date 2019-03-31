#ifndef PARTIE_H
#define PARTIE_H
#include "Piece.h"
#include "Plateau.h"

class Partie
{
    public:
        Partie();
        virtual ~Partie();
        bool gagne(Piece* pieces);
        Plateau getPlateau();
        Plateau getReserve();

    protected:

    private:

};

#endif // PARTIE_H
