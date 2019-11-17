#ifndef CREARARCHIVO_H
#define CREARARCHIVO_H
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class CrearArchivo {

public:
	CrearArchivo();
	~CrearArchivo();
	void insertarErrorT2(int);
	void insertarError(int );
	void nuevaLinea(vector <string> );
	void nuevoArchivo(int,int,char);
	void nuevaCantidad(int,int,int,int,int,int);
private:
	ofstream archivoSalida;
};

#endif

