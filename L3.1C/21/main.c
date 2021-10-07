#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int codigo=0,controle=0;
 float valor=0;

do{

system("cls");

do{
 system("cls");
 printf("\nCODIGO:\n");
  scanf("%d",&codigo);
}while(codigo<=0 || codigo>30);

do{
 printf("\nVALOR:\n");
  scanf("%f",&valor);
}while(valor<=0);

if(codigo==1){
 printf("\nProcedencia:\n");
 printf("\nSUL\n");
}
if(codigo==2){
 printf("\nProcedencia:\n");
 printf("\nNORTE\n");
}
if(codigo==3){
 printf("\nProcedencia:\n");
 printf("\nLESTE\n");
}
if(codigo==4){
 printf("\nProcedencia:\n");
 printf("\nOESTE\n");
}
if(codigo>=5 && codigo<=6){
 printf("\nProcedencia:\n");
 printf("\nNORDESTE\n");
}
if(codigo>=7 && codigo<=9){
 printf("\nProcedencia:\n");
 printf("\nSUDESTE\n");
}
if(codigo>=10 && codigo<=20){
 printf("\nProcedencia:\n");
 printf("\nCENTRO-OESTE\n");
}
if(codigo>=21 && codigo<=30){
 printf("\nProcedencia:\n");
 printf("\nNORDESTE\n");
}





 printf("\nDigite 1 para continuar:\n");
  scanf("%d",&controle);
}while(controle==1);


	system("pause");
	return 0;
}