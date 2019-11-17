#ifndef LTEXTURE_H
#define LTEXTURE_H
#include <string>
#include <cstddef>
#include <SDL.h>
#include <SDL_image.h>
//Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();
	
	//Deallocates memory
	~LTexture();
	
	//Loads image at specified path
	bool loadFromFile(SDL_Renderer* , std::string path );
	
	//Deallocates texture
	void free();

	//Renders texture at given point
	void render( SDL_Renderer* ,SDL_Rect *,int x, int y, int w, int h );
	void renderRotado( SDL_Renderer* ,int , int ,int,int,  SDL_Rect*  = NULL, double  = 0.0, SDL_Point*  = NULL, SDL_RendererFlip = SDL_FLIP_NONE );
	void setTamanioImagen(int,int);
	//Gets image dimensions
	void setMTexture(SDL_Texture*);
	SDL_Texture* getMTexture();
	
	int getWidth();
	int getHeight();
	
	
private:
	//The actual hardware texture
	SDL_Texture* mTexture;
	
	//Image dimensions
	int mWidth;
	int mHeight;
};


#endif

