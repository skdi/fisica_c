#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
using namespace std;
ofstream archivo;
float sigma=10;
float b=2.666667;
float t0=0;
float tf=20;
float r=28;
float h=0.02;
float N=(tf-t0)/h;


float dx(float q=0,float w=0,float e=0){
	return (-sigma*q+sigma*w);
}
float dy(float q=0,float w=0,float e=0){
	return (r*q-w-q*e);
}
float dz(float q=0,float w=0,float e=0){
	return (-b*e+q*w);
}

void rk4(){
	archivo.open("datos.txt");
	float k1x[int(N)],k2x[int(N)],k3x[int(N)],k4x[int(N)];
	float k1y[int(N)],k2y[int(N)],k3y[int(N)],k4y[int(N)];
	float k1z[int(N)],k2z[int(N)],k3z[int(N)],k4z[int(N)];
	float x[int(N)],y[int(N)],z[int(N)];
	x[0]=y[0]=z[0]=5;


	for(int i=0;i<int(N);i++){
		//1
		k1x[i+1]=h*dx(x[i],y[i]);
		k1y[i+1]=h*dy(x[i],y[i],z[i]);
		k1z[i+1]=h*dz(x[i],y[i],z[i]);
		//2
		k2x[i+1]=h*dx((x[i]+k1x[i])/2.0,(y[i]+k1y[i])/2.0);
		k2y[i+1]=h*dy((x[i]+k1x[i])/2.0,(y[i]+k1y[i])/2.0,(z[i]+k1z[i])/2.0);
		k2z[i+1]=h*dz((x[i]+k1x[i])/2.0,(y[i]+k1y[i])/2.0,(z[i]+k1z[i])/2.0);
		//3
		k3x[i+1]=h*dx((x[i]+k2x[i])/2.0,(y[i]+k2y[i])/2.0);
		k3y[i+1]=h*dy((x[i]+k2x[i])/2.0,(y[i]+k2y[i])/2.0,(z[i]+k2z[i])/2.0);
		k3z[i+1]=h*dz((x[i]+k2x[i])/2.0,(y[i]+k2y[i])/2.0,(z[i]+k2z[i])/2.0);
		//4
		k4x[i+1]=h*dx(x[i]+k3x[i],y[i]+k3y[i]);
		k4y[i+1]=h*dy(x[i]+k3x[i],y[i]+k3y[i],z[i]+k3z[i]);
		k4z[i+1]=h*dz(x[i]+k3x[i],y[i]+k3y[i],z[i]+k3z[i]);
		//vars
		x[i+1]=x[i]+(k1x[i]+(k2x[i]*2.0)+k3x[i]*2.0+k4x[i])/6.0;
		y[i+1]=y[i]+(k1y[i]+(k2y[i]*2.0)+k3y[i]*2.0+k4y[i])/6.0;
		z[i+1]=z[i]+(k1z[i]+(k2z[i]*2.0)+k3z[i]*2.0+k4z[i])/6.0;

		archivo<<i<<endl;
		//cout<<x[i]<<endl;
	}


}






int main(){
	rk4();
	//presa_predador();
	archivo.close();
}
