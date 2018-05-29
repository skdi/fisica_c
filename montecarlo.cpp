#include<iostream>
#include<iomanip>
#include<time.h>
#include<cmath>

using namespace std;
double generador(double N){
	srand(time(NULL));
	double x,y,n=0,R;
	for(unsigned int i=0;i<int(N);i++){
		x=rand()%1;
		y=rand()%1;
		R=(pow(x,2)+pow(y,2));
		if(R<1)
			n++;		
	}
	return n;
}

void montecarlo(){
	double N=50;
	double n=0,pi;
	while(N<=10000){
		//promedio
		n=0;
		for(int i=0;i<20;i++){
			n+=generador(N);
		}
		n/=20;
		//calculo de pi
		pi=4*(n/N);
		cout<<N<<" : "<<"el pi calculado es: "<<pi<<endl;
		//numero de iteraciones
		N+=50;
	}

}

int main(){


	montecarlo();
}
