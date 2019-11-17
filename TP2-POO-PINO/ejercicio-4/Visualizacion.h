#ifndef VISUALIZACION_H
#define VISUALIZACION_H
#include <string>
using namespace std;

class Visualizacion {
public:
	Visualizacion();
	~Visualizacion();
	void dispX(int);
	void dispY(int);
	void dispZ(int);
	void operacionEfector(string);
	void errorCoordenadas();
};

#endif

