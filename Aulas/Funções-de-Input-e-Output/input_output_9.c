#include <stdio.h>
#include <stdlib.h>

// Limpeza de Buffer

int main(void)
{

    void LimparBuffer(void);

    char a, b, c;

    // fflush(stdin); isso aqui funciona windows, porém nem sempre

    a = getchar();
    flush_in();
    b = getchar();
    flush_in();
    c = getchar();
    flush_in();

    printf("%c", a);
    printf("%c", b);
    printf("%c", c);

    return 0;
}

// Limpeza do Buffer , feito pela Rafa :)
void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

/* void LimparBuffer(void)
{
    char c;
    while ((c = getchar()) != 'n' && c != EOF)
        ;
} */