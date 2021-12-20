#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Verificar igualdade Entre duas strings

int main(int argc, char const *argv[])
{
    _Bool stringsIguais(char s1[], char s2[]);

    // false 0
    // true 1

    if (stringsIguais("casa", "casa"))
    {
        printf("sao iguais\n");
    }
    else
    {
        printf("nao sao iguais\n");
    }

    system("pause");
    return 0;
}
_Bool stringsIguais(char s1[], char s2[])
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
        ++i;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}