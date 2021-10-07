#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 
 int freq=0,matricula=0,cont=0,contf=0,i;
 float media=0,nota[3],maior=0,menor=0;
 
 nota[0]=0;
 nota[1]=0;
 nota[2]=0;

 for(i=1;i<=10;i++){

 printf("\nALUNO %i\n",i);

 do{
  system("cls");
  printf("\nMatricula:\n");
   scanf("%d",&matricula);
 }while(matricula<0);

 do{
  system("cls");
  printf("\nNOTA 1:\n");
   scanf("%f",&nota[0]);
  printf("\nNOTA 2:\n");
   scanf("%f",&nota[1]);
  printf("\nNOTA 3:\n");
   scanf("%f",&nota[2]);

  if(nota[0]>=maior){
  	maior=nota[0];
  }
  else if(nota[0]<=menor){
  	menor=nota[0];
  }
  else if(nota[1]>=maior){
    maior=nota[1];
  }
  else if(nota[1]<=menor){
  	menor=nota[1];
  }
  else if(nota[2]>=maior){
    maior=nota[2];
  }
  else if(nota[2]<=menor){
    menor=nota[2];
  }

 }while((nota[0]<=0)||(nota[1]<=0)||(nota[2]<=0));

do{
 system("cls");
 printf("\nFrequencia:\n");
  scanf("%d",&freq);
}while(freq<0);

media = (nota[0]+nota[1]+nota[2])/3;

if(media<6){
  printf("\nMedia menor que seis!\n");
  printf("\nReprovado\n");
  printf("\nMedia:%2.f\n",media);
  printf("\nMatricula:%d\n",matricula);
  cont++;
}
else if((media<6)&&(freq>40)){
  printf("\nFaltas superam 40!\n");
  printf("\nMedia menor que seis!\n");
  printf("\nReprovado\n");
  printf("\nMedia:%2.f\n",media);
  printf("\nMatricula:%d\n",matricula);
  printf("\nFrequencia:%d\n",freq);
  contf++;
  cont++;
}else if(freq>40){
  printf("\nFaltas superam 40!\n");
  printf("\nReprovado\n");
  printf("\nMedia:%2.f\n",media);
  printf("\nMatricula:%d\n",matricula);
  printf("\nFrequencia:%d\n",freq);
  cont++;
  contf++;
}
else{
  printf("\nAprovado!\n");
  printf("\nMedia:%2.f\n",media);
  printf("\nMatricula:%d\n",matricula);
  printf("\nFrequencia:%d\n",freq);
}

 } 
 
printf("\nMaior Nota:%2.f\n",maior);
printf("\nMenor Nota:%2.f\n",menor);
printf("\nReprovados:%d\n",cont);
printf("\nporcentagem de reprovados por Frequencia:%d\n",(contf*100)/10);




    system("pause");
    return 0;
}