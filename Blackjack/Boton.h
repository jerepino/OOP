#ifndef BOTON_H
#define BOTON_H
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include <string>
using namespace std;
//The mouse button
class LBoton
{
public:
	//Initializes internal variables
	LBoton();
	
	//Sets top left position
	void setPosition( int x, int y );
	
	//Handles mouse event
	void handleEvent( SDL_Event* e );
	
	//Shows button sprite
	void render(SDL_Renderer*,string);
	//Tipos de botones 
	bool pedir(SDL_Renderer*,SDL_Event*,int,int);
	bool plantarse(SDL_Renderer*,SDL_Event*,int,int);
	bool doblar(SDL_Renderer*,SDL_Event*,int,int);
	bool separar(SDL_Renderer*,SDL_Event*,int,int);
	void salir(SDL_Renderer*,SDL_Event*,int,int);
	int apuesta1(SDL_Renderer*,SDL_Event*,int,int);
	int apuesta2(SDL_Renderer*,SDL_Event*,int,int);
	int apuesta3(SDL_Renderer*,SDL_Event*,int,int);
	int apuesta4(SDL_Renderer*,SDL_Event*,int,int);
	int apuesta5(SDL_Renderer*,SDL_Event*,int,int);
private:
	//Top left position
	SDL_Point mPosition;
	LTexture botonRender;
	SDL_Rect botonFicha[5];
	const int BUTTON_WIDTH=100;
	const int BUTTON_HEIGHT=40;
	const int Tamanio_Ficha = 70;
	//	//Currently used global sprite
	//	LButtonSprite mCurrentSprite;
};


#endif

