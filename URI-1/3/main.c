#include <stdio.h>
#include <stdlib.h>

//Quadrant-URI
//Felipe Echeverria Vilhalva

int main(int argc, char const *argv[])
{
 
 int x;   /*declarando variaveis*/
 int y;  

 scanf("%d %d",&x,&y);  //entrada

  
  if(x == 0 || y == 0){  //se for NULL
      return 0;
  }
  
  while(x != 0 || y!= 0){  // se nao for NULL

    if(x>0 && y>0){
        printf("primeiro\n");
    }
    if(x>0 && y<0){
        printf("quarto\n");
    }
    if(x<0 && y<0){
        printf("terceiro\n");
    }
    if(x<0 && y>0){
        printf("segundo\n");
    }

    scanf("%d %d",&x,&y); 

   if(x == 0 || y == 0){  //fechando o programa com NULL
       return 0;
   }

  }


    system("pause");
    return 0;
}