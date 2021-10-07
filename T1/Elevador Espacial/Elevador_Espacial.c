/*
Trabalho 1 - Elevador Espacial
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
    //Declaração de variáveis
    int andar, dec_1, dec_2, dec_3, dec_4, dec_5, dec_6, dec_7;  // Casas decimais 
    int cont_1;  // Contagem dos andares
    int cont_2;  //Variável de controle do While
    // Entrada 1: Andar
    printf("-------------------------| ELEVADOR ESPACIAL |-------------------------\n");
    printf("\n--> Qual andar voce deseja ir : ");
    scanf("%d", &andar);
    // Validação da entrada 1
    if ((andar < 1) || (andar > 1000000)) {
        do {
            printf("\n--> Andar inválido!");
            printf("\n--> Digite um andar de 1 ate 1000000 ");
            printf("\n");
            printf("\n--> Informe novamente o andar que deseja ir: ");
            scanf("%d", &andar);
            printf("\n");
        } while ((andar < 1) || (andar > 1000000));
    }
    // Verificação da entrada 1
    if ((andar >= 1) && (andar <= 1000000)) {
        // Inicialização das variáveis
        dec_1 = 0;
        dec_2 = 0;
        dec_3 = 0;
        dec_4 = 0;
        dec_5 = 0;
        dec_6 = 0;
        dec_7 = 0;
        cont_1 = 0;
        cont_2 = 0;
        // Laço para separar e verificar cada casa decimal
        while (cont_2 < andar) {
            cont_2 += 1;
            cont_1 += 1;
            // Separação do andar informado em casas decimais
            dec_7 = (cont_1 % 10);
            dec_6 = ((cont_1 / 10) % 10);
            dec_5 = ((cont_1 / 100) % 10);
            dec_4 = ((cont_1 / 1000) % 10);
            dec_3 = ((cont_1 / 10000) % 10);
            dec_2 = ((cont_1 / 100000) % 10);
            dec_1 = ((cont_1 / 1000000) % 10);
            // Verificação do número 13
            if ((dec_1 == 1) && (dec_2 == 3)) {
                cont_1 += 1000000;
            }
            if ((dec_2 == 1) && (dec_3 == 3)) {
                cont_1 += 10000;
            }
            if ((dec_3 == 1) && (dec_4 == 3)) {
                cont_1 += 1000;
            }
            if ((dec_4 == 1) && (dec_5 == 3)) {
                cont_1 += 100;
            }
            if ((dec_5 == 1) && (dec_6 == 3)) {
                cont_1 += 10;
            }
            if ((dec_6 == 1) && (dec_7 == 3)) {
                cont_1 += 1;
            }
            // Novamente separando o andar informado em casas decimais
            dec_7 = (cont_1 % 10);
            dec_6 = ((cont_1 / 10) % 10);
            dec_5 = ((cont_1 / 100) % 10);
            dec_4 = ((cont_1 / 1000) % 10);
            dec_3 = ((cont_1 / 10000) % 10);
            dec_2 = ((cont_1 / 100000) % 10);
            dec_1 = ((cont_1 / 1000000) % 10);
            // Verificação do número 4
            if (dec_7 == 4) {
                cont_1 += 1;
            }
            if (dec_6 == 4) {
                cont_1 += 10;
            }
            if (dec_5 == 4) {
                cont_1 += 100;
            }
            if (dec_4 == 4) {
                cont_1 += 1000;
            }
            if (dec_3 == 4) {
                cont_1 += 10000;
            }
            if (dec_2 == 4) {
                cont_1 += 100000;
            }
            if (dec_1 == 4) {
                cont_1 += 1000000;
            }
        }
    }
    printf("--> Seu andar: %d\n",cont_1);
    printf("-----------------------------------------------------------------------\n");

    system("pause");
    return 0;
}