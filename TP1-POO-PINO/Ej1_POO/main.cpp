//Trabajo Practico N°1 - Ejercicio 1:
// Numeros menores de 7000, cantidad de pares e impares, Aleatorio 1000 entre 6300 a 9300
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void generador(int *vec,int min,int max,int n){
	srand(time(NULL));
	int i;
	for(i=0;i<n;i++){
	vec[i]=min+rand()%((max+1)-min);
	}
}
int compara_par(int *vec,int n){
	int i,par=0;
	for(i=0;i<n;i++){
		if(vec[i]%2==0){
			par++;
	}
	}
return par;		
}
int compara_impar(int *vec,int n){
	int i,impar=0;
	for(i=0;i<n;i++){
		if(vec[i]%2 != 0){
			impar++;
		}
	}
	return impar;		
}
int menores(int *vec,int comparador,int n){
	int i,menor=0;
for(i=0;i<n;i++){
	if(vec[i]<comparador){
		menor++;
	}
}
return menor;		
}
int main (void) {
	int num=1000;
	int i,PAR,IMPAR,MENORES,comparar=7000,minimo=6300,maximo=9300;
	int *vector;
	vector=new int[num];		
	generador(vector,minimo,maximo,num);
	PAR=compara_par(vector,num);
	IMPAR=compara_impar(vector,num);
	MENORES=menores(vector,comparar,num);
	cout<<"Vector: [";
	for(i=0;i<num-1;i++){
		cout<<vector[i]<<", ";
	}
	cout<<vector[num]<<"]"<<endl<<"PARES: "<<PAR<<endl<<"IMPARES: "<<IMPAR<<endl<<"MENORES: "<<MENORES<<endl;
	delete [] vector;
	return 0;
}
