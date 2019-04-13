#include "VueJoueur.h"

#include <exception>
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>


using namespace std;

SDL_Window* gWindow ;
SDL_Surface* gPiece;
SDL_Surface* gScreenSurface;
SDL_Rect image;
const int SCREEN_WIDTH = 890;
const int SCREEN_HEIGHT = 500;

VueJoueur::VueJoueur()
{
    gWindow = NULL;
    gScreenSurface = NULL;
    gPiece = NULL;



    initialiser();
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = 890;
    stretchRect.h = 390;
    SDL_BlitScaled( loadSurface( "images/blanc.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 390;
    stretchRect.y = 0;
    stretchRect.w = 100;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 90;
    stretchRect.y = 0;
    stretchRect.w = 10;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 190;
    stretchRect.y = 0;
    stretchRect.w = 10;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 290;
    stretchRect.y = 0;
    stretchRect.w = 10;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 0;
    stretchRect.y = 90;
    stretchRect.w = 400;
    stretchRect.h = 10;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 0;
    stretchRect.y = 190;
    stretchRect.w = 400;
    stretchRect.h = 10;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 0;
    stretchRect.y = 290;
    stretchRect.w = 400;
    stretchRect.h = 10;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );



    stretchRect.x = 590;
    stretchRect.y = 0;
    stretchRect.w = 10;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 690;
    stretchRect.y = 0;
    stretchRect.w = 10;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 790;
    stretchRect.y = 0;
    stretchRect.w = 10;
    stretchRect.h = 400;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 490;
    stretchRect.y = 90;
    stretchRect.w = 400;
    stretchRect.h = 10;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 490;
    stretchRect.y = 190;
    stretchRect.w = 400;
    stretchRect.h = 10;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );
    stretchRect.x = 490;
    stretchRect.y = 290;
    stretchRect.w = 400;
    stretchRect.h = 10;
    SDL_BlitScaled( loadSurface( "images/noir.png" ), NULL, gScreenSurface, &stretchRect );

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

   /*if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;SDL_Quit();exit(1);
    }

    // FONTS
   font = TTF_OpenFont("font/police.ttf",70);
  	  if (font == NULL) {
         	   cout << "Failed to load police.ttf! SDL_TTF Error: " << TTF_GetError() << endl; SDL_Quit();exit(1);
		}*/

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
   // printf("3");
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

    image.x = x*100+500;
    image.y = y*100;
    image.w=90;
    image.h=90;

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
    image.w=90;
    image.h=90;

    loadpiece(*piece);
    SDL_BlitScaled( gPiece, NULL, gScreenSurface, &image );
    SDL_UpdateWindowSurface( gWindow );
    SDL_FreeSurface(gPiece);
    gPiece = NULL;

}

void VueJoueur::viderReserve(int x,int y){
    image.x = x*100;
    image.y = y*100;
    image.w=90;
    image.h=90;

    SDL_BlitScaled( loadSurface( "images/blanc.png" ), NULL, gScreenSurface, &image );
    SDL_UpdateWindowSurface( gWindow );
}

int VueJoueur::coordonnee(int x)
{
    int xretour=-1;
    if (x>0 && x<90)
    {
        xretour=0;
    }
    if (x>100 && x<190)
    {
        xretour=1;
    }
    if (x>200 && x<290)
    {
        xretour=2;
    }
    if (x>300 && x<390)
    {
        xretour=3;
    }
    if (x>500 && x<590)
    {
        xretour=4;
    }
    if (x>600 && x<690)
    {
        xretour=5;
    }
    if (x>700 && x<790)
    {
        xretour=6;
    }
    if (x>800 && x<890)
    {
        xretour=7;
    }
    return xretour;
}

bool VueJoueur::clicJouer(int* xReserve, int* yReserve,int* xPlateau,int* yPlateau)
{
    bool quit = false;
    *xReserve = -1;
    *yReserve = -1;
    *xPlateau = -1;
    *yPlateau = -1;
    int x=0,y=0;
    SDL_Event e;
    while( *xReserve==-1 || *yReserve==-1)
    {
        while( SDL_PollEvent( &e ) )
        {
            if (e.type == SDL_QUIT) {
                    quit = true;
                    SDL_Quit();
            }
            else if( e.type == SDL_MOUSEBUTTONDOWN)
            {
                //printf("cc");
                SDL_GetMouseState( &x, &y );
                *xReserve=coordonnee(y);
                *yReserve=coordonnee(x);
                if(*yReserve>3)
                    *yReserve=-1;
                printf("x1 %d  y1 %d\n",*xReserve,*yReserve);
            }
        }
    }
    while( (*xPlateau==-1 || *yPlateau==-1 ) )
    {
        while( SDL_PollEvent( &e ) )
        {
            if (e.type == SDL_QUIT) {
                    quit = true;
                    SDL_Quit();
            }
            else if( e.type == SDL_MOUSEBUTTONUP)
            {
                SDL_GetMouseState( &x, &y );
                *xPlateau=coordonnee(y);
                *yPlateau=coordonnee(x);
                *yPlateau=*yPlateau-4;
                if(*yPlateau<0)
                    *yPlateau=-1;
            }
        }
    }
    printf("x1 %d  y1 %d     x2 %d  y2 %d\n",*xReserve,*yReserve,*xPlateau,*yPlateau);

    return quit;
}

/*void VueJoueur::affTourJoueur(){
    char format [50];
    sprintf(format, "C'est à votre tour de jouer !");
    font_color.r = 195;font_color.g = 0;font_color.b = 0;
    font_im.setSurface(TTF_RenderText_Solid(font,format,font_color));
    font_im.creerTextureAPartirDeSurface(renderer);
    SDL_Rect positionTitre;
    positionTitre.x = 100;positionTitre.y = 450;positionTitre.w = 300;positionTitre.h = 30;
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);

}*/

/*void VueJoueur::avoirGagne(){
    sprintf(format, "Vous avez perdu en %d secondes", t);
			font_color.r = 195;font_color.g = 0;font_color.b = 0;
			font_im.setSurface(TTF_RenderText_Solid(font,format,font_color));
			font_im.creerTextureAPartirDeSurface(renderer);
			SDL_Rect positionTitre;
			positionTitre.x = 4*TAILLE_SPRITE;positionTitre.y = 13*TAILLE_SPRITE;positionTitre.w = 12*TAILLE_SPRITE;positionTitre.h = 2*TAILLE_SPRITE;
			SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);

}*/


