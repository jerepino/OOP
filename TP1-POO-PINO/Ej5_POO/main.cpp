#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

void escribir(char *leer){
	cout<<"Ingrese el nombre del mes:"<<endl;
	cin>>leer;
}
void convertirCadena(char *escribir){	
for ( int i = 0; escribir [ i ]!='\0'; i++ )  {
		escribir[i] = tolower(escribir[i]) ;
	}
}
int interpretar(char *caracter){
	int aux,i=0,n;
	bool flag=true;
	char *meses;
	meses=new char[20];
	do{ switch (i){
		case 0:
			strcpy(meses,"enero");
			n=1;
		break;
		case 1:
			strcpy(meses,"febrero");
			n=2;
		break;
		case 2:
			n=3;
			strcpy(meses,"marzo");
		break;
		case 3:
			n=4;
			strcpy(meses,"abril");
		break;
		case 4:
			n=5;
			strcpy(meses,"mayo");
		break;
		case 5:
			n=6;
			strcpy(meses,"junio");
		break;
		case 6:
			n=7;
			strcpy(meses,"julio");
		break;
		case 7:
			n=8;
			strcpy(meses,"agosto");
		break;
		case 8:
			n=9;
			strcpy(meses,"septiembre");
		break;
		case 9:
			n=10;
			strcpy(meses,"octubre");
		break;
		case 10:
			n=11;
			strcpy(meses,"noviembre");
		break;
		case 11:
			n=12;
			strcpy(meses,"diciembre");
		break;
		case 12:
			cout<<"El mes esta mal escrito"<<endl;
			n=0;			
			flag=false;
		break;
		default:
			cout<<"Error desconocido"<<endl;
			exit(0);
			n=0;
		break;
	}
		
		aux=strcmp(caracter,meses);
		i++;
		
		if(aux==0){
			flag=false;
		}
	} while(flag);
	
	delete [] meses;
	return n;
}
int dias(int mes){
	int dia;
	if((mes==1) | (mes==3) | (mes==5) | (mes==7) | (mes==8) | (mes==10) | (mes==12)){
		dia=31;
	}
	else if (mes==2){
		dia=28;
	}
	else{
		dia=30;
	}
	return dia;
}
void mostrar(string dato,int numeroMes,int numDias){
	cout<<"El mes es: "<<dato<<endl<<"Es el mes: "<<numeroMes<<endl<<"Tiene "<<numDias<<" Dias"<<endl;
}
int main (void) {
	int numeroMes,numeroDias;
	char *mes;
	mes=new char[20];
	do {
	escribir(mes);
	convertirCadena(mes);
	numeroMes=interpretar(mes);
	}while(numeroMes==0);
	numeroDias=dias(numeroMes);
	mostrar(mes,numeroMes,numeroDias);
	delete [] mes;
	return 0;
}

