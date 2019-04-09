#ifndef VUEJOUEUR_H
#define VUEJOUEUR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdio.h>
#include "Piece.h"


class VueJoueur
{
    public:
        VueJoueur();
        virtual ~VueJoueur();
        void chargerPlateau(int x,int y,Piece* piece);
        void chargerReserve(int x,int y,Piece* piece);
        void viderReserve(int x,int y);
        void clicJouer(int* xReserve, int* yReserve,int* xPlateau,int* yPlateau);

    protected:


    private:
        SDL_Surface* loadSurface( std::string path );
        SDL_Surface* loadpiece(Piece piece);
        bool initialiser();
        int coordonnee(int x);



};

#endif // VUEJOUEUR_H
