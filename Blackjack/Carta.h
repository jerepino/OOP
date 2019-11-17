#ifndef CARTA_H
#define CARTA_H
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Carta {

public:
	Carta();
	~Carta();
	void barajar();
	void repartir();
	int darCarta();
private:
	
	queue <int> valor;

};

#endif

