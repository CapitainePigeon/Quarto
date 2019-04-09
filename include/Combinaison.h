#ifndef COMBINAISON_H
#define COMBINAISON_H
#include "Plateau.h"

class Combinaison
{
public:
    Combinaison();
    virtual ~Combinaison();
    static int getListePieces(int forme, Plateau plateau,int x, int y,Piece* liste[16][4]);

protected:

private:
};

#endif // COMBINAISON_H
