#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <vector>
#include "Carta.h"

using namespace std;

class Jugador {
public:
	Jugador();
	~Jugador();
	
	void doblar();
	void apuestaInicial(int=0);
	void asignarCartaJ(int);
	const vector <int> getMano();
	const int getPuntuacion();
	void limpiarMano();
	void setPozo(int);
	void paga(int=2);
private:
	
	int posicion;
	int pozo; //Es la suma con la que incia el Jugador
	vector <int> mano; //Lleva la cantidad de cartas del Jugador
	int puntosTotales; //Lleva la suma de todas las cartas
	int apuesta; //Cantidad que apuesta
	int puntuacion1;
	int puntuacion2;
};

#endif

