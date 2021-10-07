#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int controle=0;
 float valor=0;

do{

 system("cls");

do{
 printf("\nProduto:\n");
 printf("\nVALOR:\n");
  scanf("%f",&valor);
if(valor>=1 && valor<=50){
   valor = (valor *  0.05)+valor;
}
if(valor>50 && valor<=100){
   valor = (valor * 0.10)+valor;
}
if(valor>100){
   valor = (valor * 0.15)+valor;
}

}while(valor<=0);


if(valor>=1 && valor<=80){
  printf("\nVALOR NOVO: %f\n",valor);
  printf("\nClassificacao:\n");
  printf("\nBARATO\n");
}
if(valor>80 && valor<=120){
  printf("\nVALOR NOVO: %f\n",valor);
  printf("\nClassificacao:\n");
  printf("\nNORMAL\n");
}
if(valor>120 && valor<=200){
  printf("\nVALOR NOVO: %f\n",valor);
  printf("\nClassificacao:\n");
  printf("\nCARO\n");
}
if(valor>200){
  printf("\nVALOR NOVO: %f\n",valor);
  printf("\nClassificacao:\n");
  printf("\nMUITO CARO\n");
}

 printf("\nDigite 1 para continuar:\n");
  scanf("%d",&controle);  
}while(controle==1);






	system("pause");
	return 0;
}