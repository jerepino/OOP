#ifndef ROBOTCARTESIANO_H
#define ROBOTCARTESIANO_H
#include <vector>
#include "Visualizacion.h"
#include "EfectorFinal.h"
#include "Articulacion.h"
#include <string>
using namespace std;

class RobotCartesiano {
public:
	RobotCartesiano();
	~RobotCartesiano();
	void ordenesDeMovimiento();
	bool setPuntosTrabajo(int,int,int);
	void comandarEfectorFinal();
	bool setTiempoYAccion(int,string);
	
	
private:
	/*Clases que compoenen el robot*/
	vector <Articulacion> ejes;
	EfectorFinal *efector;
	Visualizacion *pantalla;
	vector <int> puntosTrabajo;
	vector <int> tiempo;
	vector <string> tipoAccion;
	int sincronizador;
};

#endif

