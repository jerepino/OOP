#include "Carta.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

Carta::Carta() {

}

Carta::~Carta() {
	
}

void Carta::barajar ( ) {
	int min=1,max=52;
	srand(time(NULL));
	for (int i=0;i<100;i++) valor.push(min+rand()%((max+1)-min));
	
}

void Carta::repartir ( ) {
	
}

int Carta::darCarta ( ) {
	int aux=0;
	aux=valor.front();
	valor.pop();
	return aux;
}

