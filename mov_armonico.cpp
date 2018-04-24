#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#define g 9.8
#define ep 2.71818281
#define pi 3.14159265
#define sizee 1000
using namespace std;
double *tetha = new double[sizee];
double *w=new double[sizee];
double *alpha=new double[sizee];
ofstream archivo;

void pendulo(){
	archivo.open("datos.ods");
	double l=1;
	double delta=0.01;
	w[0]=0;
	tetha[0]=0.5;
	alpha[0]=(-g*tetha[0]/l);
	for(int i=0;i<sizee;i++){
		alpha[i+1]=(-g*tetha[i]/l);
		tetha[i+1]=tetha[i]+w[i]*delta;
		w[i+1]=w[i]+alpha[i]*delta;

		cout<<i<<": alpha: "<<alpha[i]<<" tetha: "<<tetha[i]<<" vel_angular: "<<w[i]<<endl;
	}

}
double *v=new double[sizee];
double *x=new double[sizee];
double *a=new double[sizee];
void resorte(){
	double m=1;
	double k=1;
	x[0]=1;
	v[0]=0;
	a[0]=-k*x[0]/m;
	double delta=0.01;
	for(int i=0;i<sizee;i++){
		v[i+1]=v[i]+a[i]*delta;
		x[i+1]=x[i]+v[i]*delta;
		a[i+1]=-k*x[i]/m;
		cout<<i<<": v: "<<v[i]<<" x: "<<x[i]<<" a: "<<a[i]<<endl;
	}


}
int main(){
	pendulo();
	resorte();
	archivo.close();
	delete tetha,w,alpha,v,a,x;
	return 0;

}
