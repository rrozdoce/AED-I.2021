#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 exer10
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{
 
 int media_conjuntoN();
 int media_conjuntoM();
 int media_conjuntoO();
 int media_conjuntos(float conjunto_n,float conjunto_m,float conjunto_o);
 int n=1,m=1,o=1;
 int conjunto_n;
 int conjunto_m;
 int conjunto_o;
 float media=0;

//-----------------CONJUNTO_N----------------------\\

  do{  
    system("cls");
     printf("Conjunto N:\n");
      scanf("%d",&n);

  }while(n<0);

//-----------------CONJUNTO_M----------------------\\
 
 system("cls");

  do{
    system("cls");
     printf("Conjunto M:\n");
      scanf("%d",&m);
  }while(m<0);
 

//-----------------CONJUNTO_O----------------------\\
 
 system("cls");

  do{
    system("cls");
     printf("Conjunto O:\n");
      scanf("%d",&o);
  }while(o<0);
     

//-------------------------------------------------\\

 system("cls");

 conjunto_n = media_conjuntoN(n);

 system("cls");
 
 conjunto_m = media_conjuntoM(m);

 system("cls");

 conjunto_o = media_conjuntoO(o);

 system("cls");
 
 media = media_conjuntos(conjunto_n, conjunto_m, conjunto_o);

 printf("MEDIA ENTRE OS CONJUNTOS: %2.f\n",media);

//---------------------------------------------------\\

	system("pause");
	return 0;
}

int media_conjuntoN(int n){
   
  int conjunto_n[n]; 
  int soma=0;
  float media=0;

  for(int i=0;i<n;i++){
  	  printf("Conjunto N\n");
       printf("VALOR[%i]\n",i+1);
         scanf("%d",&conjunto_n[i]);
       soma+=conjunto_n[i];
    }

    media = soma/n;
 
  return media;
 
}

int media_conjuntoM(int m){

 int conjunto_m[m]; 
 int soma=0;
 float media=0;
  
  for(int i=0;i<m;i++){
  	  printf("Conjunto M\n");
       printf("VALOR[%i]\n",i+1);
         scanf("%d",&conjunto_m[i]);
       soma+=conjunto_m[i];
    }
   
   media = soma/m;

   return media;

}

int media_conjuntoO(int o){
  
 int conjunto_o[o]; 
 int soma=0;
 float media=0;
  
  for(int i=0;i<o;i++){
  	  printf("Conjunto O\n");
       printf("VALOR[%i]\n",i+1);
         scanf("%d",&conjunto_o[i]);
       soma+=conjunto_o[i];
    }
   
   media = soma/o;

   return media;


}

int media_conjuntos(float conjunto_n,float conjunto_m,float conjunto_o){

 float media=0;

 media = (conjunto_n + conjunto_m + conjunto_o)/3;

 return media;

}