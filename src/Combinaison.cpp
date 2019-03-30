#include "Combinaison.h"
#include "stdlib.h"
Combinaison::Combinaison()
{
    //ctor
}

Combinaison::~Combinaison()
{
    //dtor
}

static Piece** getListePieces(int forme, Plateau plateau,int x, int y ){
    Piece** liste;
    int i;
    if(forme==1){

        if((x==0 && (y==1 || y==2)) || (x==3  && (y==1 || y==2)) || (y==0 && (x==1 || x==2)) ||(y==3 && (x==1 || x==2))) {
            //pas diago
            liste= (Piece**)malloc(2* sizeof(*liste));
            for (i=0;i<2;i++){
                liste[i]=(Piece*)malloc(4*sizeof(*(liste[i])));
            }
        }else{
            //diago
            liste= (Piece**)malloc(3* sizeof(*liste));
            for (i=0;i<3;i++){
                liste[i]=(Piece*)malloc(4*sizeof(*(liste[i])));
            }
            if(x==y){
                for (i=0;i<4;i++){
                    liste[3][i]=*plateau.getXY(i,i);
                }
            }else{
                for (i=0;i<4;i++){
                    liste[3][i]=*plateau.getXY(i,3-i);
                }
            }
        }
        for (i=0;i<4;i++){
            liste[1][i]=*plateau.getXY(x,i);
            liste[2][i]=*plateau.getXY(i,y);
        }
        return liste;
    }
    if(forme==2){
     //caré
        bool hautGauche=false;
        bool basGauche=false;
        bool basDroite=false;
        bool hautDroite=false;
        if((x==0 && (y==0|| y==3)) || (x==3 && (y==0 || y==3))){
            liste= (Piece**)malloc(1* sizeof(*liste));
            liste[1]=(Piece*)malloc(4*sizeof(*(liste[1])));

            basDroite=(x==0 && y==0);
            basGauche=(x==0 && y==3);
            hautDroite=(x==3 && y==0);
            hautGauche=(x==3 && y==3);

        }else{
            if((x==0 && (y==1 || y==2)) || (x==3  && (y==1 || y==2)) || (y==0 && (x==1 || x==2)) ||(y==3 && (x==1 || x==2))) {
            //pas diago
                liste= (Piece**)malloc(2* sizeof(*liste));
                for (i=0;i<2;i++){
                    liste[i]=(Piece*)malloc(4*sizeof(*(liste[i])));
                }
                if(x==0 || x==4){
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
                liste= (Piece**)malloc(4* sizeof(*liste));
                for (i=0;i<4;i++){
                    liste[i]=(Piece*)malloc(4*sizeof(*(liste[i])));
                }
                basDroite=true;
                basGauche=true;
                hautDroite=true;
                hautGauche=true;
            }
        }

        i=0;
        if(hautGauche){
            liste[i][0]=*plateau.getXY(x,y);
            liste[i][1]=*plateau.getXY(x-1,y);
            liste[i][2]=*plateau.getXY(x-1,y-1);
            liste[i][3]=*plateau.getXY(x,y-1);
            i=i+1;

        }if(hautDroite){
            liste[i][0]=*plateau.getXY(x,y);
            liste[i][1]=*plateau.getXY(x-1,y);
            liste[i][2]=*plateau.getXY(x-1,y+1);
            liste[i][3]=*plateau.getXY(x,y+1);
            i=i+1;
        }if(basGauche){
            liste[i][0]=*plateau.getXY(x,y);
            liste[i][1]=*plateau.getXY(x+1,y);
            liste[i][2]=*plateau.getXY(x+1,y-1);
            liste[i][3]=*plateau.getXY(x,y-1);
            i=i+1;
        }if(basDroite){
            liste[i][0]=*plateau.getXY(x,y);
            liste[i][1]=*plateau.getXY(x+1,y);
            liste[i][2]=*plateau.getXY(x+1,y+1);
            liste[i][3]=*plateau.getXY(x,y+1);
            i=i+1;
        }
        return liste;
    }


}
