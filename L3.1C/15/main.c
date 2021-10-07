#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int opc=0,controle=0;
 float valor=0;

do{
system("cls");
printf("\n\t1 - Poupanca\n\t2 - Fundos de renda fixa\n");
 scanf("%d",&opc);

do{
printf("\nVALOR:\n");
 scanf("%f",&valor);
}while(valor<=0);
 
switch(opc){
 
 case 1:
   valor = (valor * 0.03)+valor;
 break;

 case 2:
   valor = (valor * 0.04)+valor;
 break;

 default:
   printf("\nOpcao invalida\n");
 break;

}
printf("\nValor corrigido: %2.f\n",valor);




printf("\nDigite 1 para continuar:\n");
 scanf("%d",&controle);
}while(controle==1);






	system("pause");
	return 0;
}