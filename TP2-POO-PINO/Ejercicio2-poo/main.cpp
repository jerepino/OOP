#include<iostream>
using namespace std;
#include "Linea.h"
int main (void) {
	double xinicial,xfinal,yinicial,yfinal;
	char dibujo;
	cout<<"Ingrese el caracter para plotear"<<endl;
	cin>>dibujo;	
	Linea recta(dibujo);
	cout<<"Ingrese el valor de xinicial"<<endl;
	cin>>xinicial;
	cout<<"Ingrese el valor de yinicial"<<endl;
	cin>>yinicial;
	cout<<"Ingrese el valor de xfinal"<<endl;
	cin>>xfinal;
	cout<<"Ingrese el valor de yfinal"<<endl;
	cin>>yfinal;
	recta.formarRecta(xinicial,yinicial,xfinal,yfinal);
	recta.mostrar();
	return 0;
}

