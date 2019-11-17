/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "LTexture.h"
#include "Boton.h"
#include "MesaDeJuego.h"
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;
const int Ancho_Cartas = 80; // relacion altura/anchura = 1.3617 
const int Alto_Cartas = 110;
const int Tamanio_Ficha = 100;
//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
SDL_Rect ficha[5];
const int numeroJugadores=2;
//Scene textures
LTexture pozo;
LTexture gBackgroundTexture;
LTexture posicionDeJugadores[numeroJugadores];
LTexture puntero;
LTexture imagenes[60];

//Botones 
LBoton boton;

bool init() {
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
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		
		//Create window
		gWindow = SDL_CreateWindow( "BlackJack-PD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
	
	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;
	
	//Load Foo' texture
	if( !pozo.loadFromFile( gRenderer,"imagenes/FICHAS/casino_chips.png" ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		success = false;
	}
	for( int i = 0; i < 5; ++i )
	{
		ficha[ i ].x = i*105+40;
		ficha[ i ].y = 0;
		ficha[ i ].w = 105;
		ficha[ i ].h = 108;
	}
	
	
	
	
	for(int i=0;i<numeroJugadores;i++){
		if(!posicionDeJugadores[i].loadFromFile(gRenderer,"imagenes/Cartas/1Tapa.png")){
			cout<<"Fallo en cargar la imagen"<<endl;
			success=false;
		}
	}
	//Load background texture
	if( !gBackgroundTexture.loadFromFile(gRenderer, "imagenes/Tablero.jpg" ) )
	{
		printf( "Failed to load background texture image!\n" );
		success = false;
	}
	//Puntero
	if( !puntero.loadFromFile(gRenderer, "imagenes/rombo.png" ) )
	{
		printf( "Failed to load background texture image!\n" );
		success = false;
	}
	
	
	
	
	
	//	boton.setPosition(0,650);
	
	return success;
}



void close() {
	//Free loaded images
	puntero.free();
	pozo.free();
	gBackgroundTexture.free();
	for(int i=0;i<numeroJugadores;i++){
		posicionDeJugadores[i].free();
		
	}
	for(int i=0;i<60;i++){
		imagenes[i].free();
	}
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] ) {
	vector <string> nombreRender;
	MesaDeJuego Black(numeroJugadores);
	bool empieza=true,bandera=false,bandera1=false,bandera2=false,bandera3=false,parar=false,hold=false;
	bool hold1=false,haganSusApuestas=false,hold2=false,hold3=false,hold4=false,hold5=false,hold6=false,hold7=false,hold8=false,hold9=false,hold10=false;
	bool baraja=true,Repartir=false,doblo=false,doblo1=false;
	bool juegaCroupier=false;
	char numeroDeCartas;
	char numeroDeCartas2;
	char numeroDeCartas3;
	int auxX=90,auxX1=90,auxX2=90,auxX3=90,auxX4=90,auxX5=90,auxX6=90,auxX7=90,auxX8=90,auxY=10,auxY1=10,auxY2=10,auxY3=10,auxY4=10,auxY5=10,auxY6=10,auxY7=10,auxY8=10;
	int turno=0,auxX9=90,auxY9=10;
	int auxX10=90,auxY10=10,auxX11=90,auxY11=10;
	int contaCroup=40,auxil1=30,auxil=20;
	//Start up SDL and create window
	
	SDL_Thread *thread;
	
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;
			
			//Event handler
			SDL_Event e;
			
			
			
			
			
			
			//While application is running
			while( !quit )
			{
				
				//				nombreRender=Black.repartirCartas();
				//				loadCARTA(nombreRender);
				//				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				gBackgroundTexture.renderRotado(gRenderer, 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT );
				
				int xx=770;
				for(int j=0;j<5;j++){
					
					pozo.render(gRenderer, &ficha[j], xx, 0, Tamanio_Ficha, Tamanio_Ficha);
					xx+=30;
					
				}
				int xxx=20;
				for(int k=0;k<10;k++){
					posicionDeJugadores[0].renderRotado(gRenderer, xxx, 10, Ancho_Cartas, Alto_Cartas);
					xxx+=7;
				}
				/*---------------------------------------------------------*/
				
				puntero.renderRotado(gRenderer, 510, 400, 20, 40);
				
				
				if(!haganSusApuestas){
					
					int p=340,h=610;
					int apuesto=0,apuesto2=0,apuesto3=0,apuesto4=0,apuesto5=0;
					apuesto=boton.apuesta1(gRenderer, &e, p, h);
					apuesto2=boton.apuesta2(gRenderer, &e, p+70, h);
					apuesto3=boton.apuesta3(gRenderer, &e, p+140, h);
					apuesto4=boton.apuesta4(gRenderer, &e, p+210, h);
					apuesto5=boton.apuesta5(gRenderer, &e, p+280, h);
					if(apuesto==1 && turno==0){
						hold=true;
						
					}
					if(apuesto==1 && turno==1){
						hold1=true;
					}
					if(apuesto2==2 && turno==0){
						hold2=true;
						
					}
					if(apuesto2==2 && turno==1){
						hold3=true;
					}
					if(apuesto3==3 && turno==0){
						hold4=true;
						
					}
					if(apuesto3==3 && turno==1){
						hold5=true;
					}
					if(apuesto4==4 && turno==0){
						hold6=true;
						
					}
					if(apuesto4==4 && turno==1){
						hold7=true;
					}
					if(apuesto5==5 && turno==0){
						hold8=true;
						
					}
					if(apuesto5==5 && turno==1){
						hold9=true;
					}
					/*Apuestan los jugadores*/
					if(Black.apuestas(turno,apuesto,apuesto2,apuesto3,apuesto4,apuesto5)){
						turno++;
					}
					
					if(turno==numeroJugadores){
						//Le toca jugar al dealer
						empieza=false;
						haganSusApuestas=true;
						turno=0;
					}
					
				}
				if (hold ){
					pozo.render(gRenderer, &ficha[0], 480,440-100, 40, 40);
				}
				if(hold1){
					pozo.render(gRenderer, &ficha[0], 620,410-100, 40, 40);
				}
				if (hold2 ){
					pozo.render(gRenderer, &ficha[1], 480,440-100, 40, 40);
				}
				if(hold3){
					pozo.render(gRenderer, &ficha[1], 620,410-100, 40, 40);
				}
				if (hold4 ){
					pozo.render(gRenderer, &ficha[2], 480,440-100, 40, 40);
				}
				if(hold5){
					pozo.render(gRenderer, &ficha[2], 620,410-100, 40, 40);
				}
				if (hold6 ){
					pozo.render(gRenderer, &ficha[3], 480,440-100, 40, 40);
				}
				if(hold7){
					pozo.render(gRenderer, &ficha[3], 620,410-100, 40, 40);
				}
				if (hold8 ){
					pozo.render(gRenderer, &ficha[4], 480,440-100, 40, 40);
				}
				if(hold9){
					pozo.render(gRenderer, &ficha[4], 620,410-100, 40, 40);
				}
				
				
				if(!empieza){
					if (baraja){
						juegaCroupier=false;
						nombreRender=Black.repartirCartas();
						nombreRender.size();
						numeroDeCartas='A';
						numeroDeCartas2='A';
						numeroDeCartas3='A';
						turno=0;
						baraja=false;
					}
					
					
					for(int k=0;k<numeroJugadores;k++){
						
						switch(k){
						case 0:
							switch(numeroDeCartas){
							case 'A':
								if( !imagenes[0].loadFromFile(gRenderer, nombreRender[0]) )
								{
									printf( "Fallo en cargar la carta cuando repartiamos!\n" );
									
								}							
								imagenes[0].renderRotado(gRenderer, auxX, auxY, Ancho_Cartas, Alto_Cartas);
								if(auxX<480){
									auxX+=16;
								}
								if(auxY<440){
									auxY+=16;
								}
								else if(auxX>=480 && auxY>=440){
									
									auxX=90;
									auxY=10;
									numeroDeCartas='B';
								}
								
								break;
							case 'B':
								if( !imagenes[1].loadFromFile(gRenderer, nombreRender[numeroJugadores]) )
								{
									printf( "Fallo en cargar la carta cuando repartiamos!\n" );
									
								}
								imagenes[0].renderRotado(gRenderer, 480, 440, Ancho_Cartas, Alto_Cartas);
								imagenes[1].renderRotado(gRenderer, auxX, auxY, Ancho_Cartas, Alto_Cartas,NULL,10);
								if(auxX<495){
									
									auxX+=16;
								}
								if(auxY<440){
									auxY+=16;
								}
								else if(auxX>=480 && auxY>=440){
									
									bandera3=true;
								}
								break;
							}
							break;
						case 1:
							switch(numeroDeCartas2){
							case 'A':
								if( !imagenes[2].loadFromFile(gRenderer, nombreRender[1]) )
								{
									printf( "Fallo en cargar la carta cuando repartiamos!\n" );
									
								}
								
								imagenes[2].renderRotado(gRenderer, auxX1, auxY1, Ancho_Cartas, Alto_Cartas, NULL, -20);
								if(auxX1<620){
									auxX1+=20;
								}
								if(auxY1<410){
									auxY1+=16;}
								
								else if(auxX1>=620 && auxY1>=410){
									numeroDeCartas2='B';
									auxX1=90;
									auxY1=10;								
								}
								break;
							case 'B':
								if( !imagenes[3].loadFromFile(gRenderer, nombreRender[numeroJugadores+1]) )
								{
									printf( "Fallo en cargar la carta cuando repartiamos!\n" );
									
								}
								imagenes[2].renderRotado(gRenderer, 620, 410, Ancho_Cartas, Alto_Cartas,NULL,-20);
								imagenes[3].renderRotado(gRenderer, auxX1, auxY1, Ancho_Cartas, Alto_Cartas,NULL,-5);
								if(auxX1<630){
									auxX1+=20;
								}
								if(auxY1<410){
									auxY1+=16;
								}
								else if(auxX1>=620 && auxY1>=410){
									bandera2=true;
								}
								break;
							}
							
							break;
						default:
							
							break;
						}
						
					}
					
					///////////////////////////////////////////------------------------------------------------------------
					
					switch(numeroDeCartas3){
					case 'A':
						if( !imagenes[15].loadFromFile(gRenderer, nombreRender[numeroJugadores*2]) )
						{
							printf( "Fallo en cargar la carta cuando repartiamos!\n" );
							
						}
						
						imagenes[15].renderRotado(gRenderer, auxX8, auxY8, Ancho_Cartas, Alto_Cartas);
						if(auxX8<475){
							auxX8+=20;
						}
						if(auxY8<48){
							auxY8+=2;}
						
						else if(auxX8>=475 && auxY8>=48){
							numeroDeCartas3='B';
							auxX8=90;
							auxY8=10;								
						}
						break;
					case 'B':
						if( !imagenes[16].loadFromFile(gRenderer, nombreRender[2*numeroJugadores+1]) )
						{
							printf( "Fallo en cargar la carta cuando repartiamos!\n" );
							
						}
						if( !imagenes[17].loadFromFile(gRenderer, "imagenes/Cartas/1Tapa.png") )
						{
							printf( "Fallo en cargar la carta cuando repartiamos!\n" );
							
						}
						imagenes[15].renderRotado(gRenderer, 475, 48, Ancho_Cartas, Alto_Cartas);
						
						imagenes[16].renderRotado(gRenderer, auxX8, auxY8, Ancho_Cartas, Alto_Cartas,NULL,10);
						if(!juegaCroupier){
							imagenes[17].renderRotado(gRenderer, auxX8, auxY8, Ancho_Cartas, Alto_Cartas,NULL,10);}
						if(auxX8<490){
							auxX8+=20;
						}
						if(auxY8<48){
							auxY8+=2;
						}
						else if(auxX8>=475 && auxY8>=48){
							bandera=true;								
						}
						
						
						
						break;
					}
				}			
				
				if(!empieza && bandera3 ){	
					int pos=400,al=630;
					
					/*boton.separar(gRenderer, &e, pos+330, al);*/
					
					
					
					if (boton.pedir(gRenderer, &e, pos, al)){
						string nuevaCarta=Black.darCartas(turno);
						
						
						if(turno==0){
							if( !imagenes[auxil].loadFromFile(gRenderer,nuevaCarta))
							{
								printf( "Fallo en cargar la carta cuando repartiamos!\n" );
							}
							auxil++;	
						}
						int getPuntos=Black.getPuntuacionJugador(turno);
						if(getPuntos<0){
							turno++;
							continue;
							
						}
						
						if(turno==1){
							if( !imagenes[auxil1].loadFromFile(gRenderer,nuevaCarta))
							{
								printf( "Fallo en cargar la carta cuando repartiamos!\n" );
							}
							auxil1++;
							
						}
						Repartir=true;
						
					}
					if(boton.doblar(gRenderer, &e, pos+220, al)){
						
						
						Black.doblarApuesta(turno);
						string nuevaCarta=Black.darCartas(turno);
						if( !imagenes[auxil].loadFromFile(gRenderer,nuevaCarta))
						{
							printf( "Fallo en cargar la carta cuando repartiamos!\n" );
						}
						if(turno==0){
							if( !imagenes[auxil].loadFromFile(gRenderer,nuevaCarta))
							{
								printf( "Fallo en cargar la carta cuando repartiamos!\n" );
							}
							auxil++;
							doblo=true;
						
						}
						int getPuntos=Black.getPuntuacionJugador(turno);
						if(getPuntos<0){
							turno++;
							continue;
							
						}
						
						if(turno==1){
							if( !imagenes[auxil1].loadFromFile(gRenderer,nuevaCarta))
							{
								printf( "Fallo en cargar la carta cuando repartiamos!\n" );
							}
							auxil1++;
							doblo1=true;
							
						}
						Repartir=true;
					}
					
					
					if(boton.plantarse(gRenderer, &e, pos+110, al)){
						turno++;
						Repartir=false;
					}
					
					
					if(Repartir ){
						switch(turno){
						case 0:
							
							
							if(auxX9<510){
								auxX9+=16;
							}
							if(auxY9<450){
								auxY9+=16;
							}
							break;
						case 1:
							if(auxX10<650){
								auxX10+=20;
							}
							if(auxY10<410){
								auxY10+=16;}
							break;
						}
						
					}
					for(int i=20;i<auxil;i++){
						imagenes[i].renderRotado(gRenderer, auxX9+(i-20)*10, auxY9+(i-20)*10, Ancho_Cartas, Alto_Cartas,NULL,20+(i-20)*15);	
					}
					for(int i=30;i<(auxil1);i++){
						
						imagenes[i].renderRotado(gRenderer, auxX10+(i-30)*10, auxY10, Ancho_Cartas, Alto_Cartas,NULL,20+(i-30)*15);
					}
					if(doblo){
						if (hold ){
							pozo.render(gRenderer, &ficha[0], 490,440-100, 40, 40);
						}
						
						if (hold2 ){
							pozo.render(gRenderer, &ficha[1], 490,440-100, 40, 40);
						}
						
						if (hold4 ){
							pozo.render(gRenderer, &ficha[2], 490,440-100, 40, 40);
						}
						
						if (hold6 ){
							pozo.render(gRenderer, &ficha[3], 490,440-100, 40, 40);
						}
						
						if (hold8 ){
							pozo.render(gRenderer, &ficha[4], 490,440-100, 40, 40);
						}
						
					}
					if(doblo1){
						if(hold1){
							pozo.render(gRenderer, &ficha[0], 630,410-100, 40, 40);
						}
						if(hold3){
							pozo.render(gRenderer, &ficha[1], 630,410-100, 40, 40);
						}
						if(hold5){
							pozo.render(gRenderer, &ficha[2], 630,410-100, 40, 40);
						}
						if(hold7){
							pozo.render(gRenderer, &ficha[3], 630,410-100, 40, 40);
						}
						if(hold9){
							pozo.render(gRenderer, &ficha[4], 630,410-100, 40, 40);
						}
						
					}
					if(turno==numeroJugadores){
						//Le toca jugar al dealer
						bool finCroupier=false;
									
						if(!juegaCroupier){
							
						imagenes[16].renderRotado(gRenderer, auxX8, auxY8, Ancho_Cartas, Alto_Cartas,NULL,10);
						SDL_RenderPresent( gRenderer );
						string nuevaCartaC=Black.jugarCroupier();
						finCroupier=Black.estadoCroupier();
						if( !imagenes[contaCroup].loadFromFile(gRenderer,nuevaCartaC))
						{
							printf( "Fallo en cargar la carta cuando repartiamos!\n" );
						}
						contaCroup++;
						
						juegaCroupier=true;
						}
						
						if(auxX11<501){
							auxX11+=20;
						}
						if(auxY11<58){
							auxY11+=2;
						}
						if(auxY11>=48 && auxX11<=500){
							
							if(!finCroupier){
								juegaCroupier=false;
							}
//							auxX11=90;
//							auxY11=10;
//								SDL_Delay(1000);
						}
						
						for(int i=40;i<contaCroup;i++){
							imagenes[i].renderRotado(gRenderer, auxX11+10+(i-40)*10, auxY11+(i-40)*10, Ancho_Cartas, Alto_Cartas,NULL,15+(i-40)*15);	
						}
						
						if(finCroupier){
							vector <int> darPremio;
							darPremio=Black.limpiarMesa();
							int contadorFinal=40;
							for(int m=0;m<darPremio.size();m++){
								if(darPremio[m]==0){
									if( !imagenes[contadorFinal].loadFromFile(gRenderer,"imagenes/gameover.png"))
									{
										printf( "Fallo en cargar la carta cuando repartiamos!\n" );
									}
									imagenes[contadorFinal].renderRotado(gRenderer,0+(contadorFinal-40)*500,0,500,800);
									SDL_RenderPresent( gRenderer );
									
								}
								else if(darPremio[m]==1){
									if( !imagenes[contadorFinal].loadFromFile(gRenderer,"imagenes/1ganaste.png"))
									{
										printf( "Fallo en cargar la carta cuando repartiamos!\n" );
									}
									imagenes[contadorFinal].renderRotado(gRenderer,0+(contadorFinal-40)*500,0,500,800);
									SDL_RenderPresent( gRenderer );
								}
								else{
									cout<<"Empate"<<endl;
								}
								contadorFinal++;
							}
//							
							juegaCroupier=false;
							contaCroup=40;	
							bandera=false;
							bandera1=false;
							bandera2=false;
							bandera3=false;
							empieza=true;
							turno=0;
							hold=false,hold1=false,hold2=false,hold3=false,hold4=false,hold5=false,hold6=false,hold7=false,hold8=false,hold9=false;
							haganSusApuestas=false,Repartir=false;
							baraja=true;
							auxX=90,auxX1=90,auxX2=90,auxX3=90,auxX4=90,auxX5=90,auxX6=90,auxX7=90,auxX8=90,auxY=10,auxY1=10,auxY2=10,auxY3=10,auxY4=10,auxY5=10,auxY6=10,auxY7=10,auxY8=10;
							auxX9=auxX,auxY9=auxY,auxil=20,auxil1=30;
							doblo=false,doblo1=false;
							auxX11=90;
							auxY11=10;
														
							SDL_Delay(2000);
						}
					}
					
					
				}
				/*--------------------------------------------------------------*/
				//Update screen
				SDL_RenderPresent( gRenderer );
				////////////////////////////////
			}
		}
	}
	//Free resources and close SDL
	close(); 
	return 0;
}
