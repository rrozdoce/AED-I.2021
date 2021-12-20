#include <stdio.h>
#include <stdlib.h>

// Contar caracteres de strings

int main(int argc, char const *argv[])
{
    int tamanhoString(char string[]);
    char stringUsuario[20];

    printf("Digite uma palavra(string) :\n");
    scanf("%s", &stringUsuario);

    int num = tamanhoString(stringUsuario);

    printf("A string %s possui %i caracteres.\n", stringUsuario, num);

    system("pause");
    return 0;
}
int tamanhoString(char string[])
{
    int numCaracteres = 0;

    while (string[numCaracteres] != '\0')
    {
        ++numCaracteres;
    }
    ++numCaracteres; // para contar \0 como caractere
    return numCaracteres;
}