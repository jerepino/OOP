#include "Visualizacion.h"
#include <iostream>
using namespace std;

Visualizacion::Visualizacion() {
	
}

Visualizacion::~Visualizacion() {
	
}

void Visualizacion::dispX (int x) {
	cout<<"La posicion actual del actuador X es: "<<x<<endl;
}

void Visualizacion::dispY (int  y) {
	cout<<"La posicion actual del actuador Y es: "<<y<<endl;
}

void Visualizacion::dispZ (int  z) {
	cout<<"La posicion actual del actuador Z es: "<<z<<endl;
}

void Visualizacion::operacionEfector (string aux) {
	cout<<aux<<endl;
}

void Visualizacion::errorCoordenadas ( ) {
	cout<<"Error: Coordenadas fuera de rango"<<endl;
}
