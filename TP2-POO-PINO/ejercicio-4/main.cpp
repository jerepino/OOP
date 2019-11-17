#include<iostream>
#include "RobotCartesiano.h"
#include <fstream>
#include <cstdlib>
using namespace std;
int main (int argc, char *argv[]) {
	RobotCartesiano *Pino0001= new RobotCartesiano;
	ifstream archivoDatosEntrada("DatosEntradaRobot.txt", ios::in); //Leer Archivo
	/*Variables para procesar archivo*/
	int coordenadaX,coordenadaY,coordenadaZ,tiempoEfector;
	string accionEfector;
	
	if ( !archivoDatosEntrada){
		cerr << "No se pudo abrir el archivo" << endl;
		exit( 1 );
	}
	
	bool flag;
	int seleccion=0;
	cout<<"Bienvenidos al sistema de control del Robot Pino-0001"<<endl;
	cout<<" '1' - Iniciar"<<endl;
	cout<<" '2' - Finalizar"<<endl;
	cin>>seleccion;
	cout<<endl;
	while(seleccion == 1){
		while(archivoDatosEntrada>>coordenadaX>>coordenadaY>>coordenadaZ>>tiempoEfector>>accionEfector){
			bool correctoP=Pino0001->setPuntosTrabajo(coordenadaX,coordenadaY,coordenadaZ);
			bool correctoT=Pino0001->setTiempoYAccion(tiempoEfector,accionEfector);
			if(!correctoP || !correctoT){
				cerr<<"Error en parametros"<<endl;
				exit(1);
			}
		}
		Pino0001->ordenesDeMovimiento();
		/*Metodo de parada*/
		cout<<"Seleccione"<<endl;
		cout<<" '1' - Continuar"<<endl;
		cout<<" '2' - Parar"<<endl;
		cin>>seleccion;
		cout<<endl;
	}
	delete Pino0001;
	return 0;
}
