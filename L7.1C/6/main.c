#include <stdio.h>
#include <stdlib.h>

//Lista 7.1 exer6
//Felipe Echeverria Vilhalva


int main(int argc, char const *argv[])
{

 int funcao(int hora1,int minuto1,int hora2,int minuto2);
 int hora_inicio=0;
 int minutos_inicio=0;
 int hora_termino=0;
 int minutos_termino=0;
 int resultado=0;
 
 do{
 system("cls");
  printf("Inicio\n");
   printf("HORA:MINUTO\n");
    scanf("%d %d",&hora_inicio,&minutos_termino); 

 }while(hora_inicio>=24 || hora_inicio<0 || minutos_inicio>=60 || minutos_inicio<0);  

 system("cls"); 

  do{
   system("cls");
    printf("Termino\n");
     printf("HORA:MINUTO\n");
      scanf("%d %d",&hora_termino,&minutos_termino);

  }while(hora_termino>=24 || hora_termino<0 || minutos_termino>=60 || minutos_termino<0);


 resultado = funcao(hora_inicio,minutos_inicio,hora_termino,minutos_termino);

  printf("Resultado em minutos: %d\n",resultado);


	system("pause");
	return 0;
}

int funcao(int hora1,int minuto1,int hora2,int minuto2){
 
 int diferenca_hora=0;
 int diferenca_minuto=0;
 int convertido_hora=0;
 int convertido_minuto=0;
 int valor_minuto=0;
 int soma=0;
 int soma1=0;
 int soma2=0;

 if(hora1 - hora2 ==0){ //se a hora1 for maior q 

   for(int hora1;hora1<=24;hora1++){

       if(hora1 == 24){
       	   for(int i=0;i<hora2;i++){
              soma2+=1;
       	   }
       }  

      soma1+=1; 	    
   }

   soma = soma1+soma2;

   convertido_hora = soma * 60;

   diferenca_minuto = (60 - minuto1) + minuto2;

   valor_minuto = convertido_hora + diferenca_minuto;


 }else{

 

 diferenca_hora = hora1 - hora2; 

 convertido_hora = diferenca_hora * 60;

 diferenca_minuto = (60 - minuto1) + minuto2;
 
 valor_minuto = convertido_hora + diferenca_minuto;

}
  return valor_minuto;
}