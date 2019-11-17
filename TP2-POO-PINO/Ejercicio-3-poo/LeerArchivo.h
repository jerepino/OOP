#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H
#include "EntidadesGeometricas.h"
#include<iostream>
#include <fstream>
#include<cstring>
#include <vector>
#include "CrearArchivo.h"
using namespace std;



class LeerArchivo {

public:
	LeerArchivo();
	LeerArchivo(char []);
	~LeerArchivo();
	void interpretarArchivo();
	void getArchivo();
	void obtenerDatos();
	void muestraGraficos();
	
private:
	EntidadesGeometricas miFigura;
	ifstream archivoClientesEntrada;
	CrearArchivo escritura;
	string interprete;
	vector <string> dato;
	int pixel1;
	int pixel2;
	int errorFig;
	int numeroLineas;
	char relleno;
	
};

#endif

