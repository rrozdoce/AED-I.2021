//gerador de cpf
 
// Libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Protótipo da função geradora de CPF
int* cpf_generator();
 
// Função main
// Main Function
int main(int argc, char** argv)
{
 int *cpf, i;
  
 // Inicia o gerador de números aleatórios
 srand(time(NULL));
  
 // Gera um cpf aleatório
 cpf = cpf_generator();
  
 // Imprime o cpf gerado na tela
 for(i = 0; i < 11; i++) {
  printf("%d", cpf[i]);
 }
 printf("\n");
  
 system("pause");
  
 // Libera a memória usada para o cpf
 free(cpf);
 return 0;
}
 
// Função Geradora de CPF
int* cpf_generator() {
    int *cpf, pesos[11], vetSoma[11], soma, resto, digito,  i;
     
    // Aloca memória para o cpf
    cpf = (int *) malloc(sizeof(int) * 11);
     
    // Gera 9 números aleatórios
    for(i = 0; i < 9; i++) {
        cpf[i] = rand() % 10;
    }
     
    // Cálculo do primeiro dígito verificador
     
    // Gera os 9 pesos
    for(i = 0; i < 9; i++) {
        pesos[i] = 10 - i;
    }
     
    // Multiplica os valores de cada coluna
    for(i = 0; i < 9; i++) {
        vetSoma[i] = cpf[i] * pesos[i];
    }
     
    // Calcula o somatório dos resultados
    soma = 0;
    for(i = 0; i < 9; i++) {
        soma += vetSoma[i];
    }
     
    // Realiza-se a divisão inteira do resultado por 11
    resto = soma % 11;
     
    // Verifica o resto da divisão
    if(resto < 2) {
        digito = 0;
    } else {
        digito = 11 - resto;
    }
     
    // Adiciona o 1º dígito verificador ao cpf
    cpf[9] = digito;
     
    // Cálculo do segundo dígito verificador
     
    // Gera os 10 pesos
    for(i = 0; i < 10; i++) {
        pesos[i] = 11 - i;
    }
     
    // Multiplica os valores de cada coluna
    for(i = 0; i < 10; i++) {
        vetSoma[i] = cpf[i] * pesos[i];
    }
     
    // Calcula o somatório dos resultados
    soma = 0;
    for(i = 0; i < 10; i++) {
        soma += vetSoma[i];
    }
     
    // Realiza-se a divisão inteira do resultado por 11
    resto = soma % 11;
     
    // Verifica o resto da divisão
    if(resto < 2) {
        digito = 0;
    } else {
        digito = 11 - resto;
    }
     
    // Adiciona o 2º dígito verificador ao cpf
    cpf[10] = digito;
     
    return cpf;
}