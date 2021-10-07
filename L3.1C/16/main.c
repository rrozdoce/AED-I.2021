#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

  int peso=0,idade=0,i;
  int soma=0,cont_peso=0,cont_idade=0;
  float altura=0;

  for(i=0;i<=10;i++){
    
  do{ 
   printf("\nIDADE:\n");
   scanf("%d",&idade);
   soma+=idade;
  }while(idade<=0);
  
  do{
   printf("\nPESO:\n");
   scanf("%d",&peso);
  }while(peso<=0);
  
  do{
   printf("\nALTURA:\n");
   scanf("%f",&altura);
  }while(altura<=0);

  if(peso>90 && altura<1.50){
  	cont_peso++;
  }
  if((idade>=10) && (idade<=30)&&(altura>1.90)){
  	cont_idade++;
  }

  }
 
  printf("\nMEDIA:%d\n",soma/10);
  printf("\nACIMA DE 90KG E ABAIXO DE 1.50m:%d\n",cont_peso);
  printf("\nPercentagem das pessoas entre 10 e 30 anos com mais de 1.90m:%f\n",(cont_idade*100)/10);






	system("pause");
	return 0;
}