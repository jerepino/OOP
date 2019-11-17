#include "Jugador.h"
#include <iostream>
using namespace std;

Jugador::Jugador() {
	this->puntuacion2=0;
	this->puntuacion1=0;
	this->pozo=1000;
}

Jugador::~Jugador() {
	
}

void Jugador::doblar ( ) {
	this->apuesta=apuesta*2;
	this->pozo-=apuesta;
	cout<<"La apuesta del jugador es: "<<apuesta<<endl;
	cout<<"El pozo del Jugador es: "<<pozo<<endl;
}

void Jugador::apuestaInicial (int valorApuesta ) {
	this->apuesta=valorApuesta;
	this->pozo-=valorApuesta;
	cout<<"La apuesta del jugador es: "<<apuesta<<endl;
	cout<<"El pozo del Jugador es: "<<pozo<<endl;
}

void Jugador::asignarCartaJ (int cart) {
	mano.push_back(cart);
}

const vector<int> Jugador::getMano ( ) {
	return mano;
}

const int Jugador::getPuntuacion ( ) {
	this->puntuacion1=0;
	this->puntuacion2=0;
	int CartasDeCadaPalo=13;
	for (int i=0;i<mano.size();i++){
		if(mano[i]==1 || mano[i]==1+CartasDeCadaPalo || mano[i]==1+2*CartasDeCadaPalo || mano[i]==1+3*CartasDeCadaPalo){
			puntuacion1+=11;
			puntuacion2+=1;
		}
		else if(mano[i]==2 || mano[i]==2+CartasDeCadaPalo || mano[i]==2+2*CartasDeCadaPalo || mano[i]==2+3*CartasDeCadaPalo){
			puntuacion1+=2;
			puntuacion2+=2;
		}
		else if(mano[i]==3 || mano[i]==3+CartasDeCadaPalo || mano[i]==3+2*CartasDeCadaPalo || mano[i]==3+3*CartasDeCadaPalo){
			puntuacion1+=3;
			puntuacion2+=3;
		}
		else if(mano[i]==4 || mano[i]==4+CartasDeCadaPalo || mano[i]==4+2*CartasDeCadaPalo || mano[i]==4+3*CartasDeCadaPalo){
			puntuacion1+=4;
			puntuacion2+=4;
		}
		else if(mano[i]==5 || mano[i]==5+CartasDeCadaPalo || mano[i]==5+2*CartasDeCadaPalo || mano[i]==5+3*CartasDeCadaPalo){
			puntuacion1+=5;
			puntuacion2+=5;
		}
		else if(mano[i]==6 || mano[i]==6+CartasDeCadaPalo || mano[i]==6+2*CartasDeCadaPalo || mano[i]==6+3*CartasDeCadaPalo){
			puntuacion1+=6;
			puntuacion2+=6;
		}
		else if(mano[i]==7 || mano[i]==7+CartasDeCadaPalo || mano[i]==7+2*CartasDeCadaPalo || mano[i]==7+3*CartasDeCadaPalo){
			puntuacion1+=7;
			puntuacion2+=7;
		}
		else if(mano[i]==8 || mano[i]==8+CartasDeCadaPalo || mano[i]==8+2*CartasDeCadaPalo || mano[i]==8+3*CartasDeCadaPalo){
			puntuacion1+=8;
			puntuacion2+=8;
		}
		else if(mano[i]==9 || mano[i]==9+CartasDeCadaPalo || mano[i]==9+2*CartasDeCadaPalo || mano[i]==9+3*CartasDeCadaPalo){
			puntuacion1+=9;
			puntuacion2+=9;
		}
		else{
			puntuacion1+=10;
			puntuacion2+=10;
		}
	}
	
	if (puntuacion2<=21){
		this->puntosTotales=puntuacion2;
	}
	if(puntuacion1>21 && puntuacion2>21){
		this->puntosTotales=-100;
	}	
	if(puntuacion1<=21){
		this->puntosTotales=puntuacion1;
	}
	
	
	return this->puntosTotales;
}

void Jugador::limpiarMano ( ) {
	mano.clear();
	this->puntuacion1=0;
	this->puntuacion2=0;
	this->puntosTotales=0;
	this->apuesta=0;
}

void Jugador::setPozo (int ) {
	
}

void Jugador::paga (int factor) {
	this->pozo+=apuesta*factor;
	
	cout<<"El pozo ahora es: "<<pozo<<endl;
	
	
}

