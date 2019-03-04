#include <iostream>
#include<string.h>
#include "piece.h"

using namespace std;

piece::piece()
{
    //ctor
}

piece::~piece()
{
    //dtor
}

void piece::pieceCaractere(){
    string binaire = couleur ? "1" : "0";
    binaire += taille ? "1" : "0";
    binaire += forme ? "1" : "0";
    binaire += pleine ? "1" : "0";

    cout<<binaire<<endl;
}
