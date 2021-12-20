#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* int x = 10;
    int y = x;

    x = 20; */

    int x = 10;
    int *ponteiro;
    ponteiro = &x;

    int y = 20;
    *ponteiro = y;
    //o valor de x foi alterado aqui, pois x = y

    printf("%i %i\n", x, y);

    getchar();

    system("pause");
    return 0;
}
