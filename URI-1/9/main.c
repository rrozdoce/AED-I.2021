#include <stdio.h>
#include <stdlib.h>

//Brinquedos do papai noel-URI
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{
 
 int numCriancas,bonecas=0,carros=0;
 char sexo[1000];
 char nome[1000]; 

  scanf("%d",&numCriancas);

  for(int i=0;i<numCriancas;i++){
     scanf("%s",&sexo[0]);

    if(sexo[0] == 'M'){
    carros++;
    }
    if(sexo[0] == 'F'){
    bonecas++;
    }
}
   printf("%d carrinhos\n",carros);
   printf("%d bonecas\n",bonecas);
    
   system("pause");
	return 0;
}