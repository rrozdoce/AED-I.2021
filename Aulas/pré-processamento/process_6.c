// MACROS

#include <stdio.h>
#include <stdlib.h>

#define MAIOR(x, y) x > y ? x : y
#define E_MINUSCULO(char) char >= 'a' && char <= 'z'

int main(void)
{

    char x = 'a';

    if (E_MINUSCULO(x))
    {
        printf("E' um letra minuscula\n");
    }
    else
    {
        printf("Nao e' um letra minuscula\n");
    }

    printf("%i\n", MAIOR(10, 50));

    system("pause");
    return 0;
}
