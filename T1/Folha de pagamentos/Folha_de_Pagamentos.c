/*
Trabalho 1 - Folha de pagamentos
Alunos:
Henrique Gettner de Oliveira RGM: 45767
Henrique Apolinário Iwamizu Tada RGM: 43927
Leandro Madeira de Oliveira RGM: 45280
Guilherme Garcia Gloor RGM: 45535
Felipe Echeverria Vilhalva RGM: 45611
João Paulo Ishii Marcon RGM: 45276
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    // Declaração de variáveis
    int qnt_funcionario; // Quantidades de funcionários
    int funcinario_num; // Número do funcionário
    int matricula; // Matrícula do funcionário
    int i; // Controle da quantidade de matrículas de acordo com a quantidade de funcionários
    int ii; // Contagem dos números que compõem a matrícula 
    int soma;
    // Entrada 1: Quantidade de funcionários
    printf("-------------------------| FOLHA DE PAGAMENTOS |-------------------------\n");
    printf("\n--> Informe a quantidade de funcionarios: ");
    scanf("%d", &qnt_funcionario);
    printf("-------------------------------------------------------------------------");
    printf("\n");
    // Validação da entrada 1
    if (qnt_funcionario <= 0 || qnt_funcionario > 10000) {
        do {
            printf("\n--> Quantidade de funcionarios incorreta!");
            printf("\n--> Por favor, informe uma quantidade de 1 a 10.000 funcionarios.");
            printf("\n");
            printf("\n--> Informe a quantidade correta de funcionarios: ");
            scanf("%d", &qnt_funcionario);
        } while (qnt_funcionario <= 0 || qnt_funcionario > 10000);
    }
    // Verificação da entrada 1 para dar continuidade ao código
    if (qnt_funcionario > 0 && qnt_funcionario <= 10000) {
        // Inicializaçao da variável 
        funcinario_num = 0;
        // Controle da quantidade de matrículas
        for (i = 1; i <= qnt_funcionario; i++) {  // Laço de controle das matrículas
            // Inicializaçao da variável 
            soma = 0;
            // Número de cada funcionário
            funcinario_num += 1;
            // Entrada 2: Quantidade de matrículas
            printf("\n --> Informe a matricula do funcionario %d : ", funcinario_num);
            scanf("%d", &matricula);
            // Validação da entrada 2
            if (matricula <= 0 || matricula > 30000) {
                do {
                    printf("\n--> Matricula incorreta do funcionario %d!", funcinario_num);
                    printf("\n--> Por favor, informe o numero de matricula de 1 a 30.000.");
                    printf("\n");
                    printf("\n--> Informe a matricula correta do funcionario %d : ", funcinario_num);
                    scanf("%d", &matricula);
                } while (matricula <= 0 || matricula > 30000);
            }
            // Verificação da entrada 2 
            if (matricula > 0 && matricula <= 30000) {
                // Laço com verificação dos divisores
                for (ii = 1; ii <= matricula; ii++) {
                    // Verifição dos divisores                    
                    if (matricula % ii == 0) {
                        soma = soma + ii;
                    }
                }
                // Saída
                printf("\n--> Salario do funcionario %d: R$ %d, 00 Reais",funcinario_num, soma);
                printf("\n");
                printf("-------------------------------------------------------------------------\n");
            }
        }
    }
    system("pause");
    return 0;
}