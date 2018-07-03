#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 
int Ale_Ent(int p)
{
	int pp;
	pp=p*(float)rand()/(RAND_MAX+1.0);
	return pp;
}

float Ale_Fra(float p)
{
	float pp;
	pp=p*(float)rand()/(RAND_MAX+1.0);
	return pp;
}


int main()
{
	FILE *in;

	int i,j,jj,k,cte, Num_Ciu=30,ruta=100,city,trash,cte1,cte2,pos,gen[ruta];
	int cadena[ruta][Num_Ciu],mas[Num_Ciu],hijo1[Num_Ciu],hijo2[Num_Ciu];
	int padre1[Num_Ciu],padre2[Num_Ciu],tem2,gen_sel[ruta],new_cadena[ruta][Num_Ciu];
	int Generacion=100;
	double sum_apt,sum_a[ruta],Acomoda=1500.0,pc=0.8,pm=0.002;
	double dist[Num_Ciu][2],MD[Num_Ciu][Num_Ciu],fun_ad[ruta+5],sum,tem;

	srand(time(NULL));

	in=fopen("p1.dat","r");
/*	Poblacion inicial: 100 rutas al azar */	
        for(k=0;k<ruta;k++)
     	{
		for(i=0;i<Num_Ciu;i++) mas[i]=0;
		j=0;
		while(j<Num_Ciu)
		{
		cte=Ale_Ent(Num_Ciu);
		if(mas[cte]==0) 
			{
			cadena[k][j]=cte;	
			mas[cte]=1;
			j++; 
			}
		}
        }

     	for(k=0;k<ruta;k++)	
     	{
		printf("ruta %d    ",k);
		for (i=0;i<Num_Ciu;i++)printf("%d ",cadena[k][i]);
		printf("\n");
     	
}
/*	Lee de un archivo las coordenas de las ciudades */ 

	fscanf(in,"%d\n",&city);
//        printf("Numero de ciudades %d\n",city);

	for(i=0;i<city;i++) 
	{  
	fscanf(in,"%d %lf %lf\n",&trash, &dist[i][0], &dist[i][1]);
	}
/*     
	for(i=0;i<city;i++) 
	{ 
	printf("%d %.2lf %.2lf\n",i, dist[i][0], dist[i][1]);
	}
*/
    	fclose(in);

/* Calculo de la Matriz de Distancias   */


	for(j=0;j<Num_Ciu;j++)
	for(i=0;i<Num_Ciu;i++)
		MD[j][i]=sqrt(pow((dist[j][0]-dist[i][0]),2.0)+ pow((dist[j][1]-dist[i][1]),2.0));
	
	for(j=0;j<20;j++)
	{
		for(i=0;i<20;i++)
		printf("%.2lf ",MD[j][i]);
 		printf("\n");
	}

  for(jj=0;jj<Generacion;jj++)
  {
/* Funcion de Adaptacion   */
	for(j=0;j<ruta;j++)
	{
		for(i=0,sum=0.0;i<Num_Ciu-1;i++) sum=sum+MD[cadena[j][i]][cadena[j][i+1]]; 
		fun_ad[j]=Acomoda-sum;
		gen[j]=j;
//		fun_ad[j]=sum;
	}
//	for(j=0;j<ruta;j++)printf("%d %.2lf\n",j,fun_ad[j]);

	/*Ordena la Fun Adap y el Gen correspondient */
	for(j=0;j<ruta-1;j++) 
	for(i=j+1;i<ruta;i++) if (fun_ad[j]<fun_ad[i])
	{
		tem=fun_ad[j];
		fun_ad[j]=fun_ad[i];	
		fun_ad[i]=tem;
		tem2=gen[j];
		gen[j]=gen[i];
		gen[i]=tem2;
	}
//	for(i=0;i<ruta-80;i++) printf("%d\t %d\t %.2lf %.2lf\n",i,gen[i],fun_ad[i],Acomoda-fun_ad[i]);

	/* Rueda de Ruleta */ 	
	for(i=0,sum_apt=0.0;i<ruta;i++) 	
	{
	sum_apt=sum_apt+fun_ad[i];
	sum_a[i]=sum_apt;
	}
	for(j=0;j<ruta;j++)
	{	
		tem=Ale_Fra(1.0)*sum_apt;
		for(i=0;i<ruta;i++)
		{
			if(sum_a[i]<tem && sum_a[i+1]>tem)
			gen_sel[j]=gen[i]; 
		}
	}
	for(i=0;i<ruta;i++) gen[i]=gen_sel[i];

	/* Funcion de Adaptacion   */
	for(j=0;j<ruta;j++)
	{
		for(i=0,sum=0.0;i<Num_Ciu-1;i++) sum=sum+MD[cadena[gen[j]][i]][cadena[gen[j]][i+1]]; 
		fun_ad[j]=Acomoda-sum;
	}

	/* Cruce    */
   for(i=0;i<ruta;i+=2)
     {
     tem=Ale_Fra(1.0);
     if(tem<pc)
     {	
     for(j=0;j<Num_Ciu;j++)
	{
	padre1[j]=cadena[gen[i]][j];
	padre2[j]=cadena[gen[i+1]][j];
	hijo2[j]=cadena[gen[i]][j];
	hijo1[j]=cadena[gen[i+1]][j];
	}
/*
     for(j=0;j<Num_Ciu;j++) printf("%d ",padre1[j]);printf("\n");
     for(j=0;j<Num_Ciu;j++) printf("%d ",padre2[j]);printf("\n");
*/
     cte1=Ale_Ent(Num_Ciu);
     cte2=Ale_Ent(Num_Ciu);
     if(cte2<cte1) {trash=cte1;cte1=cte2;cte2=trash;}
//     printf("%d %d\n",cte1,cte2);

     for(j=0;j<cte1;j++){ hijo1[j]=99;  hijo2[j]=99;}
     for(j=cte2;j<Num_Ciu;j++){ hijo1[j]=99;  hijo2[j]=99;}
/*
     for(j=0;j<Num_Ciu;j++) printf("%d ",hijo1[j]);printf("\n");
     for(j=0;j<Num_Ciu;j++) printf("%d ",hijo2[j]);printf("\n");
*/
     for(cte=0;cte<Num_Ciu;cte++) if(cte<cte1 || cte>=cte2)
	{
	 pos=cte;
	  while(hijo1[cte]==99)
	  {
	   for (j=0,trash=0;j<Num_Ciu;j++) 
	    if(padre1[pos]==hijo1[j]) 
	    {
	     trash=1;
	     pos=j;
	     break;
//	     printf("%d %d\n",pos,j);	 
	    }

	   if(trash==0) hijo1[cte]=padre1[pos];
	  }	
	}
/*     printf("Hijo 1 %d:\n",i);
     for(j=0;j<Num_Ciu;j++) printf("%d ",hijo1[j]);
     printf("\n");
*/
     for(cte=0;cte<Num_Ciu;cte++) if(cte<cte1 || cte>=cte2)
	{
	pos=cte;
	  while(hijo2[cte]==99)
	  {
	   for (j=0,trash=0;j<Num_Ciu;j++) 
	    if(padre2[pos]==hijo2[j]) 
	    {
	     trash=1;
	     pos=j;
	     break;
	    }
//	    printf("%d %d\n",pos,j);	
	   if(trash==0) hijo2[cte]=padre2[pos];
	  }	
	}
/*     printf("Hijo 2 %d:\n",i+1);
     for(j=0;j<Num_Ciu;j++) printf("%d ",hijo2[j]);
     printf("\n");
*/
     for(j=0;j<Num_Ciu;j++)
	{
		new_cadena[i][j]=hijo1[j];
		new_cadena[i+1][j]=hijo2[j];		
	}
     }
     else
     for(j=0;j<Num_Ciu;j++)
	 {
		new_cadena[i][j]=cadena[gen[i]][j];
		new_cadena[i+1][j]=cadena[gen[i+1]][j];		
	 }
     }

	/* Mutacion    */

     	for(k=0;k<ruta;k++)	
     	{
		tem=Ale_Fra(1.0);
		if(tem<pm)
		{			
			cte1=Ale_Ent(Num_Ciu);
			cte2=Ale_Ent(Num_Ciu);
//			printf("%d %d\n",cte1,cte2);
//			for (i=0;i<Num_Ciu;i++)printf("%d ",new_cadena[k][i]);
//			printf("\n");
			cte=new_cadena[k][cte1];			
			new_cadena[k][cte1]=new_cadena[k][cte2];
			new_cadena[k][cte2]=cte;
//			for (i=0;i<Num_Ciu;i++)printf("%d ",new_cadena[k][i]);
//			printf("\n");
	       }
     	}

	/* Funcion de Adaptacion (minimo)   */

	for(k=0,tem=3000.0,sum_apt=0.0;k<ruta;k++)
	{
		for(i=0,sum=0.0;i<Num_Ciu-1;i++) sum=sum+MD[new_cadena[k][i]][new_cadena[k][i+1]]; 
		fun_ad[k]=sum;
		if(fun_ad[k]<tem) tem=fun_ad[k];
		sum_apt=sum_apt+sum;
	}
	sum_apt=sum_apt/ruta;
	printf("%.2f %.2f\n",tem,sum_apt);

	for(k=0;k<ruta;k++)
		for(i=0;i<Num_Ciu;i++) cadena[k][i]=new_cadena[k][i];

  }
}
