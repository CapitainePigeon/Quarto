#include "ReserveDePiece.h"
#include "Piece.h"

ReserveDePiece::ReserveDePiece()
{
    Piece p = Piece(true,true,true,true);
    //ctor
    int nb_ligne=4;
    int nb_colonne=4;
    Piece *reserve[nb_ligne][nb_colonne];
    for (int i = 0; i < nb_ligne; i++)
        for (int j = 0; j < nb_colonne; j++)
            reserve[i][j]= new Piece(true,true,true,true);

}

ReserveDePiece::~ReserveDePiece()
{
    //dtor
}
