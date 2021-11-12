#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

 int t;  //numero de casos testes
 int n; //numero inteiro

  scanf("%d",&t);
 
 for(int i=0;i<t;i++){
   scanf("%d",&n); //entrada do numero inteiro
   printf("%d\n",(int)pow(2,n)-1); //2^n-1
    
 }


	return 0;
}