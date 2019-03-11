#include "ReserveDePiece.h"

#include "piece.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Piece.h"
using namespace std;




ReserveDePiece::ReserveDePiece()
{
    Piece p = Piece(true,true,true,true);

    nb_ligne=4;
    nb_colonne=4;
 //   reserve[nb_ligne][nb_colonne];
    cout<<"RESERVE";
    cout<<endl;
    reserve[0][1]= new Piece(true,true,true,true);
    reserve[0][1]= new Piece(true,true,true,false);
    reserve[0][2]= new Piece(true,true,false,true);
    reserve[0][3]= new Piece(true,true,false,false);

    reserve[1][1]= new Piece(true,false,true,true);
    reserve[1][1]= new Piece(true,false,true,false);
    reserve[1][2]= new Piece(true,false,false,true);
    reserve[1][3]= new Piece(true,false,false,false);

    reserve[2][1]= new Piece(false,true,true,true);
    reserve[2][1]= new Piece(false,true,true,false);
    reserve[2][2]= new Piece(false,true,false,true);
    reserve[2][3]= new Piece(false,true,false,false);

    reserve[3][1]= new Piece(false,false,true,true);
    reserve[3][1]= new Piece(false,false,true,false);
    reserve[3][2]= new Piece(false,false,false,true);
    reserve[3][3]= new Piece(false,false,false,false);

    cout<<"FIN RESERVE";
    cout<<endl;
}
void ReserveDePiece::affiche () {
    for(int i=0 ; i<nb_ligne;i++){
        for(int j=0 ; j<nb_colonne;j++){
            cout<<reserve[i][j]->getCaractere();
        }
        cout<<endl;
    }
}

ReserveDePiece::~ReserveDePiece()
{
    //dtor
}
