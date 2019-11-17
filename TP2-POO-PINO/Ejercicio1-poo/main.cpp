#include<iostream>
using namespace std;
#include "MovilElemental.h"
int main (int argc, char *argv[]) {
	
	int op_mover=10,pasos;
	MovilElemental automovil(0,0,0,"Ferrari",100);
	automovil.mostrarDatos();
	while(op_mover!=0){
	cout<<"0. SALIR"<<endl;
	cout<<"1. ADELANTE"<<endl;
	cout<<"2. DERECHA"<<endl;
	cout<<"3. ATRAS"<<endl;
	cout<<"4. IZQUIERDA"<<endl;
	cout<<"5. ARRIBA"<<endl;
	cout<<"6. ABAJO"<<endl;
	cout<<"Elija la direccion de movimiento: ";
	cin>>op_mover;
	cout<<endl;
	if((op_mover>0)&(op_mover<=6)){
	cout<<"Ingrese cantidad de paso: ";
	cin>>pasos;
	cout<<endl;
	automovil.mover(op_mover,pasos);
	automovil.mostrarSecuencia();
	}
	else if(op_mover==0){
		cout<<"Programa Finalizado"<<endl;
	}
	else{
		cout<<"Error: Ingrese la direccion nuevamente"<<endl;
	}
	
	}
	return 0;
}

