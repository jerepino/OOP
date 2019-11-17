#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H
#include <string>
using namespace std;

class EfectorFinal {
public:
	EfectorFinal();
	~EfectorFinal();
	bool tarea();
	void setTiempoyAccion(int,string);
	void setEstado(bool);
private:
	bool estado;
	int tiempo; //Tiempo final
	int t;     //tiempo actual
	string accion;
};

#endif

