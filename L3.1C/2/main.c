#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 float valor=0,num=1,deno=0,i;
 float soma=0,div=1;

 printf("\nN:\n");
 scanf("%f",&valor);

for(i=1;i<valor;i++){
 deno++;
 div=num/deno;
 soma+=div;
 i++;
}
printf("\nSOMA:%f\n",soma);





	system("pause");
	return 0;
}