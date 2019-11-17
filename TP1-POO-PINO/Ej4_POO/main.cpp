#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

void obtenerNyP(int &N,int &P){
	cout<<"Ingrese la fila de la matriz (N)"<<endl;
	cin>>N;
	cout<<"Ingrese la columna de la matriz (P)"<<endl;
	cin>>P;
}
void crearMatrizOriginal(int **Mat,int N,int P,int &max){
	int i,j,min=1;
	srand(time(NULL));
	for(i=0;i<N;i++){
		for(j=0;j<P;j++){
			*(*(Mat+i)+j)=min+rand()%((max+1)-min);
		}
	}	
}

void crearFotograma(int **Mat, int **Mataux,int N,int P){
	int j,i,suma=0;
	for(i=0;i<N;i++){
		for(j=0;j<P;j++){
			if((i==0) | (j==0) | (i==(N-1)) | (j==(P-1))){
				*(*(Mataux+i)+j)=0;
				continue;
			}
			
			suma=*(*(Mat+i)+j)+*(*(Mat+(i-1))+j)+*(*(Mat+(i+1))+j)+*(*(Mat+i)+(j-1))+*(*(Mat+i)+(j+1));
			if(suma>30){
				*(*(Mataux+i)+j)=1;
			}
			else if(suma<=30){
				*(*(Mataux+i)+j)=0;
			}
			suma=0;
		}
	}
	
	
}



void copiarMatriz(int **Mat1,int **Matcopy,int N,int P){
	int j,i;
	for(i=0;i<N;i++){
		for(j=0;j<P;j++){
			*(*(Matcopy+i)+j)=*(*(Mat1+i)+j);
		}
	}
}	
void mostrarTabla(int **Mat,int N,int P){
	int i,j;
	cout<<"La matriz es:"<<endl<<"[";
	for(i=0;i<N;i++){
		for(j=0;j<P;j++){
			cout<<" "<<*(*(Mat+i)+j)<<" ";
		}
		cout<<endl;
	}
	cout<<"]"<<endl;
}
void mostrarFotograma(int **Mat,int N,int P){
	int i,j;
	char aux;
	cout<<"El Fotograma es:"<<endl;
	for(i=-1;i<N;i++){                    //Atencion empieza en -1 para poder mostrar las columnas de referencia de los sectores.
		if(i!=-1){				
		cout<<(i+1);
		}
		else if(i==-1){
			cout<<" ";
		}
		for(j=0;j<P;j++){
			if(i==-1){
			aux=65+j;
			cout<<" "<<aux<<" ";			
			if(j==P){
			i++;
			}
			else{
				continue;
			}
			}
			if(*(*(Mat+i)+j)==1){
			cout<<" "<<"*"<<" ";
			}
			else{
				cout<<" "<<" "<<" ";
			}
		}
		cout<<endl;
	}
}
int main (void) {
	
	int N,P,i,max=20,**M,**J;  
	
	obtenerNyP(N,P);
	
	M=new int *[N];
	J=new int *[N];
	for(i=0;i<N;i++){
		M[i]=new int[P];
		J[i]=new int[P];
	}
	
	crearMatrizOriginal(M,N,P,max);
	copiarMatriz(M,J,N,P);
	crearFotograma(M,J,N,P);
	mostrarTabla(M,N,P);
	mostrarFotograma(J, N, P);
	
	for(i=0;i<N;i++){
		delete [] M[i];
		delete [] J[i];
	}
	delete [] M;
	delete [] J;
	return 0;
}

