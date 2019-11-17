#include<iostream>
#include <fstream>
#include<cstring>
#include <iomanip>
#include "CrearArchivo.h"
using namespace std;
#include <cstdlib>
using std::exit;
#include "LeerArchivo.h"
int main (int argc, char *argv[]) {
	char nombreArchivo[20];
	cout<<"ingrese el nombre del archivo"<<endl;
	cin>>nombreArchivo;
	
	LeerArchivo archivo(nombreArchivo);
	
	archivo.interpretarArchivo();
	archivo.obtenerDatos();
	archivo.muestraGraficos();
	
	


	
	
	return 0;
}

