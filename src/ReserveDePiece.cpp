#include "ReserveDePiece.h"
#include "piece.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

ReserveDePiece::ReserveDePiece()
{
    piece p = piece(true,true,true,true);
    //ctor
    nb_ligne=4;
    nb_colonne=4;
//    reserve[nb_ligne][nb_colonne];
    cout<<"RESERVE";
    cout<<endl;
    reserve[0][1]= new piece(true,true,true,true);
    reserve[0][1]= new piece(true,true,true,false);
    reserve[0][2]= new piece(true,true,false,true);
    reserve[0][3]= new piece(true,true,false,false);

    reserve[1][1]= new piece(true,false,true,true);
    reserve[1][1]= new piece(true,false,true,false);
    reserve[1][2]= new piece(true,false,false,true);
    reserve[1][3]= new piece(true,false,false,false);

    reserve[2][1]= new piece(false,true,true,true);
    reserve[2][1]= new piece(false,true,true,false);
    reserve[2][2]= new piece(false,true,false,true);
    reserve[2][3]= new piece(false,true,false,false);

    reserve[3][1]= new piece(false,false,true,true);
    reserve[3][1]= new piece(false,false,true,false);
    reserve[3][2]= new piece(false,false,false,true);
    reserve[3][3]= new piece(false,false,false,false);

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
