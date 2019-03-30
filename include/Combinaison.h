#ifndef COMBINAISON_H
#define COMBINAISON_H
#include "Plateau.h"

class Combinaison
{
public:
    Combinaison();
    virtual ~Combinaison();
    static Piece** getListePieces(int forme, Plateau* plateau,int x, int y );

protected:

private:
};

#endif // COMBINAISON_H
