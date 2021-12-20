#include <stdio.h>
#include <stdlib.h>

// Ponteiros à Estruturas

int main(void)
{

    struct horario
    {
        int hora;
        int minuto;
        int segundo;
    };

    struct horario agora, *depois;
    depois = &agora;

    depois->hora = 20;
    depois->minuto = 20;
    depois->segundo = 20;
    // ordem de precedencia

    printf("%i:%i:%i\n", agora.hora, agora.minuto, agora.segundo);

    getchar();

    system("pause");
    return 0;
}