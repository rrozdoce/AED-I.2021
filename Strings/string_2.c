#include <stdio.h>
#include <stdlib.h>

// concatenar strings sem funções da string.h

int main(int argc, char const *argv[])
{

    void concatenarStrings(char string1[], int t1,
                           char string2[], int t2,
                           char string3[]);
    char palavra1[] = {'p', 'a', 'o', ' '};
    char palavra2[] = {'m', 'o', 'r', 't', 'a', 'd', 'e', 'l', 'a'};
    char novaPalavra[13];

    concatenarStrings(palavra1, 4, palavra2, 9, novaPalavra);

    for (int i = 0; i < 13; ++i)
    {
        printf("%c", novaPalavra[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
void concatenarStrings(char string1[], int t1,
                       char string2[], int t2,
                       char string3[])
{

    for (int i = 0; i < t1; ++i)
    {
        string3[i] = string1[i];
    }

    for (int j = 0; j < t2; ++j)
    {
        string3[t1 + j] = string2[j];
        // t1 + j  fazer com q a quarta posição da string1 seja a primeira posição da string2
    }
}