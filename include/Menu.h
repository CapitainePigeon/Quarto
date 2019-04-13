#ifndef MENU_H
#define MENU_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.h"


#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512

using namespace std;

class Menu {

private :

	char format [50];
	SDL_Window * fenetre;
	SDL_Renderer * renderer;
	Image im_menu;



public :

	Menu();
	~Menu();
	void MenuBoucle();
	void sdlAffichage();

};


#endif // MENU_H
