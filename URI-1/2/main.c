#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
 
 int i=1;
 
 for(int j=60;j>=0;j = j - 5){
    printf("I=%i J=%i\n",i,j);
    i = i + 3;
 }



  system("pause");
  return 0;
}