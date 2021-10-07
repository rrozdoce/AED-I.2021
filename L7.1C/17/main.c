#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 exer17
//Felipe Echeverria Vilhalva
/*Faça uma função que receba uma matriz 12x12 e retorne a média aritmética dos elementos abaixo da 
diagonal principal.*/

int main(int argc, char const *argv[])
{
 
 int media=0;
 int funcao();

  media = funcao();


   printf("media: %d\n",media);

	system("pause");
	return 0;
}

int funcao(){
 
 int media=0;
 int soma=0;
 int matriz[12][12];
 int valor[144];

 for(int i=1;i<=12;i++){
 	for(int j=1;j<=12;j++){
 		printf("MATRIZ[%i][%i]:\n",i,j);
 		for(int m=1;m<=1;m++){
 			scanf("%d",&valor[m]);
 		      matriz[i][j] = valor[m];
 		    if(i > j){
                soma+=valor[m];
 		    }
 		}
 	}
 }

 media = soma/65;
 
 return media;

}