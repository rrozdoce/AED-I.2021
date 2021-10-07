#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 
 int horario=0;
 int conversor_horas(int num);
 int conversor_minutos(int num);
 int opc=0;

 do{
  system("cls");
  printf("Conversor de horas,minutos e segundos em segundos\n");
   printf("\n\t1 - HORAS\n\t2 - MINUTOS\n\t3 - SEGUNDOS\n");
    scanf("%d",&opc);

   if(opc!=1 && opc!=2 && opc!=3){
      printf("Opcao invalida!\n");
       system("pause");
   }
  }while(opc!=1 && opc!=2 && opc!=3);

switch(opc){

 case 1:

  printf("Hora:\n");
   scanf("%d",&horario);
     conversor_horas(horario);

 break;
  case 2:

  printf("Minutos:\n");
   scanf("%d",&horario);
    conversor_minutos(horario);

   break;

    case 3:

   printf("Minutos:\n");
    scanf("%d",&horario);   
     printf("Segundos pra segundos: %d\n",horario);

     break;

    default:
      printf("\n");
    break;
}


	system("pause");
	return 0;
}

int conversor_horas(int num){

  int convertido=0;

  convertido = (num * 60) * 60;

   printf("Horas pra segundos: %d\n",convertido);

}

int conversor_minutos(int num){

   int convertido = 0;

   convertido = num*60;

   printf("Minutos pra segundos: %d\n",convertido);

}