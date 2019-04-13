#include "Combinaison.h"
#include "stdlib.h"
#include <iostream>
#include<string.h>

using namespace std;

Combinaison::Combinaison()
{

}

Combinaison::~Combinaison()
{
    //dtor
}

int Combinaison::getListePieces(int forme, Plateau plateau,int x, int y,Piece* liste[16][4] ){
    cout<<"x "<<x<<" y "<<y<<endl;
    int nb_liste=0;
    int i;
    int compt=0;
    if(forme==1){
        if((x==0 && (y==1 || y==2)) || (x==3  && (y==1 || y==2)) || (y==0 && (x==1 || x==2)) ||(y==3 && (x==1 || x==2))) {
            //pas diagonale
            nb_liste+=2;
        }else{
            //diagonale
            nb_liste+=3;
            if(x==y){
                for (i=0;i<4;i++){
                    liste[2][i]=plateau.getXY(i,i);
                }
            }else{
                for (i=0;i<4;i++){
                    liste[2][i]=plateau.getXY(i,3-i);
                }
            }
        }
        for (i=0;i<4;i++){
            liste[0][i]=plateau.getXY(x,i);
            liste[1][i]=plateau.getXY(i,y);
        }
        return nb_liste;
    }
    if(forme==2){
     //carré
        bool hautGauche=false;
        bool basGauche=false;
        bool basDroite=false;
        bool hautDroite=false;
        if((x==0 && (y==0|| y==3)) || (x==3 && (y==0 || y==3))){
            nb_liste=1;

            basDroite=(x==0 && y==0);
            basGauche=(x==0 && y==3);
            hautDroite=(x==3 && y==0);
            hautGauche=(x==3 && y==3);

        }else{
            if((x==0 && (y==1 || y==2)) || (x==3  && (y==1 || y==2)) || (y==0 && (x==1 || x==2)) ||(y==3 && (x==1 || x==2))) {
                nb_liste=2;
                if(x==0 || x==3){
                    basDroite= x==0;
                    basGauche= x==0 ;
                    hautDroite= x==3;
                    hautGauche= x==3;

                }else{
                    basDroite= y==0;
                    basGauche= y==3 ;
                    hautDroite= y==0;
                    hautGauche= y==3;

                }
            }else{
                nb_liste=4;
                basDroite=true;
                basGauche=true;
                hautDroite=true;
                hautGauche=true;
            }
        }


        for(i=0;i<nb_liste;i++){
            if(hautGauche){
                liste[i][0]=plateau.getXY(x,y);
                liste[i][1]=plateau.getXY(x-1,y);
                liste[i][2]=plateau.getXY(x-1,y-1);
                liste[i][3]=plateau.getXY(x,y-1);
                hautGauche=false;
            }else {
                if(hautDroite){
                    liste[i][0]=plateau.getXY(x,y);
                    liste[i][1]=plateau.getXY(x-1,y);
                    liste[i][2]=plateau.getXY(x-1,y+1);
                    liste[i][3]=plateau.getXY(x,y+1);
                    hautDroite=false;
                }else{
                    if(basGauche){
                        liste[i][0]=plateau.getXY(x,y);
                        liste[i][1]=plateau.getXY(x+1,y);
                        liste[i][2]=plateau.getXY(x+1,y-1);
                        liste[i][3]=plateau.getXY(x,y-1);
                        basGauche=false;
                    }else{
                        if(basDroite){
                            liste[i][0]=plateau.getXY(x,y);
                            liste[i][1]=plateau.getXY(x+1,y);
                            liste[i][2]=plateau.getXY(x+1,y+1);
                            liste[i][3]=plateau.getXY(x,y+1);
                            basDroite=false;
                        }
                    }
                }
            }
        }
        return nb_liste ;
    }
}
