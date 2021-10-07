#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lista 7.1 exer15
//Faça uma função que receba uma matriz 3x5 e retorne a soma dos seus elementos.
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{
 

 int funcao();
 int soma=0;

 soma = funcao();

 printf("%d\n",soma);



	system("pause");
	return 0;
}

int funcao(){
  
 int soma=0;
 int matriz[3][5];
 int valor[15];

 for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      printf("matriz[%i][%i]:\n",i+1,j+1);
     for(int n=0;n<1;n++){
       scanf("%d",&valor[n]);
       matriz[i][j] = valor[n];
       soma+=matriz[i][j];
     }
   }
}

 return soma;

}