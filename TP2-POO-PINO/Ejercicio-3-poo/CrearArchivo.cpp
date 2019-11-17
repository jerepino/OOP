#include "CrearArchivo.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

CrearArchivo::CrearArchivo() {
	archivoSalida.open("tp3_figuras_1.txt",ios::ate );
	if ( !archivoSalida ){
		cerr << "No se pudo abrir el archivo" << endl;
		exit( 1 );
	}
}

CrearArchivo::~CrearArchivo() {
	
}

void CrearArchivo::insertarError (int error ) {
	if(error!=0){
		for(int i=0;i<error;i++){
			archivoSalida.seekp( 0, ios::end );
			archivoSalida<<"Error (Parametros invalidos)"<<endl;
		}
	}
}

void CrearArchivo::nuevaLinea (vector <string> datos ) {
	
	if (datos[0]=="s"){
	archivoSalida<<left<< setw( 12 ) << "Segmento" << setw( 7 ) <<datos[1]<<datos[2]<<", "<< setw( 17 ) <<datos[3] <<datos[4]<<", "<<setw( 17 )<<datos[5]<<endl;}
	if (datos[0]=="r"){
	archivoSalida<<left<< setw( 12 ) << "Rectangulo" << setw( 7 ) <<datos[1]<<datos[2]<<", "<< setw( 17 ) <<datos[3] <<datos[4]<<", "<<setw( 15 )<<datos[5]<<datos[6]<<", "<< setw( 8 )<<datos[7]<< right<<datos[8]<<","<<datos[9]<< endl;}
	if (datos[0]=="t"){
	archivoSalida<<left<< setw( 12 ) << "Triangulo" << setw( 7 ) <<datos[1]<<datos[2]<<", "<< setw( 17 ) <<datos[3] <<datos[4]<<", "<<setw( 14 )<<datos[5]<<datos[6]<<", "<< setw( 9 )<<datos[7]<<endl;}
	if (datos[0]=="c"){
	archivoSalida<<left<< setw( 12 ) << "Circulo" << setw( 7 ) <<datos[1]<<datos[2]<<", "<< setw( 17 ) <<datos[3] <<datos[4]<<endl;}
	
}

void CrearArchivo::nuevoArchivo (int pix1, int pix2 , char relleno) {
	archivoSalida.seekp(0);
	archivoSalida<<"Resolucion: "<<pix1<<"x"<<pix2<<" puntos"<<endl; 
	archivoSalida<<"Relleno Perzonalizado "<<relleno<<endl;
	archivoSalida<<endl;
	archivoSalida<<left<< setw( 12 ) << "Figura" << setw( 7 ) <<"Color"<< setw( 20 ) <<"Vertice 1 / Centro" <<setw( 18 ) <<"Vertie 2 / Radio" << setw( 11 )<<"Vertice 3"<< right<<"Vertice 4"<< endl;
}

void CrearArchivo::insertarErrorT2 (int err) {
	if(err!=0){
		for(int i=0;i<err;i++){
			archivoSalida.seekp( 0, ios::end );
			archivoSalida<<"Error (Figura inexistente)"<<endl;
		}
	}	
}

void CrearArchivo::nuevaCantidad (int segmento, int rectangulo , int triangulo, int circulo, int errores, int lineas) {
	archivoSalida.seekp( 0, ios::end );
	archivoSalida<<endl;
	archivoSalida<<"Líneas de entidad en el archivo: "<<lineas<<endl;
	archivoSalida<<"Errores: "<<errores<<endl;
	archivoSalida<<"Segmentos: "<<segmento<<endl;
	archivoSalida<<"Triangulos: "<<triangulo<<endl;
	archivoSalida<<"Rectangulos: "<<rectangulo<<endl;
	archivoSalida<<"Circulos: "<<circulo<<endl;
}

