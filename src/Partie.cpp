#include "Partie.h"
#include "piece.h"
#include "plateau.h"
#include "ReserveDePiece.h"
#include "VueJoueur.h"
#include "Combinaison.h"
#include <iostream>
#include<string.h>

using namespace std;

Plateau reserve;
Plateau plat;

Partie::Partie()
{
    reserve= Plateau();
    plat= Plateau();

    reserve.setXY(0,0, new Piece(true,true,true,true));
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



    plat.emptyXY(0,0);
    plat.emptyXY(0,1);
    plat.emptyXY(0,2);
    plat.emptyXY(0,3);

    plat.emptyXY(1,0);
    plat.emptyXY(1,1);
    plat.emptyXY(1,2);
    plat.emptyXY(1,3);

    plat.emptyXY(2,0);
    plat.emptyXY(2,1);
    plat.emptyXY(2,2);
    plat.emptyXY(2,3);

    plat.emptyXY(3,0);
    plat.emptyXY(3,1);
    plat.emptyXY(3,2);
    plat.emptyXY(3,3);
    //ctor
}

void Partie::Jeu(){

    VueJoueur* vue=new VueJoueur();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           // partie.getPlateau().getXY(i,j);
            //printf("a\n");

            vue->chargerReserve(i,j,this->getReserve().getXY(i,j));

        }
    }

    int xReserve, yReserve, xPlateau, yPlateau;
    bool gagne=false;
    Piece* liste[16][4];
    Piece* pieces[4];

    while(!gagne){

        vue->clicJouer(&xReserve, &yReserve, &xPlateau, &yPlateau);
        if( !this->getReserve().getXY(yReserve,xReserve)->isnull && this->getPlateau().getXY(yPlateau,xPlateau)->isnull ){
            vue->chargerPlateau(yPlateau,xPlateau,this->getReserve().getXY(yReserve,xReserve));
            vue->viderReserve(yReserve,xReserve);
            this->getPlateau().placer(this->getReserve().getXY(yReserve,xReserve),xPlateau,yPlateau);

            cout<<this->getPlateau().getXY(xPlateau,yPlateau)->isnull<<endl;

            int nb_liste = Combinaison::getListePieces(2,this->getPlateau(),xPlateau,yPlateau,liste);
            cout<<"nb_liste"<<nb_liste<<endl;
            int i=0;
            while(i<nb_liste && !gagne){
                    for(int j=0;j<4;j++){
                        cout<<liste[i][j]->isnull<<endl;
                    }

                gagne=this->gagne(liste[i]);
                cout<<"gagne "<<gagne<<endl;
                i++;

            }
        }

    }
}

bool Partie::gagne(Piece* pieces[4]){

    if(!(pieces[0]->isnull)  && !(pieces[1]->isnull)    && !(pieces[2]->isnull)    && !(pieces[3]->isnull)){
            return ((pieces[0]->couleur  && pieces[1]->couleur    && pieces[2]->couleur    && pieces[3]->couleur) ||
            (pieces[0]->taille   && pieces[1]->taille     && pieces[2]->taille     && pieces[3]->taille) ||
            (pieces[0]->forme    && pieces[1]->forme      && pieces[2]->forme      && pieces[3]->forme) ||
            (pieces[0]->pleine   && pieces[1]->pleine     && pieces[2]->pleine     && pieces[3]->pleine)||
            (!(pieces[0]->couleur)  && !(pieces[1]->couleur)    && !(pieces[2]->couleur)    && !(pieces[3]->couleur)) ||
            (!(pieces[0]->taille)   && !(pieces[1]->taille)     && !(pieces[2]->taille)     && !(pieces[3]->taille)) ||
            (!(pieces[0]->forme)    && !(pieces[1]->forme )     && !(pieces[2]->forme )     && !(pieces[3]->forme)) ||
            (!(pieces[0]->pleine)   && !(pieces[1]->pleine )    && !(pieces[2]->pleine )    && !(pieces[3]->pleine)));
    }
    return false;

}

Plateau Partie::getPlateau()
{
    return plat;
}

Plateau Partie::getReserve()
{
    return reserve;
}


Partie::~Partie()
{
    //dtor
}
