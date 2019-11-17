#ifndef MOVILELEMENTAL_H
#define MOVILELEMENTAL_H
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
class MovilElemental {
private:
	int bateria;
	string nombre;
	int posicionX;
	int posicionY;
	int posicionZ;
	string *secuencia;
	double segundos;
		time_t tinicio;
	time_t	tfin;
	int contador;
	double distancia;
public:
	MovilElemental(int=0,int=0,int=0,string="Peugeot",int=100);
	~MovilElemental();
	void mover(int,int);
	void mostrarDatos();
	void mostrarSecuencia();
};

#endif

