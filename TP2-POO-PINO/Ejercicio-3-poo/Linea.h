#ifndef LINEA_H
#define LINEA_H
#include<iostream>
using namespace std;
class Linea {

public:
	Linea();
	~Linea();
	void crearMapa(int=10,int=10,char='+');
	void mostrar();
	void formarRecta(double,double,double,double);
	void establecerValores(double,double,double,double);
	void graficarCirculo(double,double,double);
private:
	double xini;
	double yini;
	double	xfin;
	double yfin;
	char **matriz;
	char caracter;
	int pix1;
	int pix2;
};

#endif

