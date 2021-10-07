#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 exer16
//Faça uma função que receba uma matriz 6x6 e retorne o menor elemento da sua diagonal secundária. 
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{

int menor;
int funcao();

 menor = funcao();

  printf("MENOR: %d\n",menor);
    
    system("pause");
    return 0;
}

 int funcao(){
 
 int menor;
 int valor[36];
 int matriz[6][6];

 for(int i=1;i<=6;i++){
    for(int j=1;j<=6;j++){
        printf("MATRIZ[%i][%i]\n",i,j);
        for(int n=1;n<=1;n++){

            scanf("%d",&valor[n]);
              matriz[i][j] = valor[n];

               if(matriz[2][6]<=menor){
                 menor = matriz[2][6];          
               }                                
               if(matriz[3][5]<=menor){
                 menor = matriz[3][5];
               }
               if(matriz[3][6]<=menor){
                 menor = matriz[3][6];
               }
               if(matriz[4][4]<=menor){
                 menor = matriz[4][4];
               }
               if(matriz[4][5]<=menor){
                 menor = matriz[4][5];
               }
               if(matriz[4][6]<=menor){
                 menor = matriz[6][6];
               }
               if(matriz[5][3] <=menor){
                 menor = matriz[5][3];
               }
               if(matriz[5][4] <=menor){
                 menor = matriz[5][4];
               }
               if(matriz[5][5] <=menor){
                 menor = matriz[5][5];
               }
               if(matriz[5][6] <=menor){
                 menor = matriz[5][6];
               }
               if(matriz[6][2] <=menor){
                 menor = matriz[6][2];
               }
               if(matriz[6][3] <=menor){
                 menor = matriz[6][3];
               }
               if(matriz[6][4] <=menor){
                menor = matriz[6][4];
               }
               if(matriz[6][5] <=menor){
                menor = matriz[6][5];
               }
               if(matriz[6][6] <=menor){
                menor = matriz[6][6];
               }
           }
        }
    }         
  
  return menor;

 }