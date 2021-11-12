#include <stdio.h>
#include <stdlib.h>

//Fliper-URI
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{

 int P,R;

    scanf("%d %d",&P,&R);
   
   if(P == 0){
   	printf("C\n");
   }
   if(P == 1 && R == 1){
      printf("A\n");
   }
   if(P == 1 && R == 0){
      printf("B\n");
   }
    
		system("pause");
	return 0;
}