#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

 int t,n,i=0;

 scanf("%d",&t);

 while(i<t){

 	scanf("%d", &n);
 	printf("%d\n", (int)pow(2,n) - 1);
    i++;
 }







	return 0;
}