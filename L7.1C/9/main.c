#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 exer9
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{ 

 int maior();
 int menor();
 int tam = 1;
 int valor[tam];

    do{
    system("cls");
     printf("TAMANHO\n");
       scanf("%d",&tam);
    }while(tam<0);

 for(int i=0;i<tam;i++){
    printf("VALOR[%i]:\n",i+1);
     scanf("%d",&valor[i]);
 }

 maior(valor,tam);
 menor(valor,tam);



	system("pause");
	return 0;
}

int maior(int *valor,int tam){

 int maior=0;
 
  for(int i=0;i<tam;i++){
     if(valor[i] >= maior){
     	maior = valor[i];
     }
  }

  printf("MAIOR: %d\n",maior);

}

int menor(int *valor,int tam){

  int menor;
 
  for(int i=0;i<tam;i++){
     if(valor[i] <= menor){
     	menor = valor[i];
     }
  }

  printf("MENOR: %d\n",menor);

}