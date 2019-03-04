#include "piece.h"

piece::piece()
{
    //ctor
}

piece::~piece()
{
    //dtor
}

void piece::pieceCaractere(){
    string binaire = couleur+taille+forme+pleine;
    cout<<binaire<<endl;
}
