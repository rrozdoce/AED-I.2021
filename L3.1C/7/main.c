#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int idade=0,cont=0,i;


for(i=1;i<=10;i++){
  
  printf("\nPessoas: %i\n",i);

do{  
  printf("\nIDADE:\n");
   scanf("%d",&idade);
  if(idade>=18){
  	cont++;
  }
}while(idade<=0);


 }
 printf("\nQuantidade acima de 18:%d\n",cont);








	system("pause");
	return 0;
}