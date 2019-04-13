#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512

using namespace std;


class Image {

private :

	SDL_Surface * surface;
	SDL_Texture * texture;
	bool a_change;

public :
	Image ();
	void chargerImageDepuisFichier(const char* filename, SDL_Renderer * renderer);
 	void creerTextureAPartirDeSurface (SDL_Renderer * renderer);
 	void dessiner (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
 	SDL_Texture * getTexture() const;
 	void setSurface(SDL_Surface * surf);

};



class Menu {

private :

	char format [50];
	SDL_Window * fenetre;
	SDL_Renderer * renderer;

	Image im_menu;
	Image police_im;
	SDL_Color police_couleur;

public :
	Menu();
	~Menu();
	void MenuBoucle();
	void sdlAff_jouer();
	void sdlAffichage();
	void sdlAff_quitter();
	void sdlAff_a_suivre();
	void sdlAff_aide();
};
