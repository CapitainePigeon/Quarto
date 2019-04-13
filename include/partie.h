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
        float ChoisirRecur(int* xReserve, int* yReserve,int* xPlateau, int* yPlateau,int nb_null,int profondeur,int equipe,int forme,int* xReserve2,int* yReserve2);

    protected:

    private:

};

#endif // PARTIE_H
