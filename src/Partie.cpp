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

void Partie::Jeu(int forme){

    bool quit=false;
    bool tourJoueur=false;

    VueJoueur* vue=new VueJoueur();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vue->chargerReserve(i,j,this->getReserve().getXY(i,j));

        }
    }

    int xReserve, yReserve, xPlateau, yPlateau;
    int xReserve2, yReserve2;
    bool gagne=false;
    Piece* liste[16][4];
    Piece* pieces[4];
    int nb_null=0;
    bool AChoisi=false;
    vue-> affTourJoueur(tourJoueur);
    while(tourJoueur && (!AChoisi || this->getReserve().getXY(xReserve,yReserve)->isnull )){
        cout<<" Tour Reserve humain "<<endl;
        quit=vue->clicReserve(&yReserve, &xReserve);
        AChoisi=true;
    }

    while(!quit){

        vue-> affTourJoueur(tourJoueur);
        if(!tourJoueur){
            cout<<" Tour de IA "<<endl;
            ChoisirRecur( &xReserve, &yReserve, &xPlateau, &yPlateau, nb_null, 0,1,forme,&xReserve2, &yReserve2);
        }else{
            cout<<" Tour Plateau humain "<<endl;
            AChoisi=false;
            while(!quit &&(!AChoisi || !this->getPlateau().getXY(xPlateau,yPlateau)->isnull)){
                quit=vue->clicPlateau( &xPlateau, &yPlateau);
                this->getPlateau().affiche();
               // cout<<this->getPlateau().getXY(xPlateau,yPlateau)->getCaractere()<<endl;
                AChoisi=true;
            }
        }
        if(!quit  ){
            vue->chargerPlateau(yPlateau,xPlateau,this->getReserve().getXY(xReserve,yReserve));
            vue->viderReserve(xReserve,yReserve);
            this->getPlateau().placer(this->getReserve().getXY(xReserve,yReserve),xPlateau,yPlateau);
            this->getPlateau().affiche();
            nb_null++;
            int nb_liste = Combinaison::getListePieces(forme,this->getPlateau(),xPlateau,yPlateau,liste);
            //cout<<"nb_liste"<<nb_liste<<endl;
            int i=0;
            while(i<nb_liste && !gagne){
                    /*for(int j=0;j<4;j++){
                        cout<<liste[i][j]->isnull<<endl;
                    }*/

                gagne=this->gagne(liste[i]);
                if(gagne){
                    vue->avoirGagne();
                }
                i++;

            }

            /*if(nb_null==16){
                vue->avoirPerdu();
            }*/


        }
        if(tourJoueur){
            while(!AChoisi || this->getReserve().getXY(xReserve,yReserve)->isnull){
                cout<<" Tour Reserve humain "<<endl;
                quit=vue->clicReserve(&yReserve, &xReserve);
                AChoisi=true;
            }
        }else{
            xReserve=xReserve2;
            yReserve=yReserve2;
        }

    }
}

float Partie::ChoisirRecur(int* xReserve, int* yReserve,int* xPlateau, int* yPlateau,int nb_null,int profondeur,int equipe,int forme,int* xReserve2,int* yReserve2)
{
    bool gagne;

    if(nb_null>=16){
        cout<<" nbNull>=16 "<<endl;
        return 0;
    }
    Piece* liste[16][4];
    float score;
    int nb_liste;
    float bestScore=-1000*equipe;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

                if(this->getPlateau().getXY(i,j)->isnull){
                    this->getPlateau().placer(this->getReserve().getXY(*xReserve,*yReserve),i,j);

                    /*
                    cout<<"IA x "<<x<<" y "<<y<<" i "<<i<<" j "<<j<<endl;
                    this->getPlateau().affiche();
                    cout<<" "<<endl;
                    this->getReserve().affiche();
                    cout<<" "<<endl;
                    cout<<" "<<endl;*/

                    nb_liste = Combinaison::getListePieces(forme,this->getPlateau(),i,j,liste);
                    //cout<<"nb_liste"<<nb_liste<<endl;
                    int ig=0;
                    gagne=false;
                    while(ig<nb_liste && !gagne){
                        gagne=this->gagne(liste[i]);
                        ig++;
                    }
                    if(gagne){
                        this->getPlateau().getXY(i,j)->isnull=true;
                        this->getReserve().getXY(*xReserve,*yReserve)->isnull=false;
                        return equipe;
                    }else{
                        if(profondeur<2){
                            for(int x=0;x<4;x++){
                                for(int y=0;y<4;y++){
                                    if(!this->getReserve().getXY(x,y)->isnull){
                                        score=ChoisirRecur( &x,&y, xPlateau, yPlateau, nb_null+1, profondeur+1,equipe*-1,forme,xReserve2,yReserve2);
                                        if((equipe==1 && score>bestScore)||(equipe==-1 && score<bestScore)){
                                            bestScore=score;
                                            if(profondeur==0){
                                                *xReserve2=i;
                                                *yReserve2=j;
                                                *xPlateau=x;
                                                *yPlateau=y;
                                            }
                                        }
                                    }
                                }
                            }

                        }
                    }
                    this->getPlateau().getXY(i,j)->isnull=true;
                    this->getReserve().getXY(*xReserve,*yReserve)->isnull=false;


                }
                if(profondeur<1){

                }else{

                }

        }

    }
    //this->getPlateau().affiche();
    //cout<<" IA Recur return "<<bestScore*0.9<<endl;
    return bestScore*0.9;
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
