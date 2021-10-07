#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

 int idade=0,i;
 int cont=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0;
 
for(i=1;i<=15;i++){

  printf("\nPessoa: %i\n",i);

do{
  printf("\nIDADE:\n");
   scanf("%d",&idade);

if(idade>=1 && idade<=15){
	cont1++;
}
if(idade>=16 && idade<=30){
	cont2++;
}
if(idade>=31 && idade<=45){
	cont3++;
}
if(idade>=46 && idade<=60){
	cont4++;
}
if(idade>60){
	cont5++;
}

}while(idade<=0);



}
printf("\nPRIMERIRA FAIXA ETARIA: %d\n",cont1);
printf("\nSEGUNDA FAIXA ETARIA: %d\n",cont2);
printf("\nTERCEIRA FAIXA ETARIA: %d\n",cont3);
printf("\nQUARTA FAIXA ETARIA: %d\n",cont4);
printf("\nQUINTA FAIXA ETARIA: %d\n",cont5);
printf("\nPERCENTAGEM PRIMERIRA FAIXA ETARIA:%d\n",(cont1*100)/15);
printf("\nPERCENTAGEM QUINTA FAIXA ETARIA:%d\n",(cont5*100)/15);




	system("pause");
	return 0;
}