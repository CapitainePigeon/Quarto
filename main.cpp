#include <iostream>
#include "Piece.h"
#include "Combinaison.h"
#include "Partie.h"
#include "Plateau.h"
#include "VueJoueur.h"
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;

int main(int argc,char** argv)
{


    Partie partie = Partie();
    partie.Jeu();

    //r.affiche();
    /*piece p= piece(true,true,true,true);
    p.pieceCaractere();


    plateau p = plateau();

    ReserveDePiece r= ReserveDePiece();

    Piece pi= Piece(true,true,true,true);
    Plateau p = Plateau();

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
    //SDL_Surface* loadSurface( std::string path );
//partie.getPlateau().getXY(2,1)->getCaractere();
   // cout<<partie.getPlateau().getXY(2,1)->getCaractere()<<endl;
    //printf(""+partie.getPlateau().getXY(2,1)->getCaractere());


    //vue->chargerPlateau(1,1,partie.getPlateau().getXY(0,3));
  //  vue->viderReserve(0,3);
    //vue.initialiser();
    //SDL_Delay(30000);


    return 0;
}
