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
        bool clicPlateau(int* xPlateau,int* yPlateau);
        bool clicReserve(int* xReserve, int* yReserve);
        void avoirGagne();
        void avoirPerdu();
        void affTourJoueur(bool &tourJoueur);
        void afficherChoix(Piece* piece);

    protected:


    private:
        SDL_Surface* loadSurface( std::string path );
        SDL_Surface* loadpiece(Piece piece);
        bool initialiser();
        int coordonnee(int x);
        SDL_Renderer * renderer;
        Image im_joueur;

};

#endif // VUEJOUEUR_H
