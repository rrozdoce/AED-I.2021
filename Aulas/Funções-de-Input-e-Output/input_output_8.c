#include <stdio.h>
#include <stdlib.h>

// Função getchar e Função putchar

int main(void)
{

    /* 
      getchar...

    char x[10];
    int i = 0;
    while ((x[i] = getchar()) != '\n' && i < 8)
    {

        ++i;
    }

    x[++i] = '\0'; linha pra add o caractere nulo 
    
      printf("%s", x);
    */

    /* 
      putchar, coloca um caractere no stdout

    */

    int i = 0;
    char x;

    while ((x = getchar()) != '\n')
    {
        putchar(x);
    }

    return 0;
}