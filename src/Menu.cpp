#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Menu.h"
#include "partie.h"


Menu::Menu (){
	// Initialisation de la console
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image ne peut pas être initialiser! SDL_image Erreur: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }

    // Creation de la fenetre
    fenetre = SDL_CreateWindow("Quarto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (fenetre == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);

	im_menu.chargerImageDepuisFichier("images/menu_quarto.png",renderer);

}

Menu::~Menu(){
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(fenetre);
    	SDL_Quit();
}

void Menu::sdlAffichage(){
	//Remplir l'ecran de blanc
    	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    	SDL_RenderClear(renderer);
        im_menu.dessiner(renderer,0,0,512,512);
}

void Menu::MenuBoucle(){
	SDL_Event events;
	bool quit = false;

	// tant que ce n'est pas la fin ...
	while (!quit) {
		// tant qu'il y a des evenements  traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			switch (events.type)
			{
				case SDL_QUIT:           // Si l'utilisateur a clique sur la croix de fermeture
					quit = true;
					break;

				case SDL_MOUSEBUTTONUP: //clique souris
					if (events.button.button == SDL_BUTTON_LEFT)
					{
						if (events.button.x > 79 && events.button.x < 180 && events.button.y > 270 && events.button.y < 370 ) //test si on clique sur le carré
						{
							SDL_Delay(2000);
							quit= true;
							SDL_Quit();
							int forme = 2;
							Partie partie = Partie();
							partie.Jeu(forme);
						}
						else if (events.button.x > 252 && events.button.x < 452  && events.button.y > 320 && events.button.y <370 ) //test si on clique sur la ligne
						{
						    SDL_Delay(2000);
							quit= true;
							SDL_Quit();
							int forme = 1;
							Partie partie = Partie();
							partie.Jeu(forme);
						}
						else if (events.button.x > 410 && events.button.x < 485 && events.button.y > 470 && events.button.y < 490 ) //bouton quitter
						{
							quit=true;

						}
					}
					break;
			}

		}
		sdlAffichage();
		SDL_RenderPresent(renderer);
	}
}
