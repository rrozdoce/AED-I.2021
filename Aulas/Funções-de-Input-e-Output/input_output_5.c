#include <stdio.h>
#include <stdlib.h>

// Funções fputc e putc

int main(void)
{

    char x[] = "coxinha";

    FILE *file = fopen("Users/XSpat/OneDrive/Área de Trabalho/Arquivo.txt", "w");

    // putc era uma macro ,fputc == putc, ja fputc só pode ser implementada como uma função
    //  fputc e putc conseguem escrever um caractere no output/string q a gente especificar
    // stdout(standard out) significa q a string q a gente escrever vai ser no padrão de saida

    int i = 0;
    while (x[i] != '\0')
    {
        putc(x[i], stdout);
    }

    return 0;
}
