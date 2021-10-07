#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 
 int num=0,i;
 int opc=0,soma_total=0,soma_prazo=0,soma_vista=0;
 int valor=0;
 for(i=1;i<=3;i++){
 	printf("\nTransacao: %i\n",i);
  do{
    printf("\n\t1 - A VISTA\n\t2 -  A PRAZO\n");
     scanf("%d",&opc);
  }while(opc!=1 && opc!=2);

  do{ 
    system("cls");
    printf("\nVALOR:\n");
     scanf("%d",&valor);
  }while(valor<=0);

 if(opc==1){
 	soma_vista+=valor;
 }
 if(opc==2){
 	soma_prazo+=valor;
 }
 
 soma_total+=valor;

 }
printf("\nSoma do Total a vista: %d\n",soma_vista);
printf("\nSoma do Total a prazo: %d\n",soma_prazo);
printf("\nSoma do Total: %d\n",soma_total);
printf("\n\n");





	system("pause");
	return 0;
}