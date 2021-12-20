#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Obter String do usuário pt 2

int main(int argc, char const *argv[])
{
    /* 
   Função Getchar!!!

   Em caso de sucesso, a função retorna o caractere lido.

   Em caso de erro, a função retorna EOF e marca o indicador de erro (ferror)
   ou o indicador de fim de arquivo (feof) do stdin, dependendo da natureza do erro. 

   */

    char linha[1000];
    char caractere;
    int i = 0;

    do
    {
        caractere = getchar();
        linha[i] = caractere;
        i++;
    } while (caractere != '\n');

    linha[i - 1] = '\0';

    // \n --> é o enter

    printf("%s\n", linha);
    system("pause");
    return 0;
}
