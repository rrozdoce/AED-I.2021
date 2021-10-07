#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int opc_sexo=0,opc=0,i;
 int cont_sim=0,contf_sim=0;
 int cont_nao=0,contm_nao=0;
  
 for(i=0;i<2;i++){
 
 do{
  system("cls");
  printf("\nSEXO:\n");
  printf("\n\t1 - FEMININO\n\t2 - MASCULINO\n");
  scanf("%d",&opc_sexo);
 }while(opc_sexo!=1 && opc_sexo!=2);

 do{
  system("cls");
  printf("\nVotacao:\n");
  printf("\n\t1 - SIM\n\t2 - NAO\n");
  scanf("%d",&opc);

  if(opc==1){
  	cont_sim++;
  }
  if(opc==2){
  	cont_nao++;
  }

 }while(opc!=1 && opc!=2);


  if(opc_sexo==1 && opc==1){
	contf_sim++;
  }
  if(opc_sexo==2 && opc==2){
	contm_nao++;
  }
 

 }

printf("\nrespondeu SIM: %d\n",cont_sim);
printf("respondeu NAO: %d\n",cont_nao);
printf("Mulheres que responderam SIM: %d\n",contf_sim);
printf("Homens que responderam NAO: %d\n\n",contm_nao);


	system("pause");
	return 0;
}