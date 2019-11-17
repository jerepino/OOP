#include "EntidadesGeometricas.h"
#include <vector>
#include <string>
#include <iostream>
#include "Linea.h"
using namespace std;

EntidadesGeometricas::EntidadesGeometricas() {
	errorParametros=0;
	cantCirculo=0;
	cantRectangulo=0;
	cantSegmento=0;
	cantTriangulo=0;
}

EntidadesGeometricas::~EntidadesGeometricas() {
	
}

void EntidadesGeometricas::getTriangulo (vector <string> triangulo ) {
	
	if(triangulo.size()==8){
		cantTriangulo++;
		
		p1[0]= stod(triangulo[2]);
		p1[1]= stod(triangulo[3]);
		p2[0]= stod(triangulo[4]);
		p2[1]= stod(triangulo[5]);
		p3[0]= stod(triangulo[6]);
		p3[1]= stod(triangulo[7]);
		graficar.formarRecta(p1[0],p1[1],p2[0],p2[1]);		
		graficar.formarRecta(p2[0],p2[1],p3[0],p3[1]);
		graficar.formarRecta(p3[0],p3[1],p1[0],p1[1]);
		plot.nuevaLinea(triangulo);
		/*graficar.mostrar();*/
	}
	else{
		errorParametros++;
		
	}
}

void EntidadesGeometricas::getCirculo (vector <string> circulo ) {
	
	if(circulo.size()==5){
		cantCirculo++;

		p1[0]= stod(circulo[2]);
		p1[1]= stod(circulo[3]);
		p2[0]= stod(circulo[4]);
		
		graficar.graficarCirculo(p1[0],p1[1],p2[0]);
		plot.nuevaLinea(circulo);
	}
	else{
		errorParametros++;
		
	}
	
}

void EntidadesGeometricas::getSegmento (vector <string> segmento ) {
	
	if(segmento.size()==6){
		cantSegmento++;
		
		p1[0]= stod(segmento[2]);
		p1[1]=stod(segmento[3]);
		p2[0]= stod(segmento[4]);
		p2[1]=stod(segmento[5]);
		graficar.formarRecta(p1[0],p1[1],p2[0],p2[1]);
		plot.nuevaLinea(segmento);
		/*graficar.mostrar();*/
	
	}
	else{
		errorParametros++;
		
	}
}

void EntidadesGeometricas::getRectangulo (vector <string> rectangulo ) {
	
	if(rectangulo.size()==10){
		cantRectangulo++;
		p1[0]= stod(rectangulo[2]);
		p1[1]=stod(rectangulo[3]);
		p2[0]= stod(rectangulo[4]);
		p2[1]=stod(rectangulo[5]);
		p3[0]=stod(rectangulo[6]);
		p3[1]=stod(rectangulo[7]);
		p4[0]=stod(rectangulo[8]);
		p4[1]=stod(rectangulo[9]);
		graficar.formarRecta(p1[0],p1[1],p2[0],p2[1]);
		graficar.formarRecta(p2[0],p2[1],p3[0],p3[1]);
		graficar.formarRecta(p3[0],p3[1],p4[0],p4[1]);
		graficar.formarRecta(p4[0],p4[1],p1[0],p1[1]);
	/*	graficar.mostrar();*/
		plot.nuevaLinea(rectangulo);
	}
	else{
		errorParametros++;
		
	}
	
}



void EntidadesGeometricas::setMapa (int pixa , int pixb , char re ) {	

	plot.nuevoArchivo(pixa,pixb,re);
	graficar.crearMapa(pixa,pixb,re);	
}

void EntidadesGeometricas::mostrarGraficos ( ) {
	graficar.mostrar();
}



const int EntidadesGeometricas::getError ( ) {
	return errorParametros;
}

vector<int> EntidadesGeometricas::getCantidades ( ) {
	cantidades.push_back(cantSegmento);
	cantidades.push_back(cantRectangulo);
	cantidades.push_back(cantTriangulo);
	cantidades.push_back(cantCirculo);
	return cantidades;
}

