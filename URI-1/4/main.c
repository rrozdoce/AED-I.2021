#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 

 int  n;

 scanf("%d",&n);

  for(int i=1;i<=n;i++){
     printf("%i %i %i\n",i,i*i,i*i*i);
     printf("%i %i %i\n",i,i*i+1,i*i*i+1);   
  }

	system("pause");
	return 0;
}