#ifndef VUEJOUEUR_H
#define VUEJOUEUR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include "Image.h"
#include "Piece.h"




class VueJoueur
{
    public:
        VueJoueur();
        virtual ~VueJoueur();
        void chargerPlateau(int x,int y,Piece* piece);
        void chargerReserve(int x,int y,Piece* piece);
        void viderReserve(int x,int y);
        bool clicJouer(int* xReserve, int* yReserve,int* xPlateau,int* yPlateau);
        void avoirGagne();
        void avoirPerdu();
        void affTourJoueur();

    protected:


    private:
        SDL_Surface* loadSurface( std::string path );
        SDL_Surface* loadpiece(Piece piece);
        bool initialiser();
        int coordonnee(int x);
        TTF_Font * font;
        Image font_im;
        SDL_Color font_color;
        SDL_Renderer * renderer;

};

#endif // VUEJOUEUR_H
