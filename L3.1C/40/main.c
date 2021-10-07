#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int codigo=0,opc=0;
 float juros=0,valor=0;

do{

  system("cls");

do{
  system("cls");
  printf("\n\t1 - Poupanca\n\t2 - Poupanca plus\n\t3 - Fundos de renda fixa\n");
   scanf("%d",&opc);
}while(opc!=1 && opc!=2 && opc!=3);

do{
  printf("\nVALOR:\n");
   scanf("%f",&valor);
}while(valor<=0);


switch(opc){
  
  case 1:
    juros = (valor * 0.015);
  break;

  case 2:
    juros = (valor * 0.02);
  break;

  case 3:
    juros = (valor * 0.04);
  break;
}
  printf("\nVALOR INVESTIDO: %f\n",valor);
  printf("\nJUROS: %f\n",juros);

  //--------------0_______0-------------\\

  printf("\nLeitura terminara com codigo menor ou igual a zero!\n");
  printf("\nCODIGO:\n");
   scanf("%d",&codigo);

}while(codigo>0);

	system("pause");
	return 0;
}