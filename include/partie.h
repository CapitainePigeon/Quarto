#ifndef PARTIE_H
#define PARTIE_H
#include "Piece.h"
#include "Plateau.h"

class Partie
{
    public:
        Partie();
        virtual ~Partie();
        bool gagne(Piece* pieces[4]);
        Plateau getPlateau();
        Plateau getReserve();
        void Jeu(int forme);

    protected:

    private:

};

#endif // PARTIE_H
