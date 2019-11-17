#include "Articulacion.h"
#include <iostream>
using namespace std;

/*Una clase Articulacion, capaz de realizar su propio movimiento 
a partir de conocer la coordenada del punto a la cual debe 
desplazarse. Cada articulación conoce sus límites de trabajo,
se maneja en su propio eje (sistema de coordenadas) 
y es el responsable de detectar/notificar los requerimientos fuera
de su espacio de trabajo.*/

Articulacion::Articulacion() {
	posicionActual=0;
	limiteTrabajo.push_back(0);
	limiteTrabajo.push_back(100);
}

Articulacion::~Articulacion() {
	
}

bool Articulacion::movimiento ( ) {
	if(coordenada<posicionActual){
		posicionActual--;
	}
	else{
		posicionActual++;	
	}
	
	if(posicionActual == coordenada){
		return true;
	}
	else{
		return false;
	}
}


bool Articulacion::setCoordenada (int posicionFinal) {
	this->coordenada=(posicionFinal>=limiteTrabajo[0] && posicionFinal<=limiteTrabajo[1])?posicionFinal:-10;
	
	if(coordenada == -10){
		return false;
	}
	else{
		return true;
	}
	
}

int Articulacion::getPosicionActual ( ) {
	return this->posicionActual;
}
