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

    protected:


    private:
        SDL_Surface* loadSurface( std::string path );
        SDL_Surface* loadpiece(Piece piece);
        bool initialiser();



};

#endif // VUEJOUEUR_H
