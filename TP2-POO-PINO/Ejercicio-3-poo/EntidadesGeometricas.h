#ifndef ENTIDADESGEOMETRICAS_H
#define ENTIDADESGEOMETRICAS_H
#include <vector>
#include <string>
#include "Linea.h"
#include <unordered_set>
#include "CrearArchivo.h"
using namespace std;

class EntidadesGeometricas {
public:
	void getTriangulo(vector <string>);
	void getCirculo(vector <string>);
	void getSegmento(vector <string>);
	void getRectangulo(vector <string>);
	void setMapa(int,int,char);
	EntidadesGeometricas();
	~EntidadesGeometricas();
	void mostrarGraficos();
	const int getError();
	vector <int> getCantidades();
	
private:
	int errorParametros;
	Linea graficar;
	double p1[2];//Punto 1 o centro
	double p2[2];//Punto 2 o radio
	double p3[2];//Punto 3
	double p4[2];//Punto 4	
	
	int cantTriangulo;
	int cantCirculo;
	int cantRectangulo;
	int cantSegmento;
	vector <int> cantidades;
	CrearArchivo plot;
};

#endif

