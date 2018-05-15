#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;
ofstream archivo;
#define N 5000
int t0=0,tf=100;
float a=0.4,b=0.37,c=0.3,d=0.05,h=0.02;
double r[N];double f[N];


double rabbits(double x,double y){
	return (a*x-b*x*y);
}
double foxes(double x,double y){
	return (-c*y+d*x*y);
}


void rk4(){
	archivo.open("datos.txt");
	double mr[N],mf[N];
	double k1r[N],k2r[N],k3r[N],k4r[N];
	double k1f[N],k2f[N],k3f[N],k4f[N];
	r[0]=3;
	f[0]=1;


	for(int i=0;i<N;i++){
		//CONEJOS
		k1r[i]=rabbits(r[i],f[i]);
		k2r[i]=rabbits((r[i]+h)/2,(f[i]+k1r[i]*h)/2);
		k3r[i]=rabbits((r[i]+h)/2,(f[i]+k2r[i]*h)/2);
		k4r[i]=rabbits((r[i]+h),(f[i]+k3r[i]*h));
		mr[i]=(k1r[i]+2*k2r[i]+2*k3r[i]+k4r[i])/6;
		r[i+1]=r[i]+mr[i]*h;
		//ZORROS
		k1f[i]=foxes(r[i],f[i]);
		k2f[i]=foxes((r[i]+h)/2,(f[i]+k1f[i]*h)/2);
		k3f[i]=foxes((r[i]+h)/2,(f[i]+k2f[i]*h)/2);
		k4f[i]=foxes((r[i]+h),(f[i]+k3f[i]*h));
		mf[i]=(k1f[i]+2*k2f[i]+2*k3f[i]+k4f[i])/6;
		f[i+1]=f[i]+mf[i]*h;
		archivo<<i<<endl;
		//cout<<f[i]<<endl;
	}


}



void presa_predador(){
	archivo.open("datos.txt");
	float a,b,c,d;
	int t0,tf;
	float conejos,zorros;
	a=0.4;
	b=0.37;
	c=0.3;
	d=0.05;
	t0=0;
	tf=100;
	double dt=abs(t0-tf)/N;
	double r[N];
	double f[N];
	r[0]=3;
	f[0]=1;
	int n=0;
	for(double i=t0;i<tf;i+=dt){
		r[n+1]=a*r[n]-c*r[n]*f[n];
		f[n+1]=-b*f[n]+d*r[n]*f[n];
		//archivo<<f[n]<<endl;
		archivo<<n<<endl;
		n++;

	}

	
}


int main(){
	rk4();
	//presa_predador();
	archivo.close();
}
