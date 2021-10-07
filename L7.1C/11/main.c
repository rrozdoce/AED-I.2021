#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//

int main(int argc, char const *argv[])
{
 
 int vetor_resultante();
 int c=1;
 
 c = vetor_resultante();

 printf("VETOR[%d]\n",c);


	system("pause");
	return 0;
}

int vetor_resultante(){
  int a=1;
  int b=1;
  int c=1;

 do{

 system("cls");
  printf("A:\n");
   scanf("%d",&a);

 }while(a<0);

system("cls");

 do{
  
 system("cls");
  printf("B:\n");
   scanf("%d",&b);

 }while(b<0);

 c = a + b;

 return c;

}