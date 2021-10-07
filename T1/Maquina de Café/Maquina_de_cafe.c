/*
Trabalho 1 - Maquina de café
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
#include <time.h>
//entradas
int main () {
    // Declaração de variáveis 
    int andar_1;  // Quantidade de pessoas no andar 1
    int andar_2;  // Quantidade de pessoas no andar 2
    int andar_3;  // Quantidade de pessoas no andar 3
    int tempo_1;  // Caso a maquina seja no andar 1
    int tempo_2;  // Caso a maquina seja no andar 2
    int tempo_3;  // Caso a maquina seja no andar 3
    int menor_tempo;  // Recebe o menor tempo gasto

    printf("-------------------------| MAQUINA DE CAFE |-------------------------\n");
    printf("\n--> Para uma melhor instalacao da maquina de cafe, responda os itens abaixo:");
    printf("\n");
    // Entrada 1: Quantidade de pessoas no primeiro andar
    printf("---------------------------------------------------------------------");
    printf("\n--> Informe a quantidade de pessoas no primeiro andar: ");
    scanf("%d", &andar_1);
    // Validação da entrada 1
    if ((andar_1 < 0) || (andar_1 > 1000)) {
        do {
            printf("\n-> Quantidade incorreta!");
            printf("\n-> Informe uma quantidade de 0 ate 1000 pessoas por andar.");
            printf("\n");
            printf("\n--> Informe a quantidade correta de pessoas no primeiro andar: ");
            scanf("%d", &andar_1);
        } while ((andar_1 < 0) || (andar_1 > 1000));
    }
    // Entrada 2: Quantidade de pessoas no segundo andar
    printf("---------------------------------------------------------------------");
    printf("\n--> Informe a quantidade de pessoas no segundo andar: ");
    scanf("%d", &andar_2);
    // Validação da entrada 2
    if ((andar_2 < 0) || (andar_2 > 1000)) {
        do {
            printf("\n-> Quantidade incorreta!");
            printf("\n-> Informe uma quantidade de 0 ate 1000 pessoas por andar.");
            printf("\n");
            printf("\n--> Informe a quantidade correta de pessoas no segundo andar: ");
            scanf("%d", &andar_2);
        } while ((andar_2 < 0) || (andar_2 > 1000));
    }
    // Entrada 3: Quantidade de pessoas no terceiro andar
    printf("---------------------------------------------------------------------");
    printf("\n--> Informe a quantidade de pessoas no terceiro andar: ");
    scanf("%d", &andar_3);
    // Validação da entrada 3
    if ((andar_3 < 0) || (andar_3 > 1000)) {
        do {
            printf("\n-> Quantidade incorreta!");
            printf("\n-> Informe uma quantidade de 0 ate 1000 pessoas por andar.");
            printf("\n");
            printf("\n--> Informe a quantidade correta de pessoas no terceiro andar: ");
            scanf("%d", &andar_3);
        } while ((andar_3 < 0) || (andar_3 > 1000));
    }
    // Por conta dos laços de repetição nas validações das entradas,
    // o processamento a seguir só será executado se os valores informados forem válidos.

    // Caso a máquina seja no andar 1:
    // 4 min para descer e subir para quem está no andar 3
    // 2 min para descer e subir para quem está no andar 2
    tempo_1 = (4 * andar_3) + (2 * andar_2);
    // Caso a máquina seja no andar 2:
    // 2 min para subir e descer para quem está no andar 1
    // 2 min para descer e subir para quem eatá no andar 2
    tempo_2 = (2 * andar_1) + (2 * andar_3);
    // Caso a máquina seja no andar 3:
    // 4 min para subir e descer para quem está no andar 1
    // 2 min para subir e descer para quem está no andar 2
    tempo_3 = (4 * andar_1) + (2 * andar_2);
    // Verificação do menor tempo 
    if ((tempo_1 <= tempo_2) && (tempo_1 <= tempo_3)) {
        menor_tempo = tempo_1;
    }
    else if (tempo_2 <= tempo_3) {
        menor_tempo = tempo_2;
    }
    else {
        menor_tempo = tempo_3;
    }
    // Verificações para definir qual andar a máquina vai ficar 
    // de acordo com o tempo, e saídas
    if ((tempo_1 == tempo_2) && (tempo_1 == tempo_3)) {
        printf("\n--> Tempo: %d", menor_tempo);
        printf("\n--> Maquina localizada no(s) andar(res) 1 ou 2 ou 3.");
    }
    if ((tempo_1 == tempo_2) && (tempo_1 < tempo_3)) {
        printf("\n--> Tempo: %d", menor_tempo);
        printf("\n--> Maquina localizada no(s) andar(res) 1 ou 2.");
    }
    if ((tempo_2 == tempo_3) && (tempo_1 < tempo_3)) {
        printf("\n--> Tempo: %d", menor_tempo);
        printf("\n--> Maquina localizada no(s) andar(res) 1 ou 3.");
    }
    if ((tempo_3 == tempo_2) && (tempo_3 < tempo_1)) {
        printf("\n--> Tempo: %d", menor_tempo);
        printf("\n--> Maquina localizada no(s) andar(res) 2 ou 3.");
    }
    if ((tempo_1 < tempo_2) && (tempo_1 < tempo_3)) {
        printf("\n--> Tempo: %d", menor_tempo);
        printf("\n--> Maquina localizada no(s) andar(res) 1.");
    }
    if ((tempo_2 < tempo_3) && (tempo_2 < tempo_1)) {
        printf("\n--> Tempo: %d", menor_tempo);
        printf("\n--> Maquina localizada no(s) andar(res) 2.");
    }
    if ((tempo_3 < tempo_1) && (tempo_3 < tempo_2)) {
        printf("\n--> Tempo: %d", menor_tempo);
        printf("\n--> Maquina localizada no(s) andar(res) 3.");
    }
    printf("\n---------------------------------------------------------------------\n");
    system("pause");
    return 0;  
}