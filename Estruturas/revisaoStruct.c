#include <stdio.h>
#include <stdlib.h>

struct horario
{
    int horas;
    int minutos;
    int segundos;
};

int main(int argc, char const *argv[])
{

    void receberHorarios(struct horario list[5]);
    void printHorarios(struct horario list[5]);
    struct horario listaHorarios[5];

    receberHorarios(listaHorarios);
    printHorarios(listaHorarios);

    system("pause");
    return 0;
}

void receberHorarios(struct horario list[5])
{
    for (int i = 0; i < 5; ++i)
    {
        printf("Digite o %i Horario(hh:mm:ss)\n", i + 1);
        scanf("%d %d %d", &list[i].horas,
              &list[i].minutos,
              &list[i].segundos);
    }
}

void printHorarios(struct horario list[5])
{

    for (int i = 0; i < 5; ++i)
    {
        printf("O %i horario e' = %i:%i:%i\n", i + 1,
               list[i].horas,
               list[i].minutos,
               list[i].segundos);
    }
}