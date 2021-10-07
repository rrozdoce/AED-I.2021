#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int controle=0;
 float valor=0;

do{

system("cls");

do{
 printf("\nSALARIO:\n");
  scanf("%f",&valor);
}while(valor<=0);

if(valor>=1 && valor<=300){
   valor = (valor * 0.35)+valor;
}
if(valor>300){
   valor = (valor * 0.15)+valor;
}

 printf("\nSalario reajustado: %2.f\n",valor);

 printf("\nDigite 1 para continuar:\n");
  scanf("%d",&controle);
}while(controle==1);







	system("pause");
	return 0;
}