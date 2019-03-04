#include <iostream>
#include "piece.h"
#include "ReserveDePiece.h"
#include"plateau.h"

using namespace std;

int main()
{
    /*
    ReserveDePiece r= ReserveDePiece();

    p.pieceCaractere();
    */
    piece pi= piece(true,true,true,true);
    plateau p = plateau();
    for (int i = 0; i < p.getNbLignes(); i++){
        for (int j = 0; j < p.getNbColonnes(); j++){
            cout<<p.getXY(i,j)->getCaractere();
        }
        cout<<endl;
    }

    p.placer(pi,2,2);

    for (int i = 0; i < p.getNbLignes(); i++){
        for (int j = 0; j < p.getNbColonnes(); j++){
            cout<<p.getXY(i,j)->getCaractere();
        }
        cout<<endl;
    }

    return 0;
}
