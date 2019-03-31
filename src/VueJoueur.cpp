#include "VueJoueur.h"
#include <exception>
#include <iostream>
#include <string.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

SDL_Window* gWindow ;
SDL_Surface* gPiece;
SDL_Surface* gScreenSurface;
SDL_Rect image;
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 400;

VueJoueur::VueJoueur()
{
    gWindow = NULL;
    gScreenSurface = NULL;
    gPiece = NULL;

    initialiser();
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = 900;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/blanc.png" ), NULL, gScreenSurface, &stretchRect );
    SDL_UpdateWindowSurface( gWindow );


}

VueJoueur::~VueJoueur()
{
    //dtor
}


bool VueJoueur::initialiser()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "Quarto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            }
        }
    }
    return success;
}

SDL_Surface* VueJoueur::loadSurface( std::string path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}


SDL_Surface* VueJoueur::loadpiece(Piece piece)
{
    printf("3");
    gPiece = NULL;
    string imageName ="images/";


    if(piece.couleur){
        imageName+="red";
    }
    else{
        imageName+="bl";
    }
    if(piece.forme){
        imageName+="_cr";
    }
    else{
        imageName+="_sq";
    }
    if(piece.taille){
        imageName+="_big";
    }
    else{
        imageName+="_small";
    }
    if(piece.pleine){
        imageName+="_full";
    }
    else{
        imageName+="_emp";
    }

    imageName+=".png";
   // printf("%s \n",imageName.c_str());
    //cout<<imageName<<endl;
    gPiece=loadSurface(imageName);

    if (gPiece==NULL)
    {
        printf("image marche pas null \n");
    }
    return gPiece;
}

void VueJoueur::chargerPlateau(int x,int y,Piece* piece)
{

    image.x = x*100 +500;
    image.y = y*100;
    image.w=100;
    image.h=100;

    loadpiece(*piece);
    SDL_BlitScaled( gPiece, NULL, gScreenSurface, &image );
    SDL_UpdateWindowSurface( gWindow );
    SDL_FreeSurface(gPiece);
    gPiece = NULL;
}
void VueJoueur::chargerReserve(int x,int y,Piece* piece)
{
    image.x = x*100;
    image.y = y*100;
    image.w=100;
    image.h=100;

    loadpiece(*piece);
    SDL_BlitScaled( gPiece, NULL, gScreenSurface, &image );
    SDL_UpdateWindowSurface( gWindow );
    SDL_FreeSurface(gPiece);
    gPiece = NULL;

}

void VueJoueur::viderReserve(int x,int y){
    image.x = x*100;
    image.y = y*100;
    image.w=100;
    image.h=100;

    SDL_BlitScaled( loadSurface( "images/blanc.png" ), NULL, gScreenSurface, &image );
    SDL_UpdateWindowSurface( gWindow );
}

