#include "Linea.h"
#include<iostream>
#include <cmath>
using namespace std;

Linea::Linea () {
	pix1=10;
	pix2=10;
	establecerValores(0,0,1,1);
}
Linea::~Linea() {
	for(int i=0;i<pix1;i++){
		delete [] matriz[i];
	}
	delete [] matriz;
	matriz=0;
}
void Linea::mostrar ( ) {
	for(int i=0;i<pix1;i++){
		for(int j=0;j<pix2;j++){
			cout<<*(*(matriz+i)+j);
		}
		cout<<endl;
	}
}
void Linea::formarRecta (double xi,double yi,double xf,double yf ) {
	
	establecerValores(xi,yi,xf,yf);
	double y=yini,x=xini,m,dx;
	int yy,xx;	
	if(xfin==xini){
		while(y!=yfin){
		
			yy=(int) y;
			xx=(int) x;
			*(*(matriz+yy)+xx)=caracter;
			if(yfin>yini){
				y++;
			}
			else{
				y--;
			}
		}
	}
	else if(yfin==yini){
		while(x!=xfin){
			yy=(int) y;
			xx=(int) x;
			*(*(matriz+yy)+xx)=caracter;
			if(xfin>xini){
				x++;
			}
			else{
				x--;
			}
		}
	}
	else{
		m=(yfin-yini)/(xfin-xini);		
		dx=xfin-xini;
		while((y!=(yfin)) && (x!=(xfin))){
			y=m*(x-xini)+yini;
			yy=(int) y;
			xx=(int) x;
			*(*(matriz+yy)+xx)=caracter;
			if(dx>0){
				x++;
			}
			else{
				x--;
			}
		}
	}
}
void Linea::establecerValores (double xi, double yi, double xf, double yf) {
	xini=(xi>=0 && xi<=pix2)?xi:0;
	xfin=(xf>=0 && xf<=pix2)?xf:1;
	yini=(yi>=0 && yi<=pix1)?((pix1-1)-yi):pix1-1;
	yfin=(yf>=0 && yf<=pix1)?((pix1-1)-yf):pix1-1;
}

void Linea::crearMapa (int pix1a,int pix2b,char car ) {
	pix1=pix1a;
	pix2=pix2b;
	caracter=car;
	matriz=new char *[pix1];
	for(int i=0;i<pix1;i++){
		matriz[i]=new char[pix2];
	}
	for(int i=0;i<pix1;i++){
		for(int j=0;j<pix2;j++){
			*(*(matriz+i)+j)=' ';
		}
	}
}

void Linea::graficarCirculo (double xcentro , double ycentro , double radio ) {
	double y,x;
	int xx,yy;
	for(double tita;tita<360;tita++){
		x=xcentro+radio*cos(tita*(3.1415/180));
		y=ycentro+radio*sin(tita*(3.1415/180));
		xx=(int)x;
		yy=(int)y;
		*(*(matriz+yy)+xx)=caracter;
	}
}

