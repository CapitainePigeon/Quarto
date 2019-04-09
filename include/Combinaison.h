#ifndef COMBINAISON_H
#define COMBINAISON_H
#include "Plateau.h"

class Combinaison
{
public:
    Combinaison();
    virtual ~Combinaison();
    static void getListePieces(int forme, Plateau plateau,int x, int y,Piece** liste  );

protected:

private:
};

#endif // COMBINAISON_H
