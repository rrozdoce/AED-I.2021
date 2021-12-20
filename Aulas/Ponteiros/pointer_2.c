#include <stdio.h>
#include <stdlib.h>

// Ponteiros "char, int, double"

int main(void)
{
    // px --> endereço
    // *px --> valor

    int x = 10;
    double y = 20.50;
    char z = 'a';

    /* int *px;
    px = &x; */

    int *px = &x;
    double *py = &y;
    char *pz = &z;

    int *resultado;
    resultado = 6422276;

    printf("Endereco x = %i -- valor x = %i\n", px, *px);
    printf("Endereco y = %i -- valor y = %f\n", py, *py);
    printf("Endereco z = %i -- valor z = %c\n", pz, *pz);

    double soma = *px + *py;

    printf("Soma = %f\n", soma);

    printf("valor = %i\n", *resultado);

    getchar();

    system("pause");
    return 0;
}
