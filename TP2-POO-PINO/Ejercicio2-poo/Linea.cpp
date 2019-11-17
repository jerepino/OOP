#include "Linea.h"
#include<iostream>
using namespace std;

Linea::Linea (char car) {
	establecerValores(0,0,1,1);
	caracter=car;
	
	matriz=new char *[24];
	for(int i=0;i<24;i++){
		
		matriz[i]=new char[74];
	}
	for(int i=0;i<=22;i++){
		for(int j=0;j<=74;j++){
			*(*(matriz+i)+j)=' ';
		}
	}
}
Linea::~Linea() {
	for(int i=0;i<24;i++){
		
		delete [] matriz[i];
	}
	delete [] matriz;
	matriz=0;
}
void Linea::mostrar ( ) {
	cout<<"La recta es:"<<endl;
	for(int i=0;i<=22;i++){
		for(int j=0;j<=74;j++){
			cout<<*(*(matriz+i)+j);
		}
		cout<<endl;
	}
	cout<<"El punto inicial es: P("<<xini<<","<<22-yini<<")"<<endl;
	cout<<"El punto final es: P("<<xfin<<","<<22-yfin<<")"<<endl;
}
void Linea::formarRecta (double xi,double yi,double xf,double yf ) {
	
	establecerValores(xi,yi,xf,yf);
	double y=yini,x=xini,m,dx;
	int yy,xx;
	
	m=(yfin-yini)/(xfin-xini);
	
	dx=xfin-xini;
	while((y!=(yfin)) && (x!=(xfin+1))){
		
		y=m*(x-xini)+yini;
		yy=(int) y;
		xx=(int) x;
		
		*(*(matriz+yy)+xx)=caracter;
		if(dx>0){
			x++;
		}
		else 
		   x--;
	}
}
void Linea::establecerValores (double xi, double yi, double xf, double yf) {
	xini=(xi>=0 && xi<=74)?xi:0;
	xfin=(xf>=0 && xf<=74)?xf:1;
	yini=(yi>=0 && yi<=22)?(22-yi):22;
	yfin=(yf>=0 && yf<=22)?(22-yf):21;
}
