//Trabajo Practico 1 Ejercicio 2: Solo librerias estandar, mostrar f1=Asin(X) y f2=C+B cos(x) 0<x<360 con incrementos de 30°

#include<iostream>
#include<cmath>

using namespace std;

#define PI 3.14159265

void f1(double *x,double *f,double A,int i){
	double aux;
	int j;
	for (j=0;j<i;j++){
		aux=sin(x[j]*PI/180);
		f[j]=A*aux;
	}
	
}
void f2(double *x,double *f,double B,double C,int i){
	double aux;
	int j;
	for (j=0;j<i;j++){
		aux=cos(x[j]*PI/180);
		f[j]=C+B*aux;
	}
	
}
// Esta funcion genera el vector espaciado y devuelve la cantidad de componentes de dicho vector
int generar(double *v,double max,double min, double paso){
	int i,componentes;
	componentes=((max-min)/paso)+1;
	v[0]=min;
	for(i=1;i<componentes;i++){
		v[i]=v[i-1]+paso;
	}
	return i;
}
void mostrarResultados(double *f,int i){
	int j;
	cout<<"El vector es"<<endl;
	for(j=0;j<i;j++){
	cout<<f[j]<<endl;
	}
}
void obtenerConstantes(double &A,double &B,double &C){
	cout<<"Ingrese constante A"<<endl;
		cin>>A;
	cout<<"Ingrese constante B"<<endl;
		cin>>B;
	cout<<"Ingrese constante C"<<endl;
		cin>>C;
}
int main (void) {
	
	double max=360,min=0,paso=30;     // Parametros para generar el vectro 0<x<360  paso 30
	int i1,i2;
	
	double *v1,*v2,A,B,C;
	v1=new double[20];
	v2=new double[20];
	
	obtenerConstantes(A,B,C);
	
	i1=generar(v1,max,min,paso);
	i2=generar(v2,max,min,paso);
	
	double *fun1,*fun2;
	fun1=new double[i1];
	fun2=new double[i2];
	
	f1(v1,fun1,A,i1);
	f2(v2,fun2,B,C,i2);
	
	mostrarResultados(fun1,i1);
	mostrarResultados(fun2,i2);
	
	delete [] v1;
	delete [] v2;
	delete [] fun1;
	delete [] fun2;
return 0;
}

