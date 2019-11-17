#include "RobotCartesiano.h"
#include <string>
#include <iostream>
using namespace std;

RobotCartesiano::RobotCartesiano() {
	
	sincronizador=0;
	
	efector= new EfectorFinal;
	pantalla= new Visualizacion;
	ejes.resize(3);
}

RobotCartesiano::~RobotCartesiano() {
	ejes.clear();
	delete efector;
	delete pantalla;
	
	
}

void RobotCartesiano::ordenesDeMovimiento ( ) {
	/* registrar los puntos de trabajo deseados
	y de dar las órdenes de movimiento a cada
	articulación para resolver una trayectoria global.*/
	bool flag=true,banderaX=false,banderaY=false,banderaZ=false;
	for(int i=0; i<3;i++){
		bool verif=ejes.at(i).setCoordenada(puntosTrabajo[i]);
		if(!verif){
			pantalla->errorCoordenadas();
		}
	}
	for(int j=0; j<3;j++) puntosTrabajo.erase(puntosTrabajo.begin());
	
	efector->setTiempoyAccion(tiempo.at(0),tipoAccion.at(0));
	tiempo.erase(tiempo.begin());
	
	
	
	while(flag){
		if(!banderaX){if(ejes.at(0).movimiento()) banderaX=true;}
		if(!banderaY){if(ejes.at(1).movimiento()) banderaY=true;}
		if(!banderaZ){if(ejes.at(2).movimiento()) banderaZ=true;}
		
		int a=ejes.at(0).getPosicionActual();
		int b=ejes.at(1).getPosicionActual();
		int c=ejes.at(2).getPosicionActual();
		pantalla->dispX(a);
		pantalla->dispY(b);
		pantalla->dispZ(c);
		if(banderaX && banderaY && banderaZ){ 
			
			efector->setEstado(true);
			flag=false;	
		}
	}
	while(efector->tarea()){
		pantalla->operacionEfector(tipoAccion.at(0));
	}
	tipoAccion.erase(tipoAccion.begin());
	
}

bool RobotCartesiano::setPuntosTrabajo (int x, int y, int z) {
	
	/*validar que en los datos no existan valores negativos*/
	
	if(x>=0 && y>=0 && z>=0){
		puntosTrabajo.push_back(x);
		puntosTrabajo.push_back(y);
		puntosTrabajo.push_back(z);
		return true;
	}
	else{
		return false;
		// Nota: Agregar visualizacion del error 
	}
}

void RobotCartesiano::comandarEfectorFinal ( ) {
	/*Es capaz de indicar al efector 
	final el tiempo y el tipo de operación a 
	realizar, en este caso: Tomar, Rotar y Soltar.*/
	
}

bool RobotCartesiano::setTiempoYAccion (int t, string accion) {
	bool flag1=false,flag2=false;
	
	if (t>=0){
		tiempo.push_back(t);
		
		flag1=true;
	}
	if((accion.compare("rotar")==0||accion.compare("soltar")==0||accion.compare("tomar")==0)){
		tipoAccion.push_back(accion);
		flag2=true;
	}
	if(!flag1 || !flag2){
		
		// Nota: Agregar visualizacion del error 
		return false;
	}
	else{
		return true;
	}
}
