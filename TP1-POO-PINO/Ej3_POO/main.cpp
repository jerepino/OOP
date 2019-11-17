/*
Trabajo practico N°1 Ejercicio 3: matriz cuadrada de NxN (siendo 3 <= N <= 10) con valores enteros al azar entre 1 y Max
construir otra matriz
Para cada celda del triángulo inferior hallar la diferencia entre la sumatoria de los valores de la
columna y la sumatoria de los valores de la fila a la cual pertenece. La matriz resultante tendrá 1
(unos) en la diagonal y 0 (ceros) en el triángulo superior.
4 funciones: obtenerN(), crearMatrizOriginal(),hallarMatrizResultado(), mostrarTabla()
Al producir la salida mostrar ambas matrices.
*/

#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

void obtenerN(int &N,int &max){
	do{
		cout<<"Ingrese la dimension de la matriz 3<=N<=10"<<endl;
		cin>>N;
	if( (N>=3) & (N<=10)){
		break;
	}
		cout<<"El valor estan fuera del rango"<<endl;
	}while(true);

	cout<<"Ingrese el valor maximo de las componentes (entero)"<<endl;
	cin>>max;
}
void crearMatrizOriginal(int **Mat,int N,int &max){
	int i,j,min=1;
	srand(time(NULL));
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			*(*(Mat+i)+j)=min+rand()%((max+1)-min);
		}
	}	
}
void hallarMatrizResultado(int **Mat,int **aux,int N){
	int i,j,k,suma1=0,suma2=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i<j){
				*(*(aux+i)+j)=0;
			}
			if(i==j){
				*(*(aux+i)+j)=1;
			}
			if(i>j){
			for(k=0;k<N;k++){
				suma2=suma2+*(*(Mat+i)+k);
				suma1=suma1+*(*(Mat+k)+j);
			}
			*(*(aux+i)+j)=suma1-suma2;
			suma2=suma1=0;
			}
		}
	}
}
void copiarMatriz(int **Mat1,int **Matcopy,int N){
	int j,i;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			*(*(Matcopy+i)+j)=*(*(Mat1+i)+j);
		}
	}
}	
void mostrarTabla(int **Mat,int N){
	int i,j;
	cout<<"La matriz es:"<<endl<<"[";
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout<<" "<<*(*(Mat+i)+j)<<" ";
		}
		cout<<endl;
	}
	cout<<"]"<<endl;
}
int main (void) {
	int N,i,max,**M,**J;  
	obtenerN(N,max);
	
	M=new int *[N];
	J=new int *[N];	
	for(i=0;i<N;i++){
		M[i]=new int[N];
		J[i]=new int[N];	
	}
	
	crearMatrizOriginal(M,N,max);
	copiarMatriz(M,J,N);
	hallarMatrizResultado(M,J,N);
	mostrarTabla(M,N);
	mostrarTabla(J,N);
	for(i=0;i<N;i++){
		delete [] M[i];
        delete [] J[i];
	}
	delete [] M;
	delete [] J;
return 0;
}

