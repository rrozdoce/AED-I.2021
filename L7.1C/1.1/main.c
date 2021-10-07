#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 ex1

int main(int argc, char const *argv[])
{

 int retorne=0;
 int y=0;
 int funcao(int x);

 scanf("%d",&y);

 retorne = funcao(y);

  printf("retornado: %d\n",retorne);


	system("pause");
	return 0;
}

int funcao(int x){
  
  if(x>=0){

    return 0;
  }
  if(x<0){
    return 1;
  }
 
}