#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 float soma=0,controle=0,canal=0;
 float soma4=0,soma5=0,soma7=0,soma12=0;
 int num=0,i=1,pessoas=0;
 
 printf("\nNumero de casas:\n");
  scanf("%d",&num);

while(i<=num){
  

  do{
     printf("\nCasa: %i\n",i);
   do{
    printf("\nNumero do canal:\n");
     scanf("%f",&canal);
    }while(canal!=4 && canal!=5 && canal!=7 && canal!=12);
    
    do{
      printf("\nPessoas assistindo:\n");
       scanf("%d",&pessoas);
    }while(pessoas<0);

   if(canal==4){
   	soma4+=pessoas;
   }
   if(canal==5){
   	soma5+=pessoas;
   }
   if(canal==7){
   	soma7+=pessoas;
   }
   if(canal==12){
   	soma12+=pessoas;
   }
   
  soma+=pessoas;

   printf("\nDigite 0 para encerrar a entrada:\n");
    scanf("%f",&controle);
  }while(controle!=0);
 

  i++;	
 }
 printf("\npercentagem do canal 4:%f\n",(soma4*100)/soma);
 printf("\npercentagem do canal 5:%f\n",(soma5*100)/soma);
 printf("\npercentagem do canal 7:%f\n",(soma7*100)/soma);
 printf("\npercentagem do canal 12:%f\n",(soma12*100)/soma);





	system("pause");
	return 0;
}