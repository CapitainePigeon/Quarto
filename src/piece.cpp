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

piece::piece(bool c, bool t,bool f, bool p){
    couleur=c;
    taille=t;
    forme=f;
    pleine=p;
}


void piece::pieceCaractere(){
    int binaire = couleur ? 1 : 0;
    binaire = (binaire*10)+(taille ? 1 : 0);
    binaire = (binaire*10)+(forme ? 1 : 0);
    binaire = (binaire*10)+(pleine ? 1 : 0);

    switch(binaire)
        {
            case 0000:
            caractere = '0';
            break;


            case 0001:
            caractere = '1';
            break;


            case 0010:
            caractere = '2';
            break;


            case 0011:
            caractere = '3';
            break;


            case 0100:
            caractere = '4';
            break;


            case 0101:
            caractere = '5';
            break;


            case 0110:
            caractere = '6';
            break;


            case 0111:
            caractere = '7';
            break;


            case 1000:
            caractere = '8';
            break;


            case 1001:
            caractere = '9';
            break;

            case 1010:
            caractere = 'a';
            break;


            case 1011:
            caractere = 'b';
            break;


            case 1100:
            caractere = 'c';
            break;


            case 1101:
            caractere = 'd';
            break;


            case 1110:
            caractere = 'e';
            break;


            case 1111:
            caractere = 'f';
            break;
        }

    cout<<binaire<<endl;
    cout<<caractere<<endl;
}
