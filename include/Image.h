#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



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


#endif // IMAGE_H
