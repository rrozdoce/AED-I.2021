#include <stdio.h>
#include <stdlib.h>

// Introdução a estruturas

int main(int argc, char const *argv[])
{

    int vetor[5];

    // definição da estrutura
    struct horario
    {
        int horas;
        int minutos;
        int segundos;
    };

    // declaração de uma estrutura
    struct horario agora; // -- struct tipo da estrutura nome da estrutura
    // declarou uma estrutura de tipo horario chamada 'agora'

    // inicialização dos membros da estrutura
    agora.horas = 15;
    agora.minutos = 17;
    agora.segundos = 30;

    printf("%i: %i: %i\n", agora.horas, agora.minutos, agora.segundos);

    system("pause");
    return 0;
}
