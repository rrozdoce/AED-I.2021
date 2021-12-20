#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Verificar Caracteres Alfabéticos/Apenas Letras(lógica)
// Verificar se uma variavel é uma letra

int main(int argc, char const *argv[])
{

    void alfabetico(char variavel);

    char nome[20];
    printf("Digite uma palavra: ");
    scanf("%s", &nome);

    int i = 0;
    while (nome[i] != '\0')
    {
        alfabetico(nome[i]);
        ++i;
    }

    system("pause");
    return 0;
}

void alfabetico(char variavel)
{
    if ((variavel >= 'a' && variavel <= 'z') ||
        (variavel >= 'A' && variavel <= 'Z'))
    {
        printf("eh uma letra\n");
    }
    else
    {
        printf("nao eh uma letra\n");
    }
}