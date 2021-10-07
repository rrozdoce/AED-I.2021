#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 float resposta=0;
 int validacao();

  resposta = validacao();

   printf("SOMA: %f\n",resposta);

	system("pause");
	return 0;
}

 int validacao(){
  
  float resultado=0;
  int calculo(float x,float y,float z);
  float a=0,b=0,c=0;
 
do{ 
 system("cls");
  printf("A:\n");
   scanf("%f",&a);

  if(a != (int)a || a<=1){
  	 printf("'A' inserido incorretamente\n");
  	  printf("'A' deve ser inteiro maior que 1\n");
  	   system("pause");
  }
}while(a != (int)a || a<=1);

do{
 system("cls");
  printf("B:\n");
   scanf("%f",&b);

 if(b != (int)b){
   printf("'B' inserido incorretamente\n");
 	printf("'B' deve ser inteiro!\n");
 	system("pause");
 }
}while(b != (int)b);

do{
 system("cls");
  printf("C:\n");
   scanf("%f",&c);

 if(c != (int)c){
   printf("'C' inserido incorretamente\n");
 	printf("'C' deve ser inteiro!\n");
 	system("pause");
 }
}while(c != (int)c);

   resultado = calculo(a,b,c);

   return resultado;
 }

 int calculo(float x,float y,float z){
   
  float soma=0;
  float diferenca=0;

  diferenca = y - z;

  if(diferenca<0){
  	diferenca = abs(diferenca);
  }

  for(int i=1;i<=diferenca;i++){  
    if(i = (int)i && i/x==0){
    	soma+=i;
    }
  }
  
  return soma;
 
 }