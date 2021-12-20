#include <stdio.h>

// Ponteiros e Vetores p1

int main(void)
{

    int vetor[3] = {1, 2, 3};
    int *ponteiro = &vetor[0];

    printf("%i\n", *ponteiro);

    getchar();
    return 0;
}