#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int controle=0;
 float credito=0,valor=0;

do{
 
 system("cls");

do{
 printf("\nSALDO MEDIO:\n");
  scanf("%f",&valor);
}while(valor<=0);

if(valor>=1 && valor<=200){
  credito = (valor * 0.10);
}
if(valor>200 && valor<=300){
  credito = (valor * 0.20);
}
if(valor>300 && valor<=400){
  credito = (valor * 0.25);
}
if(valor>400){
  credito = (valor * 0.30);
}

printf("\nSaldo medio: %2.f\n",valor);
printf("\nCredito: %2.f\n",credito);
 


 printf("\nDigite 1 para continuar:\n");
  scanf("%d",&controle);
}while(controle==1);





	system("pause");
	return 0;
}