/*
Trabalho 1 - Azulejos
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
    int qnt_azulejos;  // Quantidade de azulejos.
    int a;  // Primeiro numero inteiro
    int b;  // Segundo numero inteiro
    int i;  // Controle do laço
    int qnt_pintados;  // Quantidade de azulejos pintados
    // Entrada 1: Quantidade de azulejos
    printf("------------------------------| AZULEJOS |-----------------------------\n");
    printf("\n---> Informe a quantidade de azulejos: ");
    scanf("%d", &qnt_azulejos);
    printf("-------------------------------------------------------------------------");
    // Validação da entrada 1
    if ((qnt_azulejos < 3) || (qnt_azulejos > 10000)) {
        do {
            printf("\n--> Quantidade de azulejos invalida!");
            printf("\n--> Por favor, infome uma quantidade de 3 a 10.000 azulejos.");
            printf("\n");
            printf("--> Informe a quantidade correta de azulejos: ");
            scanf("%d", &qnt_azulejos);
            printf("\n");
        } while ((qnt_azulejos < 3) || (qnt_azulejos > 10000));
    }
    // Verificação da entrada 1 para dar continuidade ao código
    if ((qnt_azulejos >= 3) && (qnt_azulejos <= 10000)) {
        // Entrada 2: Primeiro número inteiro
        printf("\n--> Informe abaixo numeros inteiros e positivos!");
        printf("\n");
        printf("\n--> Digite o primeiro numero: ");
        scanf("%d", &a);
        // Validação da entrada 2
        if ((a < 2) || (a > qnt_azulejos)) {
            do {
                printf("\n--> Numero invalido!");
                printf("\n--> Por favor, infome um numero qualquer de 2 ate quantidade de azulejos fornecida.");
                printf("\n");
                printf("\n--> Digite novamente o primeiro numero:");
                scanf("%d", &a);
            } while ((a < 2) || (a > qnt_azulejos));
        }
        // Entrada 3: Segundo número inteiro
        printf("\n--> Digite o segundo numero: ");
        scanf("%d", &b);
        // Validação da entrada 3
        if ((b < 2) || (b > qnt_azulejos)) {
            do {
                printf("\n--> Numero invalido!");
                printf("\n--> Por favor, infome um numero qualquer de 2 ate quantidade de azulejos fornecida.");
                printf("\n");
                printf("\n--> Digite novamente o segundo numero:");
                scanf("%d", &b);
            } while ((b < 2) || (b > qnt_azulejos));
        }
    }
    // Verificação das entradas 2 e 3 para executar o laço.
    if (((a >= 2) && (a <= qnt_azulejos)) && ((b >= 2) && (b <= qnt_azulejos))) {
        qnt_pintados = 0;  // Inicialização da variável
        // Laço para verificar os múltiplos de cada numero que compõe a quantidade de azulejos 
        for (i = 1; i <= qnt_azulejos; i++){
            // verificação dos múltiplos
            if ((i % a == 0) || (i % b == 0)) {
                qnt_pintados += 1;
            }
            // Verificação de igualdade das 3 entradas com 0
            else if (qnt_azulejos == a == b == 0) {
                // Não altera o valor
                qnt_pintados = qnt_pintados;
            }
        }
        // Saídas
        printf("--------------------------------------------------------------------------");
        printf("\n--> Quantidade total de azulejos: %d ", qnt_azulejos);
        printf("\n--> Quantidade de azulejos a serem pintados: %d\n ", qnt_pintados);
        printf("-------------------------------------------------------------------------\n");            
    }
    system("pause");
    return 0;
}