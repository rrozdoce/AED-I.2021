#include <stdio.h>
#include <stdlib.h>

// Manipulação de estruturas

int main(int argc, char const *argv[])
{

    int vetor[5];

    struct horario
    {
        int horas;
        int minutos;
        int segundos;
        double teste;
        char letra;
    };

    struct horario agora;

    agora.horas = 15;
    agora.minutos = 17;
    agora.segundos = 30;

    struct horario depois;

    depois.horas = agora.horas + 10;
    depois.minutos = agora.minutos;
    depois.teste = 50.55 / 123;
    depois.letra = 'a';

    printf("%i\n", depois.horas);
    printf("%i\n", depois.minutos);
    printf("%f\n", depois.teste);
    printf("%c\n", depois.letra);

    system("pause");
    return 0;
}
