#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

LTexture::LTexture() {
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture() {
	//Deallocate
	free();
}

bool LTexture::loadFromFile( SDL_Renderer* gRenderer,std::string path ) {
	//Get rid of preexisting texture
	free();
	
	//The final texture
	SDL_Texture* newTexture = NULL;
	
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
		
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	
	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free() {
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(SDL_Renderer* gRenderer,SDL_Rect* clip, int x, int y,int w1,int h1 ) {
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, w1, h1 };
	
	//Set clip rendering dimensions
//	if( clip != NULL )
//	{
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
	
	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad,0,NULL,SDL_FLIP_NONE);
	
	
	//		SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	//	SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
}

int LTexture::getWidth() {
	return mWidth;
}

int LTexture::getHeight() {
	return mHeight;
}

void LTexture::renderRotado (SDL_Renderer * gRenderer, int x, int y,int w,int h , SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip) {
	//Set rendering space and render to screen
	//	SDL_Rect renderQuad = { x, y, w, h };
	
	SDL_Rect renderQuad;
	renderQuad.x=x;
	renderQuad.y=y;
	renderQuad.w=w;
	renderQuad.h=h;
	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	
	//Render to screen
	//
	SDL_RenderCopyEx( gRenderer, mTexture,NULL, &renderQuad, angle, center, flip );
}

void LTexture::setTamanioImagen (int w, int h) {
	//Get image dimensions
	mWidth = w;
	mHeight = h;
}


void LTexture::setMTexture (SDL_Texture * aux) {
	mTexture=aux;
}

SDL_Texture * LTexture::getMTexture ( ) {
	return mTexture;
}



