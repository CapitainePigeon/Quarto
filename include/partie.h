#ifndef PARTIE_H
#define PARTIE_H
#include "Piece.h"

class Partie
{
    public:
        Partie();
        virtual ~Partie();
        bool gagne(Piece* pieces);

    protected:

    private:

};

#endif // PARTIE_H
