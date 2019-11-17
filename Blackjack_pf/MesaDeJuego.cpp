#include "MesaDeJuego.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Carta.h"
#include <vector>
#include "Jugador.h"
#include "Croupier.h"
#include "Boton.h"
using namespace std;

MesaDeJuego::MesaDeJuego(unsigned int nJugadores) {
	cantidadJugadores=nJugadores;
	player.resize(cantidadJugadores);
	this->jugandoCroupier=false;
}

MesaDeJuego::~MesaDeJuego() {
	player.clear();
}

string MesaDeJuego::jugarCroupier ( ) {	
	int puntuacionC;
	string cartaCasa;
	puntuacionC=casino.getPuntuacion();
	if(puntuacionC<0){
		cartaCasa="imagenes/Cartas/1Tapa.png";
		this->jugandoCroupier=true;
	}
	else if(puntuacionC<=16 && puntuacionC>0){
		cartaCasa=darCartas(cantidadJugadores);
		this->jugandoCroupier=false;
	}
	else if(puntuacionC>=17){
		
		this->jugandoCroupier=true;
		cartaCasa="imagenes/Cartas/1Tapa.png";
	}
	return cartaCasa;
}

vector<string> MesaDeJuego::repartirCartas () {
	vector<string> AAA;
	mazo.barajar();
	for(int j=0;j<2;j++){
		for(int i=0;i<cantidadJugadores;i++){
			AAA.push_back(darCartas(i));
		}
	}
	for(int k=0;k<2;k++){
		AAA.push_back(darCartas(cantidadJugadores));
	}
	return AAA;
}

string MesaDeJuego::interpretarCartas (int tipo) {
	string auxiliar;
	switch (tipo){
	case 1:
		auxiliar="imagenes/Cartas/CA.png";
		break;
	case 2:
		auxiliar="imagenes/Cartas/C2.png";
		break;
	case 3:
		auxiliar="imagenes/Cartas/C3.png";
		break;
	case 4:
		auxiliar="imagenes/Cartas/C4.png";
		break;
	case 5:
		auxiliar="imagenes/Cartas/C5.png";
		break;
	case 6:
		auxiliar="imagenes/Cartas/C6.png";
		
		break;
	case 7:
		auxiliar="imagenes/Cartas/C7.png";
		break;
	case 8:
		auxiliar="imagenes/Cartas/C8.png";
		break;
	case 9:
		auxiliar="imagenes/Cartas/C9.png";
		break;
	case 10:
		auxiliar="imagenes/Cartas/C10.png";
		break;
	case 11:
		auxiliar="imagenes/Cartas/CJ.png";
		break;
	case 12:
		auxiliar="imagenes/Cartas/CQ.png";
		break;
	case 13:
		auxiliar="imagenes/Cartas/CK.png";
		break;
	case 14:
		auxiliar="imagenes/Cartas/TA.png";
		break;
	case 15:
		auxiliar="imagenes/Cartas/T2.png";
		break;
	case 16:
		auxiliar="imagenes/Cartas/T3.png";
		break;
	case 17:
		auxiliar="imagenes/Cartas/T4.png";
		break;
	case 18:
		auxiliar="imagenes/Cartas/T5.png";
		break;
	case 19:
		auxiliar="imagenes/Cartas/T6.png";
		break;
	case 20:
		auxiliar="imagenes/Cartas/T7.png";
		break;
	case 21:
		auxiliar="imagenes/Cartas/T8.png";
		break;
	case 22:
		auxiliar="imagenes/Cartas/T9.png";
		break;
	case 23:
		auxiliar="imagenes/Cartas/T10.png";
		break;
	case 24:
		auxiliar="imagenes/Cartas/TJ.png";
		break;
	case 25:
		auxiliar="imagenes/Cartas/TQ.png";
		break;
	case 26:
		auxiliar="imagenes/Cartas/TK.png";
		break;
	case 27:
		auxiliar="imagenes/Cartas/DA.png";
		break;
	case 28:
		auxiliar="imagenes/Cartas/D2.png";
		break;
	case 29:
		auxiliar="imagenes/Cartas/D3.png";
		break;
	case 30:
		auxiliar="imagenes/Cartas/D4.png";
		break;
	case 31:
		auxiliar="imagenes/Cartas/D5.png";
		break;
	case 32:
		auxiliar="imagenes/Cartas/D6.png";
		break;
	case 33:
		auxiliar="imagenes/Cartas/D7.png";
		break;
	case 34:
		auxiliar="imagenes/Cartas/D8.png";
		break;
	case 35:
		auxiliar="imagenes/Cartas/D9.png";
		break;
	case 36:
		auxiliar="imagenes/Cartas/D10.png";
		break;
	case 37:
		auxiliar="imagenes/Cartas/DJ.png";
		break;
	case 38:
		auxiliar="imagenes/Cartas/DQ.png";
		break;
	case 39:
		auxiliar="imagenes/Cartas/DK.png";
		break;
	case 40:
		auxiliar="imagenes/Cartas/PA.png";
		break;
	case 41:
		auxiliar="imagenes/Cartas/P2.png";
		break;
	case 42:
		auxiliar="imagenes/Cartas/P3.png";
		break;
	case 43:
		auxiliar="imagenes/Cartas/P4.png";
		break;
	case 44:
		auxiliar="imagenes/Cartas/P5.png";
		break;
	case 45:
		auxiliar="imagenes/Cartas/P6.png";
		break;
	case 46:
		auxiliar="imagenes/Cartas/P7.png";
		break;
	case 47:
		auxiliar="imagenes/Cartas/P8.png";
		break;
	case 48:
		auxiliar="imagenes/Cartas/P9.png";
		break;
	case 49:
		auxiliar="imagenes/Cartas/P10.png";
		break;
	case 50:
		auxiliar="imagenes/Cartas/PJ.png";
		break;
	case 51:
		auxiliar="imagenes/Cartas/PQ.png";
		break;
	case 52:
		auxiliar="imagenes/Cartas/TK.png";
		break;
	};
	return auxiliar;
}

vector <int> MesaDeJuego::limpiarMesa ( ) {
	vector <int> winer;
	int puntosCasino=casino.getPuntuacion();
	for(int j=0;j<cantidadJugadores;j++){
		int puntosJugador=player[j].getPuntuacion();
		if(puntosJugador>puntosCasino){
			player[j].paga();
			winer.push_back(1);
		}
		if(puntosJugador==puntosCasino){
			player[j].paga(1);
			winer.push_back(2);
		}
		if (puntosJugador<puntosCasino){
		winer.push_back(0);
		}
		player[j].limpiarMano();
	}
	casino.limpiarManoC();
	return winer;
}

bool MesaDeJuego::apuestas (int nJ,int a1, int a2, int a3, int a4, int a5) {
	bool apostando=false;
	int sumaApuesta=0;
	sumaApuesta=a1+a2+a3+a4+a5;
	if(sumaApuesta!=0){
		player[nJ].apuestaInicial(sumaApuesta);
		apostando=true;
	}
	return apostando;
}

string MesaDeJuego::darCartas (int jugador) {
	int aux=mazo.darCarta();
	if (jugador==cantidadJugadores){
		casino.asignarCartaC(aux);
	}
	else{
		player.at(jugador).asignarCartaJ(aux);
	}
	return interpretarCartas(aux);
}

void MesaDeJuego::doblarApuesta (int jugador ) {
	player[jugador].doblar();
}

bool MesaDeJuego::estadoCroupier ( ) {
	return this->jugandoCroupier;
}

int MesaDeJuego::getPuntuacionJugador (int J ) {
	return player[J].getPuntuacion ( );
	
}

