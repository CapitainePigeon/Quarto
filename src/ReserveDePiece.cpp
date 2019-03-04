#include "ReserveDePiece.h"

ReserveDePiece::ReserveDePiece()
{
    piece p = piece(true,true,true,true);
    //ctor
    nb_ligne=4;
    nb_colonne=4;
    piece reserve[nb_ligne][nb_colonne];
    for (int i = 0; i < nb_ligne; i++)
        for (int j = 0; j < nb_colonne; j++)
            reserve[i][j] = new piece(true,true,true,true);

}

ReserveDePiece::~ReserveDePiece()
{
    //dtor
}
