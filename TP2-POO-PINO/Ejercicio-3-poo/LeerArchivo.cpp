#include "LeerArchivo.h"
#include<iostream>
#include <fstream>
#include<cstring>
#include <vector>
using namespace std;
#include <cstdlib>
using std::exit;
#include "EntidadesGeometricas.h"

LeerArchivo::LeerArchivo() {
	errorFig=0;
	numeroLineas=0;
	archivoClientesEntrada.open("ejemplo1.txt", ios::in);
	if ( !archivoClientesEntrada ){
		cerr << "No se pudo abrir el archivo" << endl;
		exit( 1 );
	} // fin de if
	
}

LeerArchivo::LeerArchivo (char  nombreArchivo[]) {
	errorFig=0;
	numeroLineas=0;
	archivoClientesEntrada.open(nombreArchivo, ios::in);
	if ( !archivoClientesEntrada ){
		cerr << "No se pudo abrir el archivo" << endl;
		exit( 1 );
	} // fin de if

}

LeerArchivo::~LeerArchivo() {
	
}
void LeerArchivo::interpretarArchivo ( ) {
	char buffer[500];
	char a;

	archivoClientesEntrada>>pixel1>>a>>pixel2>>a>>relleno;
	long ubicacion = archivoClientesEntrada.tellg();
	archivoClientesEntrada.seekg(ubicacion+1);
	
	miFigura.setMapa(pixel1,pixel2,relleno);
	
	
	while(!archivoClientesEntrada.eof()){
		
		
		archivoClientesEntrada.getline(buffer,5,',');
		archivoClientesEntrada.ignore(1,'\n');
		interprete=buffer;
		
		if(interprete != "\n"){
			dato.push_back(interprete);
		}
	}
	dato.erase(dato.end());
	
	
}

void LeerArchivo::getArchivo ( ) {
	
}


void LeerArchivo::obtenerDatos ( ) {
	vector <string> auxiliar;
	string s,r,t,c;
	s="s";
	r="r";
	t="t";
	c="c";
	int j=0;
	for(int i=0;i<dato.size();i++){

		if(dato[i]=="s"){
			j=i;
			numeroLineas++;
			while(r.compare(dato[j])!=0 && t.compare(dato[j])!=0 && c.compare(dato[j])!=0 && j != dato.size()){
			auxiliar.push_back(dato[j]);
			j++;
			if(s.compare(dato[j])==0 || dato[j]=="a"||dato[j]=="b"||dato[j]=="d"||dato[j]=="e"||dato[j]=="f"||dato[j]=="g"||dato[j]=="h"||dato[j]=="i"||dato[j]=="j"||dato[j]=="k"||dato[j]=="l"||dato[j]=="m"||dato[j]=="n"||dato[j]=="o"||dato[j]=="p"||dato[j]=="q"||dato[j]=="u"||dato[j]=="v"||dato[j]=="w"||dato[j]=="x"||dato[j]=="y"||dato[j]=="z"){break; }
			}

			miFigura.getSegmento(auxiliar);
//			escritura.nuevaLinea(auxiliar);
			auxiliar.clear();
		}
		if(dato[i]=="r"){
			j=i;
			numeroLineas++;
			while(s.compare(dato[j])!=0 && t.compare(dato[j])!=0 && c.compare(dato[j])!=0 && j != dato.size()){
				auxiliar.push_back(dato[j]);
				j++;
				if(r.compare(dato[j])==0 || dato[j]=="a"||dato[j]=="b"||dato[j]=="d"||dato[j]=="e"||dato[j]=="f"||dato[j]=="g"||dato[j]=="h"||dato[j]=="i"||dato[j]=="j"||dato[j]=="k"||dato[j]=="l"||dato[j]=="m"||dato[j]=="n"||dato[j]=="o"||dato[j]=="p"||dato[j]=="q"||dato[j]=="u"||dato[j]=="v"||dato[j]=="w"||dato[j]=="x"||dato[j]=="y"||dato[j]=="z"){break; }
			}

			miFigura.getRectangulo(auxiliar);
//			escritura.nuevaLinea(auxiliar);
			auxiliar.clear();
		}
		if(dato[i]=="t"){
			j=i;
			numeroLineas++;
			while(r.compare(dato[j])!=0 && s.compare(dato[j])!=0 && c.compare(dato[j])!=0 && j!= dato.size()){
				auxiliar.push_back(dato[j]);
				j++;
				if(t.compare(dato[j])==0 || dato[j]=="a"||dato[j]=="b"||dato[j]=="d"||dato[j]=="e"||dato[j]=="f"||dato[j]=="g"||dato[j]=="h"||dato[j]=="i"||dato[j]=="j"||dato[j]=="k"||dato[j]=="l"||dato[j]=="m"||dato[j]=="n"||dato[j]=="o"||dato[j]=="p"||dato[j]=="q"||dato[j]=="u"||dato[j]=="v"||dato[j]=="w"||dato[j]=="x"||dato[j]=="y"||dato[j]=="z"){break; }
			}

			miFigura.getTriangulo(auxiliar);
//			escritura.nuevaLinea(auxiliar);
			auxiliar.clear();
		}
		if(dato[i]=="c"){
			j=i;
			numeroLineas++;
			while(r.compare(dato[j])!=0 && t.compare(dato[j])!=0 && s.compare(dato[j])!=0 && j!= dato.size()){
				auxiliar.push_back(dato[j]);
				j++;
				if(c.compare(dato[j])==0 || dato[j]=="a"||dato[j]=="b"||dato[j]=="d"||dato[j]=="e"||dato[j]=="f"||dato[j]=="g"||dato[j]=="h"||dato[j]=="i"||dato[j]=="j"||dato[j]=="k"||dato[j]=="l"||dato[j]=="m"||dato[j]=="n"||dato[j]=="o"||dato[j]=="p"||dato[j]=="q"||dato[j]=="u"||dato[j]=="v"||dato[j]=="w"||dato[j]=="x"||dato[j]=="y"||dato[j]=="z"){break; }
			}

			miFigura.getCirculo(auxiliar);
//			escritura.nuevaLinea(auxiliar);
			auxiliar.clear();
		}
		if(dato[i]=="a"||dato[i]=="b"||dato[i]=="d"||dato[i]=="e"||dato[i]=="f"||dato[i]=="g"||dato[i]=="h"||dato[i]=="i"||dato[i]=="j"||dato[i]=="k"||dato[i]=="l"||dato[i]=="m"||dato[i]=="n"||dato[i]=="o"||dato[i]=="p"||dato[i]=="q"||dato[i]=="u"||dato[i]=="v"||dato[i]=="w"||dato[i]=="x"||dato[i]=="y"||dato[i]=="z"){
				
				errorFig++;
				numeroLineas++;
		}
		
	}
}

void LeerArchivo::muestraGraficos ( ) {

	int aux,auxError;
	vector <int> auxiliar;
	aux=miFigura.getError();
	
	auxError=aux+errorFig;
	escritura.insertarError(aux);
	escritura.insertarErrorT2(errorFig);
	auxiliar=miFigura.getCantidades();
	escritura.nuevaCantidad(auxiliar[0],auxiliar[1],auxiliar[2],auxiliar[3],auxError,numeroLineas);
	miFigura.mostrarGraficos();
}
