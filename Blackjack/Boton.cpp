#include "Boton.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "LTexture.h"
#include <string>

using namespace std;
LBoton::LBoton(){
	mPosition.x = 0;
	mPosition.y = 0;
	//  BUTTON_WIDTH=40;
	//	BUTTON_HEIGHT=10;
}

void LBoton::setPosition( int x, int y ){
	mPosition.x = x;
	mPosition.y = y;
}

void LBoton::handleEvent( SDL_Event* e ){
	//If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEMOTION:
				
				break;
				
			case SDL_MOUSEBUTTONDOWN:
				cout<<"Click"<<endl;
				break;
				
			case SDL_MOUSEBUTTONUP:
				
				break;
			}
		}
	}
}

void LBoton::render(SDL_Renderer* gRenderer,string archivo){
	//	botonRender.setMTexture(button.getMTexture());
	//Show current button sprite	
	if( !botonRender.loadFromFile( gRenderer,archivo ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		
	}
	botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
}

bool LBoton::pedir (SDL_Renderer* gRenderer,SDL_Event* e,int posX, int posY) {
	bool pedir=false;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//imagen
	if( !botonRender.loadFromFile( gRenderer,"imagenes/pedir.png" ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		
	}
	
	botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				
				if( !botonRender.loadFromFile( gRenderer,"imagenes/pedir2.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				pedir=true;
				SDL_Delay(200);
				
				break;
			case SDL_MOUSEBUTTONUP:
				if( !botonRender.loadFromFile( gRenderer,"imagenes/pedir.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				
				break;
			default:
				break;
			}
		}
	}
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return pedir;
}

bool LBoton::plantarse (SDL_Renderer * gRenderer, SDL_Event * e, int posX, int posY ) {
	
	bool plantado=false;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//imagen
	if( !botonRender.loadFromFile( gRenderer,"imagenes/plantarse.png" ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		
	}
	
	botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				
				if( !botonRender.loadFromFile( gRenderer,"imagenes/plantarse2.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				plantado=true;
				SDL_Delay(200);
				
				
				break;
			case SDL_MOUSEBUTTONUP:
				if( !botonRender.loadFromFile( gRenderer,"imagenes/plantarse.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				break;
			default:
				break;
			}
		}
	}
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return plantado;
}

bool LBoton::doblar (SDL_Renderer * gRenderer, SDL_Event * e, int posX, int posY ) {
	bool doblar=false;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//imagen
	
	if( !botonRender.loadFromFile( gRenderer,"imagenes/doblar.png" ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		
	}
	
	botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				if( !botonRender.loadFromFile( gRenderer,"imagenes/doblar2.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				doblar=true;
				SDL_Delay(200);
				
				break;
			case SDL_MOUSEBUTTONUP:
				
				if( !botonRender.loadFromFile( gRenderer,"imagenes/doblar.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				break;
			default:
				break;
			}
		}
	}
	
	
	
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return doblar;
}

bool LBoton::separar (SDL_Renderer * gRenderer, SDL_Event * e, int posX, int posY ) {
	bool separar=false;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//Imagen
	if( !botonRender.loadFromFile( gRenderer,"imagenes/separar.png" ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		
	}
	
	botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				
				if( !botonRender.loadFromFile( gRenderer,"imagenes/separar2.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				separar=true;
				SDL_Delay(200);
				
				break;
			case SDL_MOUSEBUTTONUP:
				if( !botonRender.loadFromFile( gRenderer,"imagenes/separar.png" ) )
				{
					printf( "Failed to load Foo' texture image!\n" );
					
				}
				
				botonRender.renderRotado(gRenderer,mPosition.x, mPosition.y,BUTTON_WIDTH,BUTTON_HEIGHT);
				
				
				break;
			default:		
				
				break;
			}
		}
	}
	
	
	
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return separar;
}

void LBoton::salir (SDL_Renderer * gRenderer, SDL_Event * e, int posX, int posY ) {
	
}

int LBoton::apuesta1 (SDL_Renderer * gRenderer, SDL_Event * e , int posX, int posY ) {
	// valor de la apuesta 
	int ap1=0;
	
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//Imagen
	if( !botonRender.loadFromFile( gRenderer,"imagenes/FICHAS/casino_chips.png" ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		
	}
	for( int i = 0; i < 5; ++i )
	{
		botonFicha[ i ].x = i*105+40;
		botonFicha[ i ].y = 0;
		botonFicha[ i ].w = 105;
		botonFicha[ i ].h = 108;
	}
	
	botonRender.render(gRenderer,&botonFicha[0], mPosition.x,mPosition.y,Tamanio_Ficha,Tamanio_Ficha);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + Tamanio_Ficha)
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + Tamanio_Ficha )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				if(e->button.clicks==1){
					
					ap1=1;
					
					SDL_Delay(200);
				}
				break;
				
			default:		
				
				break;
			}
		}
	}
	
	
	
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return ap1;
}

int LBoton::apuesta2 (SDL_Renderer * gRenderer, SDL_Event * e , int posX, int posY ) {
	int ap2=0;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//Imagen
	
	botonRender.render(gRenderer,&botonFicha[1], mPosition.x,mPosition.y,Tamanio_Ficha,Tamanio_Ficha);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + Tamanio_Ficha )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + Tamanio_Ficha )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				if(e->button.clicks==1){
					
					ap2=2;
					
					SDL_Delay(200);
				}
				
				
				break;
				
			default:		
				
				break;
			}
		}
	}
	
	
	
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return ap2;
}

int LBoton::apuesta3 (SDL_Renderer * gRenderer, SDL_Event * e , int posX, int posY ) {
	int ap3=0;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//Imagen
	
	botonRender.render(gRenderer,&botonFicha[2], mPosition.x,mPosition.y,Tamanio_Ficha,Tamanio_Ficha);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + Tamanio_Ficha )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + Tamanio_Ficha )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				if(e->button.clicks==1){
					
					ap3=3;
					
					SDL_Delay(200);
				}
				break;
				
			default:		
				
				break;
			}
		}
	}
	
	
	
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return ap3;
}

int LBoton::apuesta4 (SDL_Renderer * gRenderer, SDL_Event * e , int posX, int posY ) {
	int ap4=0;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//Imagen
	
	botonRender.render(gRenderer,&botonFicha[3], mPosition.x,mPosition.y,Tamanio_Ficha,Tamanio_Ficha);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + Tamanio_Ficha )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + Tamanio_Ficha )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				if(e->button.clicks==1){
					
					ap4=4;
					
					SDL_Delay(200);
				}
				
				break;
				
			default:		
				
				break;
			}
		}
	}
	
	
	
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return ap4;
}

int LBoton::apuesta5 (SDL_Renderer * gRenderer, SDL_Event * e , int posX, int posY ) {
	int ap5=0;
	//Set posicion 
	mPosition.x = posX;
	mPosition.y = posY;
	//Imagen
	
	botonRender.render(gRenderer,&botonFicha[4], mPosition.x,mPosition.y,Tamanio_Ficha,Tamanio_Ficha);
	
	
	
	//Accion al presionar boton	
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );
		
		//Check if mouse is in button
		bool inside = true;
		
		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + Tamanio_Ficha )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + Tamanio_Ficha )
		{
			inside = false;
		}
		
		//Mouse is outside button
		if( !inside )
		{
			
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
			case SDL_MOUSEBUTTONDOWN:
				if(e->button.clicks==1){
					
					ap5=5;
					
					SDL_Delay(200);
				}
				break;
				
			default:		
				
				break;
			}
		}
	}
	
	
	
	//Dejo en 0 para las proximas aplicaciones 
	mPosition.x = 0;
	mPosition.y = 0;
	return ap5;
}

