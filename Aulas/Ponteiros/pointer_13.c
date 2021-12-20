#include <stdio.h>

// Copiar uma String utilizando Ponteiros

void copiarString(char *copiarDaqui, char *colarAqui)
{
}

int main(void)
{
    void copiarString(char *copiarDaqui, char *colarAqui);

    char string1[] = "Pão com mortadela";
    char string2[20];

    copiarString(string1, string2);
    printf("%s\n", string2);

    getchar();
}
