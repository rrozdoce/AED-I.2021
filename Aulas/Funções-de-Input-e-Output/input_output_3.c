#include <stdio.h>
#include <stdlib.h>

// Funções fgetc e getc

int main(void)
{

    char x[100];

    /*     x[0] = fgetc(stdin); // stdin --> irá obter dados da entrada padrão do teclado

    // fgetc(stdin) --> retorna o proximo caractere do ponteiro file informado em stdin
    // fgetc = getc , porém tem história por tras que o prof conta na aula

          printf("%c", x[0]);
     */

    // obter string do usuario
    int i = 0;
    while ((x[i] = fgetc(stdin)) != '\n') // esse ciclo será executado enquanto o usuario nao apertar Enter no teclado
    {
        ++i;
    }

    /* x[i] = '\0'; // ultimo caractere será nulo */

    x[++i] = '\0'; // adicionar + 1 como caractere nulo, pois '\n' esta ocupando x[i]

    printf("%s", x);

    system("pause");
    return 0;
}