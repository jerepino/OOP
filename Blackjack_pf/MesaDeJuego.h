#ifndef MESADEJUEGO_H
#define MESADEJUEGO_H
#include "Carta.h"
#include <vector>
#include "Jugador.h"
#include "Croupier.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "Boton.h"
using namespace std;

class MesaDeJuego {
public:
	string darCartas(int);
	MesaDeJuego(unsigned int = 1);
	~MesaDeJuego();
	string jugarCroupier( );
	bool apuestas(int,int=0,int=0,int=0,int=0,int=0);
	vector<string> repartirCartas(); //Reparto al inicio de la partida 
	string interpretarCartas(int);
	vector <int> limpiarMesa();
	void doblarApuesta(int);
	bool estadoCroupier();
	int getPuntuacionJugador(int);
private:
	LTexture imagenes;
	unsigned int cantidadJugadores;
	Carta mazo;
	vector <Jugador> player;
	Croupier casino;
	const int Ancho_Cartas = 80; // relacion altura/anchura = 1.3617 
	const int Alto_Cartas = 110;
	bool jugandoCroupier;
};

#endif

