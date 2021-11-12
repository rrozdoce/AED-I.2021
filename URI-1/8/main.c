#include <stdio.h>
#include <stdlib.h>

//Escolha Dificil
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{
 
 int C=0,B=0,P=0;
 int c=0,b=0,p=0;
 int a=0;
 
  scanf("%d %d %d",&C,&B,&P);
  scanf("%d %d %d",&c,&b,&p);

  if(C-c<0){
  	a+=abs(C-c);
  }
  if(B-b<0){
  	a+=abs(B-b);
  }
  if(P-p<0){
    a+=abs(P-p);
  }
    printf("%d\n",a);
 
    system("pause");
	return 0;
}