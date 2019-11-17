#include "EfectorFinal.h"
#include <string>
using namespace std;
/* puede encontrarse en 2 estados: inactivo o activo (seg�n si se encuentra
en camino a su coordenada de trabajo o ha alcanzado la misma). El efector final
desconoce las coordenadas de su posici�n. Se asume por simplificaci�n que, el 
efector puede moverse libremente en su espacio de trabajo. Es capaz de 
permanecer una cierta cantidad de ciclos realizando una tarea
espec�fica dada e informar cuando �sta ha terminado. 
Autom�ticamente se coloca en estado inactivo al finalizar la misma*/
EfectorFinal::EfectorFinal() {
	this->estado=false;
	this->t=0;
}

EfectorFinal::~EfectorFinal() {
	
}

bool EfectorFinal::tarea ( ) {
	if(estado){
		t++;
		if(t==tiempo){
			t=0;
			setEstado(false);
			return false;
			
		}
		else{
			return true;
		}
	}
}

void EfectorFinal::setTiempoyAccion (int ti, string ac) {
	this->accion=ac;
	this->tiempo=ti;
}

void EfectorFinal::setEstado (bool a) {
	this->estado=a;
}

