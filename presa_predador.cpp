#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;
ofstream archivo;

void presa_predador(){
	archivo.open("datos.txt");
	float a,b,c,d;
	int t0,tf,N;
	float conejos,zorros;
	a=0.4;
	b=0.37;
	c=0.3;
	d=0.05;
	N=5000;
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
		//archivo<<n<<" rabbits: "<<r[n]<<" foxes: "<<f[n]<<endl;
		//archivo<<r[n]<<endl;
		//archivo<<f[n]<<endl;
		archivo<<n<<endl;
		n++;

	}

	
}


int main(){
	presa_predador();
	archivo.close();
}
