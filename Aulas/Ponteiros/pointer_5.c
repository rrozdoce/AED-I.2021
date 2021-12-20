#include <stdio.h>
#include <stdlib.h>

// Ponteiros à Estruturas(Operações Matemáticas)

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

    depois->hora = 20; //(*depois).hora;
    depois->minuto = 80;
    depois->segundo = 20;

    int somatorio = 100;

    struct horario antes;

    antes.hora = somatorio + depois->segundo;
    antes.minuto = agora.hora + depois->minuto;
    antes.segundo = depois->minuto + depois->segundo;

    printf("%i:%i:%i\n", antes.hora, antes.minuto, antes.segundo);

    getchar();

    system("pause");
    return 0;
}