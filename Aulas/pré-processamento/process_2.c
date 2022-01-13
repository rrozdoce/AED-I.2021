#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159
#define NULO 0

// Comando #define / Pré Processamento

double areaCirculo(double raio)
{
    return raio * raio * PI;
}

int main(void)
{
    double areaCirculo(double raio);
    double r;
    int i = 3;

    while (i != NULO)
    {
        printf("Digite o raio do Circulo:");
        scanf("%lf", &r);
        printf("A area do Circulo e %lf\n", areaCirculo(r));
        --i;
    }

    system("pause");
    return 0;
}
