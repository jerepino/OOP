#include "MovilElemental.h"
#include<ctime>
#include<cstring>
#include<iostream>
using namespace std;

enum direccion{
	NINGUNA, ADELANTE, DERECHA, ATRAS, IZQUIERDA, ARRIBA, ABAJO
};
MovilElemental::MovilElemental (int x, int y, int z, string nomb, int bat) {
	posicionX=x;
	posicionY=y;
	posicionZ=z;
	nombre=nomb;
	bateria=bat;
	secuencia=new string[30];
	time(&tinicio);
	contador=0;
	
}

MovilElemental::~MovilElemental() {
	time(&tfin);
	segundos=difftime(tfin,tinicio);
	cout<<"El tiempo es:"<<segundos<<endl;
	delete [] secuencia;
	secuencia=0;
}

void MovilElemental::mover (int dir , int dist) {
	
	switch(dir){
		case(ADELANTE):
			posicionY+=dist;
		secuencia[contador]="Adelante";
		break;
		case(ATRAS):
			posicionY-=dist;
		secuencia[contador]="Atras";
		break;
		case(IZQUIERDA):
			posicionX-=dist;
		secuencia[contador]="Izquierda";
		break;
		case(DERECHA):
			posicionX+=dist;
		secuencia[contador]="Derecha";
		break;
		case(ARRIBA):
			posicionZ+=dist;
		secuencia[contador]="Arriba";
		break;
		case(ABAJO):
			posicionZ-=dist;
		secuencia[contador]="Abajo";
		break;
	default:
		break;
		
	}
	contador++;
	distancia+=dist;
}

void MovilElemental::mostrarDatos ( ) {
cout<<"El nombre es: "<<nombre<<endl;
cout<<"La bateria es: "<<bateria<<endl;
}



void MovilElemental::mostrarSecuencia ( ) {
	cout<<"La secuencia es:"<<endl;
	for(int i=0;i<=contador;i++){
		cout<<secuencia[i]<<" ";
	}
	cout<<endl;
	cout<<"La posicion es: ("<<posicionX<<","<<posicionY<<","<<posicionZ<<")"<<endl;
	cout<<"La distancia es: "<<distancia<<endl;
}

