#ifndef CROUPIER_H
#define CROUPIER_H
#include <string>
#include <vector>
using namespace std;

class Croupier {
public:
	Croupier();
	~Croupier();
	void asignarCartaC(int);
	const vector <int> getCartaC();
	const int getPuntuacion ( );
	void limpiarManoC();
private:
	vector <int> manoCroupier;
	int pozo; //Es la suma con la que incia el Jugador
	int puntosTotales; //Lleva la suma de todas las cartas
	int apuesta; //Cantidad que apuesta
	int puntuacion1;
	int puntuacion2;
};

#endif

