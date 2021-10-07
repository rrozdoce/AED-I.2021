#include <stdio.h>
#include <stdlib.h>
#define tam 5
//Lista 7.1 exer12
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{

 int funcao();


  funcao();



	system("pause");
	return 0;
}

int funcao(){
  
  int vetor[tam];
  int valor_repetido[tam];
  int valor_resultante[tam];

   for(int i=0;i<tam;i++){
 	  printf("VETOR[%d]\n",i+1);
 	   scanf("%d",&vetor[i]);
  }


  for(int i=0;i<tam;i++){
  	  for(int j=0;j<tam;j++){
  	  	if(i != j){
  	  	  if(vetor[i] == vetor[j]){
  	  	  	printf("VALOR repetido :%i nos indices %i e %i\n",vetor[i],i+1,j+1);
  	  	  	  valor_repetido[tam] = vetor[i] - vetor[i];
  	  	  	  break;	  
  	  	  }
  	  	  if(vetor[i] != vetor[j]){
  	  	  	  valor_resultante[tam] = vetor[i];
  	  	  	  break;
  	  	  }
  	  	}
  	  }
  }
  
  for(int i=0;i<tam;i++){
  	 printf("vetor[%i] : %i\n",i+1,valor_resultante[tam]);
  }
}