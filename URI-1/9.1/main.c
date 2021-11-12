#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int numCriancas, bonecas = 0, carros = 0;
    char sexo[10];
    char nome[10];

    scanf("%d", &numCriancas);

    for (int i = 0; i < numCriancas; i++)
    {
        scanf("%s", &nome[i]);
        scanf("%s", &sexo[i]);

        if (sexo[i] == 'M' || sexo[i] == 'm')
        {
            carros++;
        }
        if (sexo[i] == 'F' || sexo[i] == 'f')
        {
            bonecas++;
        }
    }
    printf("%d carrinhos\n", carros);
    printf("%d bonecas\n", bonecas);

    system("pause");
    return 0;
}
