#include <stdio.h>
#include <stdlib.h>

// Vetores de Estruturas

int main(int argc, char const *argv[])
{

    struct horario
    {
        int horas;
        int minutos;
        int segundos;
    };

    struct horario teste[5] =
        {{10, 20, 30}, {20, 20, 40}, {30, 40, 50}, {40, 50, 60}, {50, 60, 70}};

    for (int i = 0; i < 5; ++i)
    {
        printf(" %i: %i: %i\n", teste[i].horas,
               teste[i].minutos,
               teste[i].segundos);
    }

    system("pause");
    return 0;
}
