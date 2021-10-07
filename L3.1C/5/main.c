#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 char nome;
 int i;
 float valor=0;

 for(i=1;i<=15;i++){


  printf("\nNOME:\n");
   scanf("%s",&nome);

do{
  printf("\nVALOR:\n");
   scanf("%f",&valor);

if(valor<=1000){
  valor = (valor * 0.10)+valor;
}
if(valor>1000){
  valor = (valor * 0.15)+valor;
}
}while(valor<=0);
printf("\nNOME: %s\n",nome);
printf("\nVALOR COM BONUS: %f\n",valor);



}






	system("pause");
	return 0;
}