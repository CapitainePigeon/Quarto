#include <iostream>
#include "piece.h"
#include "ReserveDePiece.h"
#include"plateau.h"
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;

int main(int argc,char** argv)
{

    ReserveDePiece r= ReserveDePiece();

    //r.affiche();
    /*piece p= piece(true,true,true,true);
    p.pieceCaractere();


    plateau p = plateau();
    for (int i = 0; i < p.getNbLignes(); i++)
    {
        for (int j = 0; j < p.getNbColonnes(); j++)
        {
            cout<<p.getXY(i,j)->getCaractere();
        }
        cout<<endl;
    }

    p.placer(pi,2,2);

    for (int i = 0; i < p.getNbLignes(); i++)
    {
        for (int j = 0; j < p.getNbColonnes(); j++)
        {
            cout<<p.getXY(i,j)->getCaractere();
        }
        cout<<endl;
    }

    return 0; */

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
    SDL_Delay(10000);


    return 0;
}
