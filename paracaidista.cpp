#include <iostream>
#include <math.h>
#include <cmath>
#define g 9.8
#define ep 2.71818281
using namespace std;
double paracaidista(double m,double c,int t){
           return ((g*m)/c)*(1-pow(ep,(-c*t)/m));
}
double paracaidista2(double v,double m,double c,int t){
        return (v+(g-(c*v/m))*t);
}
void imprimir_p2(double m,double c,int t){
    double v=0;
    for(unsigned int i=0;i<=(t/2);i++){
        cout<<2*i<<" : "<<paracaidista2(v,m,c,2*i)<<"m/s"<<endl;
        v=paracaidista2(v,m,c,i);
    }
}

void imprimir_p(double m,double c,int t){
    for(unsigned int i=0;i<=t;i++)
        cout<<i<<" : "<<paracaidista(m,c,i)<<"m/s"<<endl;
}

using namespace std;


int main()
{
    double m=68.1;double c=12.5;int t=12;
    /*cout<<"ingrese la masa del paracaidista"<<endl;
    double m;cin>>m;cout<<endl;
    cout<<"ingrese la la costante C del paracaidista"<<endl;
    double c;cin>>c;cout<<endl;
    cout<<"ingrese un intervalo de tiempo t"<<endl;
    int t;cin>>t;cout<<endl;*/
    cout<<"Metodo1..."<<endl;
    paracaidista(m,c,t);
    imprimir_p(m,c,t);
    cout<<"Metodo2..."<<endl;
    paracaidista2(0,m,c,t);
    imprimir_p2(m,c,t);

    return 0;
}
