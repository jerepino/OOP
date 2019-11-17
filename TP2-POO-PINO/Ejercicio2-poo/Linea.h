#ifndef LINEA_H
#define LINEA_H
#include<iostream>
using namespace std;
class Linea {
private:
	double xini;
	double yini;
	double	xfin;
	double yfin;
	char **matriz;
	char caracter;
	
public:
	Linea(char = '+');
	~Linea();
	void mostrar();
	void formarRecta(double,double,double,double);
	void establecerValores(double,double,double,double);
};

#endif

