#ifndef ARTICULACION_H
#define ARTICULACION_H
#include <vector>
using namespace std;

class Articulacion {
public:
	Articulacion();
	~Articulacion();
	bool movimiento();
	bool setCoordenada(int);
	int getPosicionActual();
private:
	int coordenada;
	vector <int> limiteTrabajo;
	int posicionActual;
};

#endif

