#include <stdio.h>
#include <stdlib.h>

// Lista 7.1 exer5
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{
 
 int media_aritimetica();
 int media_ponderada();
 int nota [3] = {0};
 int controle = 0;
 float resposta = 0;
 char letra;


do{
 system("cls");
  printf("LETRA:\n");
    scanf("%c",&letra);

 for(int  i=0;i<3;i++){
  do{
   system("cls");
   printf("NOTA [%d]\n",i+1);
    scanf("%d",&nota[i]);
   }while(nota[i]<0 || nota[i]>10);
 }    
     if(letra == 'A'){
        resposta = media_aritimetica(nota[0],nota[1],nota[2]);
         printf("\nMedia: %f\n",resposta);
     }
      else if(letra == 'a'){
     	resposta = media_aritimetica(nota[0],nota[1],nota[2]);
     	 printf("\nMedia: %f\n",resposta);
     }
     else if(letra == 'B'){
        resposta = media_ponderada(nota[0],nota[1],nota[2]);
         printf("\nMedia: %f\n",resposta);
     }
     else if(letra== 'b'){
        resposta = media_ponderada(nota[0],nota[1],nota[2]);
         printf("\nMedia: %f\n",resposta);
     }
     else{
     	printf("__Valor invalido__\n");
     }

  printf("Continuar?\n");
   printf("\n\t1 - SIM\n\t2 - NAO\n");
    scanf("%d",&controle);


}while(controle == 1);

	system("pause");
	return 0;
}

int media_aritimetica(int nota1,int nota2,int nota3){
   
   float media=0;

   media = (nota1 + nota2 + nota3)/3;


   return media;
}

int media_ponderada(int nota1,int nota2,int nota3){

	float media=0;

	media = ((nota1 * 5) + (nota2 * 3) + (nota3 * 2/3;

	return media;
}