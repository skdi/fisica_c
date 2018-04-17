#include <iostream>
#include <math.h>
#include <cmath>
#define g 9.8
#define ep 2.71818281
#define pi 3.14159265
using namespace std;


/*void imprimir(double m,double c,int t){
    for(unsigned int i=0;i<=t;i++)
        cout<<i<<" : "<<<<"m/s"<<endl;
}*/
/////////////////////////////////////////////////////

double x_posicion(double x,double v,double t){
    return (x+v*t);
}
double x_velocidad(double vx,double ax,double t){
    return vx+ax*t;
}

double aceleracion_x(double k,double v,double teta){
    return (-k*pow(v,2)*cos(teta));
}
void imprimir_x(double v,double x,double t,double k,double teta){
    double vx=x_velocidad(v,aceleracion_x(k,v,teta),1);
    for(int i=0.1;i<=t;i=1+0.1){
        vx=vx+aceleracion_x(k,vx,teta)+i;
    }
}

/////////////////////////////////////////////////////
double aceleracion_y(double k,double v,double teta){
    return (-g-k*pow(v,2)*sin(teta));
}
double velocidad(double vx,double vy){
    return sqrt(pow(vx,2)+pow(vy,2));
}
double velocidad_y(double v,double a,int t){
       return v+a*t;    
}
void imprimir_vy(double v,double vx,double t){
    double vy;double vt=velocidad(vx,vy);

        cout<<"v0y: "<<v<<"vt: "<<vt<<endl;

    for(double i=0.1;i<=t;i=i+0.1){
        vy=velocidad_y(v,-9.8,i);
        vt=velocidad(vx,vy);
        cout<<(i*10)<<": "<<vy<<" vt: "<<vt<<endl;
    }
}

double h_max(double v,double teta){
    return (pow(v,2)*pow(sin(teta),2))/(2*g);
}
double r_max(double v,double teta){
    return (pow(v,2)*sin(2*teta)/g);
}
double t_vuelo(double v,double teta){
    return (2*v*sin(teta)/g);
}
int main()
{
    double v0=25;
    double vx=19.9659;
    double vy=15.0554;
    double d=0.06;
    double teta=0.64;
    double m=0.1;
    double c=0.5;
    double A=pi*(pow(d,2)/4);
    double p=1;
    double k=(1/2*m)*c*A*p;;
    //cout<<h_max(v0,teta)<<endl;
    //cout<<r_max(v0,teta)<<endl;
    //cout<<t_vuelo(v0,teta)<<endl;

    //imprimir_vy(vy,vx,t_vuelo(v0,teta));


    return 0;
}
