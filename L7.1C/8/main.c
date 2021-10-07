#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 exer8
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{
 
 int funcao();
 int valor[100] = {0};

  for(int i=0;i<100;i++){  

  	printf("VALOR[%i]:\n",i+1);
  	scanf("%d",&valor[i]);

  }

 funcao(valor,100);

	system("pause");
	return 0;
}

int funcao(int *valor){

  int maior=0;
  int menor;

  for(int i=0;i<100;i++){

     if(valor[i] >= maior){
     	maior = valor[i];
     }
     if(valor[i] <= menor){
     	menor = valor[i];
     }
  }

  printf("MAIOR: %d\n",maior);
  printf("MENOR: %d\n",menor);
}