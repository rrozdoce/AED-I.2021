#include <stdio.h>
#include <stdlib.h>

// Porque utilizar #define / Diretivas de Pré Processamento

void umaFuncao(void)
{
    printf("%i\n", 1000);
}

void umaOutraFuncao(void)
{
    printf("%i\n", 1000);
}

int main(void)
{
    void umaFuncao(void);
    void umaOutraFuncao(void);

    printf("%i\n", 1000);
    umaFuncao();
    umaOutraFuncao();

    system("pause");
    return 0;
}