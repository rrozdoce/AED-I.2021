#include <stdio.h>
#include <stdlib.h>

// Passar e Receber Estruturas à uma Função

int main(int argc, char const *argv[])
{

    struct horario
    {
        int horas;
        int minutos;
        int segundos;
    } agora = {10, 20, 30}; // pode declarar assim tbm

    struct horario agora = {.segundos = 10, .minutos = 20};

    /*struct horario agora;
    agora.horas = 10;
    agora.minutos = 20;
    agora.segundos = 30; */

    printf("%i: %i: %i\n", agora.horas,
           agora.minutos,
           agora.segundos);

    system("pause");
    return 0;
}
