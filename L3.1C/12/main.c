#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

int idade=0,peso=0;
int cont=0,cont_idade=0,cont_peso=0,i;
float soma=0,altura=0;

for(i=1;i<=2;i++){
  
  printf("\nPESSOA %i\n",i);

 do{
  printf("\nIDADE:\n");
  scanf("%d",&idade);

 if(idade>50){
 	cont_idade++;
  }

 }while(idade<=0);

 do{
  printf("\nPESO:\n");
  scanf("%d",&peso);

  if(peso<40){
  	cont_peso++;
  }
 }while(peso<=0);

 do{
  printf("\nALTURA:\n");
  scanf("%f",&altura);
 }while(altura<=0);

 if(idade>=10 && idade<=20){
 	soma+=altura;
 	cont++;
 }


}
 printf("\nACIMA DE 50:%d\n",cont_idade);
 printf("\nMedia de Alturas entre 10 e 20 anos:%f\n",soma/cont);
 printf("\npercentagem acima de 40kg:%2.f\n",(cont_peso*100)/25);





	system("pause");
	return 0;
}