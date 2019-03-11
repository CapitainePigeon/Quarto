#include "Partie.h"
#include "piece.h"
#include "plateau.h"
#include "ReserveDePiece.h"

Partie::Partie()
{
    Plateau reserve= Plateau();
    Plateau plat= Plateau();

    reserve.setXY(0,1, new Piece(true,true,true,true));
    reserve.setXY(0,1, new Piece(true,true,true,false));
    reserve.setXY(0,2, new Piece(true,true,false,true));
    reserve.setXY(0,3, new Piece(true,true,false,false));

    reserve.setXY(1,0, new Piece(true,false,true,true));
    reserve.setXY(1,1, new Piece(true,false,true,false));
    reserve.setXY(1,2,new Piece(true,false,false,true));
    reserve.setXY(1,3, new Piece(true,false,false,false));

    reserve.setXY(2,0, new Piece(false,true,true,true));
    reserve.setXY(2,1, new Piece(false,true,true,false));
    reserve.setXY(2,2, new Piece(false,true,false,true));
    reserve.setXY(2,3, new Piece(false,true,false,false));

    reserve.setXY(3,0, new Piece(false,false,true,true));
    reserve.setXY(3,1, new Piece(false,false,true,false));
    reserve.setXY(3,2, new Piece(false,false,false,true));
    reserve.setXY(3,3, new Piece(false,false,false,false));

    //ctor
}

Partie::~Partie()
{
    //dtor
}
