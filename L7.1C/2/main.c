#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 ex2
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{

 
 int funcao(int n1,int n2);
 int x=0,y=0;
 int resultado=0;

 do{
 scanf("%d %d",&x,&y);
 }while(x<0 && y>0);

  resultado = funcao(x,y);

 printf("SOMA: %d\n",resultado);



	system("pause");
	return 0;
}
int funcao(int n1,int n2){
 
 int i;
 int soma=0;
 int diferenca=0;;

 diferenca = n1 - n2;

 if(diferenca<0){
 	diferenca = abs(diferenca);
 }

  for(i=1;i<=diferenca;i++){

    if(i = (int)i)
      soma+=i;
   }
 
  return soma;

}