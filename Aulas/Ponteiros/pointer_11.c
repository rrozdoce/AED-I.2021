#include <stdio.h>

// Ponteiros e Vetores p2

int main(void)
{

    int vetor[3] = {1, 2, 3};

    int *ponteiro = &vetor[0];

    /* ++ponteiro;
    ++ponteiro; */

    *(ponteiro + 1) = 10;

    //printf("%i\n", *ponteiro);

    printf("%i\n", vetor[1]);

    getchar();
    return 0;
}