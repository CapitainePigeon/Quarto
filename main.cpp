#include <iostream>
#include "piece.h"
#include "ReserveDePiece.h"
#include"plateau.h"

using namespace std;

int main()
{

    ReserveDePiece r= ReserveDePiece();
    r.affiche();
    /*piece p= piece(true,true,true,true);
    p.pieceCaractere();
    */
    /*
    plateau p = plateau();
    for (int i = 0; i < p.getNbLignes(); i++)
        for (int j = 0; j < p.getNbColonnes(); j++)
            cout<<p.getXY(i,j).getCaractere();

    return 0;*/
}
