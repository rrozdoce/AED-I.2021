#include <stdio.h>
#include <stdlib.h>

//  Função gets (Aprenda como utilizar e porque não utilizar)

int main(void)
{

    char x[10];
    char y[10];

    gets(x); // ler uma string do stdin
    // gets é uma função insegura, ela nem exista na versao mais nova de C

    printf("%s", x);

    return 0;
}
