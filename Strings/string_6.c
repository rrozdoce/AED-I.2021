#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Obter String do usuário

int main(int argc, char const *argv[])
{
    char nome[30];
    char sobrenome[20];

    printf("Insira seu nome e sobrenome:\n");
    scanf("%s%s", &nome, &sobrenome); // Felipe Echeverria

    printf("%s %s\n", nome, sobrenome);

    system("pause");
    return 0;
}
