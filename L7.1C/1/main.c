#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 
 int tam = 30;
 int valor[tam];
  int maior=0;

  for(int i=0;i<tam;i++){

    if(valor[i] >= maior){
        maior = valor[i];
    }

  }

  printf("MAIOR: %d\n",maior);


	system("pause");
	return 0;
}
