#include "Croupier.h"

Croupier::Croupier() {
	this->puntuacion1=0;
	this->puntuacion2=0;
	this->pozo=90000;
}

Croupier::~Croupier() {
	
}

void Croupier::asignarCartaC (int car ) {
	manoCroupier.push_back(car);
}

const vector<int> Croupier::getCartaC ( ) {
	return manoCroupier;
}
const int Croupier::getPuntuacion ( ) {
	this->puntuacion1=0;
	this->puntuacion2=0;
	
	int CartasDeCadaPalo=13;
	for (int i=0;i<manoCroupier.size();i++){
		if(manoCroupier[i]==1 || manoCroupier[i]==1+CartasDeCadaPalo || manoCroupier[i]==1+2*CartasDeCadaPalo || manoCroupier[i]==1+3*CartasDeCadaPalo){
			puntuacion1+=11;
			puntuacion2+=1;
			
		}
		else if(manoCroupier[i]==2 || manoCroupier[i]==2+CartasDeCadaPalo || manoCroupier[i]==2+2*CartasDeCadaPalo || manoCroupier[i]==2+3*CartasDeCadaPalo){
			puntuacion1+=2;
			puntuacion2+=2;
		}
		else if(manoCroupier[i]==3 || manoCroupier[i]==3+CartasDeCadaPalo || manoCroupier[i]==3+2*CartasDeCadaPalo || manoCroupier[i]==3+3*CartasDeCadaPalo){
			puntuacion1+=3;
			puntuacion2+=3;
		}
		else if(manoCroupier[i]==4 || manoCroupier[i]==4+CartasDeCadaPalo || manoCroupier[i]==4+2*CartasDeCadaPalo || manoCroupier[i]==4+3*CartasDeCadaPalo){
			puntuacion1+=4;
			puntuacion2+=4;
		}
		else if(manoCroupier[i]==5 || manoCroupier[i]==5+CartasDeCadaPalo || manoCroupier[i]==5+2*CartasDeCadaPalo || manoCroupier[i]==5+3*CartasDeCadaPalo){
			puntuacion1+=5;
			puntuacion2+=5;
			
		}
		else if(manoCroupier[i]==6 || manoCroupier[i]==6+CartasDeCadaPalo || manoCroupier[i]==6+2*CartasDeCadaPalo || manoCroupier[i]==6+3*CartasDeCadaPalo){
			puntuacion1+=6;
			puntuacion2+=6;
			
		}
		else if(manoCroupier[i]==7 || manoCroupier[i]==7+CartasDeCadaPalo || manoCroupier[i]==7+2*CartasDeCadaPalo || manoCroupier[i]==7+3*CartasDeCadaPalo){
			puntuacion1+=7;
			puntuacion2+=7;
		}
		else if(manoCroupier[i]==8 || manoCroupier[i]==8+CartasDeCadaPalo || manoCroupier[i]==8+2*CartasDeCadaPalo || manoCroupier[i]==8+3*CartasDeCadaPalo){
			puntuacion1+=8;
			puntuacion2+=8;
		}
		else if(manoCroupier[i]==9 || manoCroupier[i]==9+CartasDeCadaPalo || manoCroupier[i]==9+2*CartasDeCadaPalo || manoCroupier[i]==9+3*CartasDeCadaPalo){
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

void Croupier::limpiarManoC ( ) {
	manoCroupier.clear();
	this->puntuacion1=0;
	this->puntuacion2=0;
	this->puntosTotales=0;
}

